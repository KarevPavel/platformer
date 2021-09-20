//
// Created by yacopsae on 18/08/2021.
//
#pragma once

#include <SFML/Graphics.hpp>
#include <state/state_list.hpp>

#include "player_engine.h"
#include "main_menu.h"
#include "menu_engine.h"
#include "game_engine.h"
#include "settings_manager.hpp"
#include "ball.h"
#include "menu_state.hpp"
#include "game_state.hpp"
#include "pause_state.hpp"

class Application {

 public:
  Application();
  int run();
  int start();

 private:
  void configureWindow(sf::RenderWindow &window);
  void processEvents();
  void update(sf::Time deltaTime);
  void render();
  sf::RenderWindow _window;
  SettingsManager settingsManager;
  StateList _stateList;
};