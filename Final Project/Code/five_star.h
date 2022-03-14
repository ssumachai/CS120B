#ifndef __FIVE_STAR_H__
#define __FIVE_STAR_H__

#include "unit.h"

// 'childe', 84x48px
const unsigned char childe [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xb7, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xf0, 0xff, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xfc, 
	0xec, 0x7e, 0x33, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf3, 0x11, 0xef, 0xbb, 0xff, 0xff, 
	0xff, 0xf0, 0xff, 0xff, 0xff, 0x2e, 0x23, 0xef, 0xbf, 0xdd, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 
	0xc5, 0x47, 0xa6, 0x7f, 0xec, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xe8, 0x0d, 0x31, 0xbf, 0xff, 
	0xff, 0xff, 0xf0, 0xff, 0xff, 0xfe, 0x18, 0x1b, 0x58, 0x1b, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 
	0xfc, 0x33, 0x92, 0x0e, 0x0f, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf8, 0x60, 0x52, 0x47, 0xf7, 
	0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xe1, 0xe0, 0x92, 0x04, 0x7f, 0xff, 0xff, 0xff, 0xf0, 0xff, 
	0xff, 0x8f, 0xe1, 0x32, 0x04, 0xd9, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xec, 0x53, 0x0c, 
	0xdf, 0x3f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfb, 0x33, 0x9b, 0x7d, 0xcb, 0xe0, 0x7f, 0xff, 0xf0, 
	0xff, 0xff, 0xf9, 0xff, 0x0b, 0xfa, 0x44, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xfe, 0x07, 
	0xfa, 0x62, 0x1f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfc, 0xf8, 0x03, 0xfc, 0x26, 0x17, 0xff, 0xff, 
	0xf0, 0xff, 0xff, 0xfc, 0xc7, 0xf9, 0xf8, 0xf7, 0xf7, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfe, 0xf0, 
	0xb1, 0xf8, 0x57, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfd, 0xb8, 0x00, 0x30, 0x13, 0xff, 0xff, 
	0xff, 0xf0, 0xff, 0xff, 0xff, 0xd8, 0x00, 0x18, 0x03, 0xdf, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 
	0xe0, 0x00, 0x04, 0x06, 0x7f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x01, 0xff, 
	0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 
	0xff, 0xff, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x1f, 
	0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xf0, 0xff, 
	0xff, 0xff, 0xff, 0xe0, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xe2, 0x04, 
	0x7f, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x3f, 0xf7, 0xff, 0xff, 0xf0, 
	0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0xf3, 0xff, 0xbf, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xe0, 
	0x00, 0x7f, 0xfe, 0xff, 0xbf, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x7f, 0xff, 0xff, 0xbf, 
	0xf0, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0xff, 0xff, 0xff, 0xdf, 0xf0, 0xff, 0xff, 0xff, 0xff, 
	0xf0, 0x00, 0xff, 0xff, 0xff, 0xdf, 0xf0, 0xff, 0xff, 0xfe, 0xff, 0xf8, 0x01, 0xfe, 0xff, 0xff, 
	0xff, 0xf0, 0xff, 0xfb, 0xf9, 0xf7, 0xfc, 0x01, 0xfd, 0xff, 0xff, 0xff, 0xf0, 0xdf, 0xf9, 0xdb, 
	0xef, 0xfc, 0x03, 0xff, 0xef, 0xe3, 0xff, 0xf0, 0xbf, 0xf2, 0xf7, 0xf8, 0xf8, 0x01, 0xff, 0xf7, 
	0xc3, 0xff, 0xf0, 0x37, 0xf6, 0xfc, 0xff, 0xf8, 0x01, 0xbd, 0xff, 0xbf, 0xff, 0xb0, 0x19, 0xed, 
	0xf5, 0xfe, 0xfc, 0x02, 0xfd, 0xff, 0x7f, 0xff, 0x70, 0x0f, 0xcb, 0xf7, 0x3f, 0xfe, 0x0b, 0xff, 
	0xf6, 0xdf, 0xff, 0x30, 0x05, 0xbd, 0xff, 0x7f, 0xdf, 0x3b, 0xfd, 0x7f, 0xff, 0xfe, 0x10, 0x07, 
	0xce, 0xef, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xfc, 0x30, 0x02, 0x77, 0xdf, 0xff, 0xfd, 0xfa, 
	0xff, 0xff, 0xdf, 0xfd, 0xf0, 0x01, 0x7f, 0xff, 0xff, 0xf7, 0xfe, 0x7f, 0xff, 0x3f, 0xfb, 0xf0
};
// 'jean', 84x48px
const unsigned char jean [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xf8, 0x27, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xe0, 
	0x00, 0x7f, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xff, 
	0xf0, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf8, 
	0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0xff, 0xff, 
	0xff, 0xf0, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 
	0x80, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x1f, 
	0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0xff, 0xff, 
	0xfe, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 
	0x17, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x80, 0x07, 0xff, 0xff, 0xf0, 0xff, 
	0xff, 0xff, 0x00, 0x40, 0x00, 0x00, 0x07, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0x00, 0x00, 0x01, 
	0x00, 0x0f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x12, 0x0f, 0xff, 0xff, 0xf0, 
	0xff, 0xff, 0xfe, 0x04, 0x00, 0x02, 0x02, 0x0f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfe, 0x04, 0x04, 
	0x00, 0x02, 0x07, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfe, 0x00, 0x01, 0x08, 0x00, 0x07, 0xff, 0xff, 
	0xf0, 0xff, 0xff, 0xfe, 0x07, 0xfa, 0x20, 0xfe, 0x47, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfc, 0x08, 
	0x90, 0x10, 0x92, 0x07, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x08, 0x00, 0x27, 0xff, 
	0xff, 0xf0, 0xff, 0xff, 0xfc, 0x80, 0x00, 0x00, 0x00, 0x17, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf9, 
	0x80, 0x00, 0x00, 0x00, 0x1b, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf3, 0xc4, 0x00, 0x00, 0x02, 0x3f, 
	0xff, 0xff, 0xf0, 0xff, 0xff, 0xef, 0x86, 0x00, 0x00, 0x06, 0x1f, 0xff, 0xff, 0xf0, 0xff, 0xff, 
	0xfe, 0x83, 0x00, 0x00, 0x0e, 0x17, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xef, 0xd3, 0xc0, 0x00, 0x3c, 
	0xbf, 0x7f, 0xff, 0xf0, 0xff, 0xff, 0xbf, 0xf3, 0xf0, 0x00, 0xfc, 0xff, 0xdf, 0xff, 0xf0, 0xff, 
	0xfe, 0xff, 0xfb, 0xfc, 0x03, 0xfd, 0xff, 0xf7, 0xff, 0xf0, 0xff, 0xff, 0xcf, 0xfb, 0xff, 0x8f, 
	0xfd, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfb, 0xf3, 0xe7, 0x9c, 0x7c, 0xff, 0xff, 0xff, 0xf0, 
	0xff, 0xff, 0xff, 0x77, 0xe0, 0x70, 0x7e, 0xef, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xcf, 0xc0, 
	0x08, 0x3f, 0x3f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0x9e, 0x00, 0x00, 0x07, 0xdf, 0xff, 0xff, 
	0xf0, 0xff, 0xff, 0xfe, 0x78, 0x00, 0x60, 0x03, 0xe7, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfe, 0xfc, 
	0x00, 0xf8, 0x03, 0xf7, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfe, 0xfe, 0x03, 0xfc, 0x07, 0xf7, 0xf1, 
	0xff, 0xf0, 0xff, 0xff, 0xfe, 0xfe, 0x0f, 0xff, 0x05, 0xe7, 0x8f, 0xff, 0xf0, 0xff, 0xff, 0xfe, 
	0x37, 0xa3, 0xfc, 0x4e, 0x85, 0x3c, 0x7f, 0xf0, 0xff, 0xff, 0xff, 0x89, 0x80, 0x00, 0x18, 0x06, 
	0x43, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0xf1, 0x44, 0x3f, 0xf0, 0xff, 0xff, 
	0xfc, 0xc0, 0x00, 0x00, 0x00, 0x2d, 0x16, 0x7f, 0xf0, 0xff, 0xff, 0xff, 0xa0, 0x00, 0x00, 0x00, 
	0x54, 0x43, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xcf, 0xe0, 0x00, 0x7e, 0x3d, 0x09, 0xff, 0xf0, 0xff, 
	0xff, 0xff, 0x7f, 0xff, 0x9f, 0xff, 0xee, 0x9f, 0xff, 0xf0, 0xff, 0xff, 0xf6, 0x80, 0x3e, 0x97, 
	0xc0, 0x1f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x17, 0xff, 0xff, 0xf0
};
// 'keqing', 84x48px
const unsigned char keqing [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf7, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 
	0xf0, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfc, 0x0f, 
	0xf0, 0x00, 0x7e, 0x20, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfa, 0x27, 0x00, 0x00, 0x0d, 0x00, 0xff, 
	0xff, 0xf0, 0xff, 0xff, 0xf9, 0x90, 0x00, 0x00, 0x00, 0xc9, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf8, 
	0x60, 0x00, 0x00, 0x00, 0xe9, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfc, 0x40, 0x00, 0x00, 0x00, 0x3b, 
	0xff, 0xff, 0xf0, 0xff, 0xff, 0xfc, 0x80, 0x00, 0x00, 0x94, 0x1d, 0xff, 0xff, 0xf0, 0xff, 0xff, 
	0xff, 0x00, 0x00, 0x00, 0x82, 0x0d, 0x7f, 0xff, 0xf0, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x7e, 
	0x06, 0x7f, 0xff, 0xf0, 0xff, 0xff, 0xec, 0x00, 0x00, 0x00, 0x43, 0x06, 0x7f, 0xff, 0xf0, 0xff, 
	0xff, 0xf8, 0x04, 0x10, 0x00, 0x25, 0x00, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf2, 0x00, 0x00, 0x80, 
	0x13, 0x06, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xe2, 0x00, 0x21, 0x00, 0x8a, 0x81, 0xff, 0xff, 0xf0, 
	0xff, 0xff, 0x98, 0x00, 0x62, 0x02, 0x05, 0x81, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf8, 0x04, 0x85, 
	0x86, 0x02, 0x81, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfa, 0x82, 0x51, 0x0e, 0x00, 0x85, 0xff, 0xff, 
	0xf0, 0xff, 0xff, 0xfa, 0x0c, 0xa3, 0x04, 0x39, 0x87, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfe, 0x4f, 
	0xfa, 0x01, 0xff, 0x07, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfa, 0x05, 0x78, 0x00, 0x7b, 0x86, 0xff, 
	0xff, 0xf0, 0xff, 0xff, 0xf2, 0x20, 0x00, 0x00, 0x01, 0x84, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf3, 
	0x18, 0x00, 0x00, 0x00, 0x88, 0x7f, 0xff, 0xf0, 0xff, 0xff, 0xe1, 0x09, 0x00, 0x00, 0x01, 0x08, 
	0x7f, 0xff, 0xf0, 0xff, 0xff, 0xe1, 0x8c, 0x00, 0x00, 0x03, 0x14, 0x3f, 0xff, 0xf0, 0xff, 0xff, 
	0xc2, 0x8a, 0x00, 0x00, 0x06, 0x04, 0x1f, 0xff, 0xf0, 0xff, 0xff, 0x82, 0x47, 0x00, 0x00, 0x0e, 
	0x22, 0x1f, 0xff, 0xf0, 0xff, 0xff, 0x00, 0x23, 0xe0, 0x00, 0x7e, 0x62, 0x0f, 0xff, 0xf0, 0xff, 
	0xfe, 0x04, 0x37, 0xf8, 0x01, 0xfc, 0xa0, 0x07, 0xff, 0xf0, 0xff, 0xfc, 0x00, 0x4b, 0xf8, 0x01, 
	0xfb, 0x21, 0x03, 0xff, 0xf0, 0xff, 0xf8, 0x00, 0x0f, 0xfc, 0x63, 0xff, 0x90, 0x01, 0xff, 0xf0, 
	0xff, 0xf1, 0x00, 0x9f, 0xff, 0xff, 0xff, 0x90, 0x04, 0x7f, 0xf0, 0xff, 0xc6, 0x00, 0x1f, 0xff, 
	0x67, 0xff, 0xc8, 0x02, 0x3f, 0xf0, 0xff, 0x88, 0x01, 0x3f, 0xff, 0x1f, 0xff, 0xc0, 0x01, 0x8f, 
	0xf0, 0xff, 0x30, 0x40, 0x3f, 0xbf, 0xff, 0xdf, 0xe4, 0x10, 0xc7, 0xf0, 0xfe, 0x60, 0xa2, 0x0f, 
	0x0b, 0xed, 0x0f, 0x08, 0x68, 0x73, 0xf0, 0xfd, 0xc1, 0x38, 0x0f, 0x06, 0x06, 0x0f, 0x01, 0xc8, 
	0x39, 0xf0, 0xfb, 0x83, 0x3c, 0x0e, 0x07, 0x1e, 0x07, 0x01, 0xc6, 0x0c, 0xf0, 0xf7, 0x06, 0x1c, 
	0x0e, 0x03, 0x0c, 0x03, 0x03, 0xc3, 0x0f, 0x70, 0xee, 0x0d, 0x1e, 0x1c, 0x01, 0x08, 0x03, 0x07, 
	0x8d, 0x87, 0x30, 0xcc, 0x1b, 0xeb, 0x18, 0x00, 0x08, 0x01, 0x8d, 0x74, 0xc3, 0xb0, 0xdc, 0x31, 
	0x15, 0x3c, 0x01, 0xb8, 0x00, 0x8a, 0xc8, 0xe1, 0x90, 0x9c, 0x69, 0x9f, 0xb7, 0x20, 0x00, 0x00, 
	0x9f, 0x99, 0x71, 0x90, 0x98, 0x92, 0xdf, 0xb7, 0xf8, 0x00, 0x00, 0x5f, 0xb5, 0xd1, 0x90, 0x80, 
	0x88, 0x1f, 0xf7, 0x74, 0x00, 0x00, 0x3f, 0x81, 0x10, 0x80, 0x80, 0x0f, 0xff, 0xdf, 0xfa, 0x80, 
	0x00, 0x3f, 0xff, 0x44, 0x00, 0x80, 0x33, 0xff, 0x9f, 0x7d, 0x80, 0x00, 0x1f, 0xfc, 0xc8, 0x00
};
// 'klee', 84x48px
const unsigned char klee [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x70, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xf0, 0x70, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xff, 0x7f, 0xff, 0xff, 0xe0, 
	0x70, 0xff, 0xff, 0xff, 0xff, 0xff, 0xaf, 0xff, 0xff, 0xff, 0x80, 0x70, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0x8f, 0xf7, 0xff, 0xff, 0x00, 0x70, 0xff, 0xfc, 0x07, 0xff, 0xfe, 0x23, 0xff, 0xef, 0xfe, 
	0x00, 0x70, 0xff, 0xf3, 0xff, 0xff, 0xfe, 0x9b, 0xff, 0xfb, 0xfc, 0x00, 0xf0, 0xff, 0xc7, 0xfd, 
	0xff, 0xff, 0x8f, 0xff, 0xfd, 0xf8, 0x01, 0xf0, 0xff, 0x8f, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0xf8, 0x01, 0xf0, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x90, 0x03, 0xf0, 0xff, 0x87, 
	0xf7, 0xff, 0xff, 0xfe, 0xff, 0xff, 0x38, 0x0f, 0xf0, 0xff, 0x87, 0xdf, 0xff, 0xff, 0xff, 0xff, 
	0xfe, 0x50, 0x00, 0xf0, 0xff, 0x81, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x70, 0x01, 0xf0, 0xff, 
	0xc0, 0x3f, 0x8f, 0xff, 0xff, 0xff, 0x8e, 0xc5, 0x03, 0xf0, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x06, 0xc3, 0x07, 0xf0, 0xff, 0xfe, 0x06, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc5, 0x3f, 0xf0, 
	0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x01, 0x78, 0x3f, 0xf0, 0xff, 0xff, 0xfc, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xb3, 0xff, 0xf0, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcf, 0xff, 
	0xf0, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe7, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0x08, 0x00, 0x00, 0x00, 0x00, 0x7f, 
	0xff, 0xf0, 0xff, 0xff, 0x82, 0x08, 0xf0, 0x00, 0xf0, 0x00, 0x0f, 0xff, 0xf0, 0xff, 0xfc, 0x00, 
	0x0b, 0xf8, 0x01, 0x7e, 0x80, 0x01, 0xff, 0xf0, 0xff, 0xc0, 0x00, 0x00, 0xf8, 0x01, 0x68, 0x80, 
	0x00, 0x1f, 0xf0, 0xff, 0xff, 0xf9, 0x00, 0x00, 0x00, 0x00, 0x04, 0xff, 0xff, 0xf0, 0xff, 0xff, 
	0xf0, 0x00, 0x00, 0x00, 0x01, 0x00, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x03, 0x02, 0x1f, 0xff, 0xf0, 0xff, 
	0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xf0, 0xff, 0xfe, 0x00, 0x03, 0xe0, 0x00, 
	0x3e, 0x00, 0x03, 0xff, 0xf0, 0xff, 0xfc, 0x00, 0x03, 0xfc, 0x01, 0xfe, 0x00, 0x01, 0xff, 0xf0, 
	0xff, 0xf8, 0x00, 0x01, 0xf1, 0x00, 0x3c, 0x00, 0x00, 0xff, 0xf0, 0xff, 0xf0, 0x00, 0x00, 0x08, 
	0x78, 0x00, 0x02, 0x00, 0x7f, 0xf0, 0xff, 0xe0, 0x02, 0x40, 0x20, 0x20, 0x00, 0x17, 0x00, 0x3f, 
	0xf0, 0xff, 0xe0, 0x03, 0xe0, 0x80, 0x00, 0x18, 0x3f, 0x00, 0x3f, 0xf0, 0xff, 0xc0, 0x07, 0xff, 
	0x80, 0x00, 0x7f, 0xfe, 0x00, 0x3f, 0xf0, 0xff, 0xe0, 0x07, 0xff, 0xc0, 0x01, 0xff, 0xff, 0x84, 
	0x3f, 0xf0, 0xff, 0xe4, 0x07, 0xff, 0xf0, 0x00, 0xff, 0xff, 0x1c, 0x7f, 0xf0, 0xff, 0xff, 0x03, 
	0xff, 0xfe, 0x00, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xfe, 0x0f, 0xc0, 0x07, 0xff, 
	0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x60, 0x01, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 
	0xff, 0xfc, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x07, 
	0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xdf, 0x07, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 
	0xff, 0xff, 0xff, 0xfe, 0x03, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x01, 
	0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0xff, 0xff, 0xff, 0xff, 0xf0
};
// 'qiqi', 84x48px
const unsigned char qiqi [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xfc, 0x3f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 
	0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0xff, 
	0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 
	0xfc, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x01, 0xff, 
	0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x7f, 0xcf, 0xff, 0xf0, 0xff, 0xff, 
	0xff, 0x80, 0x00, 0x00, 0x00, 0x1f, 0xd7, 0xff, 0xf0, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x20, 0x00, 
	0x07, 0x9b, 0xff, 0xf0, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x02, 0xb7, 0xff, 0xf0, 0xff, 
	0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x67, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x80, 
	0x00, 0x00, 0xcf, 0xff, 0xf0, 0xff, 0xff, 0xe0, 0x00, 0x01, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xf0, 
	0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xf0, 0xff, 0xff, 0x80, 0x00, 0x00, 
	0x00, 0x00, 0x10, 0x1f, 0xff, 0xf0, 0xff, 0xff, 0x80, 0x00, 0x00, 0x08, 0x00, 0x12, 0x0f, 0xff, 
	0xf0, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xf0, 0xff, 0xfe, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xf0, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 
	0xff, 0xf0, 0xff, 0xfc, 0x01, 0x00, 0xf8, 0x01, 0xfc, 0x00, 0x03, 0xff, 0xf0, 0xff, 0xfc, 0x01, 
	0x07, 0xa8, 0x00, 0x8f, 0x08, 0x03, 0xff, 0xf0, 0xff, 0xfb, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 
	0x03, 0xff, 0xf0, 0xff, 0xfd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 0xff, 0xf0, 0xff, 0xfd, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x10, 0x1b, 0xff, 0xf0, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 
	0x30, 0x77, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0x04, 0x00, 0x00, 0x02, 0x71, 0xff, 0xff, 0xf0, 0xff, 
	0xff, 0xf0, 0x02, 0x00, 0x00, 0x04, 0x67, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0x01, 0x00, 0x00, 
	0x08, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xe0, 0x0c, 0x84, 0x02, 0x11, 0xff, 0xff, 0xff, 0xf0, 
	0xff, 0xff, 0xe0, 0x16, 0x77, 0x9e, 0xe0, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xe0, 0x0f, 0x17, 
	0xf6, 0xcf, 0x7f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xe1, 0xf7, 0xcf, 0x6f, 0x1e, 0xff, 0xff, 0xff, 
	0xf0, 0xff, 0xff, 0xff, 0xfa, 0x3f, 0xff, 0xc5, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xde, 
	0x1f, 0x2f, 0x87, 0xbf, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xee, 0x7d, 0xfb, 0xe7, 0xff, 0xff, 
	0xff, 0xf0, 0xff, 0xff, 0xff, 0x80, 0x3f, 0x6f, 0xc1, 0x1f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfe, 
	0x1c, 0x3e, 0x67, 0xc3, 0xc7, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xfc, 0x20, 0x70, 0x03, 0xff, 
	0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf8, 0x20, 0xf0, 0x01, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 
	0xff, 0xfc, 0x31, 0xfc, 0xc3, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x07, 0xfe, 0x0f, 
	0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0x3f, 0xfe, 0x06, 0x06, 0x07, 0xff, 0xff, 0xff, 0xf0, 0xff, 
	0xfc, 0xff, 0xff, 0x00, 0x02, 0x0f, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xf3, 0xff, 0xff, 0xbc, 0x01, 
	0xdf, 0xff, 0xff, 0xff, 0xf0, 0xff, 0x8f, 0xff, 0xfc, 0xfc, 0x03, 0xb3, 0xff, 0xff, 0xff, 0xf0
};
// 'yae_miko', 84x48px
const unsigned char yae_miko [] PROGMEM = {
	0xff, 0xff, 0xff, 0xe2, 0x7f, 0xff, 0xf2, 0x3f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xcd, 0xfe, 
	0x03, 0xfd, 0x9f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfe, 0xcb, 0xe0, 0x08, 0x3e, 0x9b, 0xff, 0xff, 
	0xf0, 0xff, 0xff, 0xfe, 0x17, 0x00, 0x00, 0x07, 0x43, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xfe, 0x10, 
	0x00, 0x00, 0x00, 0x43, 0xff, 0xff, 0xf0, 0xff, 0xf1, 0xfe, 0x10, 0x00, 0x00, 0x00, 0x63, 0xfc, 
	0x7f, 0xf0, 0xff, 0xf8, 0x8f, 0x40, 0x00, 0x00, 0x00, 0x17, 0x88, 0xff, 0xf0, 0xff, 0xfc, 0x77, 
	0x80, 0x00, 0x00, 0x00, 0x0f, 0x71, 0xff, 0xf0, 0xff, 0xfe, 0x05, 0x00, 0x00, 0x00, 0x00, 0x05, 
	0x03, 0xff, 0xf0, 0xff, 0xff, 0xf2, 0x00, 0x00, 0x00, 0x00, 0x02, 0x7f, 0xff, 0xf0, 0xff, 0xff, 
	0xfc, 0x00, 0x00, 0x00, 0x00, 0x09, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 
	0x04, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xf0, 0xff, 
	0xff, 0xf1, 0x10, 0x20, 0x00, 0x80, 0x44, 0x7f, 0xff, 0xf0, 0xff, 0xfe, 0x02, 0x40, 0x00, 0x01, 
	0x40, 0x06, 0x03, 0xff, 0xf0, 0xff, 0xff, 0xe3, 0x00, 0x00, 0x00, 0x00, 0x06, 0x3f, 0xff, 0xf0, 
	0xff, 0xff, 0xc0, 0x00, 0x08, 0x02, 0x00, 0x01, 0x1f, 0xff, 0xf0, 0xff, 0xff, 0xa1, 0x02, 0x04, 
	0x14, 0x00, 0x04, 0x7f, 0xff, 0xf0, 0xff, 0xfe, 0x0c, 0x00, 0x02, 0x08, 0x02, 0x01, 0x83, 0xff, 
	0xf0, 0xff, 0xfc, 0x10, 0x1f, 0xf9, 0x89, 0xff, 0xc0, 0x41, 0xff, 0xf0, 0xff, 0xf8, 0x00, 0x46, 
	0xf8, 0xe0, 0x7a, 0x10, 0x00, 0xff, 0xf0, 0xff, 0xe1, 0x3d, 0x80, 0x00, 0x5c, 0x00, 0x0f, 0xe4, 
	0x3f, 0xf0, 0xff, 0xc0, 0x14, 0x88, 0x00, 0x02, 0x00, 0x8a, 0xc0, 0x1f, 0xf0, 0xff, 0x00, 0xe0, 
	0x8c, 0x00, 0x00, 0x01, 0x8a, 0x38, 0x07, 0xf0, 0xfc, 0x07, 0xcc, 0x0c, 0x00, 0x00, 0x01, 0x82, 
	0x5f, 0x81, 0xf0, 0xff, 0xff, 0xac, 0x4e, 0x00, 0x00, 0x03, 0x82, 0xb7, 0xff, 0xf0, 0xff, 0xff, 
	0xbe, 0x07, 0x00, 0x00, 0x0f, 0x00, 0xf7, 0xff, 0xf0, 0xff, 0xff, 0x94, 0x27, 0xc0, 0x00, 0x1f, 
	0x20, 0xe7, 0xff, 0xf0, 0xff, 0xff, 0xd9, 0x06, 0x98, 0x00, 0xfe, 0x42, 0x0f, 0xff, 0xf0, 0xff, 
	0xff, 0xe7, 0x0a, 0xf8, 0x00, 0xfe, 0x87, 0x8f, 0xff, 0xf0, 0xff, 0xff, 0xef, 0x07, 0xbf, 0xff, 
	0xe7, 0x07, 0xdf, 0xff, 0xf0, 0xff, 0xff, 0xcf, 0x07, 0x80, 0x00, 0x0f, 0x07, 0xc7, 0xff, 0xf0, 
	0xff, 0xff, 0xff, 0x04, 0x80, 0x00, 0x09, 0x07, 0xef, 0xff, 0xf0, 0xff, 0xff, 0xff, 0x90, 0x80, 
	0x00, 0x09, 0x07, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0x0b, 0x00, 0x00, 0x06, 0x07, 0xff, 0xff, 
	0xf0, 0xff, 0xff, 0xff, 0x45, 0x00, 0x00, 0x07, 0x17, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf8, 0x23, 
	0x00, 0x00, 0x06, 0x20, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xe0, 0x10, 0x00, 0x70, 0x00, 0x40, 0x1f, 
	0xff, 0xf0, 0xff, 0xff, 0x80, 0x05, 0xc6, 0x07, 0x81, 0x80, 0x0f, 0xff, 0xf0, 0xff, 0xff, 0x00, 
	0x05, 0x8e, 0x01, 0x9f, 0x00, 0x07, 0xff, 0xf0, 0xff, 0xfe, 0x00, 0x0c, 0x50, 0x00, 0x15, 0x80, 
	0x03, 0xff, 0xf0, 0xff, 0xfe, 0x00, 0x08, 0x23, 0xaf, 0x00, 0x80, 0x01, 0xff, 0xf0, 0xff, 0xf8, 
	0x00, 0x10, 0x41, 0x40, 0x40, 0x40, 0x00, 0xff, 0xf0, 0xff, 0xf0, 0x00, 0x30, 0x00, 0x20, 0x00, 
	0x60, 0x00, 0x7f, 0xf0, 0xff, 0xf0, 0x00, 0x20, 0x00, 0x00, 0x00, 0x30, 0x00, 0x7f, 0xf0, 0xff, 
	0xd8, 0x00, 0x60, 0x00, 0x00, 0x00, 0x30, 0x00, 0xdf, 0xf0, 0xff, 0xec, 0x00, 0xc0, 0x00, 0x00, 
	0x00, 0x1c, 0x01, 0x9f, 0xf0, 0xff, 0xdf, 0xc1, 0xc0, 0x00, 0x20, 0x00, 0x1e, 0x1f, 0xdf, 0xf0
};

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 3264)
const unsigned char* five_art_array[6] = {
    yae_miko,
    klee,
    jean,
    qiqi,
    keqing,
    childe
};

void setupFiveStars(unit (&units)[6]){
    char yae_name[16] = "Yae Miko";
    char klee_name[16] = "Klee";
    char jean_name[16] = "Jean";
    char qiqi_name[16] = "Qiqi";
    char keqing_name[16] = "Keqing";
    char childe_name[16] = "Tartaglia";

    for(byte i = 0; i < 6; ++i){
        units[i].rarity = 5;
    }
    
    units[0].setName(yae_name);
    units[1].setName(klee_name);
    units[2].setName(jean_name);
    units[3].setName(qiqi_name);
    units[4].setName(keqing_name);
    units[5].setName(childe_name);
}

#endif