//
// Created by yacopsae on 12/10/2021.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "scene_manager.hpp"
#include "resource_manager.hpp"

class Engine {
  bool isRunning = true;

  sf::RenderWindow window;
  SceneManager sceneMng;
  TextureManager textureMng;
 public:
  Engine();
  ~Engine();

  void start();
  void stop();

  inline sf::RenderWindow &getWindow() { return window; }
  inline SceneManager &getSceneManager() { return sceneMng; }
  inline TextureManager &getTextureManager() { return textureMng; }
};


