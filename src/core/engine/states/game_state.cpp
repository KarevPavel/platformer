//
// Created by yacopsae on 16/09/2021.
//

#include "game_state.hpp"

GameState::GameState(StateStack &state_list, sf::RenderWindow &window) :
	State(state_list),
	_window(window) {
  _window.setView(_window.getDefaultView());
}

std::string GameState::getId() {
  return "PauseState";
}

bool GameState::update(sf::Time deltaTime) {
  return false;
}

bool GameState::draw(sf::RenderTarget &target, sf::RenderStates state) const {
  return false;
}

bool GameState::handleEvent(const sf::Event &event) {
  return false;
}
