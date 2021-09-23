//
// Created by yacopsae on 18/08/2021.
//
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <manager/font_manager.hpp>
#include <manager/music_manager.hpp>
#include "state_list.hpp"
#include "settings_manager.hpp"

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

  FontManager _fonts;
  MusicPlayer _music;
  sf::RenderWindow _window;
  SettingsManager settingsManager;
  StateList _stateList;
};