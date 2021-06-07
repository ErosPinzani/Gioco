//
// Created by erosp on 06/06/2021.
//

#ifndef CHARACTERS_H_MEDIKIT_H
#define CHARACTERS_H_MEDIKIT_H

#include "Consumables.h"


class Medikit : public Consumables {
public:
    Medikit(const TextureHolder& textures);
    void Update() final;

    int powerUp;
private:
    const TextureHolder& textures;
};

#endif //CHARACTERS_H_MEDIKIT_H