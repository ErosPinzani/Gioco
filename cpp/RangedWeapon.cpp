//
// Created by erosp on 07/06/2021.
//

#include "..\h\RangedWeapon.h"

Textures::ID toTextureID(RangedWeapon::Type type) {
    switch(type) {
        case RangedWeapon::Type::energyShooter:
            return Textures::energyShooter;
        case RangedWeapon::Type::redShooter:
            return Textures::redShooter;
    }
}

RangedWeapon::RangedWeapon(const TextureHolder& textures, RangedWeapon::Type type): textures(textures), typeWeapon(type) {

    equipped = false;
    this->type = Object::Type::rangedWeapon;

    if(typeWeapon == energyShooter) {
        projectileType = Projectile::Type::energyBall;
        typeWeapon = energyShooter;

    } else if(typeWeapon == redShooter) {
        projectileType = Projectile::Type::redProjectile;
        typeWeapon = redShooter;
    }

    //counterLifeTime = 2000;   use it to have a life time
    counterLifeTime = 1;
    projectilesCounter = 0;
    range = 400;
    power = 10;
    addStuff(40);

    texture = textures.get(toTextureID(type));
    sprite.setTexture(texture);

    rect.setPosition(sf::Vector2f(300,300));
    rect.setOrigin(32/2,23/2);
    sprite.setOrigin(32/2,23/2);
    rect.setSize(sf::Vector2f(32,23));
    sprite.setPosition(rect.getPosition());

}

bool RangedWeapon::addStuff(int added) {
    if(added > 0) {
        projectilesCounter += added;
        return true;
    }
    return false;
}

bool RangedWeapon::use() {
    if(projectilesCounter <= 0) {
        std::cout<<"non ci sono proiettili da sparare"<<std::endl;
        counterLifeTime = 0;
        return false;
    }

    projectilesCounter--;
    return true;
}

void RangedWeapon::update() {
    Weapon::update();
}

void RangedWeapon::changeType(RangedWeapon::Type type) {
    if(type == energyShooter) {
        typeWeapon = energyShooter;
        projectileType = Projectile::Type::energyBall;
    } else if(type == redShooter) {
        typeWeapon = redShooter;
        projectileType = Projectile::Type::redProjectile;
    }
    texture = textures.get(toTextureID(type));
    sprite.setTexture(texture);
}