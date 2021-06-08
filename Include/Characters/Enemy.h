//
// Created by erosp on 05/06/2021.
//

#ifndef HERO_H_ENEMY_H
#define HERO_H_ENEMY_H

#include <memory>
#include "Characters.h"
#include "../Strategy/InspectionStrategy.h"
#include "../Strategy/ChaseStrategy.h"
#include "../Random.h"

class Enemy : public Characters {
public:
    enum EnemyType {
        ogre,
        goblin,
        boss
    };

    Enemy();

    void update() override;
    void setDirection();
    void changeDirection() override;
    void setPosition(float x, float y)override;
    void setPositionV(sf::Vector2f &movement)override;
    const sf::Sprite &getSprite()override;
    int getAttackDamage()override;

    void die()override;

    std::shared_ptr<Strategy> strategy;

    bool attackAvailable;
    std::shared_ptr<Weapon> weapon;

    sf::Vector2f windowSize;

    sf::Clock attackClock;
    int counterWalk;
    bool delayWalk, delayMoreWalk;

};

#endif //HERO_H_ENEMY_H
