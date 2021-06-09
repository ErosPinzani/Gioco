//
// Created by erosp on 03/06/2021.
//

#include "..\Include\Game.h"


const sf::Time Game::TimePerFrame = sf::seconds(1.f / 80.f);

Game::Game() : mWindow(new sf::RenderWindow(sf::VideoMode(1500, 850), "Berto's Adventure", sf::Style::Default)), mFont(),mStatisticsText(), mStatisticsUpdateTime(),mStatisticsNumFrames(0) {
    //startMenu(mWindow->getSize().x, mWindow->getSize().y )

    loadTextures();
    //loadSound();

    view = std::make_shared<sf::View>(sf::Vector2f(0, 0), sf::Vector2f(400, 400));

    mWindow->setView(*view);


/*
    //view
    sf::View view1(sf::FloatRect(200, 200, 300, 200));
    view1.setSize(sf::Vector2f(mWindow->getSize().x, mWindow->getSize().y));
    view1.setCenter(sf::Vector2f(view1.getSize().x/2, view1.getSize().y/2));
    mWindow->setView(view1);

    //hero view
    mWindow->setView(view1);
    view1.setCenter(Hero1.rect.getPosition());
*/

    world = std::make_shared<World>(mWindow, textureHolder);
    /*
    mFont =  world->mainFont;
    startMenu = std::make_shared<Menu>(mWindow);
    startMenu->height = mWindow->getSize().y;
    startMenu->width = mWindow->getSize().x;
    sf::Text playText;
    playText.setFont(mFont);
    playText.setString("Play");
    playText.setCharacterSize(50);
    playText.setFillColor(sf::Color::White);
    playText.setPosition(mWindow->getSize().x/2.f, mWindow->getSize().y/4.f);
    startMenu->choicesVector.emplace_back(playText);
    sf::Text quitText;
    quitText.setFont(mFont);
    quitText.setString("Quit");
    quitText.setPosition(mWindow->getSize().x/2.f, mWindow->getSize().y/4.f + 200);
    startMenu->choicesVector.emplace_back(quitText);
    */


    //sets the icon
    sf::Image icon;

    if ( !icon.loadFromFile("???"))
        throw std::runtime_error("icon not loaded");
    mWindow->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

}

void Game::play() {
    sf::Clock clock;
    sf::Clock shootingClock;
    sf::Time shootingTime = shootingClock.restart();
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow->isOpen()) {

        //  int choice = processMenuEvents();

        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents(shootingClock);
            update(elapsedTime);
        }

        //frame of the game
        render();
    }
}

void Game::render() {
    mWindow->clear();
    mWindow->setView(*view);

    //startMenu->draw();
    world->draw();

    mWindow->display();
}

int Game::processMenuEvents() {
    sf::Event event;
    while (mWindow->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyReleased:
                if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    startMenu->moveUp();
                } else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    startMenu->moveDown();
                } else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                    /*
                    if (startMenu->getPressedChoice() == 0) {
                        std::cout << "Play button pressed" << std::endl;
                        //metto return 1 e poi in Game::run imposto che processEvent viene attivato solo se ha w
                        return 1;
                    }
                    if (startMenu->getPressedChoice() == 1)
                        return 0;
                    */

                    return startMenu->getPressedChoice();
                }
                break;
            case sf::Event::Closed:
                mWindow->close();
                break;
            default:
                break;
        }
    }
    return 0;
}

/*
  while(mWindow->pollEvent(event){
    switch(event.type){
        case sf::Event::KeyReleased:
            if(sf::Keyboard::Up)
                menu.moveUp();
            if(sf::Keyboard::Down)
                menu.moveUp();
            break;
        case sf::Event::Return:
            if(getPressedChoice() == 0){
                std::cout << "Play button pressed" << std::endl;
                //metto return 1 e poi in Game::run imposto che processEvent viene attivato solo se ha w
            }
            if(getPressedChoice() == 1){
                std::cout << "Play button pressed" << std::endl;
            }
            if(getPressedChoice() == 2)
                mWindow->close();
            break;
        case sf::Event::Closed:
            mWindow->close();
            break;
        default:
            break;
    }
  }
 */

void Game::processEvents(sf::Clock &shootingClock) {

    sf::Event event;
    while (mWindow->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                mWindow->close();
                break;
            case sf::Event::KeyPressed:
                world->handlePlayerInput(event.key.code, true, shootingClock);
                break;
            case sf::Event::KeyReleased:
                world->handlePlayerInput(event.key.code, false, shootingClock);
                break;
            default:
                break;
        }
    }

}

void Game::update(sf::Time deltaTime) {
    world->update(deltaTime);
    view->setCenter(world->hero->rect.getPosition());
    view->setSize(sf::Vector2f(mWindow->getSize().x / 2, mWindow->getSize().y / 2));
}

void Game::loadTextures() {

    textureHolder.load(Textures::???, "???");

}
/*
void Game::loadSound() {

    if(!soundBuffer.loadFromFile("Media/SoundEffects/energyShot"))
        std::cout<<"error - sound not loaded"<<std::endl;
    sound.setBuffer(soundBuffer);
    sound.play();

}
*/