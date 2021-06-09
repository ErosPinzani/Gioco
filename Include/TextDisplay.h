//
// Created by erosp on 09/06/2021.
//

#ifndef GAME_CPP_TEXTDISPLAY_H
#define GAME_CPP_TEXTDISPLAY_H

#include <string>
#include "Entity.h"

class TextDisplay: public Entity {
public:
    TextDisplay();

    void setString(std::string mstring);
    void update();

private:
    std::string string = "default";
};
#endif //GAME_CPP_TEXTDISPLAY_H
