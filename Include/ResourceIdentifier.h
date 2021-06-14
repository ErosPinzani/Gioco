//
// Created by erosp on 08/06/2021.
//

#ifndef GAME_H_RESOURCEIDENTIFIER_H
#define GAME_H_RESOURCEIDENTIFIER_H

// Forward declaration of SFML classes
namespace sf {
    class Texture;
}

namespace Textures {
    enum ID {
        //walls
        stoneWall,
        //tiles
        stoneTile,
        //hero
        stHero,
        aoeHero,
        //enemies
        gregarious,
        rangedGregarious,
        //bullets
        aoeBullet,
        stBullet,
        rangedGregaariousBullet,
        //objects
        medikitTexture
    };
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

//It will be called a lot
typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

#endif //GAME_H_RESOURCEIDENTIFIER_H
