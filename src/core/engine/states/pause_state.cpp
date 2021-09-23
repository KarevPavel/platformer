//
// Created by yacopsae on 16/09/2021.
//

#include "pause_state.hpp"

PauseState::PauseState(StateList &state_list, sf::RenderWindow &window) :
	State(state_list),
	_window(window) {
  _window.setView(_window.getDefaultView());
}

std::string PauseState::getId() {
  return "PauseState";
}

void PauseState::update(sf::Time deltaTime) {

}

void PauseState::draw(sf::RenderTarget &target, sf::RenderStates state) const {

}

void PauseState::handleEvent(const sf::Event &event) {

}

void MenuState::loadResources()
{