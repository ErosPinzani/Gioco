//
// Created by erosp on 07/06/2021.
//

#include "../../../Include/Objects/Weapons/RangedStWeapon.h"
/*
Textures::ID toTextureID(RangedStWeapon::TypeObject type) {
    if (type == Objects::rangedWeaponSt)
        return Textures::???;
}*/

RangedStWeapon::RangedStWeapon(const TextureHolder& textures, RangedStWeapon::TypeObject type): textures(textures), type(type) {
    this->type = Objects::TypeObject::rangedWeaponSt;
    bulletType = Bullets::BulletType::stBullet;

    //counterLifeTime = 2000;   use it to have a life time
    counterLifeTime = 1;
    range = 400;
    power = 10;

    //texture = textures.get(toTextureID(type));
    sprite.setTexture(texture);

    rect.setPosition(sf::Vector2f(300,300));
    rect.setOrigin(32/2,23/2);
    sprite.setOrigin(32/2,23/2);
    rect.setSize(sf::Vector2f(32,23));
    sprite.setPosition(rect.getPosition());
}

void RangedStWeapon::update() {
    Weapon::update();
}