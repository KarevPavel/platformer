//
// Created by yacopsae on 12/10/2021.
//

#include "engine.hpp"
#include "menu_scene.hpp"

Engine::Engine() : sceneMng(this)
{
  window.create(sf::VideoMode(800, 600), "randballs");
}


Engine::~Engine()
{

}

void Engine::stop() { isRunning = false; }

void Engine::start()
{
  //поменял на MenuScene
  sceneMng.addScene(std::make_unique<MenuScene>());

  sf::Clock clock;

  auto frameTimeElapsed = sf::Time::Zero;
  auto TIME_PER_FRAME = sf::seconds(1.f / 20.f);

  while (isRunning) {
	auto scene = sceneMng.getCurrent();

	scene->update();
	frameTimeElapsed += clock.restart();

	while (frameTimeElapsed > TIME_PER_FRAME) {

	  frameTimeElapsed -= TIME_PER_FRAME;
	  scene->fixedUpdate(TIME_PER_FRAME.asSeconds());
	}
	scene->render(TIME_PER_FRAME.asSeconds());
  }
}