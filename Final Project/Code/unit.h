#ifndef __UNIT_H__
#define __UNIT_H__

#include <LiquidCrystal.h>


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 2, en = 3, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

class unit {
    public:
        byte rarity;
        //unsigned char art[504];
        char character_name[16];
        
        /*void setArt(unsigned char artwork[504]){
            for(byte i = 0; i < 504; ++i){
                art[i] = artwork[i];
            }
        }
        */
        void setName(char name[16]){
            for(byte i = 0; i < 16; ++i){
                character_name[i] = name[i];
            }
        }
        void printToLCD(){
            lcd.setCursor(0, 0);
            lcd.print(character_name);
            for(byte i = 0; i < rarity; ++i){
                lcd.setCursor(i, 1);
                lcd.write(byte(0));
            }
        }
};

#endif