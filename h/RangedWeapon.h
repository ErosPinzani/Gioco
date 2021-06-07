//
// Created by erosp on 07/06/2021.
//

#ifndef CHARACTERS_H_RANGEDWEAPON_H
#define CHARACTERS_H_RANGEDWEAPON_H

#include "Weapon.h"
class RangedStWeapon: public Weapon {
public:
    enum WeaponType{
        rangedStWeapon,
        rangedAoeWeapon
    };
    RangedStWeapon(const TextureHolder& textures, RangedStWeapon::Type type);
    void update() override;
    bool use() override;

public:
    Type typeWeapon;
    WeaponType weaponType;

private:
    const TextureHolder& textures;

};
#endif //CHARACTERS_H_RANGEDWEAPON_H
