//
// Created by yacopsae on 16/09/2021.
//

#include "game_state.hpp"

GameState::GameState(StateStack &stack, sf::RenderWindow &window) :
	State(stack),
	_window(window),
	_gameWorld(window) {
  _window.setView(_window.getDefaultView());
}

std::string GameState::getId() {
  return "GameState";
}

void GameState::draw(sf::RenderTarget &target, sf::RenderStates state) const {
  _gameWorld.draw();
}

bool GameState::update(sf::Time deltaTime) {
  // d = st (distance = speed * time)
  _gameWorld.update(deltaTime);

  if (_gameWorld.isGameFinished()) {
	_window.setView(_window.getDefaultView());
	requestPop();
	requestPush(State_ID::MenuState);
  }
  return true;
}

bool GameState::handleEvent(const sf::Event &event) {
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
	requestPush(State_ID::PauseState);

  _gameWorld.processEvents(event);

  return true;
}
