//
// Created by erosp on 07/06/2021.
//

#ifndef CHARACTERS_H_MELEEWEAPON_H
#define CHARACTERS_H_MELEEWEAPON_H

#include "Weapon.h"

class MeleeWeapon: public Weapon {
public:
    MeleeWeapon(const TextureHolder& textures);

    void callFightAnimation();

private:
    bool effect;
    const TextureHolder& textures;
};

#endif //CHARACTERS_H_MELEEWEAPON_H
