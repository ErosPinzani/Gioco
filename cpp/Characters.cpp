//
// Created by erosp on 03/06/2021.
//

#include "..\h\Characters.h"

Characters::Characters() {

    //all characters are this big
    rect.setSize(sf::Vector2f(32,32));

    //life bar
    bar = sf::RectangleShape(sf::Vector2f(32,5));
    lifeBar = sf::RectangleShape(sf::Vector2f(32,5));
    bar.setOutlineThickness(3);
    bar.setOutlineColor(sf::Color::Black);
    bar.setFillColor(sf::Color::Black);
    lifeBar.setFillColor(sf::Color::Green);

    isMovingDown = false;
    isMovingLeft = false;
    isMovingRight = false;
    isMovingUp = false;
    active = true;
}

void Characters::move() {}

void Characters::attack() {}
/*
bool Characters::interactWithObject(std::shared_ptr <Object> object) {
    return true;
}
*/
void Characters::die() {

}

void Characters::display() {
    barDisplayed = true;
    timerTextures.restart();
}

void Characters::update() {
    //life bar
    if(barDisplayed) {
        bar.setPosition(position.x-16,position.y-32);
        lifeBar.setPosition(position.x-16,position.y-32);
        lifeBar.setSize(sf::Vector2f(32*hp/hpMax,5));
        if(lifeBar.getSize().x <= 16)
            lifeBar.setFillColor(sf::Color::Yellow);
        if(lifeBar.getSize().x <= 8)
            lifeBar.setFillColor(sf::Color::Red);
        if(timerTextures.getElapsedTime().asSeconds() > .5) {
            barDisplayed = false;
        }
    }
}

void Characters::setPositionV(sf::Vector2f& movement) {
    rect.move(movement.x, movement.y);
}

void Characters::setPosition(float x, float y) {
    rect.move(x,y);
}

void Characters::changeDirection() {}

int Characters::getAttackDamage() {
    return 0;
}

sf::Vector2f Characters::getPosition() {
    return position;
}
