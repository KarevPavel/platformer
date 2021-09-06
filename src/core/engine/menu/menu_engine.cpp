//
// Created by yacopsae on 12/10/2020.
//
#include <menu_engine.h>

namespace core::engine {

    void MenuEngine::Escape_click() {
        prevMenu->draw();
    }

    void MenuEngine::S_click() {
        control.selectNext();
    }

    void MenuEngine::W_click() {
        control.selectPrev();
    }

    void MenuEngine::Down_click() {
        control.selectNext();
    }

    void MenuEngine::Up_click() {
        control.selectPrev();
    }

    void MenuEngine::update(sf::Event::KeyEvent keyevent) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            S_click();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            W_click();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            A_click();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            D_click();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            Enter_click();
        }
        control.draw();
    }

    void MenuEngine::Enter_click() {
        auto selected = control.findSelected();

        if (selected->hasSubmenu()) {
            prevMenu = &control;
            selected->showNextMenu();
        }

        auto stateChange = selected->getStateChanger();
        if (stateChange != nullptr) {
            std::invoke(stateChange, gameEngine, selected->getChangedState());
        }

        auto func = selected->getAction();
        if (func != nullptr) {
            std::invoke(func, gameEngine, window);
        }
    }
}