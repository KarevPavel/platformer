//
// Created by yacopsae on 09/10/2020.
//

#include <main_menu.h>

namespace core::models {

    MainMenu::MainMenu(sf::RenderWindow &window) : Menu(window) {
        std::string str = "New game";
        auto menuItem = core::engine::MenuItem(str, 10, true);
        auto newGameAction = &engine::GameEngine::startNewGame;
        menuItem.setAction(newGameAction);
        addItem(menuItem);

        std::string str3 = "Exit";
        auto menuItem2 = core::engine::MenuItem(str3, 30);
        auto exitGameAction = &engine::GameEngine::exitGame;
        menuItem2.setAction(exitGameAction);
        addItem(menuItem2);

        std::string str1 = "Options";
        auto menuItem1 = core::engine::MenuItem(str1, 20);
        addItem(menuItem1);
    }
}