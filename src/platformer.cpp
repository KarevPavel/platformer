#include <SFML/Graphics.hpp>
#include "core/models/main_menu.cpp"
#include "core/engine/menu_engine.h"

#include "test.cpp"
#include "core/models/Player.cpp"
#include "core/models/Ball.h"
#include "core/levels/level1.h"

void configureWindow(sf::RenderWindow &window);

enum STATE {
    MENU,
    GAME
};

static STATE currentState = MENU;

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
	sf::RenderWindow window({1800, 1000}, "TestMe", sf::Style::Default, settings);
    configureWindow(window);
    window.setFramerateLimit(60);
    core::models::MainMenu menu(window);
    core::engine::GameEngine gameEngine{};
    core::engine::MenuEngine menuEngine(menu, gameEngine, window);

    PlayerModel playerModel{window};
    Player player{playerModel};
    sf::Clock clock;

    level1 lvl { window };

    float x,y, oX, oY, r;
    x = 60;
    y = 60;
    r = 40;
    oX = x + r;
    oY = y + r;
    Ball ball{
            x,
            y,
            oX,
            oY,
            r,
            120,
            300,
            lvl,
            window
    };

    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
        clock.restart(); //перезагружает время
        time = time/800; //скорость игры

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }
        ball.processEvent(event, time);
        window.display();

        /*while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            switch (event.type) {
                case sf::Event::EventType::KeyPressed:
                    if(currentState == STATE::MENU) {
                        ball.processEvent(event, time);


                        //menuEngine.processEvent(event.key);
                        //player.processEvent(event.key, elapsed);
                    }
                    if(currentState == STATE::GAME)
                        player.processEvent(event.key, time);
                    break;
                case sf::Event::EventType::Closed:
                    window.close();
                    break;
                default:
                    break;
            }

            window.display();
        }*/
    }
	return 0;
}

//TODO: READ CFG FILES, THEM CONFIGURE WINDOW
void configureWindow(sf::RenderWindow &window) {
    window.setVerticalSyncEnabled(true);
}


