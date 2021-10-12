//
// Created by yacopsae on 12/10/2021.
//

#pragma once

#include <vector>
#include <memory>
#include "scene.hpp"

class SceneManager {
  std::vector<std::unique_ptr<Scene>> scenes;
  Scene *current = nullptr;

  class Engine *engine;
 public:
  explicit SceneManager(Engine *engine);
  ~SceneManager();

  bool addScene(std::unique_ptr<Scene> scene);
  bool setCurrent(const std::string &name);

  inline Scene *getCurrent() { return current; }
};


