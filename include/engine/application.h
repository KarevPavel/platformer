//
// Created by yacopsae on 18/08/2021.
//
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include "music_player.hpp"
#include "resource_manager.hpp"
#include "state_stack.hpp"
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
  TextureManager _textures;
  sf::RenderWindow _window;
  SettingsManager settingsManager;
  StateStack _stateList;
};