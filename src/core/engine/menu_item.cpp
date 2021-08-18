//
// Created by yacopsae on 12/10/2020.
//

#include <menu_item.h>

namespace core::engine {

    MenuItem::MenuItem(const std::string &txt,
                       const int pos,
                       const sf::Color fontColor,
                       const std::string &fontName,
                       const bool isSelected) {
        this->text.setString(txt);
        this->text.setFillColor(fontColor);
        this->position = pos;
        sf::Font font;
        font.loadFromFile(fontName);
        this->text.setFont(font);
        this->selected = isSelected;
    }


    void MenuItem::setNextMenu(Menu &menu) {
        this->nextMenu = &menu;
    }

    bool MenuItem::hasSubmenu() {
        if (nextMenu == nullptr)
            return false;
        return true;
    }

    void MenuItem::showNextMenu() {
        nextMenu->draw();
    }

    void MenuItem::setAction(GEngineFn function){
        this->action = function;
    }

    GEngineFn MenuItem::getAction(){
        return action;
    }

}