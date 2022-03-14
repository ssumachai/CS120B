/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)
*          Lab Section:    021 
 *         Assignment:    Custom Laboratory Project Demo 2
 *         Exercise Description: Intermediate Functionality utilizing Joystick + Software Complexity
 *        
 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.
 *
 *         Demo Link: https://youtu.be/1obgGrfoXeM
 */

#include "unit.h"
#include "five_star.h"
#include "four_star.h"
#include "three_star.h"

unit five_pool[6];
unit four_pool[3];
unit three_pool[5];
unit curr_unit;
enum States {start, MENU, WISH_IDLE_PAGE1, WISH_IDLE_PAGE2, PITY_PAGE1, PITY_PAGE2, ONE_PULL_PRESS, 
            TEN_PULL_PRESS, ONE_WISH, TEN_WISH, WISH_WAIT, RESET, PRINT_RESET} state;
const int button1 = 9, button2 = 10;            // Wish Buttons
const int joyX = 14, joyY = 15, button = 8;     // Joystick
bool wish_arrow, menu_arrow;                    //Arrow Indicators
byte timer;                                     // Timer, lol
byte curr_wish, wish_amount;                    // For use in State WISH_WAIT
byte four_star_pity, five_star_pity;            // For Wish Numbers
bool four_guarantee, five_guarantee;            // used to track 50/50 and Guarantee

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

void setup() {
    pinMode(button1, INPUT_PULLUP);
    pinMode(button2, INPUT_PULLUP);
    pinMode(button, INPUT_PULLUP);
    lcd.createChar(0, stars);
    lcd.begin(16, 2);
    setupFourStars(four_pool);
    setupFiveStars(five_pool);
    setupThreeStars(three_pool);
    randomSeed(analogRead(16));
    Serial.begin(9600);
}

