//
// Created by erosp on 06/06/2021.
//

#include "..\h\Medikit.h"

Medikit::Medikit(const TextureHolder &textures): textures(textures) {

    textures = textures.get(Textures::healPack);
    sprite.setTexture(texture);

    rect.setPosition(sf::Vector2f(300,300));
    rect.setOrigin(32/2,23/2);
    sprite.setOrigin(32/2,23/2);
    rect.setSize(sf::Vector2f(32,23));
    sprite.setPosition(rect.getPosition());

    powerUp = 50;
    active = true;
    counterLifeTime = 1;
}

void Medikit::Update() {
    rect.setPosition(position);
    sprite.setPosition(rect.getPosition());
    //ConsumableObject::update();
}