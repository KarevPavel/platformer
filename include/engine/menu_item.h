//
// Created by yacopsae on 12/10/2020.
//

#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <list>
#include <queue>
#include <utility>
#include <deque>
#include <keyboard.h>
#include <menu.h>
#include <game_engine.h>

namespace core::engine {

    class Menu;

    class MenuItem {

    public:
        explicit MenuItem(const std::string &txt, int pos, bool isSelected = false) : MenuItem(txt, pos,
                                                                                               sf::Color::White,
                                                                                               isSelected) {}

        MenuItem(const std::string &txt, int pos, sf::Color fontColor, bool isSelected = false) : MenuItem(txt, pos,
                                                                                                           fontColor,
                                                                                                           "/home/yacopsae/CLionProjects/platformer/resources/fonts/LiberationMono-Bold.ttf",
                                                                                                           isSelected) {}

        MenuItem(const std::string &txt,
                 int pos,
                 sf::Color fontColor,
                 const std::string & fontName,
                 bool isSelected = false);

        bool operator()(const MenuItem &menuItem1, const MenuItem &menuItem2) {
            return menuItem1.getPosition() < menuItem2.getPosition();
        }

        friend bool operator<(const MenuItem& l, const MenuItem& r) {
            return l.getPosition() < r.getPosition();
        }

        sf::Text getText();

        bool isSelected() const;

        int getPosition() const;

        void setNextMenu(Menu & menu);

        bool hasSubmenu();

        void showNextMenu();

        void setAction(GEngineFn function);

        GEngineFn getAction();

        void setStateChanger(GEngineStateChange stateChanger);

        GEngineStateChange getStateChanger();

        void isSelected(bool isSelected);

        sf::Font getFont();

        GameEngine::STATE & getChangedState();

        void setChangedState(GameEngine::STATE state);

    private:
        sf::Text text;
        bool selected;
        int position;
        Menu * nextMenu;
        sf::Font font;
        GEngineFn action;
        GEngineStateChange stateChanger;
        GameEngine::STATE changedState;
    };
}