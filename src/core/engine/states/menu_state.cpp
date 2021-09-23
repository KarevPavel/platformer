#include "menu_state.hpp"

MenuState::MenuState(StateList &state_list,
					 sf::RenderWindow &window,
					 FontManager &fonts,
					 MusicPlayer &music) :
	State(state_list),
	_window(window),
	_fonts(fonts),
	_music(music) {
  _window.setView(_window.getDefaultView());


  //_backgroundTexture.setTexture(textures.getResourceReference(Textures_ID::WorldBackground));
  _backgroundTexture.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));

  createButtons(_window);
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

void MenuState::createButtons(sf::RenderWindow &window) {

}

