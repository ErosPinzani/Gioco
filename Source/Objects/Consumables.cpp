//
// Created by erosp on 06/06/2021.
//

#include "../../Include/Objects/Consumables.h"

int Consumables::getQuantity() const {
    return quantity;
}

void Consumables::update() {
    //TODO non so perché ma questa position me la mette a 0 ma non mi sembra che ci siano più position nell'oggetto
    // quindi non so perché
    rect.setPosition(position);
    sprite.setPosition(rect.getPosition());
}