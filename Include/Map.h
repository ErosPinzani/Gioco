//
// Created by erosp on 09/06/2021.
//

#ifndef GAME_CPP_MAP_H
#define GAME_CPP_MAP_H

#include "SFML/Graphics.hpp"
#include "Objects/Tile.h"

class Map {
public:
    Map(const TextureHolder &textures, Tile::BackGroundType backGroundType, sf::Vector2u windowSize);

    ~Map();

    bool createLevel(int inx, int iny);
    //Tile::BackGroundType getCell (int x, int y) const;
    void setCell (int x, int y, Tile::BackGroundType inputTile);
    std::shared_ptr<Tile> getCell (int x, int y);

    std::vector<std::shared_ptr<Tile>> tileMap;

private:
    bool makeCorridor(int x, int y, int length, int direction);
    bool makeRoom(int x, int y, int direction);
    //ci può essere soltanto una bossroom per livello
    bool makeBossRoom(int x, int y);
    int getRand(int min, int max);

    std::shared_ptr<sf::RenderWindow> mapWindow;
    std::vector<std::shared_ptr<Tile>> wallArray;

    const TextureHolder& textures;
    sf::Texture tileTexture;
    sf::Sprite tileSprite;
    const int xsize;
    const int ysize;

    const int maxRoomSide;
    const int minRoomSide;

    const int numSideCell = 25;
    int towerLevel = 0;
    int objects; //chest, loot on the map


    //rooms have priority, define rooms and corridors chance to be created
    const int chanceRoom;
    const int chanceCorridor;
    const int chance1Door = 30;
    const int chance2Door = 85;
    const int chance3Door = 95;
    const int chance4Door = 100;

    bool bossRoom = false;
    const int minBossRoomSide = 10;

    bool mapFilled = false;
};
#endif //GAME_CPP_MAP_H
