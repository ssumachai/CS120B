/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)
*          Lab Section:    021 
 *         Assignment:    Final Project
 *         Exercise Description: Oh That's Pitiful (Full Functionality + 3 Complexities)
 *        
 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.
 *
 *         Demo Link: https://youtu.be/JGi1TA9-SYM
 */

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include "unit.h"
#include "three_star.h"
#include "four_star.h"
#include "five_star.h"

// Declare LCD object for software SPI
// Adafruit_PCD8544(CLK,DIN,D/C,CE,RST);
Adafruit_PCD8544 display = Adafruit_PCD8544(13, 18, 12, 10, 11);
unit five_pool[6];
unit four_pool[3];
unit three_pool[5];
unit curr_unit;



const int button1 = 17, button2 = 16;           // Wish Buttons
const int joyX = 14, joyY = 15, button = 8;     // Joystick     
bool wish_arrow, menu_arrow;                    // Arrow Indicators
bool menu, pity, wish, reset = false;           // Bools for Tasks to Display Appropriate Displays
bool confirmed, wishing = false;                // LCD Confirmation
byte timer;                                     // Timer lol
byte curr_wish, wish_amount;                    // For use in State WISH_WAIT
byte four_star_pity, five_star_pity;            // For Wish Numbers
byte five_rate;                                 // Rate of a Five Star Object
bool five_guarantee;                            // Used to Track 5* 50/50

// Custom Glype used to indicate Rarity
byte stars[] = {
    B00000,
    B00000,
    B00100,
    B01110,
    B11111,
    B01110,
    B00100,
    B00000
};

void check_soft_pity(){
    if(five_star_pity < 74){        
        five_rate = 6;          
    }
    else if(five_star_pity == 74){
        five_rate = 200;
    }
    else if(five_star_pity > 74){
        five_rate += 30;
    }
}

void pull(){
    // Wish Rates will Vary depending on your pity
    // Explained above
    check_soft_pity();
    int four_range_low, four_range_hi;

    four_range_low = five_rate + 1;
    four_range_hi = four_range_low + 50;

    long randNumber = 0;
    long randUnit = 0;
    long fifty_fifty = 0;
    randNumber = random(1, 1001);
    Serial.print("Draw: ");
    Serial.print(randNumber);
    if(five_star_pity == 89 || (randNumber >= 1 && randNumber <= five_rate)){
        five_star_pity = 0;
        ++four_star_pity;
        if(!five_guarantee){
            fifty_fifty = random(0, 2);
            if(fifty_fifty){
                randUnit = 0;
            }
            else{
                five_guarantee = true;
                randUnit = random(1, 6);
            }
        }
        else{
            randUnit = 0;
            five_guarantee = false;
        }
        curr_unit = five_pool[randUnit];
    }
    else if(four_star_pity == 9 || (randNumber >= four_range_hi && randNumber <= four_range_hi)){
        four_star_pity = 0;
        ++five_star_pity;
        randUnit = random(0, 3);
        curr_unit = four_pool[randUnit];
    }
    else{
        ++four_star_pity;
        ++five_star_pity;
        randUnit = random(0, 5);
        curr_unit = three_pool[randUnit];
    }
    Serial.print("\nUnit: ");
    Serial.print(randUnit);
    Serial.print("\nFour-Star Pity: ");
    Serial.print(four_star_pity);
    Serial.print("\nFive-Star Pity: ");
    Serial.print(five_star_pity);
    Serial.print("\n");   
}

// Task Structure Definition
typedef struct task {
  int state;
  unsigned long period;
  unsigned long elapsedTime;
  int (*TickFct)(int);
    
} task;

const unsigned short tasksNum = 4;
task tasks[tasksNum];

enum wish_States {wish_start, MENU, WISH_IDLE, PITY, ONE_PULL_PRESS,
                  TEN_PULL_PRESS, ONE_WISH, TEN_WISH, WISH_WAIT, RESET, RESETTING};
