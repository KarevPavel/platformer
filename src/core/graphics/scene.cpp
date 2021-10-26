//
// Created by yacopsae on 12/10/2021.
//

#include "scene.hpp"
#include "engine.hpp"

Scene::Scene(const std::string &name) : name(name) {
}

Scene::~Scene() {
}

void Scene::setEngine(Engine *engine) {
  this->engine = engine;

  window = &engine->getWindow();
  sceneMng = &engine->getSceneManager();
}

void Scene::handleDefaultEvents(sf::Event *event) {
  if (event->type == sf::Event::Closed ||
	  (event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Escape))
	engine->stop();
  else if (event->type == sf::Event::Resized)
    engine->getWindow().setView(engine->getWindow().getView());


  // todo handle here resizing window and black border bars for resolution
}