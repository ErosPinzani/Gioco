//
// Created by erosp on 06/06/2021.
//

#ifndef MAIN_CPP_AOERANGED_H
#define MAIN_CPP_AOERANGED_H

#include "Hero.h"

class AoeRanged : public Hero {
public:
    AoeRanged(const TextureHolder& textures, sf::Vector2u windowSize);
    HeroType heroType;
};
#endif //MAIN_CPP_AOERANGED_H
