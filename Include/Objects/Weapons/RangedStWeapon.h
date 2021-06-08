//
// Created by erosp on 07/06/2021.
//

#ifndef CHARACTERS_H_RANGEDSTWEAPON_H
#define CHARACTERS_H_RANGEDSTWEAPON_H

#include "Weapon.h"

class RangedStWeapon: public Weapon {
public:
    RangedStWeapon(const TextureHolder& textures, RangedStWeapon::TypeObject type);
    void update() override;
    bool use() override;

public:
    TypeObject type;
    Projectile::Type projectileType;

private:
    const TextureHolder& textures;

};

#endif //CHARACTERS_H_RANGEDSTWEAPON_H
