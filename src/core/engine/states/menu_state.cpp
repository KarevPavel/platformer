//
// Created by yacopsae on 08/09/2021.
//

#include "menu_state.hpp"

MenuState::MenuState(StateList &state_list, sf::RenderWindow &window) :
	State(state_list),
	_window(window) {
  _window.setView(_window.getDefaultView());
}

std::string MenuState::getId() {
  return "MenuState";
}

void MenuState::update(sf::Time deltaTime) {

}

void MenuState::draw(sf::RenderTarget &target, sf::RenderStates state) const {

}

void MenuState::handleEvent(const sf::Event &event) {

}

