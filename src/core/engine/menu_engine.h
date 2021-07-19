//
// Created by yacopsae on 12/10/2020.
//

#ifndef PLATFORMER_MENU_ENGINE_H
#define PLATFORMER_MENU_ENGINE_H

#include "keyboard.cpp"
#include "menu.h"
#include "game_engine.h"

namespace core::engine {

    class MenuEngine : public core::keyboard::KeyboardEngine<Menu> {

    public:
        MenuEngine(Menu &menu, GameEngine &gameEngine,  sf::RenderWindow &window) : KeyboardEngine(menu), gameEngine(gameEngine), window(window){}

        void S_click() override;

        void W_click() override;

        void Down_click() override;

        void Up_click() override;

        void Enter_click() override;

        void Escape_click() override;

    private:
        Menu *prevMenu;
        GameEngine &gameEngine;
        sf::RenderWindow &window;
    };

}
#endif //PLATFORMER_MENU_ENGINE_H
