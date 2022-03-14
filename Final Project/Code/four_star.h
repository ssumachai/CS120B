#ifndef __FOUR_STAR_H__
#define __FOUR_STAR_H__

#include "unit.h"

// 'bennett', 84x48px
const unsigned char bennett [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xc0, 
	0x79, 0x07, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xfc, 0x03, 0xf3, 0xc0, 0xff, 0xff, 0xff, 
	0xf0, 0xff, 0xff, 0xff, 0xe0, 0x0e, 0x1f, 0xf0, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfe, 0x1d, 
	0xff, 0xff, 0xf8, 0x0f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf8, 0x7b, 0xff, 0xff, 0xfc, 0x1f, 0xff, 
	0xff, 0xf0, 0xff, 0xff, 0xf8, 0xc7, 0xc0, 0x1f, 0x07, 0x0f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 
	0x8f, 0x80, 0x00, 0x01, 0x83, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x41, 
	0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xf0, 0xff, 0xff, 
	0xfb, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xf0, 0xff, 0xff, 0xf3, 0x80, 0x00, 0x00, 0x00, 
	0x01, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xe3, 0x00, 0x00, 0x00, 0x00, 0x09, 0xff, 0xff, 0xf0, 0xff, 
	0xff, 0xfa, 0x00, 0x80, 0x00, 0x08, 0x00, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf2, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x7f, 0xff, 0xf0, 0xff, 0xff, 0xf6, 0x00, 0x00, 0x00, 0x04, 0x00, 0x7f, 0xff, 0xf0, 
	0xff, 0xff, 0xf2, 0x00, 0x00, 0x00, 0x10, 0x00, 0x7f, 0xff, 0xf0, 0xff, 0xff, 0xf2, 0x04, 0x00, 
	0x00, 0x08, 0x02, 0x3f, 0xff, 0xf0, 0xff, 0xff, 0xe0, 0x14, 0x00, 0x00, 0x02, 0x0a, 0x1f, 0xff, 
	0xf0, 0xff, 0xff, 0xe1, 0x00, 0x04, 0x08, 0x00, 0x08, 0x7f, 0xff, 0xf0, 0xff, 0xff, 0xec, 0x87, 
	0xf8, 0x01, 0xff, 0x08, 0x7f, 0xff, 0xf0, 0xff, 0xff, 0xec, 0x80, 0xf0, 0x40, 0xf0, 0x19, 0xff, 
	0xff, 0xf0, 0xff, 0xff, 0xff, 0x40, 0x00, 0x10, 0x00, 0x79, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 
	0x20, 0x00, 0x00, 0x00, 0x4b, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0x8c, 0x00, 0x00, 0x03, 0x9f, 
	0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf4, 0x00, 0x00, 0x02, 0x7f, 0xff, 0xff, 0xf0, 0xff, 0xff, 
	0xff, 0xfe, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x0f, 
	0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xf0, 0xff, 
	0xff, 0xff, 0xff, 0xf0, 0x00, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 
	0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xfe, 0xf0, 0x00, 0xff, 0xff, 0xff, 0xff, 0xf0, 
	0xff, 0xff, 0xff, 0xf8, 0xf0, 0x00, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf2, 0xf0, 
	0x00, 0xfd, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xea, 0x60, 0x40, 0x77, 0xff, 0xff, 0xff, 
	0xf0, 0xff, 0xff, 0xff, 0xdc, 0x80, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfe, 0xff, 
	0x80, 0x00, 0x1f, 0xe7, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfc, 0x7f, 0x80, 0x00, 0x1f, 0xf3, 0xff, 
	0xff, 0xf0, 0xff, 0xff, 0xe0, 0xdf, 0x80, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0x81, 
	0xff, 0x81, 0x08, 0x1f, 0xf8, 0x0f, 0xff, 0xf0, 0xff, 0xfe, 0x01, 0xdf, 0xc0, 0x00, 0x3f, 0xfc, 
	0x07, 0xff, 0xf0, 0xff, 0xfc, 0x03, 0xff, 0xe0, 0x00, 0x7b, 0xfc, 0x03, 0xff, 0xf0, 0xff, 0xf8, 
	0x05, 0xfc, 0xfe, 0x07, 0xf3, 0xfa, 0x01, 0xff, 0xf0, 0xff, 0xf8, 0x08, 0xfc, 0x9b, 0xfd, 0x93, 
	0xf1, 0x00, 0xff, 0xf0, 0x9f, 0xf0, 0x08, 0xfc, 0x7f, 0xff, 0xe3, 0xf1, 0x00, 0xff, 0xf0, 0xc3, 
	0xe0, 0x0f, 0xfc, 0x1e, 0x07, 0x83, 0xfd, 0x00, 0x3f, 0xf0, 0xfd, 0x80, 0x01, 0xfc, 0x07, 0xfe, 
	0x03, 0xf8, 0x00, 0x1f, 0xf0, 0x0f, 0x00, 0x0e, 0xfc, 0x3f, 0xff, 0xc3, 0xff, 0x00, 0x0f, 0xf0
};
// 'sara', 84x48px
const unsigned char sara [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 
	0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0x9f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xfd, 0xef, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xdf, 
	0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xf1, 0xff, 
	0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xcd, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 
	0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xfc, 0x1f, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xfc, 0x01, 0xcf, 0xff, 0xff, 0xff, 0xff, 
	0xf0, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 
	0xf8, 0x03, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0x01, 0xd3, 0xff, 0xff, 
	0xff, 0xf0, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 
	0xfc, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x03, 0xff, 
	0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xed, 0xff, 0xff, 0xf0, 0xff, 0xff, 
	0xff, 0xfe, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x1f, 
	0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xf0, 0xff, 
	0xff, 0xff, 0xff, 0xf0, 0x01, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xb7, 0xfe, 0x07, 
	0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0x5b, 0xf0, 0x01, 0xff, 0xff, 0xff, 0xff, 0xf0, 
	0xff, 0xff, 0xff, 0xa3, 0xfe, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xd1, 0xff, 
	0xbf, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0x69, 0xff, 0xbf, 0xff, 0xcf, 0xff, 0xff, 
	0xf0, 0xff, 0xff, 0xfc, 0x3c, 0xff, 0x1f, 0xe7, 0x87, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xe0, 0x02, 
	0x7e, 0x87, 0xf0, 0x00, 0xff, 0xff, 0xf0, 0xff, 0xff, 0x00, 0x01, 0x7e, 0x0f, 0xf0, 0x00, 0x0f, 
	0xff, 0xf0, 0xff, 0xf0, 0x00, 0x99, 0xf7, 0xbc, 0xf8, 0x00, 0x00, 0xff, 0xf0, 0xff, 0xe7, 0x00, 
	0xb0, 0x1b, 0xff, 0xc0, 0x00, 0x0c, 0x7f, 0xf0, 0xff, 0xf1, 0x80, 0x00, 0xb8, 0x03, 0xe0, 0x00, 
	0x19, 0xff, 0xf0, 0xff, 0xf8, 0xc0, 0x00, 0xff, 0xbf, 0xe0, 0x00, 0x33, 0xff, 0xf0, 0xff, 0xfc, 
	0xc0, 0x00, 0x9f, 0xbf, 0x90, 0x00, 0x67, 0xff, 0xf0, 0xff, 0xfc, 0x01, 0x00, 0x00, 0x90, 0x00, 
	0x00, 0x03, 0xff, 0xf0, 0xff, 0xf8, 0x30, 0x00, 0x00, 0x00, 0x40, 0x09, 0x81, 0xff, 0xf0, 0xff, 
	0xf0, 0x12, 0x00, 0x08, 0x01, 0x00, 0x01, 0x80, 0xff, 0xf0, 0xff, 0x70, 0x1e, 0x00, 0x00, 0x00, 
	0x00, 0x07, 0x00, 0xdf, 0xf0, 0xff, 0xfc, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0f, 0xf0
};
// 'xinyan', 84x48px
const unsigned char xinyan [] PROGMEM = {
	0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf8, 0xff, 
	0xff, 0xf1, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 
	0xf0, 0xff, 0xff, 0xdf, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xbf, 0xff, 0xf0, 0xff, 0xff, 0xe3, 0xf9, 
	0xff, 0xff, 0xf9, 0xfc, 0x7f, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 
	0xff, 0xf0, 0xff, 0xff, 0xf1, 0x7f, 0xff, 0xff, 0xff, 0xe8, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfe, 
	0x7f, 0xff, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xf0, 
	0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xf0, 0xff, 0xff, 0x1b, 0xff, 0xff, 0xff, 0xff, 
	0xfd, 0x8f, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0x8b, 0xff, 0xff, 0xff, 0xbf, 0xf9, 0x1f, 0xff, 0xf0, 
	0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0x1f, 0xff, 0x0f, 0xff, 0xf0, 0xff, 0xfc, 0x3f, 0xff, 0xff, 
	0xfe, 0x07, 0xff, 0xe3, 0xff, 0xf0, 0xff, 0xfb, 0xff, 0xff, 0xfc, 0xf8, 0x39, 0xff, 0xfd, 0xff, 
	0xf0, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xe3, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0x97, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xfe, 0x0e, 0x01, 0x03, 0xff, 0xff, 
	0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 
	0xff, 0x80, 0x00, 0x0b, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x07, 0xff, 
	0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 
	0xff, 0xff, 0x80, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x1f, 
	0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xf0, 0xff, 
	0xff, 0xff, 0xff, 0xfc, 0x03, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x9f, 0x1f, 0xff, 0xff, 0xff, 0xf0, 
	0xff, 0xff, 0xff, 0xff, 0x8f, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x9f, 
	0xff, 0x9f, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 
	0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfd, 0x8f, 
	0xbf, 0xff, 0xdf, 0x1b, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfc, 0x03, 0xff, 0x4f, 0xfc, 0x03, 0xff, 
	0xff, 0xf0, 0xff, 0xff, 0xd8, 0x81, 0xfc, 0x13, 0xf8, 0x11, 0xbf, 0xff, 0xf0, 0xff, 0xff, 0xe0, 
	0x01, 0xf8, 0x09, 0xf8, 0x00, 0x7f, 0xff, 0xf0, 0xff, 0xff, 0xc0, 0x03, 0xe0, 0x00, 0x7c, 0x10, 
	0x3f, 0xff, 0xf0, 0xff, 0xff, 0x80, 0x8f, 0xf0, 0x00, 0xff, 0x10, 0x1f, 0xff, 0xf0, 0xff, 0xff, 
	0xf8, 0x9f, 0xf8, 0x01, 0xff, 0x91, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xc0, 0x9f, 0xfe, 0x07, 0xff, 
	0x90, 0x3f, 0xff, 0xf0, 0xff, 0xff, 0xe0, 0xbf, 0xff, 0x0f, 0xff, 0xd0, 0x7f, 0xff, 0xf0, 0xff, 
	0xff, 0xe5, 0xbf, 0xff, 0xbf, 0xff, 0xda, 0x7f, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0xff, 
	0xff, 0xc0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf9, 0x7f, 0xff, 0xff, 0xff, 0xe8, 0xff, 0xff, 0xf0
};

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 1632)
const unsigned char* four_art_array[3] = {
	bennett,
	xinyan,
	sara
};

void setupFourStars(unit (&units)[3]){
    char bennett_name[16] = "Bennett";
    char xinyan_name[16] = "Xinyan";
    char sara_name[16] = "Kujou Sara";

    for(byte i = 0; i < 3; ++i){
        units[i].rarity = 4;
		units[i].index = i;
    }
    
    units[0].setName(bennett_name);
    units[1].setName(xinyan_name);
    units[2].setName(sara_name);
}

#endif