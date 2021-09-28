//
// Created by yacopsae on 16/09/2021.
//

#include "pause_state.hpp"

PauseState::PauseState(StateStack &state_list, sf::RenderWindow &window) :
	State(state_list),
	_window(window) {
  _window.setView(_window.getDefaultView());
}

std::string PauseState::getId() {
  return "PauseState";
}

bool PauseState::update(sf::Time deltaTime) {
  return false;
}

bool PauseState::draw(sf::RenderTarget &target, sf::RenderStates state) const {
  return false;
}

bool PauseState::handleEvent(const sf::Event &event) {
  return false;
}
