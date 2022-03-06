#include "unit.h"
#include "five_star.h"

unit pool[6];
byte five_star_pity;
byte four_star_pity;
enum States {start, IDLE, ONE_PULL_PRESS, TEN_PULL_PRESS, ONE_WISH, TEN_WISH} state;
const int button1 = 9;
const int button2 = 10;
const int joyX = 14;
const int joyY = 15;
const int button = 8;
bool yes;

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
    setupFiveStars(pool);
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
            state = IDLE;
            break;
        case IDLE:            
            if(one_wish && !ten_wish){
                state = ONE_PULL_PRESS;
                yes = true;
                lcd.clear();
            }
            else if(!one_wish && ten_wish){
                state = TEN_PULL_PRESS;
                yes = true;
                lcd.clear();
            }
            else{
                state = IDLE;
            }
            break;
        case ONE_PULL_PRESS:
            if(xValue < 500 && (yValue >= 500 && yValue <= 550)){
                yes = true;
            }
            else if(xValue > 550 && (yValue >= 500 && yValue <= 550)){
                yes = false;
            }

            if(!confirm){
                state = (yes) ? ONE_WISH : IDLE;
                lcd.clear();
            }
            else{
                state = ONE_PULL_PRESS;
            }
            break;
        case TEN_PULL_PRESS:
            if(xValue < 500 && (yValue >= 500 && yValue <= 550)){
                yes = true;
            }
            else if(xValue > 550 && (yValue >= 500 && yValue <= 550)){
                yes = false;
            }

            if(!confirm){
                state = (yes) ? TEN_WISH : IDLE;
                lcd.clear();
            }
            else{
                state = TEN_PULL_PRESS;
            }
            break;
        case ONE_WISH:
            state = (!confirm) ? IDLE : ONE_WISH;
            break;
        case TEN_WISH:
            state = (!confirm) ? IDLE : TEN_WISH;
            break;
        default:
            state = start;
            break;
    }

    switch(state){
        case IDLE:
            lcd.setCursor(0,0);
            lcd.print("Button1: 1  Pull");
            lcd.setCursor(0, 1);
            lcd.print("Button2: 10 Pull");
            break;
        case ONE_PULL_PRESS:
            lcd.setCursor(0,0);
            lcd.print("Use 1 Wish?");
            lcd.setCursor(0, 1);
            lcd.print(" Yes / Cancel");
            if(yes){
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
            if(yes){
                lcd.setCursor(0, 1);
                lcd.write(">");
            }
            else{
                lcd.setCursor(6, 1);
                lcd.write(">");
            }
            break;
        case ONE_WISH:
            lcd.setCursor(0,0);
            lcd.print("Used 1 Wish");
            lcd.setCursor(0, 1);
            lcd.print("- JS TO RETURN - ");
            break;
        case TEN_WISH:
            lcd.setCursor(0,0);
            lcd.print("Used 10 Wishes");
            lcd.setCursor(0, 1);
            lcd.print("- JS TO RETURN - ");
            break;
        default:
            break;
    }
}

void loop() {
    Tick();
    delay(100);
}