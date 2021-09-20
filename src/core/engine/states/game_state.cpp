//
// Created by yacopsae on 16/09/2021.
//

#include "game_state.hpp"

GameState::GameState(StateList &state_list, sf::RenderWindow &window) :
	State(state_list),
	_window(window) {
  _window.setView(_window.getDefaultView());
}

std::string GameState::getId() {
  return "PauseState";
}

void GameState::update(sf::Time deltaTime) {

}

void GameState::draw(sf::RenderTarget &target, sf::RenderStates state) const {

}

void GameState::handleEvent(const sf::Event &event) {

}
