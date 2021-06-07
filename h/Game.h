//
// Created by erosp on 03/06/2021.
//

#ifndef GIOCO_GAME_H
#define GIOCO_GAME_H

#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    void play();

private:
    void processEvents(sf::Clock& shootingClock);
    void update(sf::Time);
    void render();
    int processMenuEvents();

    void updateStatistics(sf::Time elapsedTime);

    void loadTextures();
    //void loadSound();

private:
    std::shared_ptr<World> world;
    std::shared_ptr<sf::View> view;
    std::shared_ptr<Menu> startMenu;
    //Menu startMenu;
    /*
    sf::SoundBuffer soundBuffer;
    sf::Music music;
    sf::Sound sound;
    */

    TextureHolder textureHolder;
    std::shared_ptr<sf::RenderWindow> mWindow;
    static const sf::Time TimePerFrame;

    sf::Font mFont;

    //std::shared_ptr<AchievementFactory> throphies;
};

#endif //GIOCO_GAME_H
