#include "keyboard.cpp"
#include "SFML/Graphics.hpp"
#include "menu.h"
#include "menu_item.h"

namespace core::engine {

    Menu::Menu(sf::RenderWindow &window, HorizontalAlign hAlign, VerticalAlign vAlign) : window(window), vAlign(vAlign),
                                                                                         hAlign(hAlign),
                                                                                         itemsIsSorted(false) {
        this->items = std::list<MenuItem>();
    }

    void Menu::draw() {
        sf::Font font;
        font.loadFromFile(core::engine::menu::DEFAULT_FONT_NAME);
        if(!itemsIsSorted) {
            items.sort(MenuItem::MenuItemComparator());
        }
        int delta(0);
        for (auto & it : items) {
            auto text = it.getText();
            auto vector2 = window.getSize();
            if (it.isSelected()) {
                text.setFillColor(sf::Color::Red);
            }
            text.setFont(font);

            text.setString(text.getString());
            auto cSize = text.getCharacterSize();
            unsigned int lenghtPx = cSize * text.getString().getSize();
            text.setPosition(calcXPos(vector2, lenghtPx), calcYPos(vector2, delta));
            delta += (cSize + (cSize / 2));
            window.draw(text);
        }
    }

    void Menu::selectNext() {
        auto it = findSelected();
        it->isSelected(false);
        it++;
        if (it == items.end()) items.begin()->isSelected(true);
        else it->isSelected(true);
    }

    std::_List_iterator<MenuItem> Menu::findSelected() {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->isSelected()) {
                return it;
            }
        }
    }

    void Menu::addItem(const MenuItem &menuItem) {
        items.push_back(menuItem);
        itemsIsSorted = false;
    }

    void Menu::selectPrev() {
        auto it = findSelected();
        it->isSelected(false);
        auto t = items.begin();
        if (it == items.begin()) {
            it = items.end();
            it--;
            it->isSelected(true);
        } else {
            --it;
            it->isSelected(true);
        }
    }

    void Menu::setPrevMenu(Menu &menu){
        this->prevMenu = &menu;
    }

    unsigned int Menu::calcYPos(sf::Vector2u &vector2U, int delta = 0) {
        if (vAlign == VerticalAlign::TOP)
            return 0 + delta;

        if (vAlign == VerticalAlign::MID)
            return vector2U.y / 2 + delta;

        if (vAlign == VerticalAlign::BOTTOM)
            return vector2U.y + delta;

        return 0;
    }

    unsigned int Menu::calcXPos(sf::Vector2u &vector2U, int xDelta) {
        if (hAlign == HorizontalAlign::LEFT)
            return 0 + xDelta/2;

        if (hAlign == HorizontalAlign::CENTER)
            return (vector2U.x - xDelta)/2;

        if (hAlign == HorizontalAlign::RIGHT)
            return vector2U.x - xDelta/2;

        return 0;
    }
}