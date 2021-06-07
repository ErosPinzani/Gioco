//
// Created by erosp on 06/06/2021.
//

#ifndef MAIN_CPP_MELEE_H
#define MAIN_CPP_MELEE_H

#include "Hero.h"

class Melee : public Hero {
    Melee(const TextureHolder& textures, sf::Vector2u windowSize);
    HeroType heroType;
};

#endif //MAIN_CPP_MELEE_H
