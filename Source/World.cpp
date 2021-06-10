//
// Created by erosp on 08/06/2021.
//

#include "..\Include\World.h"

World::World(std::shared_ptr<sf::RenderWindow> window, const TextureHolder &textures): window(window), textures(textures), player(new Hero(Hero::HeroType::St, textures,window->getSize())), map(new Map(textures, Tile::BackGroundType::baseFloor, window->getSize())) {
    //player related stuff
    int x,y;
    do{
        x = generateRandom(24);
        y = generateRandom(24);
    } while (map->tileMap[x*25+y]->backGround != Tile::labFloor);
    player->rect.setPosition(x*64+16,y*64+16);
    //life text
    mainFont.loadFromFile("???");

    playerLife = std::make_shared<TextDisplay>();
    playerLife->setString(std::to_string(player->hp));
    playerLife->text.setFont(mainFont);
    textureDisplayArray.emplace_back(playerLife);

    createEnemies();
    createObjects();
}

void World::createEnemies() {
    for(int i=0; i<5; i++) {
        std::shared_ptr<Enemy> enemy = enemyFactory.createEnemy(Enemy::EnemyType::ogre, textures,window->getSize());
        int x,y;
        do{
            x = generateRandom(24);
            y = generateRandom(24);
        } while (map->tileMap[x*25+y]->backGround != Tile::labFloor && map->tileMap[x*25+y]->backGround != Tile::woodFloor);
        enemy->rect.setPosition(x*64+16,y*64+16);
        enemyArray.emplace_back(enemy);
    }
    for(int i=0; i<10; i++) {
        std::shared_ptr<Enemy> enemy = enemyFactory.createEnemy(Enemy::EnemyType::goblin, textures, window->getSize());
        int x,y;
        do{
            x = generateRandom(24);
            y = generateRandom(24);
        } while (map->tileMap[x*25+y]->backGround != Tile::labFloor && map->tileMap[x*25+y]->backGround != Tile::woodFloor);
        enemy->rect.setPosition(x*64+16,y*64+16);
        enemyArray.emplace_back(enemy);
    }
}

void World::createObjects() {
    //create medikits
    std::shared_ptr<Objects> medikit = objectFactory.createObject(Objects::TypeObject::medikit, textures);
    int x,y;
    do{
        x = generateRandom(24);
        y = generateRandom(24);
    } while (map->tileMap[x*25+y]->backGround != Tile::woodFloor);
    medikit->setPosition(sf::Vector2f(x*64+16,y*64+16));

    collectableObject.emplace_back(medikit);
}

void World::dropObject(int index) {
    std::shared_ptr<Objects> object = objectFactory.createObject(textures);

    if(object != nullptr) {
        object->setPosition(enemyArray[ index ]->getPosition());
        std::shared_ptr<Medikit> newMedikit = std::dynamic_pointer_cast<Medikit>(object);
        //std::shared_ptr<Coin> newCoin = std::dynamic_pointer_cast<Coin>(object);

        collectableObject.emplace_back(object);
    }
}

void World::update(sf::Time dt) {
    player->update(dt);
    updateEnemies();
    updateProjectiles();
    updateObjects();
    checkCollision();
    updateTextureDisplayed();

}

void World::updateTextureDisplayed() {
    //life text
    playerLife->setString("Life: " + std::to_string(player->hp));
    int counter = 0;
    for ( auto iter = textureDisplayArray.begin(); iter != textureDisplayArray.end(); iter++ ) {
        textureDisplayArray[counter]->text.setPosition(player->getPosition().x - window->getSize().x/4 + counter*1, player->getPosition().y - window->getSize().y/4 + counter*50);
        textureDisplayArray[ counter ]->update();

        counter++;
    }
}

