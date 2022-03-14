#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

Adafruit_PCD8544 display = Adafruit_PCD8544(13, 18, 12, 10, 11);

void setup(){

    // Initialize Nokia Display
    display.begin();
    display.setRotation(2);         // I Soldered Upside Down...
    display.setContrast(57);
    display.clearDisplay();
    display.invertDisplay(1);
}

void loop(){
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.setTextSize(2);
    display.println("Hello!");
    display.display();
    delay(2000);
    display.clearDisplay();
}