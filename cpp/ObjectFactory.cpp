//
// Created by erosp on 06/06/2021.
//

#include "..\h\ObjectFactory.h"

std::shared_ptr<Object> ObjectFactory::createObject(Object::Type type, const TextureHolder &textures) {
    std::shared_ptr<Object> object;

    if ( type == Object::Type::rangedWeapon ) {
        object = std::make_shared<RangedWeapon>(textures, RangedWeapon::Type::energyShooter);
    } else if(type== Object::Type::meleeWeapon ) {
        object = std::make_shared<MeleeWeapon>(textures);
    } else if(type== Object::Type::healPack ) {
        object = std::make_shared<Healpack>(textures);
    } else if( type == Object::Type::Shield ) {}

    return object;
}

std::shared_ptr<Object> ObjectFactory::createObject(const TextureHolder &textures) {
    std::shared_ptr<Object> object;
    Object::Type type = typeDrop();

    if(type == 0 || type == 1) { // || type == 2 || type == 3) {
        object = createObject(type, textures);
    }

    return object;
}

Object::Type ObjectFactory::typeDrop() {
    int random = generateRandom(100);
    Object::Type typeSelected ;

    //15% to drop healpack
    if(random < 15) {
        typeSelected = healPack;
    } //50% to drop weapon
    else if(random < 65) {
        typeSelected = rangedWeapon;
    }

    return typeSelected;
}