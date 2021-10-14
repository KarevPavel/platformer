//
// Created by yacopsae on 13/10/2021.
//

#include <scene.hpp>
#include <sound_system.hpp>
#include <level_system.hpp>
#include <levels.hpp>
#include <game_system.hpp>
#include "game_scene.hpp"

GameScene::GameScene() : Scene("game") {

}

GameScene::~GameScene() = default;

void GameScene::init() {
  em.init(engine);


  em.addSystem(std::make_unique<GameSystem>());

  em.addSystem(std::make_unique<SoundSystem>());

  em.getEventDispatcher()->trigger<GameEvent::GameStart>(constants::LEVEL1_PATH);

  em.addRenderSystem(std::make_unique<LevelSystem>());

  em.getEventDispatcher()->trigger<SoundEvent::MusicStop>();
}

void GameScene::update() {

}

void GameScene::fixedUpdate(const float dt) {
  em.onUpdate(dt);
}

void GameScene::render(const float alpha_lerp) {
  window->clear(sf::Color(255, 255, 255));

  em.onRender(alpha_lerp);

  window->display();
}

