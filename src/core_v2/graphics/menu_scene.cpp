//
// Created by yacopsae on 12/10/2021.
//

#include "menu_scene.hpp"
#include "engine.hpp"

MenuScene::MenuScene() : Scene("menu") {

}

MenuScene::~MenuScene() {
}


void MenuScene::init() {
  em.init(engine);

}


sf::Vector2f MenuScene::getMousePosition()
{
  return static_cast<sf::Vector2f>(sf::Mouse::getPosition(engine->getWindow()));
}


void MenuScene::update() {
  sf::Event event;
  while (window->pollEvent(event)) {
	handleDefaultEvents(&event);
  }
}

void MenuScene::fixedUpdate(const float dt) {
  em.onUpdate(dt);
}

void MenuScene::render(const float alpha_lerp)
{
  window->clear(sf::Color(83, 83, 83));

  em.onRender(alpha_lerp);

  window->display();
}