//
// Created by erosp on 06/06/2021.
//

#include "../../Include/Objects/Objects.h"

Objects::Objects(): equipped(false) {}

void Objects::get() {}

bool Objects::use() {
    return true;
}

void Objects::leave() {}

void Objects::setPosition(sf::Vector2f vector) {
    position = vector;
    rect.setPosition(position);
    sprite.setPosition(rect.getPosition());
}

void Objects::update() {
    counterLifeTime --;
    if(counterLifeTime<=0)
        active=false;
}