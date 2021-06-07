//
// Created by erosp on 06/06/2021.
//

#ifndef MAIN_CPP_INSPECTIONSTRATEGY_H
#define MAIN_CPP_INSPECTIONSTRATEGY_H

#include "Strategy.h"

class InspectionStrategy : public Strategy {
public:
    InspectionStrategy(sf::Vector2u windowSize);

    //change direction every x frames
    void update(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight, sf::RectangleShape& rect) override;

    void animation(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight, bool & delayWalk, bool &delayMoreWalk, int &counterWalk) override;

    int changeDirectionTime, counterDirection = 0;
    Direction direction;
    Type type;

private:
    void changeDirection(bool &isMovingUp, bool &isMovingDown, bool &isMovingLeft, bool &isMovingRight);

    int speed;
    sf::Vector2u windowSize;


};
#endif //MAIN_CPP_INSPECTIONSTRATEGY_H
