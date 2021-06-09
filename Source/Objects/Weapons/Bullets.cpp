//
// Created by erosp on 09/06/2021.
//

#include "..\..\..\Include\Objects\Weapons\Bullets.h"

Textures::ID toTextureID(Bullets::BulletType bulletType) {
    switch(bulletType) {
        case Bullets::BulletType::aoeBullet:
            return Textures::???;
        case Bullets::BulletType::stBullet:
            return Textures::???;
    }
}

Bullets::Bullets(const TextureHolder& textures,  BulletType bulletType): textures(textures), active(false), delayWalk(false), delayMoreWalk (false), delayMoreMoreWalk(false), counterWalk(0), bulletType(bulletType) {
    rect.setPosition(0, 0);
    texture = textures.get(toTextureID(bulletType));
    sprite.setTexture(texture);

    switch(bulletType) {
        case aoeBullet:
            rect.setOrigin(30 / 2, 30 / 2);
            sprite.setOrigin(56 / 2, 56 / 2);  //non credo necessario
            rect.setSize(sf::Vector2f(30, 30));
            sprite.setTextureRect((sf::IntRect(0, 0, 56, 56)));
            attackDamage = 10;
            range = 5;
            break;
        case stBullet:
            rect.setOrigin(18 / 2,  15/ 2);
            sprite.setOrigin(18 / 2, 15 / 2);  //non credo necessario
            rect.setSize(sf::Vector2f(18, 15));
            sprite.setTextureRect((sf::IntRect(0, 0, 18, 15)));
            attackDamage = 5;
            range = 10;
            break;
    }
}

void Bullets::setPosition(const sf::Vector2f &position, Direction direction) {
    active = true;

    this->direction = direction;
    rect.move(position);
    sprite.setPosition(rect.getPosition());

    initialPos = rect.getPosition();
}

const sf::Sprite &Bullets::getSprite() {
    return Entity::getSprite();
}

void Bullets::update() {
    switch(direction) {
        case up:
            rect.move(0,-movementSpeed);
            break;
        case down:
            rect.move(0,movementSpeed);
            break;
        case left:
            rect.move(-movementSpeed,0);
            break;
        case right:
            rect.move(movementSpeed,0);
            break;
    }

    if ( delayWalk ) {
        if ( delayMoreWalk ) {
            if(delayMoreMoreWalk)
                if(bulletType == aoeBullet) {
                    counterWalk = (counterWalk + 1) % 4;
                } else if(bulletType == stBullet)
                    counterWalk = (counterWalk + 1) % 2;

            delayMoreMoreWalk = !delayMoreMoreWalk;
        }
        delayMoreWalk = !delayMoreWalk;
    }
    delayWalk = !delayWalk;

    if(bulletType == aoeBullet) {
        sprite.setTextureRect((sf::IntRect(counterWalk*58,0,56,56)));
    } else if(bulletType == stBullet)
        sprite.setTextureRect((sf::IntRect(counterWalk*18,0,18,15)));

    if(abs(rect.getPosition().x-initialPos.x) > range || abs(rect.getPosition().y-initialPos.y) > range)
        active = false;

    //keeps rect and sprite together
    sprite.setPosition(rect.getPosition());
}