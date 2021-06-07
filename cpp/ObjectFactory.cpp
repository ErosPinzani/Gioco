//
// Created by erosp on 06/06/2021.
//

#include "..\h\ObjectFactory.h"

std::shared_ptr<Objects> ObjectFactory::createObject(Objects::Type type, const TextureHolder &textures) {
    std::shared_ptr<Objects> object;

    if ( type == Objects::Type::rangedWeaponSt ) {
        object = std::make_shared<RangedStWeapon>(textures, RangedStWeapon::Type::???);
    }else if(type == Objects::Type::rangedWeaponAoe ) {
        object = std::make_shared<RangedAoeWeapon>(textures, RangedAoeWeapon::Type::???);
    } else if(type == Objects::Type::meleeWeapon ) {
        object = std::make_shared<MeleeWeapon>(textures, MeleeWeapon::Type::???);
    } else if( type == Objects::Type::medikit ) {
        object = std::make_shared<Medikit>(textures)
    } else if( type == Objects::Type::coins ) {
        object = std::make_shared<Coins>(textures)
    }

    return object;
}

std::shared_ptr<Objects> ObjectFactory::createObject(const TextureHolder &textures) {
    std::shared_ptr<Objects> object;
    Objects::Type type = typeDrop();

    if(type == 0 || type == 1) { // || type == 2 || type == 3) {
        object = createObject(type, textures);
    }

    return object;
}

Objects::Type ObjectFactory::typeDrop() {
    int random = generateRandom(100);
    Objects::Type typeSelected ;

    //15% to drop healpack
    if(random < 15) {
        typeSelected = medikit;
    } //50% to drop coins
    else if(random < 65) {
        typeSelected = rangedWeapon;
    }

    return typeSelected;
}