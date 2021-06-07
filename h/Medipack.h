//
// Created by erosp on 06/06/2021.
//

#ifndef CHARACTERS_H_MEDIPACK_H
#define CHARACTERS_H_MEDIPACK_H

#include "Consumables.h"


class Medipack : public Consumables {
public:
    Medipack(const TextureHolder& textures);
    void Update() final;

    int powerUp;
private:
    const TextureHolder& textures;
};

#endif //CHARACTERS_H_MEDIPACK_H