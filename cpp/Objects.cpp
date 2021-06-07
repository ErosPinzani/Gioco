//
// Created by erosp on 06/06/2021.
//

#include "..\h\Objects.h"

Object::Object(): equipped(false) {}

void Object::get() {}

bool Object::use() {
    return true;
}

void Object::leave() {}

void Object::setPosition(sf::Vector2f vector) {
    position = vector;
    rect.setPosition(position);
    sprite.setPosition(rect.getPosition());
}

void Object::update() {
    counterLifeTime --;
    if(counterLifeTime<=0)
        active=false;
}