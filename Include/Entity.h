//
// Created by erosp on 03/06/2021.
//

#ifndef GIOCO_ENTITY_H
#define GIOCO_ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Entity{
public:
    enum Direction{
        up,
        down,
        left,
        right
    };

    virtual const sf::Sprite &getSprite();
    virtual ~Entity() = 0;

    sf::RectangleShape rect;
    sf::Texture texture;
    Direction direction;
    sf::Sprite sprite;
    sf::Text text;
};

#endif //GIOCO_ENTITY_H
