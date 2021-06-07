//
// Created by erosp on 06/06/2021.
//

#ifndef MAIN_CPP_STRANGED_H
#define MAIN_CPP_STRANGED_H

#include "Hero.h"

class stRanged : public Hero {
public:
    stRanged(const TextureHolder& textures, sf::Vector2u windowSize);
    HeroType heroType;
};
#endif //MAIN_CPP_STRANGED_H
