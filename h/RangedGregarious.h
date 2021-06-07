//
// Created by erosp on 06/06/2021.
//

#ifndef MAIN_CPP_RANGEDGREGARIOUS_H
#define MAIN_CPP_RANGEDGREGARIOUS_H

#include "Enemy.h"

class RangedGregarious: public Enemy {
public:
    explicit RangedGregarious(const TextureHolder& textures, sf::Vector2u windowSize, std::shared_ptr<Strategy> strategy);
    EnemyType enemyType;
    void update() final;

private:
    sf::Clock shootingTimer;
    const TextureHolder& textures;

};

#endif //MAIN_CPP_RANGEDGREGARIOUS_H
