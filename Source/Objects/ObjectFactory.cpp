//
// Created by erosp on 06/06/2021.
//

#include "../../Include/Objects/ObjectFactory.h"

std::shared_ptr<Objects> ObjectFactory::createObject(Objects::TypeObject type, const TextureHolder &textures) {
    std::shared_ptr<Objects> object;

    if ( type == Objects::TypeObject::rangedWeaponSt ) {
        object = std::make_shared<RangedStWeapon>(textures, RangedStWeapon::TypeObject::???);
    }else if(type == Objects::TypeObject::rangedWeaponAoe ) {
        object = std::make_shared<RangedAoeWeapon>(textures, RangedAoeWeapon::TypeObject::???);
    } else if(type == Objects::TypeObject::meleeWeapon ) {
        object = std::make_shared<MeleeWeapon>(textures, MeleeWeapon::TypeObject::???);
    } else if( type == Objects::TypeObject::medikit ) {
        object = std::make_shared<Medikit>(textures);
    } /*else if( type == Objects::TypeObject::coins ) {
        object = std::make_shared<Coins>(textures);
    }*/
    return object;
}

std::shared_ptr<Objects> ObjectFactory::createObject(const TextureHolder &textures) {
    std::shared_ptr<Objects> object;
    Objects::TypeObject type = typeDrop();

    if(type == 0 || type == 1) { // || type == 2 || type == 3) {
        object = createObject(type, textures);
    }

    return object;
}

Objects::TypeObject ObjectFactory::typeDrop() {
    int random = generateRandom(100);
    Objects::TypeObject typeSelected ;

    //15% to drop healpack
    if(random < 15) {
        typeSelected = medikit;
    } //50% to drop coins
    else if(random < 65) {
        typeSelected = coins;
    }

    return typeSelected;
}