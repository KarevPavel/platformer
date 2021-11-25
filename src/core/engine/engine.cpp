//
// Created by yacopsae on 12/10/2021.
//

#include "engine.hpp"

#include <box2d/b2_world.h>

#include "menu_scene.hpp"
#include "debug_box_2_d.hpp"

Engine::Engine() : sceneManager(this),
				   box2DWorld(b2Vec2(0.f, 9.8f)),
				   debugDraw(window),
				   contactSystem(),
				   textureManager(),
				   imageManager(),
				   fontManager() {
  window.create(sf::VideoMode(1920, 1080), "Platformer", sf::Style::Default);

  debugDraw.SetFlags(b2Draw::e_shapeBit | b2Draw::e_centerOfMassBit);

  box2DWorld.SetContactListener(&contactSystem);
  //box2DWorld.SetDebugDraw(&debugDraw);
  window.setView(view);
}

Engine::~Engine() {

}

void Engine::stop() { isRunning = false; }

void Engine::start() {

  sceneManager.addScene(std::make_unique<MenuScene>());

  sf::Clock clock;

  auto frameTimeElapsed = sf::Time::Zero;
  auto TIME_PER_FRAME = sf::seconds(1.f / 60.f);

  while (isRunning) {
	auto scene = sceneManager.getCurrent();

	scene->update();
	frameTimeElapsed += clock.restart();

	while (frameTimeElapsed > TIME_PER_FRAME) {

	  frameTimeElapsed -= TIME_PER_FRAME;
	  scene->fixedUpdate(TIME_PER_FRAME.asSeconds());
	}
	scene->render(TIME_PER_FRAME.asSeconds());
  }
}
