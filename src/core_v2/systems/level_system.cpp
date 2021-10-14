//
// Created by yacopsae on 13/10/2021.
//

#include <iostream>
#include <SFML/Graphics/Shape.hpp>

#include "game_components.hpp"
#include "level_system.hpp"
#include "engine.hpp"


// TODO: ВООБЩЕ НАФИГ ВСЁ НЕПРАВИЛЬНО!!!!
LevelSystem::LevelSystem() = default;

void LevelSystem::onInit() {
  //eventDispatcher->sink<GameEvent::GameStart>().connect<&LevelSystem::receiveGameStart>(this);
}
/*void LevelSystem::receiveGameStart(const GameEvent::GameStart &event) {
  std::cout << "GameStartEvent!" << std::endl;
  std::cout << "Start loading map" << std::endl;
  LoadFromFile(event.level);
  std::cout << "Finish loading map" << std::endl;


  this->engine->getSceneManager().addScene(std::make_unique<GameScene>());
}*/


void LevelSystem::update(const float dt) {
  auto view = registry->view<GameComponents::Map>();

  auto entity = view.back();
  auto map = view.get<GameComponents::Map>(entity);

  if (map.sprites.empty()) {
	std::cout << "WTF&! spriteList is empty!!!" << std::endl;
  }

  for (const auto &sprite : map.sprites) {
	sprite->getPosition();

	if (sprite->getTexture()->getSize().x > 0) {
	std::cout << "draw sprite at: " << sprite->getPosition().x << ":" << sprite->getPosition().y << std::endl;
	std::cout << "Texture size: " << sprite->getTexture()->getSize().x << ":" << sprite->getTexture()->getSize().y << std::endl;
	engine->getWindow().draw(*sprite);
	}
  }
}