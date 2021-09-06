//
// Created by yacopsae on 12/10/2020.
//

#pragma once

#include "keyboard.h"
#include "menu.h"
#include "game_engine.h"

namespace core::engine {

    class MenuEngine : public core::keyboard::KeyboardEngine<Menu> {

    public:
        MenuEngine(Menu &menu, GameEngine &gameEngine, sf::RenderWindow &window) : KeyboardEngine(menu),
                                                                                   gameEngine(gameEngine),
                                                                                   window(window) {
            sf::View view{};
            view.setSize(250, 250);
            view.setCenter(window.getSize().x / 2, window.getSize().y / 2);
            window.setView(view);
        }

        void S_click() override;

        void W_click() override;

        void Down_click() override;

        void Up_click() override;

        void Enter_click() override;

        void Escape_click() override;

        void update(sf::Event::KeyEvent keyevent) override;

    private:
        Menu *prevMenu;
        GameEngine &gameEngine;
        sf::RenderWindow &window;
    };
}