//
// Created by erosp on 06/06/2021.
//

#ifndef MAIN_CPP_GREGARIOUS_H
#define MAIN_CPP_GREGARIOUS_H

#include "Enemy.h"

class Gregarious: public Enemy {
public:
    explicit Gregarious(const TextureHolder& textures, sf::Vector2u windowSize, std::shared_ptr<Strategy> strategy);
    EnemyType enemyType;
private:
    const TextureHolder &textures;

};


#endif //MAIN_CPP_GREGARIOUS_H