int wish_Tick(int state){
    int one_wish = digitalRead(button1);
    int ten_wish = digitalRead(button2);
    int xValue = analogRead(joyX);
    int yValue = analogRead(joyY);
    int confirm = digitalRead(button);

    switch(state){
        case wish_start:
            state = MENU;
            reset = pity = wish = wishing = confirmed = false;
            menu = true;
            four_star_pity = five_star_pity = 0;
            five_guarantee = false;
            five_rate = 6;
            timer = 0;
            break;
        case MENU:
            if(!confirm){
                if(menu_arrow){
                    state = WISH_IDLE;
                    wish = true;
                    menu = false;
                }
                else{
                    state = PITY;
                    pity = true;
                    menu = false;
                }
                lcd.clear();
                display.clearDisplay();
            }
            else{
                state = MENU;
                menu = true;
                pity = wish = false;
            }
            break;
        case PITY:
            if(!confirm){
                state = MENU;
                wish = pity = false;
                menu = true;
                lcd.clear();
                display.clearDisplay();
            }
            else{
                state = PITY;
                pity = true;
                menu = wish = false;
            }
            break;
        case WISH_IDLE:
            wishing = confirmed = false;
            if(!confirm){
                state = MENU;
                menu = true;
                pity = wish = false;
                lcd.clear();
                display.clearDisplay();
            }
            else{
                if(one_wish && !ten_wish){
                    state = ONE_PULL_PRESS;
                    confirmed = true;
                    wish_amount = 1;
                    lcd.clear();
                    display.clearDisplay();
                }
                else if(!one_wish && ten_wish){
                    state = TEN_PULL_PRESS;
                    confirmed = true;
                    wish_amount = 10;
                    lcd.clear();
                    display.clearDisplay();
                }
                else{
                    state = WISH_IDLE;
                }
            }
            break;
        case ONE_PULL_PRESS:
            if(one_wish && ten_wish){
                state = RESET;
                reset = true;
                confirmed = false;
                lcd.clear();
                display.clearDisplay();
            }
            else{
                if(!confirm){
                    if(wish_arrow){
                        wishing = true;
                        state = ONE_WISH;
                        wish = false;
                        pull();
                    }
                    else{
                        state = WISH_IDLE;
                    }
                    confirmed = false;
                    lcd.clear();
                }
                else{
                    state = ONE_PULL_PRESS;
                }
            }
            break;
        case TEN_PULL_PRESS:
            if(one_wish && ten_wish){
                state = RESET;
                reset = true;
                confirmed = false;
                lcd.clear();
                display.clearDisplay();
            }
            else{
                if(!confirm){
                    if(wish_arrow){
                        state = TEN_WISH;
                        wishing = true;
                        wish = false;
                        curr_wish = 1;
                        pull();
                    }
                    else{
                        state = WISH_IDLE;
                    }
                    confirmed = false;
                }
                else{
                    state = TEN_PULL_PRESS;
                }
            }
            break;
        case ONE_WISH:
            if(yValue > 800 && (xValue >= 200 && xValue <= 1100)){
                state = WISH_WAIT;
                wishing = false;
                display.clearDisplay();
            }
            else{
                state = ONE_WISH;
            }
            break;
        case TEN_WISH:
            if(curr_wish < 10){
                if(!confirm){
                    ++curr_wish;
                    pull();
                    display.clearDisplay();
                    lcd.clear();
                }
            }
            if(curr_wish == 10 && (yValue > 800 && (xValue >= 200 && xValue <= 1100))){
                    state = WISH_WAIT;
                    wishing = false;
                    display.clearDisplay();
            }
            else{
                state = TEN_WISH;
            }
            break;
        case WISH_WAIT:
            if(!confirm){
                state = WISH_IDLE;
                wishing = confirmed = false;
                wish = true;
            }
            else{
                state = WISH_WAIT;
            }
            break;
        case RESET:
            if(!confirm){
                if(wish_arrow){
                    state = RESETTING;
                    timer = 0;
                    confirmed = true;
                    lcd.clear();
                    display.clearDisplay();
                }
                else{
                    reset = false;
                    state = WISH_IDLE;
                    lcd.clear();
                }
            }
            else{
                state = RESET;
            }
            break;
        case RESETTING:
            if(timer < 20){
                state = RESETTING;
            }
            else{
                state = wish_start;
            }
            break;
        default:
            break;
    }

    switch(state){
        case RESETTING:
            ++timer;
            break;
        default:
            break;
    }

    return state;
}

