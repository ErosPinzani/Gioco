//
// Created by erosp on 09/06/2021.
//

#ifndef WORLD_H_MENU_H
#define WORLD_H_MENU_H

#include "../Include/ResourceHolder.h"
#include "SFML/Graphics.hpp"

class Menu {
public:
    Menu(std::shared_ptr<sf::RenderWindow> window);
    ~Menu();

    void draw();
    void moveUp();
    void moveDown();
    int getPressedChoice() {return selectedChoice; };

public:
    float width, height;
    int selectedChoice;
    sf::Font font; // font utilizzato nel menu
    std::vector<sf::Text> choicesVector; //vettore di possibilità di un menu
    std::shared_ptr<sf::RenderWindow> window;
};
#endif //WORLD_H_MENU_H
