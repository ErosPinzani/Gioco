//
// Created by erosp on 06/06/2021.
//

#include "../../Include/Strategy/ChaseStrategy.h"

ChaseStrategy::ChaseStrategy(sf::Vector2u windowSize) {
    speed = 10;
    this->windowSize = windowSize;
    type = chase;
}

void ChaseStrategy::update(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight, sf::RectangleShape &rect) {

    sf::Vector2f movements(0.f,0.f);
    sf::Vector2f enemyPos(rect.getPosition());

    //Hero is down right
    double modulo = sqrt(pow(HeroPosition.x, 2) + pow(enemyPos.y,2));
    if(HeroPosition.x >= enemyPos.x && HeroPosition.y >= enemyPos.y) {
        movements = sf::Vector2f(abs(((HeroPosition.x-enemyPos.x)/modulo)*speed), abs(((HeroPosition.y-enemyPos.y)/modulo)*speed));
        if(movements.x > movements.y) {
            isMovingRight = true;
            isMovingDown = false;
        } else {
            isMovingRight = false;
            isMovingDown = true;
        }
        isMovingUp = false;
        isMovingLeft = false;

        //Hero is down left
    } else if(HeroPosition.x <= enemyPos.x && HeroPosition.y >= enemyPos.y) {
        movements = sf::Vector2f(-abs(((HeroPosition.x-enemyPos.x)/modulo)*speed), abs(((HeroPosition.y-enemyPos.y)/modulo)*speed));
        if(-movements.x > movements.y) {
            isMovingLeft = true;
            isMovingDown = false;
        } else {
            isMovingLeft = false;
            isMovingDown = true;
        }
        isMovingUp = false;
        isMovingRight = false;

        //Hero is up right
    } else if(HeroPosition.x >= enemyPos.x && HeroPosition.y <= enemyPos.y) {
        movements = sf::Vector2f(abs(((HeroPosition.x-enemyPos.x)/modulo)*speed), -abs(((HeroPosition.y-enemyPos.y)/modulo)*speed));
        if(movements.x > -movements.y) {
            isMovingRight = true;
            isMovingUp = false;
        } else {
            isMovingRight = false;
            isMovingUp = true;
        }
        isMovingLeft = false;
        isMovingDown = false;

        //Hero is up left
    } else if(HeroPosition.x <= enemyPos.x && HeroPosition.y <= enemyPos.y) {
        movements = sf::Vector2f(-abs(((HeroPosition.x-enemyPos.x)/modulo)*speed), -abs(((HeroPosition.y-enemyPos.y)/modulo)*speed));
        if(-movements.x > -movements.y) {
            isMovingLeft = true;
            isMovingUp = false;
        } else {
            isMovingLeft = false;
            isMovingUp = true;
        }

        isMovingRight = false;
        isMovingDown = false;
    }

    rect.move(movements);
}

void
ChaseStrategy::animation(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight, bool &delayWalk, bool &delayMoreWalk, int &counterWalk) {

    if(!((isMovingLeft && isMovingRight) || (isMovingUp && isMovingDown))) {
        if ( delayWalk ) {
            if ( delayMoreWalk )
                counterWalk = (counterWalk + 1) % 3;
            delayMoreWalk = !delayMoreWalk;
        }
        delayWalk = !delayWalk;
    }
}
