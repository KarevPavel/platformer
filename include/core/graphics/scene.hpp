//
// Created by yacopsae on 12/10/2021.
//


#pragma once

#include <string>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>

#include "resource_manager.hpp"

class Scene {
  std::string name;
 protected:
  TextureManager *textureMng;

  class Engine *engine;
  class SceneManager *sceneMng;
  class sf::RenderWindow *window;

  void handleDefaultEvents(class sf::Event *);

 public:
  Scene(const std::string &name);
  ~Scene();

  void setEngine(Engine *engine);
  inline const std::string &getName() { return name; }

  inline virtual void init() {}
  inline virtual void update() {}
  inline virtual void fixedUpdate(const float dt) {}
  inline virtual void render(const float alpha_lerp) {}
};