//
// Created by yacopsae on 12/10/2020.
//

#ifndef PLATFORMER_MENU_ITEM_H
#define PLATFORMER_MENU_ITEM_H
#include "SFML/Graphics.hpp"
#include <iostream>
#include <list>
#include <queue>
#include <utility>
#include <deque>
#include "constants.h"
#include "keyboard.cpp"
#include "menu.h"
#include "game_engine.h"

namespace core::engine {

    class MenuItem {

    public:
        explicit MenuItem(const std::string &txt, int pos, bool isSelected = false) : MenuItem(txt, pos,
                                                                                               core::engine::menu::DEFAULT_FONT_COLOR,
                                                                                               isSelected) {}

        MenuItem(const std::string &txt, int pos, sf::Color fontColor, bool isSelected = false) : MenuItem(txt, pos,
                                                                                                           fontColor,
                                                                                                           core::engine::menu::DEFAULT_FONT_NAME,
                                                                                                           isSelected) {}

        MenuItem(const std::string &txt, int pos, sf::Color fontColor, const std::string &fontName,
                 bool isSelected = false);

        sf::Text getText() const {
            return text;
        }

        bool isSelected() const {
            return selected;
        }

        void isSelected(bool isSelected) {
            selected = isSelected;
        }

        int getPosition() const {
            return position;
        }

        struct MenuItemComparator {
            bool operator()(const MenuItem &menuItem1, const MenuItem &menuItem2) {
                return menuItem1.position < menuItem2.position;
            }
        };

        void setNextMenu(Menu &menu);

        bool hasSubmenu();

        void showNextMenu();

        void setAction(GEngineFn function);

        GEngineFn getAction();


    private:
        sf::Text text;
        bool selected;
        int position;
        Menu *nextMenu{};
        GEngineFn action;
    };
}
#endif //PLATFORMER_MENU_ITEM_H
