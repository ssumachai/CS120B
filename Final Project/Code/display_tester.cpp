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

void setup(){
    Serial.begin(9600);

    // Initialize Nokia Display
    display.begin();
    display.setRotation(2);         // I Soldered Upside Down...
    display.setContrast(57);
    display.clearDisplay();

    // Initialize 16 x 2 LCD Display
    lcd.createChar(0, stars);
    lcd.begin(16, 2);

    // Initialize Loot System, 3*, 4*, and 5*
    setupThreeStars(three_pool);
    setupFourStars(four_pool);
    setupFiveStars(five_pool);
}

void loop(){
    for(int i = 0; i < 5; ++i){
        display.clearDisplay();
        display.drawBitmap(0, 0, three_art_array[i], 84, 48, BLACK);
        display.display();

        lcd.clear();
        three_pool[i].printToDisplays();
        delay(1000);
    }
    for(int i = 0; i < 3; ++i){
        display.clearDisplay();
        display.drawBitmap(0, 0, four_art_array[i], 84, 48, BLACK);
        display.display();

        lcd.clear();
        four_pool[i].printToDisplays();
        delay(1000);
    }
    for(int i = 0; i < 6; ++i){
        display.clearDisplay();
        display.drawBitmap(0, 0, five_art_array[i], 84, 48, BLACK);
        display.display();

        lcd.clear();
        five_pool[i].printToDisplays();
        delay(1000);
    }
}