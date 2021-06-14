//
// Created by erosp on 07/06/2021.
//

#ifndef CHARACTERS_H_MELEEWEAPON_H
#define CHARACTERS_H_MELEEWEAPON_H

#include "..\Objects.h"
#include "Weapon.h"
#include "Bullets.h"

class MeleeWeapon: public Weapon {
public:
    MeleeWeapon(const TextureHolder &textures, TypeObject object);

    void callFightAnimation();

private:
    bool effect;
    const TextureHolder& textures;
};

#endif //CHARACTERS_H_MELEEWEAPON_H
