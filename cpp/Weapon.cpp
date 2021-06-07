//
// Created by erosp on 07/06/2021.
//

#include "..\h\Weapon.h"

Weapon::Weapon() {
}

void Weapon::update() {
    rect.setPosition(position);
    sprite.setPosition(rect.getPosition());
}

bool Weapon::use() {
    return false;
}