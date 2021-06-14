//
// Created by erosp on 06/06/2021.
//

#include "../../Include/Characters/Gregarious.h"

Gregarious::Gregarious(const TextureHolder &textures, sf::Vector2u windowSize, std::shared_ptr<Strategy> strategy):textures(textures) {
    enemyType = ogre;
    if(std::dynamic_pointer_cast<InspectionStrategy>(strategy) != nullptr)
        this->strategy = std::make_shared<InspectionStrategy>(windowSize);
    else
        std::cout <<"errore sulla conversione della strategia"<< std::endl;

    this->windowSize.x = (int)windowSize.x;
    this->windowSize.y = (int)windowSize.y;

    speedBasic = 2;
    hp = 20;
    hpMax = hp;
    attackDamage = 20;

    rect.setOrigin(32/2,32/2);
    sprite.setOrigin(32/2,32/2);
    texture = textures.get(Textures::gregarious);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));
}

