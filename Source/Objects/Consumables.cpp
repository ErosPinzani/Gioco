//
// Created by erosp on 06/06/2021.
//

#include "../../Include/Objects/Consumables.h"

int Consumables::getQuantity() const {
    return quantity;
}

void Consumables::update() {
    rect.setPosition(position);
    sprite.setPosition(rect.getPosition());
}