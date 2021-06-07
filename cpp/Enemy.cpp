//
// Created by erosp on 05/06/2021.
//

#include <iostream>
#include "..\h\Enemy.h"

Enemy::Enemy() {}

int Enemy::getAttackDamage() {
    if(attackClock.getElapsedTime().asSeconds() > .5) {
        attackClock.restart();
        return attackDamage;
    }
    else return 0;
}

void Enemy::update() {

    //controls the walking animation
    strategy->animation(isMovingUp,isMovingDown,isMovingLeft,isMovingRight,delayMoreWalk,delayMoreWalk,counterWalk);

    strategy->update(isMovingUp, isMovingDown, isMovingLeft, isMovingRight, rect);
    sprite.setPosition(rect.getPosition());
    position = sprite.getPosition();

    //serve per texture corretta
    setDirection();

    if(hp<=0) {
        this->die();
    }

    Characters::update();

}

void Enemy::setDirection() {
    if(isMovingUp) {
        this->direction = up;
        sprite.setTextureRect(sf::IntRect(counterWalk*32,32*3,32,32));
    } else if(isMovingRight) {
        this->direction = right;
        sprite.setTextureRect(sf::IntRect(counterWalk*32,32*2,32,32));
    } else if(isMovingLeft) {
        this->direction = left;
        sprite.setTextureRect(sf::IntRect(counterWalk*32,32,32,32));
    } else if(isMovingDown) {
        this->direction = down;
        sprite.setTextureRect(sf::IntRect(counterWalk*32,0,32,32));
    }
}
void Enemy::setPositionV(sf::Vector2f &movement) {
    Characters::setPositionV(movement);
    //checkWorldBounds();
}

void Enemy::setPosition(float x, float y) {
    Characters::setPosition(x,y);
}


const sf::Sprite &Enemy::getSprite() {
    return Entity::getSprite();
}

void Enemy::die() {
    active = false;
    if(!observers.empty())
        notifyObservers();// notify his observers who will update his enemyKills counter, advancing with achievements
    /*
    for(auto iter=observers.begin(); iter!=observers.end(); iter++){
            observers.erase(iter); //remove all his observers at his death
    }
    */
}

void Enemy::registerObserver(std::shared_ptr<DemolisherAchievement> observer) {
    observers.emplace_back(observer);
}

void Enemy::removeObserver(std::shared_ptr<DemolisherAchievement> observer) {
    int counterObs = 0;
    for(auto iter=observers.begin(); iter!=observers.end(); iter++){
        if(observers[counterObs] == observer)
            observers.erase(iter);
        counterObs++;
    }
}

void Enemy::notifyObservers() const {
    int counterObs = 0;
    for(auto iter=observers.begin(); iter!=observers.end(); iter ++){
        observers[counterObs]->update();
        counterObs++;
    }
}

void Enemy::changeDirection() {
    isMovingUp= false;
    isMovingDown= false;
    isMovingLeft= false;
    isMovingRight= false;
    int randDirection = generateRandom(4);
    if(randDirection==1) isMovingUp=true;
    if(randDirection==2) isMovingDown=true;
    if(randDirection==3) isMovingLeft=true;
    if(randDirection==4) isMovingRight=true;
}