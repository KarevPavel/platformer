//
// Created by yacopsae on 18/08/2021.
//

#include "applcation.h"

static core::engine::GameEngine::STATE currentState = core::engine::GameEngine::STATE::MENU;

Application::Application() : _window() {
  configureWindow(_window);
  _stateList.add<MenuState>(_window);
  _stateList.add<GameState>(_window);
  _stateList.add<PauseState>(_window);
}

void Application::configureWindow(sf::RenderWindow &window) {
  window.setVerticalSyncEnabled(settingsManager.verticalSync());
  window.setFramerateLimit(settingsManager.frameLimit());

  sf::ContextSettings settings{
	  0,
	  0,
	  settingsManager.antialiasingLevel()
  };;
  window.create(settingsManager.videoMode(), "Test title", sf::Style::Titlebar | sf::Style::Close, settings);
}

int Application::run() {
  sf::Clock clock;
  auto frameTimeElapsed = sf::Time::Zero;

  auto timePerFrame = sf::seconds(1.f / settingsManager.timePerFrame());

  while (_window.isOpen()) {
	frameTimeElapsed += clock.restart();
	while (frameTimeElapsed > timePerFrame) {
	  // Update world no more than 60 frames per seconds
	  frameTimeElapsed -= timePerFrame;
	  processEvents();
	  update(timePerFrame);
	}
	render();
  }
  return 0;
}

void Application::processEvents() {
  sf::Event event;
  while (_window.pollEvent(event)) {
	if (event.type == sf::Event::Closed)
	  _window.close();
	//_stateList.handleEvent(event);
  }
}

void Application::update(sf::Time deltaTime) {
  _stateList.update(deltaTime);
}

void Application::render() {
  // before drawing anything clean
  // the previous frame
  _window.clear();

  // draw the application
  _stateList.draw(_window, sf::Transform::Identity);

  // display to the _window
  _window.display();
}

int Application::start() {
  configureWindow(this->_window);

  float x, y, oX, oY, r;
  x = 400;
  y = 400;
  r = 10;
  oX = x + r;
  oY = y + r;
  Ball ball{
	  x,
	  y,
	  oX,
	  oY,
	  r,
	  120,
	  30,
	  _window
  };

  core::models::MainMenu menu(_window);
  core::engine::GameEngine gameEngine{currentState, _window, ball, core::engine::game::FIRST_LEVEL};
  core::engine::MenuEngine menuEngine(menu, gameEngine, _window);

  PlayerModel playerModel{_window};
  core::engine::PlayerEngine player{playerModel};
  sf::Clock clock;

  while (_window.isOpen()) {

	auto elapsed = clock.getElapsedTime();
	float time = elapsed.asMicroseconds(); //дать прошедшее время в микросекундах
	clock.restart(); //перезагружает время
	time = time / 800; //скорость игры
	sf::Time t;
	t.asMicroseconds();

	sf::Event event;
	while (_window.pollEvent(event)) {
	  if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		_window.close();
	}

	_window.clear();
	if (currentState == core::engine::GameEngine::STATE::MENU) {
	  menuEngine.update(event.key);
	}

	if (currentState == core::engine::GameEngine::STATE::GAME) {
	  //gameEngine.startNewGame(_window);
	  gameEngine.update(elapsed);
	}

	//Ball.update(event, time);
	_window.display();
  }

  return 0;
}