void World::updateObjects() {
    if(!collectableObject.empty()) {
        int counter = 0;
        int deleted = -1;
        for ( auto iter = collectableObject.begin(); iter != collectableObject.end(); iter++ ) {
            collectableObject[ counter ]->update();

            if ( collectableObject[ counter ]->counterLifeTime <= 0 ) {
                deleted = counter;
            }
            counter++;
        }
        if(deleted>=0)
            collectableObject.erase(collectableObject.begin() + deleted);
    }
}

void World::updateEnemies() {
    if(!enemyArray.empty()) {
        int counter = 0;
        int deleted = -1;
        for ( auto iter = enemyArray.begin(); iter != enemyArray.end(); iter++ ) {

            //set player position to the strategy
            auto chaseStrategy = std::dynamic_pointer_cast<ChaseStrategy>(enemyArray[counter]->strategy);
            if(chaseStrategy != nullptr)
                chaseStrategy->HeroPosition = player->getPosition();

            enemyArray[ counter ]->update();

            //if it uses his weapon it adds it to the enemyProjectiles
            auto shooter = std::dynamic_pointer_cast<RangedGregarious>(enemyArray[counter]);
            if( shooter != nullptr && shooter->attackAvailable) {

                //if it is in seek Strategy
                auto chase = std::dynamic_pointer_cast<ChaseStrategy>(enemyArray[counter]->strategy);
                if(chase != nullptr) {
                    projectileEnemyArray.emplace_back(std::make_shared<Bullets>(textures, Bullets::stBullet));
                    projectileEnemyArray.back()->setPosition(shooter->rect.getPosition(), shooter->direction);
                    projectileEnemyArray.back()->range = shooter->weapon->range;
                    projectileEnemyArray.back()->attackDamage = shooter->weapon->power;
                    shooter->attackAvailable = false;
                }
            }

            if ( !enemyArray[ counter ]->active ) {
                deleted = counter;
            }
            counter++;
        }
        if(deleted>=0) {
            dropObject(deleted);
            enemyArray.erase(enemyArray.begin() + deleted);
        }
    }
}

void World::updateProjectiles() {
    //friendly projectiles
    if(!projectilePlayerArray.empty()) {
        int counter = 0;
        int deleted = -1;
        for ( auto iter = projectilePlayerArray.begin(); iter != projectilePlayerArray.end(); iter++ ) {
            projectilePlayerArray[ counter ]->update();

            if ( !projectilePlayerArray[ counter ]->active ) {
                deleted = counter;
            }
            counter++;
        }
        if(deleted>=0)
            projectilePlayerArray.erase(projectilePlayerArray.begin() + deleted);
    }
    //enemy projectiles
    if(!projectileEnemyArray.empty()) {
        int counter = 0;
        int deleted = -1;
        for ( auto iter = projectileEnemyArray.begin(); iter != projectileEnemyArray.end(); iter++ ) {
            projectileEnemyArray[ counter ]->update();

            if ( !projectileEnemyArray[ counter ]->active ) {
                deleted = counter;
            }
            counter++;
        }
        if(deleted>=0)
            projectileEnemyArray.erase(projectileEnemyArray.begin() + deleted);
    }
}

void World::checkCollision() {

    collisionPlayerProjectilesOnObjects();
    collisionEnemyProjectilesOnObjects();
    collisionPlayerEnemy();
    //Wall
    collisionWithMap();
}

