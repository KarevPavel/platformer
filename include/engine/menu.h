//
// Created by yacopsae on 04/10/2020.
//

#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <list>
#include <queue>
#include <utility>
#include <deque>
#include <constants.h>
#include <keyboard.h>
#include <menu_item.h>

namespace core::engine {

class MenuItem;

enum VerticalAlign {
  TOP,
  MID,
  BOTTOM
};

enum HorizontalAlign {
  LEFT,
  CENTER,
  RIGHT,
};

const VerticalAlign DEFAULT_V_ALIGN = VerticalAlign::MID;
const HorizontalAlign DEFAULT_H_ALIGN = HorizontalAlign::CENTER;

class Menu {

 public:

  explicit Menu(sf::RenderWindow &window) : Menu(window, DEFAULT_H_ALIGN, DEFAULT_V_ALIGN) {}

  Menu(sf::RenderWindow &window, HorizontalAlign hAlign, VerticalAlign vAlign);

  void draw();

  void addItem(const MenuItem &menuItem);

  void selectNext();

  std::_List_iterator<MenuItem> findSelected();

  void selectPrev();

  void setPrevMenu(Menu &menu);

 private:
  bool itemsIsSorted;
  HorizontalAlign hAlign;
  VerticalAlign vAlign;
  std::list<MenuItem> items;
  sf::RenderWindow &window;
  Menu *prevMenu;

  unsigned int calcXPos(sf::Vector2u &vector2U, int xDelta);

  unsigned int calcYPos(sf::Vector2u &vector2U, int delta);
};
}