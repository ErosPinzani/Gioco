//
// Created by erosp on 03/06/2021.
//

#include <iostream>
#include "../../Include/Characters/Hero.h"

/*Textures::ID toTextureID(PlayerCharacter::SubType type) {
    switch(type) {
        case PlayerCharacter::SubType::blueHero:
            return Textures::HeroBlue;
        case PlayerCharacter::SubType::blondHero:
            return Textures::HeroBlond;
        case PlayerCharacter::SubType::whiteHero:
            return Textures::HeroWhite;
        case PlayerCharacter::SubType::grayHero:
            return Textures::HeroGray;
        case PlayerCharacter::SubType::starLord:
            return Textures::StarLord;
    }
}*/

Hero::Hero(){}
/*
Hero::Hero(HeroType heroType, const TextureHolder& textures, sf::Vector2u windowSize):textures(textures), counterWalk(0), delayWalk(false), delayMoreWalk(false), shooting(false), dead(false) {
    this->windowSize.x = (int)windowSize.x;
    this->windowSize.y = (int)windowSize.y;

    rect.setPosition(windowSize.x/2.f,windowSize.y/2.f);
    //rect.setPosition(generateRandom(800), generateRandom(800));
    speedBasic = 2;
    hp = 200;
    hpMax = hp;
    attackDamage = 0;

    rect.setOrigin(32 / 2, 32 / 2);
    sprite.setOrigin(32 / 2, 32 / 2);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));

    texture = textures.get(toTextureID(heroType));
    sprite.setTexture(texture);
}
*/
void Hero::update(sf::Time dt) {
    //now sprite is linked to rect's position
    sprite.setPosition(rect.getPosition());
    position = sprite.getPosition();

    sf::Vector2f movements(0.f,0.f);
    if(isMovingUp) {
        movements.y-=speedBasic;
        setDirection(Hero::up);
    }
    if(isMovingDown) {
        movements.y+=speedBasic;
        setDirection(Hero::down);
    }
    if(isMovingRight) {
        movements.x+=speedBasic;
        setDirection(Hero::right);
    }
    if(isMovingLeft) {
        movements.x-=speedBasic+;
        setDirection(Hero::left);
    }

    //controls the walking animation
    if(!((isMovingLeft && isMovingRight) || (isMovingUp && isMovingDown))) {
        if ( delayWalk ) {
            if ( delayMoreWalk )
                counterWalk = (counterWalk + 1) % 3;
            delayMoreWalk = !delayMoreWalk;
        }
        delayWalk = !delayWalk;
    }

    setPosition(movements /* *dt.asSeconds()*/);

    Characters::update();

    //if dead
    if(hp<=0) {
        dead = true;
        std::cout<<"GAME OVER"<<std::endl;
    }
}

bool Hero::interactWithObject(std::shared_ptr<Object> object) {

    std::shared_ptr<Weapon> newWeapon = std::dynamic_pointer_cast<Weapon>(object);
    if(newWeapon != nullptr) {
        changeWeapon(newWeapon);

    } else {
        std::shared_ptr<Healpack> newHeal = std::dynamic_pointer_cast<Healpack>(object);
        if(newHeal != nullptr) {
            hp = hp + newHeal->powerUp;
            if(hp > hpMax)
                hp = hpMax;

            newHeal->counterLifeTime--;
            display();
            //needs not to be equipped for being displayed
            newHeal->active = false;
        }
    }
    return true;
}

bool Hero::useWeapon() {
    if (weapon->use())
        return true;
    else {
        std::cout<<"Something went wrong with weapon usage"<<endl;
        return false;
    }
}

void Hero::die() {}

void Hero::setPosition(sf::Vector2f movement) {
    Character::setPosition(movement);
    checkWorldBounds();
}

void Hero::checkWorldWalls() {
    //check right bound
    if((rect.getPosition().x+16)>windowSize.x)
        rect.setPosition(windowSize.x-16, rect.getPosition().y);
        //check left bound;
    else if(rect.getPosition().x-16<0)
        rect.setPosition(16, rect.getPosition().y);
    //check button bound
    if((rect.getPosition().y)+16>windowSize.y)
        rect.setPosition(rect.getPosition().x, windowSize.y-16);
        //check upper bound
    else if(rect.getPosition().y-16<0)
        rect.setPosition(rect.getPosition().x, 16);
}

void Hero::setPosition(float x, float y) {
    Characters::setPosition(x,y);
}

sf::Vector2f Hero::getPosition() {
    return Characters::getPosition();
}

const sf::Sprite &Hero::getSprite() {
    return Entity::getSprite();
}

float Hero::getSpeed() const {
    return speedBasic;
}

void Hero::setSpeed(int speed) {
    this->speedBasic = speed;
}

void Hero::setDirection(Hero::Direction direction) {
    switch(direction) {
        case up:
            this->direction = up;
            sprite.setTextureRect(sf::IntRect(counterWalk*32,32*3,32,32));
            break;
        case down:
            this->direction = down;
            sprite.setTextureRect(sf::IntRect(counterWalk*32,0,32,32));
            break;
        case left:
            this->direction = left;
            sprite.setTextureRect(sf::IntRect(counterWalk*32,32,32,32));
            break;
        case right:
            this->direction = right;
            sprite.setTextureRect(sf::IntRect(counterWalk*32,32*2,32,32));
            break;
    }
}
