#ifndef __FOUR_STAR_H__
#define __FOUR_STAR_H__

#include "unit.h"


void setupFourStars(unit (&units)[3]){
    
    char thoma_name[16] = "Thoma           ";
    char fischl_name[16] = "Fischl          ";
    char diona_name[16] = "Diona           ";


    for(byte i = 0; i < 3; ++i){
        units[i].rarity = 4;
    }
    
    //units[0].setArt(yae_art);
    units[0].setName(thoma_name);
    units[1].setName(fischl_name);
    units[2].setName(diona_name);


}


#endif