#ifndef __FIVE_STAR_H__
#define __FIVE_STAR_H__

#include "unit.h"


void setupFiveStars(unit (&units)[6]){
    
    //Yae Miko, 5 Star
    /*unsigned char yae_art[504] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x20, 0x20, 0x20, 0xC0, 0x20, 0xA0, 0x40, 0x40,
    0xC0, 0xC0, 0xC8, 0x88, 0x88, 0x80, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x80, 0x14, 0x04, 0x05, 0x00, 0x11, 0x56, 0x24, 0x7C, 0x78, 0x38, 0x02, 0x80, 0x00,
    0x00, 0xF4, 0x00, 0x23, 0x0C, 0x0E, 0x18, 0x2F, 0x02, 0x03, 0x87, 0x07, 0x03, 0xC2, 0xE1, 0xC0,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x18, 0x3C, 0x3C, 0x38, 0x28,
    0xBA, 0x78, 0xEE, 0x88, 0x8C, 0x9E, 0x9F, 0x98, 0xE8, 0xE8, 0x70, 0xB8, 0x65, 0x50, 0x30, 0xF8,
    0xFC, 0xFE, 0x3F, 0x8F, 0x25, 0x06, 0x02, 0xC0, 0xBC, 0x7E, 0xFE, 0x40, 0x82, 0x84, 0x80, 0x80,
    0x88, 0x0F, 0x8B, 0x28, 0xB8, 0xF8, 0x3E, 0x3E, 0x3E, 0x3E, 0x3C, 0xF8, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x20, 0x00, 0x50, 0x70, 0x30, 0x20, 0xA0, 0xC0, 0xE0, 0xF0, 0xB9, 0xB9, 0xCF, 0xEF, 0xF4,
    0xFA, 0xBC, 0xDD, 0xBF, 0xFF, 0xFE, 0xFC, 0xF8, 0x71, 0x03, 0x01, 0x01, 0x00, 0xC0, 0xF8, 0xFD,
    0xFC, 0xF7, 0xFF, 0xFC, 0xF5, 0xE5, 0x61, 0xF0, 0x20, 0x00, 0x10, 0x00, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x08, 0x1E, 0x3E, 0x3E, 0xFF, 0x7F, 0xFE, 0xFE, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 0x8F, 0xC7, 0xE1, 0xF0, 0x38, 0x00, 0xC0, 0xE0,
    0xF8, 0xFF, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xEF, 0xFE, 0xF9, 0x1C, 0x1C, 0x08, 0x1C,
    0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x01, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x0F, 0x0F, 0x07, 0x07, 0x07, 0x07, 0x0F, 0x01,
    0x0A, 0x0F, 0x17, 0x17, 0x1F, 0x0F, 0x0D, 0x03, 0x03, 0x07, 0x07, 0x07, 0x03, 0x03, 0x09, 0x03,
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    };
    */
    char yae_name[16] = "Yae Miko       ";
    char diluc_name[16] = "Diluc          ";
    char jean_name[16] = "Jean           ";
    char qiqi_name[16] = "Qiqi           ";
    char keqing_name[16] = "Keqing         ";
    char mona_name[16] = "Mona           ";

    for(byte i = 0; i < 6; ++i){
        units[i].rarity = 5;
    }
    
    //units[0].setArt(yae_art);
    units[0].setName(yae_name);
    units[1].setName(diluc_name);
    units[2].setName(jean_name);
    units[3].setName(qiqi_name);
    units[4].setName(keqing_name);
    units[5].setName(mona_name);


}


#endif