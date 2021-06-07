//
// Created by erosp on 06/06/2021.
//

#include "..\h\AoeRanged.h"

AoeRanged::AoeRanged(const TextureHolder& textures, sf::Vector2u windowSize):textures(textures), counterWalk(0), delayWalk(false), delayMoreWalk(false), shooting(false), dead(false) {
    heroType = Aoe;
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
