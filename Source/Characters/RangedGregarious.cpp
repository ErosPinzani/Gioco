//
// Created by erosp on 06/06/2021.
//

#include "../../Include/Characters/RangedGregarious.h"

RangedGregarious::RangedGregarious(const TextureHolder &textures, sf::Vector2u windowSize, std::shared_ptr<Strategy> strategy):textures(textures) {
    enemyType = goblin;
    if(std::dynamic_pointer_cast<InspectionStrategy>(strategy) != nullptr) {
        this->strategy = std::make_shared<InspectionStrategy>(windowSize);
    }
    else if(std::dynamic_pointer_cast<ChaseStrategy>(strategy) != nullptr) {
        this->strategy = std::make_shared<ChaseStrategy>(windowSize);
    } else
        std::cout <<"errore sulla conversione della strategia"<< std::endl;

    this->windowSize.x = (int)windowSize.x;
    this->windowSize.y = (int)windowSize.y;

    speedBasic = 0;
    hp = 40;
    hpMax = hp;
    attackDamage = 40;

    rect.setOrigin(32/2,32/2);
    sprite.setOrigin(32/2,32/2);
    texture = textures.get(Textures::???);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));
}

void RangedGregarious::update() {
    if(shootingTimer.getElapsedTime().asSeconds() > 1) {
        attackAvailable = true;
        shootingTimer.restart();
    }
    Enemy::update();
}
