//
// Created by yacopsae on 12/10/2021.
//

#include <textures.hpp>
#include <sound.hpp>
#include <sound_system.hpp>
#include <game_system.hpp>
#include <game_scene.hpp>
#include "menu_scene.hpp"
#include "engine.hpp"

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

  em.getEventDispatcher()->trigger<SoundEvent::MusicStart>(constants::MAIN_MENU_PATH);

}

sf::Vector2f MenuScene::getMousePosition() {
  return static_cast<sf::Vector2f>(sf::Mouse::getPosition(engine->getWindow()));
}

void MenuScene::update() {
  sf::Event event;
  while (window->pollEvent(event)) {
	handleDefaultEvents(&event);

	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
	  this->engine->getSceneManager().addScene(std::make_unique<GameScene>());
	}
  }
}

void MenuScene::fixedUpdate(const float dt) {
  em.onUpdate(dt);
}

void MenuScene::render(const float alpha_lerp) {
  window->clear(sf::Color(255, 255, 255));
  window->draw(background_texture);
  em.onRender(alpha_lerp);

  window->display();
}