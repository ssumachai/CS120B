
/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)
*          Lab Section:    021 
 *         Assignment:    Custom Laboratory Project Demo 1
 *         Exercise Description: Basic Functionality utilizing Joystick
 *        
 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.
 *
 *         Demo Link: https://youtu.be/useuHu8Gm1I
 */
 
#include <LiquidCrystal.h>


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 2, en = 3, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
const int joyX = 14, joyY = 15, button = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int xValue, yValue;
int xCount, yCount = 0;
int timer;


enum States {start, IDLE, NSUP, NSDOWN, EWUP, EWDOWN, PRESS} state;

void clearScoreScreen(){
    lcd.setCursor(9, 0);
    lcd.print("       ");
    lcd.setCursor(9, 1);
    lcd.print("       ");
}

void Tick(){
    xValue = analogRead(joyX);
    yValue = analogRead(joyY);


    switch(state){
        case start:
            timer = xCount = yCount = 0;
            state = IDLE;
            break;
        case IDLE:
            if(!digitalRead(button)){
                state = PRESS;
            }
            else{
                if((xValue >= 500 && xValue <= 550) && (yValue >= 500 && yValue <= 550)){
                    state = IDLE;
                }
                else if(xValue < 500 && (yValue >= 500 && yValue <= 550)){
                    state = EWDOWN;
                }
                else if(xValue > 550 && (yValue >= 500 && yValue <= 550)){
                    state = EWUP;
                }
                else if(yValue < 500 && (xValue >= 500 && xValue <= 550)){
                    state = NSUP;
                }
                else if(yValue > 550 && (xValue >= 500 && xValue <= 550)){
                    state = NSDOWN;
                }
                else{
                    state = IDLE;
                }
            }
            break;
        case NSUP:
            state = (yValue > 550 && (xValue >= 500 && xValue <= 550)) ? NSUP : IDLE;
            break;
        case NSDOWN:
            state = (yValue < 500 && (xValue >= 500 && xValue <= 550)) ? NSDOWN : IDLE;
            break;
        case EWDOWN:
            state = (xValue < 500 && (yValue >= 500 && yValue <= 550)) ? EWDOWN : IDLE;
            break;
        case EWUP:
            state = (xValue > 550 && (yValue >= 500 && yValue <= 550)) ? EWUP : IDLE;
            break;
        case PRESS:
            state = (digitalRead(button)) ? IDLE : PRESS;
            break;
        default:
            state = start;
            break;        
    }

    switch(state){
        case IDLE:
            timer = 0;
            break;
        case NSUP:
            if(timer % 10 == 0){
                ++yCount;
            }
            ++timer;
            break;
        case NSDOWN:
            if(timer % 10 == 0){
                if(yCount > 0)
                    --yCount;
            }
            ++timer;
            break;
        case EWUP:
            if(timer % 10 == 0){
                ++xCount;
            }
            ++timer;
            break;
        case EWDOWN:
            if(timer % 10 == 0){
                if(xCount > 0)
                    --xCount;
            }
            ++timer;
            break;
        case PRESS:
            clearScoreScreen();
            xCount = yCount = 0;
            break;
        default:
            break;
    }       
}

void setup() {
    pinMode(button, INPUT_PULLUP);
    lcd.begin(16, 2);
    lcd.print("X-Count: ");
    lcd.setCursor(0, 1);
    lcd.print("Y-Count: ");
}

void loop() {
    Tick();
    lcd.setCursor(9, 0);
    lcd.print(xCount);
    lcd.setCursor(9, 1);
    lcd.print(yCount);
    delay(100);
}