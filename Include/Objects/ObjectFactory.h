//
// Created by erosp on 06/06/2021.
//

#ifndef CHARACTERS_H_OBJECTFACTORY_H
#define CHARACTERS_H_OBJECTFACTORY_H

#include "Medikit.h"
//#include "Coin.h"
#include "Weapons\MeleeWeapon.h"
#include "Weapons\RangedAoeWeapon.h"
#include "Weapons\RangedStWeapon.h"
#include "..\Random.h"
#include "..\..\Include\ResourceIdentifier.h"
#include "..\..\Include\ResourceHolder.h"

class ObjectFactory: public Objects {
public:
    std::shared_ptr<Objects> createObject(Objects::TypeObject type, const TextureHolder&textures);
    std::shared_ptr<Objects> createObject(const TextureHolder&textures);

private:
    Objects::TypeObject typeDrop();

};

#endif //CHARACTERS_H_OBJECTFACTORY_H