enum lcd_States {lcd_start, lcd_display, lcd_confirm, lcd_wish, lcd_wait, lcd_reset};
int lcd_Tick(int state){
    switch(state){
        case lcd_start:
            state = lcd_display;
            pity = wish = false;
            break;
        case lcd_display:
            if(confirmed){
                state = lcd_confirm;
                lcd.clear();
            }
            else if(wishing){
                state = lcd_wish;
                lcd.clear();
            }
            else{
                state = lcd_display;
            }
            
            break;
        case lcd_confirm:
            if(reset){
                state = lcd_reset;
                lcd.clear();
            }
            else{
                if(!confirmed){
                    state = lcd_display;
                    lcd.clear();
                }
                else{
                    state = lcd_confirm;
                }
            }
            break;
        case lcd_wish:
            if(!wishing){
                state = lcd_wait;
                lcd.clear();
            }
            else{
                state = lcd_wish;
            }
            break;
        case lcd_wait:
            if(wish){
                state = lcd_display;
            }
            else{
                state = lcd_wait;
            }
        case lcd_reset:
            state = (reset) ? lcd_reset : lcd_display;
            break;
        default:
            break;
    }

    switch(state){
        case lcd_display:
            if(menu && !pity && !wish){
                lcd.setCursor(0,0);
                lcd.print(F(" Wish Simulator"));
                lcd.setCursor(0, 1);
                lcd.print(F(" Pity History"));
                lcd.setCursor(0, !menu_arrow);
                lcd.write(">");
            }
            else if(!menu && pity && !wish){
                lcd.setCursor(0, 0);
                lcd.print(F("4-Star Pity: "));
                lcd.print(four_star_pity);
                lcd.setCursor(0, 1);
                lcd.print(F("5-Star Pity: "));
                lcd.print(five_star_pity);
            }
            else if(!menu && !pity && wish){
                lcd.setCursor(0,0);
                lcd.print(F("Button1: 1  Pull"));
                lcd.setCursor(0, 1);
                lcd.print(F("Button2: 10 Pull"));
            }
            break;
        case lcd_confirm:
            lcd.setCursor(0,0);
            if(wish_amount == 1){
                lcd.print(F("Use 1 Wish?"));
            }
            else if(wish_amount == 10){
                lcd.print(F("Use 10 Wishes?"));
            }
            lcd.setCursor(0, 1);
            lcd.print(F(" Yes / Cancel"));
            if(wish_arrow){
                lcd.setCursor(0, 1);
                lcd.write(">");
            }
            else{
                lcd.setCursor(6, 1);
                lcd.write(">");
            }
            break;
        case lcd_wish:
            lcd.setCursor(0,0);
            curr_unit.printToDisplays();
            if(wish_amount == 10){
                lcd.setCursor(7, 1);
                if(curr_wish < 10){
                    lcd.print(F("( "));
                }
                else{
                    lcd.print(F("("));
                }
                lcd.print(curr_wish);
                lcd.print(F(" / 10)"));
            }
            break;
        case lcd_wait:
            lcd.setCursor(0, 0);
            if(wish_amount == 1){
                lcd.print(F("Used 1 Wish"));
            }
            else if(wish_amount == 10){
                lcd.print(F("Used  10 Wishes"));
            }
            lcd.setCursor(0,1);
            lcd.print(F("- JS TO RETURN -"));
            break;
        case lcd_reset:
            lcd.setCursor(0,0);
            if(confirmed){
                lcd.print(F("Resetting Pity..."));
            }
            else{
                lcd.print(F("Reset All Pity?"));
            }
            lcd.setCursor(0, 1);
            if(confirmed){
                lcd.print(F("Returning Home"));
            }
            else{
                lcd.print(F(" Yes / Cancel"));
                if(wish_arrow){
                    lcd.setCursor(0, 1);
                }
                else{
                    lcd.setCursor(6, 1);
                }
                lcd.write(">");
            }
            break;
        default:
            break;
    }

    return state;
}

enum nokia_States {nokia_start, nokia_display, nokia_wish, nokia_reset};
int nokia_Tick(int state){
    switch(state){
        case nokia_start:
            display.clearDisplay();
            state = nokia_display;
            break;
        case nokia_display:
            if(wishing){
                state = nokia_wish;
            }
            else if(reset){
                state = nokia_reset;
            }
            else{
                state = nokia_display;
            }
            break;
        case nokia_wish:
            if(!wishing){
                display.clearDisplay();
                state = nokia_display;
            }
            else{
                state = nokia_wish;
            }
            break;
        case nokia_reset:
            if(reset){
                state = nokia_reset;
            }
            else{
                state = nokia_display;
                display.clearDisplay();
            }
            break;
        default:
            break;
    }

    switch(state){
        case nokia_display:
            if(menu && !pity && !wish){
                display.setTextColor(BLACK);
                display.setCursor(0,0);
                display.setTextSize(1);
                display.println(F("  Oh That's\n   Pitiful\n"));
                display.setTextSize(1);
                display.println(F("  A Genshin\n Impact Wish\nPity Simulator"));
                display.display();
            }
            else if(!menu && pity && !wish){
                display.setTextColor(BLACK);
                display.setCursor(0,0);
                display.setTextSize(1);
                display.println(F("\n  Press the \n Joystick to \nReturn to the \n  Main Menu"));
                display.display();
            }
            else if(!menu && !pity && wish){
                display.setTextColor(BLACK);
                display.setCursor(0,0);
                display.setTextSize(1);
                display.println(F("Press: \n1-Wish+10-Wish to Reset Pity\n  Joystick\nto Return to\nthe Main Menu"));
                display.display();
            }
            break;
        case nokia_wish:
            display.clearDisplay();
            switch(curr_unit.rarity){
                case 3:
                    display.drawBitmap(0, 0, three_art_array[curr_unit.index], 84, 48, BLACK);
                    break;
                case 4:
                    display.drawBitmap(0, 0, four_art_array[curr_unit.index], 84, 48, BLACK);
                    break;
                case 5:
                    display.drawBitmap(0, 0, five_art_array[curr_unit.index], 84, 48, BLACK);
                    break;
                default:
                    break;
            }
            display.display();
            break;
        case nokia_reset:
            display.setTextColor(BLACK);
            display.setCursor(0,0);
            display.setTextSize(2);
            display.println(F("  OwO"));
            display.setTextSize(1);
            display.println(F("\nPreparing to\nReset Pity..."));
            display.display();
            break;
        default:
            break;
    }

    return state;
}

