//
// Created by erosp on 06/06/2021.
//

#ifndef CHARACTERS_H_MEDIKIT_H
#define CHARACTERS_H_MEDIKIT_H

#include "Consumables.h"
#include "..\..\Include\ResourceIdentifier.h"
#include "..\..\Include\ResourceHolder.h"

class Medikit : public Consumables {
public:
    Medikit(const TextureHolder &textures, TypeObject object);
    void update() final;

    int powerUp;
private:
    const TextureHolder& textures;
};

#endif //CHARACTERS_H_MEDIKIT_H