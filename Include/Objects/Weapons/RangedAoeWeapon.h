//
// Created by erosp on 07/06/2021.
//

#ifndef CHARACTERS_H_RANGEDAOEWEAPON_H
#define CHARACTERS_H_RANGEDAOEWEAPON_H

#include "Weapon.h"

class RangedAoeWeapon: public Weapon {
public:
    RangedAoeWeapon(const TextureHolder& textures, RangedAoeWeapon::TypeObject type);
    void update();

public:
    TypeObject type;
    Projectile::Type projectileType;

private:
    const TextureHolder& textures;

};
#endif //CHARACTERS_H_RANGEDAOEWEAPON_H
