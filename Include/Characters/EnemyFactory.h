//
// Created by erosp on 08/06/2021.
//

#ifndef GAME_H_ENEMYFACTORY_H
#define GAME_H_ENEMYFACTORY_H

#include "Gregarious.h"
#include "RangedGregarious.h"
#include "Enemy.h"

class EnemyFactory {
public:
    std::shared_ptr<Enemy> createEnemy(Enemy::EnemyType enemytype, const TextureHolder&textures, sf::Vector2u windowSize);
};

#endif //GAME_H_ENEMYFACTORY_H