enum joy_States {joy_start, joy_idle, joy_up, joy_down, joy_left, joy_right};
int joy_Tick(int state){
    int xValue = analogRead(joyX);
    int yValue = analogRead(joyY);
    
    switch(state){
        case joy_start:
            state = joy_idle;
            menu_arrow = wish_arrow = true;
            break;
        case joy_idle:
            if(xValue < 200 && (yValue >= 200 && yValue <= 1100)){
                state = joy_left;
            }
            else if(xValue > 800 && (yValue >= 200 && yValue <= 1100)){
                state = joy_right;
            }
            else if(yValue < 200 && (xValue >= 200 && xValue <= 1100)){
                state = joy_up;
            }
            else if(yValue > 800 && (xValue >= 200 && xValue <= 1100)){
                state = joy_down;
            }
            else{
                state = joy_idle;
            }
            break;
        case joy_up:
        case joy_down:
        case joy_left:
        case joy_right:
            state = joy_idle;
            break;
        default:
            break;
    }

    switch(state){
        case joy_up:
            menu_arrow = true;
            break;
        case joy_down:
            menu_arrow = false;
            break;
        case joy_left:
            wish_arrow = true;
            break;
        case joy_right:
            wish_arrow = false;
            break;
        default:
            break;
    }

    return state;
}

void setup(){
    // Initialize Serial Monitor for PC Tracking
    Serial.begin(9600);
    
    // Initialize Nokia Display
    display.begin();
    display.setRotation(2);                     // I Soldered Upside Down...
    display.setContrast(57);
    display.clearDisplay();

    // Initialize 16 x 2 LCD
    lcd.createChar(0, stars);
    lcd.begin(16, 2);
    lcd.clear();

    // Initialize Loot System, 3*, 4*, and 5*
    setupThreeStars(three_pool);
    setupFourStars(four_pool);
    setupFiveStars(five_pool);
    randomSeed(analogRead(19));

    // Setup Drop Rates
    five_rate = 6;

    // Setup Pin Mode for Buttons
    pinMode(button1, INPUT_PULLUP);
    pinMode(button2, INPUT_PULLUP);
    pinMode(button, INPUT_PULLUP);


    // Setup Tasks

    unsigned char i = 0;

    tasks[i].state = wish_start;
    tasks[i].period = 100;
    tasks[i].elapsedTime = 0;
    tasks[i].TickFct = &wish_Tick;
    ++i;
    tasks[i].state = lcd_start;
    tasks[i].period = 100;
    tasks[i].elapsedTime = 0;
    tasks[i].TickFct = &lcd_Tick;
    ++i;
    tasks[i].state = nokia_start;
    tasks[i].period = 100;
    tasks[i].elapsedTime = 0;
    tasks[i].TickFct = &nokia_Tick;
    ++i;
    tasks[i].state = joy_start;
    tasks[i].period = 100;
    tasks[i].elapsedTime = 0;
    tasks[i].TickFct = &joy_Tick;
}

void loop(){
    unsigned char i;
    for(i = 0; i < tasksNum; ++i){
        if( (millis() - tasks[i].elapsedTime) >= tasks[i].period){
            tasks[i].state = tasks[i].TickFct(tasks[i].state);
            tasks[i].elapsedTime = millis();
        }
    }
    delay(100);
}