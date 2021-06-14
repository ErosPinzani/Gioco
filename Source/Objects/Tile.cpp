//
// Created by erosp on 09/06/2021.
//

#include "..\..\Include\Objects\Tile.h"

Textures::ID toTextureID(Tile::BackGroundType type) {
    switch(type) {
        case Tile::BackGroundType::floor:
            return Textures::ID::stoneTile;
        case Tile::BackGroundType ::wall:
            return Textures::ID ::stoneWall;
    }
}

Tile::Tile(const TextureHolder &textures, sf::Vector2f coordinates, BackGroundType btype): textures(textures), type(TileType::Floor), backGround(btype), coordinates(coordinates) {
    rect.setOrigin(32/2,32/2);
    sprite.setOrigin(32/2,32/2);

    texture = textures.get(toTextureID(backGround));
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(64*0,64*0,64,64));
    rect.setSize(sf::Vector2f(64,64));

    rect.setPosition(coordinates.x * 64, coordinates.y * 64);
    sprite.setPosition(rect.getPosition());

}