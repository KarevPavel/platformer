//
// Created by yacopsae on 12/10/2021.
//

#include "engine.hpp"

#include <box2d/b2_world.h>

#include "menu_scene.hpp"
#include "debug_box_2_d.hpp"


Engine::Engine() : scene_manager(this), box2DWorld(b2Vec2(0.f, 9.8f)), debugDraw(window) {
  window.create(sf::VideoMode(1600, 900), "Platformer");
  auto test = debugDraw.GetFlags();
  box2DWorld.SetDebugDraw(debugDraw);
}

Engine::~Engine() {

}

void Engine::stop() { isRunning = false; }

void Engine::start() {

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