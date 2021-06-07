//
// Created by erosp on 06/06/2021.
//

#ifndef MAIN_CPP_STRATEGY_H
#define MAIN_CPP_STRATEGY_H

#include <SFML/Graphics.hpp>

class Strategy {
public:
    enum Type {
        inspection,
        chase
    };

    enum Direction {
        up,
        down,
        left,
        right
    };

    Strategy();

    virtual void update(bool& isMovingUp,bool& isMovingDown,bool& isMovingLeft,bool& isMovingRight, sf::RectangleShape& rect);
    virtual void animation(bool& isMovingUp,bool& isMovingDown,bool& isMovingLeft,bool& isMovingRight, bool& delayWalk, bool& delayMoreWalk, int& counterWalk);
};

#endif //MAIN_CPP_STRATEGY_H
