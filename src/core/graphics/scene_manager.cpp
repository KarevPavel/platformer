//
// Created by yacopsae on 12/10/2021.
//

#include "scene_manager.hpp"

SceneManager::SceneManager(Engine *engine) : engine(engine) {
}

SceneManager::~SceneManager() = default;

bool SceneManager::addScene(std::unique_ptr<Scene> scene) {
  auto name = scene->getName();
  scene->setEngine(engine);
  scene->init();

  scenes.push_back(std::move(scene));

  return setCurrent(name);
}

bool SceneManager::setCurrent(const std::string &name) {
  for (auto &s : scenes)
	if (s->getName() == name) {
	  current = s.get();
	  return true;
	}

  return false;
}