//
// Created by erosp on 07/06/2021.
//

#ifndef CHARACTERS_H_RANGEDAOEWEAPON_H
#define CHARACTERS_H_RANGEDAOEWEAPON_H

#include <iostream>
#include "Weapon.h"
#include "Bullets.h"

class RangedAoeWeapon: public Weapon {
public:
    RangedAoeWeapon(const TextureHolder& textures, RangedAoeWeapon::TypeObject type);
    void update();

public:
    TypeObject type;
    Bullets::BulletType bulletType;

private:
    const TextureHolder& textures;

};
#endif //CHARACTERS_H_RANGEDAOEWEAPON_H
