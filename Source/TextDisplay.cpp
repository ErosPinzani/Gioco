//
// Created by erosp on 09/06/2021.
//

#include "..\Include\TextDisplay.h"

TextDisplay::TextDisplay() {
    text.setPosition(10,10);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(50);
}

void TextDisplay::update() {
    text.setString(string);
}

void TextDisplay::setString(std::string mstring) {
    string = mstring;
}