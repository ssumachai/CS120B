/*         Your Name & E-mail:  Sumachai Suksanguan (ssuks001@ucr.edu)
*          Lab Section:    021 
 *         Assignment:    Final Project
 *         Exercise Description: Oh That's Pitiful
 *        
 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.
 *
 *         Demo Link:
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
byte timer;                                     // Timer lol
byte curr_wish, wish_amount;                    // For use in State WISH_WAIT
byte four_star_pity, five_star_pity;            // For Wish Numbers
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


// Task Structure Definition
typedef struct task {
  int state;
  unsigned long period;
  unsigned long elapsedTime;
  int (*TickFct)(int);
    
} task;

const unsigned short tasksNum = 10;
task tasks[tasksNum];

void setup(){
    // Initialize Serial Monitor for PC Tracking
    Serial.begin(9600);
    
    // Initialize Nokia Display
    display.begin();
    display.setRotation(2);                     // I Soldered Upside Down...
    display.setContrast(57);
    display.clearDisplay();
    display.invertDisplay(1);

    // Initialize 16 x 2 LCD
    lcd.createChar(0, stars);
    lcd.begin(16, 2);
    lcd.clear();

    // Initialize Loot System, 3*, 4*, and 5*
    setupThreeStars(three_pool);
    setupFourStars(four_pool);
    setupFiveStars(five_pool);
    randomSeed(analogRead(19));

    // Setup Pin Mode for Buttons
    pinMode(button1, INPUT_PULLUP);
    pinMode(button2, INPUT_PULLUP);
    pinMode(button, INPUT_PULLUP);
}

void loop(){
    unsigned char i;
    for(i = 0; i < tasksNum; ++i){
        if( (millis() - tasks[i].elapsedTime) >= tasks[i].period){
            tasks[i].state = tasks[i].TickFct(tasks[i].state);
            tasks[i].elapsedTime = millis();
        }
    }
    delay(500);
}