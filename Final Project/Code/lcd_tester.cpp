#include "unit.h"
#include "five_star.h"

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
    lcd.createChar(0, stars);
    lcd.begin(16, 2);
    setupFiveStars();

    units[0].printToLCD();
}

void loop() {
}