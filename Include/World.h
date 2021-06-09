//
// Created by erosp on 08/06/2021.
//

#ifndef GAME_H_WORLD_H
#define GAME_H_WORLD_H

#include <string>
#include <SFML/Audio.hpp>

#include "Characters\Hero.h"
#include "Characters\Gregarious.h"
#include "Characters\RangedGregarious.h"
#include "Characters\EnemyFactory.h"
#include "Map.h"
#include "TextDisplay.h"
#include "Objects\Medikit.h"
//#include "Objects\Coin.h"
#include "Objects\ObjectFactory.h"

class World {
public:
    World(std::shared_ptr<sf::RenderWindow> window, const TextureHolder& textures);
    void update(sf::Time dt);
    void draw();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed, sf::Clock& shootingClock);

    void createObjects();
    void dropObject(int index);
    void createEnemies();

    void useWeapon();

    void drawProjectiles();
    void drawEnemies();
    void drawMap();
    void drawObjects();
    void drawTextDisplayed();
    void drawPlayer();

    void updateProjectiles();
    void updateEnemies();
    void updateObjects();
    void updateTextureDisplayed();

    void checkCollision();
    void collisionWithMap();
    void collisionPlayerProjectilesOnObjects();
    void collisionEnemyProjectilesOnObjects();
    void collisionPlayerEnemy();
    void checkCollection();

public:
    std::shared_ptr<Hero> player;
    std::shared_ptr<sf::RenderWindow> window;
    //std::vector<int> wallArray;

    std::shared_ptr<Map> map;

    sf::Font mainFont;

    const TextureHolder& textures;
    //this holds all the texts
    std::vector<std::shared_ptr<TextDisplay>> textureDisplayArray;
    std::shared_ptr<TextDisplay> playerLife;
    std::shared_ptr<TextDisplay> demolisherAchievement;

    sf::Clock textureTimer;

    std::vector<std::shared_ptr<Enemy>> enemyArray;
    EnemyFactory enemyFactory;
    ObjectFactory objectFactory;

    std::vector<std::shared_ptr<Bullets>> projectilePlayerArray;
    std::vector<std::shared_ptr<Bullets>> projectileEnemyArray;
    std::vector<std::shared_ptr<Objects>> collectableObject;

    std::shared_ptr<Medikit> medikit;

};

#endif //GAME_H_WORLD_H
