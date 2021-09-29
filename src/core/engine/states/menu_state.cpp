#include "menu_state.hpp"
#include <button.hpp>
#include <textures.hpp>

MenuState::MenuState(StateStack &state_list,
					 sf::RenderWindow &window,
					 FontManager &fonts,
					 MusicPlayer &music,
					 TextureManager &textures) :
	State(state_list),
	_window(window),
	_fonts(fonts),
	_textures(textures),
	_music(music) {
  _window.setView(_window.getDefaultView());

  _backgroundTexture.setTexture(textures.getResourceReference(constants::BLACK_PATH));
  _backgroundTexture.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));

  createButtons(_window, {window.getSize().x / 4.f, window.getSize().y / 6.f});
}

std::string MenuState::getId() {
  return "MenuState";
}

void MenuState::draw(sf::RenderTarget &target, sf::RenderStates state) const {
  target.draw(_backgroundTexture, state);
}

bool MenuState::update(sf::Time deltaTime) {
  return false;
}

bool MenuState::handleEvent(const sf::Event &event) {
  return false;
}

void MenuState::createButtons(sf::RenderWindow &window, sf::Vector2f position) {
  // Play Button
  auto play_button = std::make_unique<Button>(_textures, _fonts);
  play_button->setText("Play the game!");
  play_button->matchSizeToText(20.f);
  play_button->setPosition(position.x, position.y + play_button->getLocalBounds().height);

  play_button->setActiveFunction([this](Button &self) {
	requestPop();
	requestPush(State_ID::GameState);
  });
}

