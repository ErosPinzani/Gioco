//
// Created by erosp on 07/06/2021.
//

#ifndef CHARACTERS_H_WEAPON_H
#define CHARACTERS_H_WEAPON_H

#include "../Objects.h"

class Weapon : public Objects {
public:
    enum weaponType{

    };
    Weapon();
    void update() override;
    bool use() override;

public:
    int range;
    int power;
};
#endif //CHARACTERS_H_WEAPON_H
