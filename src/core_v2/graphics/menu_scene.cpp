//
// Created by yacopsae on 12/10/2021.
//

#include <textures.hpp>
#include <sound.hpp>
#include <sound_system.hpp>
#include "menu_scene.hpp"
#include "engine.hpp"
#include "main_menu_music_start_event.hpp"

MenuScene::MenuScene() : Scene("menu") {
}

MenuScene::~MenuScene() {
}

void MenuScene::init() {
  em.init(engine);

  em.addSystem(std::make_unique<SoundSystem>());

  background_texture.setTexture(textureMng->getResource(constants::BLACK_PATH));
  background_texture
	  .setTextureRect(sf::IntRect(0, 0, engine->getWindow().getSize().x, engine->getWindow().getSize().y));

  em.getEventDispatcher()->trigger<GameEvent::MusicStart>(constants::MAIN_MENU_PATH);

}

sf::Vector2f MenuScene::getMousePosition() {
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

void MenuScene::render(const float alpha_lerp) {
  window->clear(sf::Color(83, 83, 83));
  window->draw(background_texture);
  em.onRender(alpha_lerp);

  window->display();
}