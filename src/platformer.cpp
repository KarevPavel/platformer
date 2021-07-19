#include <SFML/Graphics.hpp>
#include "core/models/main_menu.cpp"
#include "core/engine/menu_engine.h"

#include "test.cpp"
#include "core/models/Player.cpp"
#include "core/models/BallKeyBoard.h"

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
	sf::RenderWindow window({600, 600}, "TestMe", sf::Style::Default, settings);
    configureWindow(window);
    core::models::MainMenu menu(window);
    core::engine::GameEngine gameEngine{};
    core::engine::MenuEngine menuEngine(menu, gameEngine, window);

    PlayerModel playerModel{window};
    Player player{playerModel};
    sf::Clock clock;
    sf::Event event{};


    float x,y, oX, oY, r;
    x = 60;
    y = 60;
    r = 40;
    oX = x + r;
    oY = y + r;
    Ball ball{ x, y, oX, oY, r, 80, 90, window };
    BallKeyBoard ballkb{ ball };

    while (window.isOpen() && window.waitEvent(event)) {
        auto elapsed = clock.getElapsedTime().asSeconds();
        switch (event.type) {
            case sf::Event::EventType::KeyPressed:
                if(currentState == STATE::MENU) {
                    ballkb.processEvent(event.key);
                    //menuEngine.processEvent(event.key);
                    //player.processEvent(event.key, elapsed);
                }
                if(currentState == STATE::GAME)
                    player.processEvent(event.key, elapsed);
                break;
            case sf::Event::EventType::Closed:
                window.close();
                break;
            default:
                break;
        }
        window.display();
    }
	return 0;
}

//TODO: READ CFG FILES, THEM CONFIGURE WINDOW
void configureWindow(sf::RenderWindow &window){
    window.setVerticalSyncEnabled(true);
}
