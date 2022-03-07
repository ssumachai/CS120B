#ifndef __THREE_STAR_H__
#define __THREE_STAR_H__

#include "unit.h"


void setupThreeStars(unit (&units)[5]){
    
    char sword_name[16] = "Random Sword";
    char bow_name[16] = "Random Bow";
    char claymore_name[16] = "Random Claymore";
    char catalyst_name[16] = "Random Catalyst";
    char polearm_name[16] = "Random Polearm";

    for(byte i = 0; i < 5; ++i){
        units[i].rarity = 3;
    }
    
    //units[0].setArt(yae_art);
    units[0].setName(sword_name);
    units[1].setName(bow_name);
    units[2].setName(claymore_name);
    units[3].setName(catalyst_name);
    units[4].setName(polearm_name);


}


#endif