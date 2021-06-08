//
// Created by erosp on 03/06/2021.
//

#ifndef GIOCO_CHARACTERS_H
#define GIOCO_CHARACTERS_H

#include "../Entity.h"
#include "../Objects/Weapons/Weapon.h"

class Characters: public Entity{
public:
    Characters();

    virtual ~Characters() = 0;
    virtual void move();
    virtual void setPositionV(sf::Vector2f& movement);
    virtual void setPosition(float x, float y);
    virtual sf::Vector2f getPosition();
    virtual void changeDirection();

    virtual void attack();
    virtual int getAttackDamage();
    //basic interaction with the world, it will be associated with a key
    //virtual bool interactWithObject(std::shared_ptr <Object> object);
    virtual void die();
    virtual void update();

    virtual void display();

    bool active;

    int hp;
    int hpMax;
    int attackDamage;
    bool isMovingUp, isMovingDown, isMovingLeft, isMovingRight;

    bool barDisplayed = false;
    sf::RectangleShape bar;
    sf::RectangleShape lifeBar;

    sf::Vector2f windowSize;

protected:
    //int armor;
    int speedBasic;
    sf::Vector2f position;

    //Inventory inventory;
    sf::Clock timerTextures;


};
#endif //GIOCO_CHARACTERS_H