void pull(){
    //Wish Rates
    // 5-Star - 0.6% 1 - 6 out of 1000
    // 4-Star - 5.1% 7 - 57 out of 1000
    // 3-Star - 94.3% 58 - 1000

    // 4-Star Pity at 10
    // 5-Star Pity at 90
    long randNumber = 0;
    long randUnit = 0;
    long fifty_fifty = 0;
    randNumber = random(1, 1001);
    Serial.print("Draw: ");
    Serial.print(randNumber);
    if(five_star_pity == 89 || (randNumber >= 1 && randNumber <= 6)){
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
    else if(four_star_pity == 9 || (randNumber >= 7 && randNumber <= 57)){
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
    Serial.print("\n4-Star Pity: ");
    Serial.print(four_star_pity);
    Serial.print("\nFive-Star Pity: ");
    Serial.print(five_star_pity);
    Serial.print("\n");
}


void Tick(){
    int one_wish = digitalRead(button1);
    int ten_wish = digitalRead(button2);
    int xValue = analogRead(joyX);
    int yValue = analogRead(joyY);
    int confirm = digitalRead(button);

    switch(state){
        case start:
            lcd.clear();
            state = MENU;
            menu_arrow = true;
            four_star_pity = five_star_pity = 0;
            timer = 0;
            break;
        case MENU:
            if(yValue < 500 && (xValue >= 500 && xValue <= 550)){
                menu_arrow = true;
            }
            else if(yValue > 550 && (xValue >= 500 && xValue <= 550)){
                menu_arrow = false;
            }

            if(!confirm){
                if(menu_arrow){
                    state = WISH_IDLE_PAGE1;
                }
                else{
                    state = PITY_PAGE1;
                }
                lcd.clear();
            }
            break;
        case PITY_PAGE1:
            if(yValue > 550 && (xValue >= 500 && xValue <= 550)){
                state = PITY_PAGE2;
                lcd.clear();
            }
            else{
                state = PITY_PAGE1;
            }
            break;
        case PITY_PAGE2:
            if(yValue < 500 && (xValue >= 500 && xValue <= 550)){
                state = PITY_PAGE1;
                lcd.clear();
            }
            else{
                if(!confirm){
                    state = MENU;
                    lcd.clear();
                }
                else{
                    state = PITY_PAGE2;
                }
            }
            break;
        case WISH_IDLE_PAGE1:            
            if(yValue > 550 && (xValue >= 500 && xValue <= 550)){
                state = WISH_IDLE_PAGE2;
                lcd.clear();
            }
            else{
                if(one_wish && !ten_wish){
                    state = ONE_PULL_PRESS;
                    wish_arrow = true;
                    lcd.clear();
                }
                else if(!one_wish && ten_wish){
                    state = TEN_PULL_PRESS;
                    wish_arrow = true;
                    lcd.clear();
                }
                else{
                    state = WISH_IDLE_PAGE1;
                }
            }
            break;
        case WISH_IDLE_PAGE2:
            if(yValue < 500 && (xValue >= 500 && xValue <= 550)){
                state = WISH_IDLE_PAGE1;
                lcd.clear();
            }
            else{
                if(!confirm){
                    state = MENU;
                    lcd.clear();
                }
                else{
                    state = WISH_IDLE_PAGE2;
                }
            }
            break;
        case ONE_PULL_PRESS:
            if(one_wish && ten_wish){
                state = RESET;
                lcd.clear();
            }
            else{
                if(xValue < 500 && (yValue >= 500 && yValue <= 550)){
                    wish_arrow = true;
                }
                else if(xValue > 550 && (yValue >= 500 && yValue <= 550)){
                    wish_arrow = false;
                }

                if(!confirm){
                    if(wish_arrow){
                        state = ONE_WISH;
                        pull();
                    }
                    else{
                        state = WISH_IDLE_PAGE1;
                    }
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
                lcd.clear();
            }
            else{
                if(xValue < 500 && (yValue >= 500 && yValue <= 550)){
                    wish_arrow = true;
                }
                else if(xValue > 550 && (yValue >= 500 && yValue <= 550)){
                    wish_arrow = false;
                }

                if(!confirm){
                    if(wish_arrow){
                        state = TEN_WISH;
                        wish_amount = 10;
                        curr_wish = 1;
                        pull();
                    }
                    else{
                        state = WISH_IDLE_PAGE1;
                    }
                    lcd.clear();
                }
                else{
                    state = TEN_PULL_PRESS;
                }
            }
            break;
        case RESET:
            if(xValue < 500 && (yValue >= 500 && yValue <= 550)){
                wish_arrow = true;
            }
            else if(xValue > 550 && (yValue >= 500 && yValue <= 550)){
                wish_arrow = false;
            }

            if(!confirm){
                if(wish_arrow){
                    state = PRINT_RESET;
                    timer = 0;
                    lcd.clear();
                }
                else{
                    state = WISH_IDLE_PAGE1;
                    lcd.clear();
                }
            }
            else{
                state = RESET;
            }
            break;
        case PRINT_RESET:
            if(timer < 30){
                state = PRINT_RESET;
            }
            else{
                state = start;
            }
            break;
        case ONE_WISH:
            if(yValue > 550 && (xValue >= 500 && xValue <= 550)){
                state = WISH_WAIT;
                wish_amount = 1;
            }
            else{
                state = ONE_WISH;
            }
            lcd.clear();
            break;
        case TEN_WISH:
                if(curr_wish < 10){
                    if(!confirm){
                        ++curr_wish;
                        pull();
                    }
                }
                if(curr_wish == 10 && (yValue > 550 && (xValue >= 500 && xValue <= 550))){
                    state = WISH_WAIT;
                    wish_amount = 10;
                }
                else{
                    state = TEN_WISH;
                }
                lcd.clear();
            break;
        case WISH_WAIT:
            state = (!confirm) ? WISH_IDLE_PAGE1 : WISH_WAIT;
            break;
        default:
            state = start;
            break;
    }

    switch(state){
        case MENU:
            lcd.setCursor(0,0);
            lcd.print(" Wish Simulator");
            lcd.setCursor(0,1);
            lcd.print(" Pity History");
            if(menu_arrow){
                lcd.setCursor(0, 0);
                lcd.write(">");
            }
            else{
                lcd.setCursor(0, 1);
                lcd.write(">");
            }
            break;
        case WISH_IDLE_PAGE1:
            lcd.setCursor(0,0);
            lcd.print("Button1: 1  Pull");
            lcd.setCursor(0, 1);
            lcd.print("Button2: 10 Pull");
            break;
        case WISH_IDLE_PAGE2:
        case PITY_PAGE2:
            lcd.setCursor(0,0);
            lcd.print(" PRESS JS TO GO ");
            lcd.setCursor(0,1);
            lcd.print("  TO HOME MENU  ");
            break;
        case PITY_PAGE1:
            lcd.setCursor(0,0);
            lcd.print("4-Star Pity: ");
            lcd.print(four_star_pity);
            lcd.setCursor(0,1);
            lcd.print("5-Star Pity: ");
            lcd.print(five_star_pity);
            break;
        case ONE_PULL_PRESS:
            lcd.setCursor(0,0);
            lcd.print("Use 1 Wish?");
            lcd.setCursor(0, 1);
            lcd.print(" Yes / Cancel");
            if(wish_arrow){
                lcd.setCursor(0, 1);
                lcd.write(">");
            }
            else{
                lcd.setCursor(6, 1);
                lcd.write(">");
            }
            break;
        case TEN_PULL_PRESS:
            lcd.setCursor(0,0);
            lcd.print("Use 10 Wishes?");
            lcd.setCursor(0, 1);
            lcd.print(" Yes / Cancel");
            if(wish_arrow){
                lcd.setCursor(0, 1);
                lcd.write(">");
            }
            else{
                lcd.setCursor(6, 1);
                lcd.write(">");
            }
            break;
        case RESET:
            lcd.setCursor(0,0);
            lcd.print("Reset All Pity?");
            lcd.setCursor(0, 1);
            lcd.print(" Yes / Cancel");
            if(wish_arrow){
                lcd.setCursor(0, 1);
                lcd.write(">");
            }
            else{
                lcd.setCursor(6, 1);
                lcd.write(">");
            }
            break;
        case PRINT_RESET:
            ++timer;
            lcd.setCursor(0, 0);
            lcd.print("Resetting Pity...");
            lcd.setCursor(0, 1);
            lcd.print("Returning Home");
            break;
        case ONE_WISH:
            lcd.setCursor(0,0);
            curr_unit.printToLCD();
            break;
        case TEN_WISH:
            lcd.setCursor(0,0);
            curr_unit.printToLCD();
            if(curr_wish < 10){
                lcd.setCursor(7,1);
                lcd.print("( ");
                lcd.print(curr_wish);
                lcd.print(" / 10)");
            }
            else{
                lcd.setCursor(7, 1);
                lcd.print("(");
                lcd.print(curr_wish);
                lcd.print(" / 10)");
            }
            break;
        case WISH_WAIT:
            lcd.setCursor(0, 0);
            if(wish_amount == 1){
                lcd.print("Used 1 Wish");
            }
            else if(wish_amount == 10){
                lcd.print("Used  10 Wishes");
            }
            lcd.setCursor(0,1);
            lcd.print("- JS TO RETURN -");
        default:
            break;
    }
}

void loop() {
    Tick();
    delay(100);
}