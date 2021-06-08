//
// Created by erosp on 03/06/2021.
//

#ifndef GIOCO_HERO_H
#define GIOCO_HERO_H

#include <memory>
#include "Characters.h"
#include "../Objects/Objects.h"

class Hero: public Characters{
public:
    enum HeroType{
        close,
        St,
        Aoe,
    };

    Hero();
    virtual bool interactWithObject(std::shared_ptr<Objects> object);
    //a movement that covers several tiles thanks to the ProtoBelt
    void dash();
    void die() override;
    void update(sf::Time dt);

    void setPosition(sf::Vector2f movement);
    void setPosition(float x, float y) override;
    sf::Vector2f getPosition() override;

    virtual const sf::Sprite &getSprite() override;
    void setDirection(Hero::Direction direction);

    float getSpeed() const;
    void setSpeed(int speed);

    bool dead;
protected:
    sf::Vector2u windowSize;
private:
    void checkWorldWalls();

    const TextureHolder& textures;
    int counterWalk;
    bool delayWalk, delayMoreWalk;
};
#endif //GIOCO_HERO_H