void World::collisionWithMap() {
    int counterMap = 0;
    //iter on tiles
    for(auto iterMap = map->tileMap.begin(); iterMap != map->tileMap.end(); iterMap++) {

        //if tile is a wall
        if(map->tileMap[counterMap]->backGround == Tile::BackGroundType::metalWall) {
            int counterEnemy = 0;
            //iter on enemies
            for(auto iterEnemy = enemyArray.begin(); iterEnemy != enemyArray.end(); iterEnemy++) {

                //if enemy touches a wall
                std::shared_ptr<Enemy> enemy = enemyArray[counterEnemy];
                if(enemy->rect.getGlobalBounds().intersects(map->tileMap[counterMap]->rect.getGlobalBounds())) {

                    //enemy bounce on walls
                    if(enemy->isMovingUp) {
                        enemy->changeDirection();
                        enemy->setPosition(0,1);
                        if(enemy->rect.getGlobalBounds().intersects(map->tileMap[counterMap]->rect.getGlobalBounds())) {
                            enemy->setPosition(2,0);
                        }
                        if(enemy->rect.getGlobalBounds().intersects(map->tileMap[counterMap]->rect.getGlobalBounds())) {
                            enemy->changeDirection();
                            enemy->setPosition(-4,0);
                        }
                    } else if(enemy->isMovingDown) {
                        enemy->changeDirection();
                        enemy->setPosition(0,-1);
                        if(enemy->rect.getGlobalBounds().intersects(map->tileMap[counterMap]->rect.getGlobalBounds())) {
                            enemy->setPosition(2,0);
                        }
                        if(enemy->rect.getGlobalBounds().intersects(map->tileMap[counterMap]->rect.getGlobalBounds())) {
                            enemy->changeDirection();
                            enemy->setPosition(-4,0);
                        }
                    } else if(enemy->isMovingLeft) {
                        enemy->changeDirection();
                        enemy->setPosition(1, 0);
                        if(enemy->rect.getGlobalBounds().intersects(map->tileMap[counterMap]->rect.getGlobalBounds())) {
                            enemy->setPosition(0,2);
                        }
                        if(enemy->rect.getGlobalBounds().intersects(map->tileMap[counterMap]->rect.getGlobalBounds())) {
                            enemy->changeDirection();
                            enemy->setPosition(0,-4);
                        }
                    } else if(enemy->isMovingRight) {
                        enemy->changeDirection();
                        enemy->setPosition(-1, 0);
                        if(enemy->rect.getGlobalBounds().intersects(map->tileMap[counterMap]->rect.getGlobalBounds())) {
                            enemy->setPosition(0,2);
                        }
                        if(enemy->rect.getGlobalBounds().intersects(map->tileMap[counterMap]->rect.getGlobalBounds())) {
                            enemy->changeDirection();
                            enemy->setPosition(0,-4);
                        }
                    }
                }
                counterEnemy++;
            }
            //check player
            if(player->rect.getGlobalBounds().intersects(map->tileMap[counterMap]->rect.getGlobalBounds())) {

                if(player->isMovingUp && player->isMovingLeft) {
                    player->setPosition(2,2);
                } else if(player->isMovingUp && player->isMovingRight) {
                    player->setPosition(-2,2);
                } else if(player->isMovingDown && player->isMovingLeft) {
                    player->setPosition(2,-2);
                } else if(player->isMovingDown && player->isMovingRight) {
                    player->setPosition(-2,-2);
                } else if(player->isMovingUp) {
                    player->setPosition(0,2);
                } else if(player->isMovingDown) {
                    player->setPosition(0,-2);
                } else if(player->isMovingLeft) {
                    player->setPosition(2,0);
                } else if(player->isMovingRight) {
                    player->setPosition(-2,0);
                }
            }
            //check Projectiles
            if(!projectilePlayerArray.empty()) {
                int counterProjectiles = 0;
                //go through all projectiles
                for ( auto iterProjectile = projectilePlayerArray.begin(); iterProjectile != projectilePlayerArray.end(); iterProjectile++ ) {

                    if(projectilePlayerArray[counterProjectiles]->rect.getGlobalBounds().intersects(map->tileMap[counterMap]->rect.getGlobalBounds())) {
                        projectilePlayerArray[counterProjectiles]->active = false;
                    }
                    counterProjectiles++;
                }
            }
            if(!projectileEnemyArray.empty()) {
                int counterProjectiles = 0;
                //go through all projectiles
                for ( auto iterProjectile = projectileEnemyArray.begin(); iterProjectile != projectileEnemyArray.end();
                      iterProjectile++ ) {

                    if(projectileEnemyArray[counterProjectiles]->rect.getGlobalBounds().intersects(map->tileMap[counterMap]->rect
                                                                                                           .getGlobalBounds())) {
                        projectileEnemyArray[counterProjectiles]->active = false;
                    }
                    counterProjectiles++;
                }
            }
        }
        counterMap++;
    }
}
//TODO sistemare hero choice
void World::collisionPlayerEnemy() {
    //Enemies and Player
    int counterEnemy = 0;
    for ( auto iter = enemyArray.begin(); iter != enemyArray.end(); iter++ ) {
        if ( player->rect.getGlobalBounds().intersects(enemyArray[counterEnemy]->rect.getGlobalBounds())) {
            player->display();
            player->hp -= enemyArray[counterEnemy]->getAttackDamage();
        }
        counterEnemy++;
    }
}

