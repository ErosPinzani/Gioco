//
// Created by erosp on 08/06/2021.
//

#include "..\..\Include\Characters\EnemyFactory.h"

std::shared_ptr<Enemy> EnemyFactory::createEnemy(Enemy::EnemyType enemyType, const TextureHolder& textures, sf::Vector2u windowSize) {

    std::shared_ptr<Enemy> enemy;
    std::shared_ptr<Strategy> strategy;

    if ( enemyType == Enemy::EnemyType::ogre ) {
        strategy = std::make_shared<ChaseStrategy>(windowSize);
        enemy = std::make_shared<Gregarious>(textures, windowSize, strategy);
    } else if(enemyType == Enemy::EnemyType::goblin ) {
        strategy = std::make_shared<InspectionStrategy>(windowSize);
        enemy = std::make_shared<RangedGregarious>(textures, windowSize, strategy);
    } else if(enemyType == Enemy::EnemyType::boss ) {
        strategy = std::make_shared<InspectionStrategy>(windowSize);
        enemy = std::make_shared<Boss>(textures, windowSize, strategy);
    }
    return enemy;
}