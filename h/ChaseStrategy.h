//
// Created by erosp on 06/06/2021.
//

#ifndef MAIN_CPP_CHASESTRATEGY_H
#define MAIN_CPP_CHASESTRATEGY_H

#include "Strategy.h"
#include <cmath>

class ChaseStrategy: public Strategy {
public:
    ChaseStrategy(sf::Vector2u windowSize);

    void update(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight, sf::RectangleShape& rect) override;

    void animation(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight, bool &delayWalk, bool &delayMoreWalk, int &counterWalk) override;

    Direction direction;
    Type type;
    sf::Vector2f HeroPosition;

private:
    float speed;
    sf::Vector2u windowSize;

};

#endif //MAIN_CPP_CHASESTRATEGY_H
