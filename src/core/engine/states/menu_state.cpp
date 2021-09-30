#include "menu_state.hpp"
#include <button.hpp>
#include <textures.hpp>
#include <fonts.hpp>
#include <sound.hpp>

MenuState::MenuState(StateStack &state_list,
					 sf::RenderWindow &window,
					 FontManager &fonts,
					 MusicPlayer &music,
					 TextureManager &textures) :
	State(state_list),
	_window(window),
	_fonts(fonts),
	_textures(textures),
	_music(music),
	_buttons(window),
	_gameName("Epic Game Ever", fonts.getResourceReference(constants::LIBERATIONMONO_BOLD_PATH), 90)
	{
  _window.setView(_window.getDefaultView());

  _backgroundTexture.setTexture(textures.getResourceReference(constants::BLACK_PATH));
  _backgroundTexture.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));

  _music.play(constants::MAIN_MENU_PATH);

  const sf::Vector2f titlePosition(window.getSize().x / 2.f, window.getSize().y / 3.f);
  Utils::centerOrigin(_gameName);
  _gameName.setPosition(titlePosition.x, titlePosition.y);
  createButtons(_window, Utils::getPositionBelow(_gameName));
}

std::string MenuState::getId() {
  return "MenuState";
}

void MenuState::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(_backgroundTexture);

  target.draw(_gameName, states);

  _buttons.draw(target, states);
}

bool MenuState::update(sf::Time deltaTime) {

  _buttons.update();

  return false;
}

bool MenuState::handleEvent(const sf::Event &event) {
  _buttons.handleEvents(event);

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

  _buttons.store(std::move(play_button));
}