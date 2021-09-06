//
// Created by yacopsae on 18/08/2021.
//


#include <applcation.h>

static core::engine::GameEngine::STATE currentState = core::engine::GameEngine::STATE::MENU;

void Application::configureWindow(sf::RenderWindow &window) {
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
}

int Application::start() {

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window({1280, 1024}, "TestMe", sf::Style::Default);

    configureWindow(window);

    core::models::MainMenu menu(window);
    core::engine::GameEngine gameEngine{currentState, window, core::engine::game::FIRST_LEVEL};
    core::engine::MenuEngine menuEngine(menu, gameEngine, window);

    PlayerModel playerModel { window };
    core::engine::PlayerEngine player{playerModel};
    sf::Clock clock;

    float x, y, oX, oY, r;
    x = 400;
    y = 400;
    r = 10;
    oX = x + r;
    oY = y + r;
    ball ball{
            x,
            y,
            oX,
            oY,
            r,
            120,
            30,
            window
    };

    while (window.isOpen()) {

        auto elapsed = clock.getElapsedTime();
        float time = elapsed.asMicroseconds(); //дать прошедшее время в микросекундах
        clock.restart(); //перезагружает время
        time = time / 800; //скорость игры
        sf::Time t;
        t.asMicroseconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        window.clear();
        if (currentState == core::engine::GameEngine::STATE::MENU) {
            menuEngine.update(event.key);
        }

        if (currentState == core::engine::GameEngine::STATE::GAME) {
            //gameEngine.startNewGame(window);
            gameEngine.update(elapsed);
            ball.update(elapsed);
        }

        //ball.update(event, time);
        window.display();
    }

    return 0;
}