void World::collisionPlayerProjectilesOnObjects() {
    if(!projectilePlayerArray.empty() && !enemyArray.empty()) {
        int counterProjectiles = 0;
        //go through all projectiles
        for ( auto iterProjectile = projectilePlayerArray.begin(); iterProjectile != projectilePlayerArray.end(); iterProjectile++ ) {

            int counterEnemy = 0;
            //go through all enemies
            for ( auto iterEnemy = enemyArray.begin(); iterEnemy != enemyArray.end(); iterEnemy++ ) {
                if ( projectilePlayerArray[ counterProjectiles ]->rect.getGlobalBounds().
                        intersects(enemyArray[ counterEnemy ]->rect.getGlobalBounds())) {

                    std::cout << "Collision!" << std::endl;
                    //change strategy
                    std::shared_ptr<Strategy> newStrategy = std::make_shared<InspectionStrategy>(window->getSize());
                    enemyArray[counterEnemy]->strategy = newStrategy;

                    //check life and bar
                    enemyArray[counterEnemy]->display();
                    enemyArray[counterEnemy]->hp -= projectilePlayerArray[counterProjectiles]->attackDamage;
                    projectilePlayerArray[counterProjectiles]->active = false;
                }
                counterEnemy++;
            }
            counterProjectiles++;
        }
    }
}   //tested

void World::collisionEnemyProjectilesOnObjects() {
    if(!projectileEnemyArray.empty()) {
        int counterProjectiles = 0;
        //go through all projectiles
        for ( auto iterProjectile = projectileEnemyArray.begin(); iterProjectile != projectileEnemyArray.end(); iterProjectile++ ) {

            //check player collision
            if ( projectileEnemyArray[ counterProjectiles ]->rect.getGlobalBounds().intersects(player->rect.getGlobalBounds())) {
                std::cout << "got shoot!" << std::endl;
                player->hp -= projectileEnemyArray[counterProjectiles]->attackDamage;
                player->display();
                projectileEnemyArray[counterProjectiles]->active = false;
            }

            counterProjectiles++;
        }
    }
}

void World::draw() {
    drawMap();

    drawProjectiles();
    drawObjects();
    drawEnemies();
    drawPlayer();

    drawTextDisplayed();
}

void World::drawPlayer() {
    if(!player->dead) {
        window->draw(player->getSprite());
        if(player->barDisplayed) {
            window->draw(player->bar);
            window->draw(player->lifeBar);
        }
    }
}

void World::drawTextDisplayed() {
    if(!textureDisplayArray.empty()) {
        int counter = 0;
        for ( auto iter = textureDisplayArray.begin(); iter != textureDisplayArray.end(); iter++ ) {
            window->draw(textureDisplayArray[ counter ]->text);
            counter++;
        }
    }
}

void World::drawObjects() {
    if(!collectableObject.empty()) {
        int counter = 0;
        for ( auto iter = collectableObject.begin(); iter != collectableObject.end(); iter++ ) {
            if(!collectableObject[counter]->equipped && collectableObject[counter]->active)
                window->draw(collectableObject[ counter ]->getSprite());
            counter++;
        }
    }
}

