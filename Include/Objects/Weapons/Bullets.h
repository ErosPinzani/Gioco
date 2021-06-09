//
// Created by erosp on 09/06/2021.
//

#ifndef WORLD_H_BULLETS_H
#define WORLD_H_BULLETS_H

#include <cmath>

#include "..\..\..\Include\Entity.h"
#include "..\..\..\Include\ResourceHolder.h"
#include "..\..\..\Include\ResourceIdentifier.h"

class Bullet: public Entity {
public:

    enum BulletType {
        aoeBullet,
        stBullet
    };

    Bullet(const TextureHolder& textures, BulletType type);
    //when it's created sets the position with the Player
    virtual void setPosition(const sf::Vector2f& position, Direction direction);
    virtual const sf::Sprite&getSprite();
    void update();

public:
    bool active;
    int range;
    int attackDamage;

private:
    BulletType bulletType;
    const TextureHolder& textures;
    bool delayWalk, delayMoreWalk, delayMoreMoreWalk;
    int counterWalk;
    sf::Vector2f initialPos;

    int movementSpeed = 10;
};
#endif //WORLD_H_BULLETS_H
