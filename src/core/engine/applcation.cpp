//
// Created by yacopsae on 18/08/2021.
//


#include <applcation.h>
#include <player_model.h>
#include <player.h>
#include <player_engine.h>

enum STATE {
    MENU,
    GAME
};

static STATE currentState = MENU;

void Application::configureWindow(sf::RenderWindow &window) {
    window.setVerticalSyncEnabled(true);
}

int Application::start() {

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window({1800, 1000}, "TestMe", sf::Style::Default, settings);
    configureWindow(window);
    window.setFramerateLimit(60);
    core::models::MainMenu menu(window);
    core::engine::GameEngine gameEngine{};
    core::engine::MenuEngine menuEngine(menu, gameEngine, window);

    player_model playerModel{window};
    core::engine::PlayerEngine player{playerModel};
    sf::Clock clock;

    level1 lvl{window};

    float x, y, oX, oY, r;
    x = 60;
    y = 60;
    r = 40;
    oX = x + r;
    oY = y + r;
    ball ball{
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
        time = time / 800; //скорость игры

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        if (currentState == STATE::MENU) {

        }

        ball.processEvent(event, time);
        window.display();
    }

    return 0;
}