void World::drawMap() {
    for(int i=0; i<25*25; i++) {
        window->draw(map->tileMap[i]->sprite);
    }
}

void World::drawEnemies() {
    if(!enemyArray.empty()) {
        int counter = 0;
        for ( auto iter = enemyArray.begin(); iter != enemyArray.end(); iter++ ) {
            window->draw(enemyArray[counter]->getSprite());
            if(enemyArray[counter]->barDisplayed) {
                window->draw(enemyArray[counter]->bar);
                window->draw(enemyArray[counter]->lifeBar);
            }
            counter++;
        }
    }
}

void World::handlePlayerInput(sf::Keyboard::Key key, bool isPressed, sf::Clock& shootingClock) {
    if (key == sf::Keyboard::W || key == sf::Keyboard::Up)
        player->isMovingUp = isPressed;
    else if (key == sf::Keyboard::S || key == sf::Keyboard::Down)
        player->isMovingDown = isPressed;
    else if (key == sf::Keyboard::A || key == sf::Keyboard::Left)
        player->isMovingLeft = isPressed;
    else if (key == sf::Keyboard::D || key == sf::Keyboard::Right)
        player->isMovingRight = isPressed;
    else if (key == sf::Keyboard::Q)
        checkCollection();
    else if (key == sf::Keyboard::Space && isPressed) {
        if(shootingClock.getElapsedTime().asSeconds() >= 0.2) {
            useWeapon();
            shootingClock.restart();
        }
    }
    else if (key == sf::Keyboard::Escape && isPressed)
        window->close();
}

void World::checkCollection() {
    if(!collectableObject.empty()) {
        int counterObject = 0;
        //go through all objects
        for ( auto iter = collectableObject.begin(); iter != collectableObject.end(); iter++ ) {
            if ( collectableObject[ counterObject ]->rect.getGlobalBounds().intersects(player->rect.getGlobalBounds())) {
                std::cout << "collecting object" << std::endl;
                player->interactWithObject(collectableObject[ counterObject ]);
            }
            counterObject++;
        }
    }
}

//gets the projectile back in the array of the world and sets the right position
void World::useWeapon() {
    if( player->useWeapon()) {

        std::shared_ptr<RangedStWeapon> mStWeapon = std::dynamic_pointer_cast<RangedStWeapon>(player->weapon);
        if(mStWeapon != nullptr) {
            projectilePlayerArray.emplace_back(std::make_shared<Bullets>(textures, mStWeapon->bulletType));
            projectilePlayerArray.back()->setPosition(player->rect.getPosition(), player->direction);
            projectilePlayerArray.back()->range = player->weapon->range;
        }

        std::shared_ptr<RangedAoeWeapon> mAoeWeapon = std::dynamic_pointer_cast<RangedAoeWeapon>(player->weapon);
        if(mAoeWeapon != nullptr) {
            projectilePlayerArray.emplace_back(std::make_shared<Bullets>(textures, mAoeWeapon->bulletType));
            projectilePlayerArray.back()->setPosition(player->rect.getPosition(), player->direction);
            projectilePlayerArray.back()->range = player->weapon->range;
        }
    }
}

void World::drawProjectiles() {
    if(!projectilePlayerArray.empty()) {
        int counter = 0;
        for ( auto iter = projectilePlayerArray.begin(); iter != projectilePlayerArray.end(); iter++ ) {
            window->draw(projectilePlayerArray[ counter ]->getSprite());
            counter++;
        }
    }
    if(!projectileEnemyArray.empty()) {
        int counter = 0;
        for ( auto iter = projectileEnemyArray.begin(); iter != projectileEnemyArray.end(); iter++ ) {
            window->draw(projectileEnemyArray[ counter ]->getSprite());
            counter++;
        }
    }
}
