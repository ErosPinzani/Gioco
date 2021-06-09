#include <iostream>
#include "../Include/Game.h"

int main() {
    try {
        Game game;
        game.play();
    } catch (std::exception& ex) {
        std::cout << "\nEXCEPTION: " << ex.what() << std::endl;
    }
}
