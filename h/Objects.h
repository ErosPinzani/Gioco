//
// Created by erosp on 06/06/2021.
//

#ifndef CHARACTERS_H_OBJECTS_H
#define CHARACTERS_H_OBJECTS_H

#include <string>
#include "Entity.h"

class Objects: public Entity {
public:
    enum Type {
        healPack,
        rangedWeapon,
        meleeWeapon,
        Shield
    };

    Object();

    //virtual ~Object() = 0;
    virtual bool use();
    virtual void get();
    virtual void leave();

    virtual void setPosition(sf::Vector2f vector);
    virtual void update();

public:
    int counterLifeTime = 2;

    Type type;
    std::string description;

    bool equipped;
    bool active = true;
    sf::Vector2f position;
};

#endif //CHARACTERS_H_OBJECTS_H