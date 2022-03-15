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
}

void loop(){
    display.setTextColor(BLACK);
    display.setCursor(0,0);
    display.setTextSize(1);
    display.println("Press: \n1-Wish+10-Wish to Reset Pity\n Select Cancel to Return to Wish Screen");
    display.display();
    delay(2000);
    display.clearDisplay();
}