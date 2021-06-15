//
// Created by erosp on 09/06/2021.
//

#ifndef GAME_CPP_TILE_H
#define GAME_CPP_TILE_H

#include <random>
#include "..\..\Include\ResourceHolder.h"
#include "..\..\Include\ResourceIdentifier.h"
#include "..\Entity.h"

class Tile : public Entity {
public:

    enum BackGroundType {
        floor,
        baseFloor,
        wall
    };

    enum TileType {
        Unused,
        Wall,
        dirtWall,
        brokenWall,
        Floor,
        dirtFloor,
        brokenFloor,
        Door, BrokenDoor,
        UpStairs,
        DownStairs,
        Chest
    }; //BrokenFloor e BrokenWall costituiscono dei passaggi come Door, Upstairs e DownStairs

    Tile(const TextureHolder& textures, sf::Vector2f coordinates, BackGroundType type);

public:
    TileType type;
    BackGroundType backGround;
    sf::Vector2f coordinates;

private:
    const TextureHolder& textures;
    std::random_device rd;
    std::uniform_real_distribution<> distribution;
};
#endif //GAME_CPP_TILE_H
