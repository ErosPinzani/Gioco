//
// Created by erosp on 06/06/2021.
//

#ifndef CHARACTERS_H_OBJECTFACTORY_H
#define CHARACTERS_H_OBJECTFACTORY_H

#include <memory>
#include "Objects.h"
#include "Medikit.h"
#include "Weapons/MeleeWeapon.h"
#include "Weapons/RangedAoeWeapon.h"
#include "Weapons/RangedStWeapon.h"
#include "../Random.h"

class ObjectFactory: public Object {
public:
    std::shared_ptr<Object> createObject(Object::Type type, const TextureHolder&textures);
    std::shared_ptr<Object> createObject(const TextureHolder&textures);

private:
    Object::Type typeDrop();

};

#endif //CHARACTERS_H_OBJECTFACTORY_H
