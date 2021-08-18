//
// Created by yacopsae on 09/10/2020.
//

#include <main_menu.h>

namespace core::models {

    MainMenu::MainMenu(sf::RenderWindow &window) : Menu(window) {
        std::string str = "New game";
        auto menuItem = core::engine::MenuItem(str, 1, true);
        auto newGameAction = &engine::GameEngine::StartNewGame;
        menuItem.setAction(newGameAction);
        addItem(menuItem);

        std::string str3 = "Exit";
        auto menuItem2 = core::engine::MenuItem(str3, 3);
        addItem(menuItem2);

        std::string str1 = "Options";
        auto menuItem1 = core::engine::MenuItem(str1, 2);

        addItem(menuItem1);
    }
}