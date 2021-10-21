//
// Created by yacopsae on 12/10/2021.
//

#include "engine.hpp"
#include "menu_scene.hpp"

Engine::Engine() : scene_manager(this) {
  window.create(sf::VideoMode(1600, 900), "Platformer");
}

Engine::~Engine() {

}

void Engine::stop() { isRunning = false; }

void Engine::start() {
  //поменял на MenuScene
  scene_manager.addScene(std::make_unique<MenuScene>());

  sf::Clock clock;

  auto frameTimeElapsed = sf::Time::Zero;
  auto TIME_PER_FRAME = sf::seconds(1.f / 60.f);

  while (isRunning) {
	auto scene = scene_manager.getCurrent();

	scene->update();
	frameTimeElapsed += clock.restart();

	while (frameTimeElapsed > TIME_PER_FRAME) {

	  frameTimeElapsed -= TIME_PER_FRAME;
	  scene->fixedUpdate(TIME_PER_FRAME.asSeconds());
	}
	scene->render(TIME_PER_FRAME.asSeconds());
  }
}
