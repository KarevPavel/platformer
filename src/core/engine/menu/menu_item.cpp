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
        sf::Font font;
        font.loadFromFile(fontName);
        this->font = font;
        this->text = sf::Text{
                sf::String{txt},
                font,
                10
        };
        this->text.setFillColor(fontColor);
        this->position = pos;
        this->selected = isSelected;
        this->nextMenu = nullptr;
        this->action = nullptr;
    }

    void MenuItem::setNextMenu(Menu & menu) {
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

    void MenuItem::setAction(GEngineFn function) {
        this->action = function;
    }

    void MenuItem::setStateChanger(GEngineStateChange stateChanger) {
        this->stateChanger = stateChanger;
    }

    GEngineFn MenuItem::getAction() {
        return action;
    }

    GEngineStateChange MenuItem::getStateChanger() {
        return stateChanger;
    }

    GameEngine::STATE & MenuItem::getChangedState() {
        return changedState;
    }

    void MenuItem::setChangedState(GameEngine::STATE state) {
        changedState = state;
    }

    sf::Text MenuItem::getText() {
        return text;
    }

    bool MenuItem::isSelected() const {
        return selected;
    }

    void MenuItem::isSelected(bool isSelected) {
        selected = isSelected;
    }

    int MenuItem::getPosition() const {
        return position;
    }

    sf::Font MenuItem::getFont() {
        return font;
    }


}
