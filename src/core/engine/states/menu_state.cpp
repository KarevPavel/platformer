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
	_gameName("AWERSOMESHOOTEREVER", fonts.getResourceReference(constants::ANOTHER_DANGER_SLANTED___DEMO_PATH), 90)
	{
  _window.setView(_window.getDefaultView());

  _backgroundTexture.setTexture(textures.getResourceReference(constants::BLACK_PATH));
  _backgroundTexture.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));

  _music.play(constants::MAIN_MENU_PATH);

  const sf::Vector2f titlePosition(window.getSize().x / 2.f, window.getSize().y / 3.f);
  Utils::centerOrigin(_gameName);
  _gameName.setPosition(titlePosition.x, titlePosition.y);
  _gameName.setOutlineThickness(2.f);
  _gameName.setOutlineColor(sf::Color::Red);
  _gameName.setFillColor(sf::Color::Black);
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

/*
  auto fullScreenButton = std::make_unique<Button>(_textures, _fonts);
  fullScreenButton->setText("Fullscreen: " + (false ? std::string("yes") : std::string("no")));
  fullScreenButton->matchSizeToText(20.f);
  fullScreenButton->setPositionBelow(*play_button, 10.f);
  fullScreenButton->setActiveFunction([this, &window](Button &self)
									  {
										//fullScreen = (fullScreen) ? 0 : sf::Style::Fullscreen;
										//self.setText("Fullscreen: " + (fullScreen ? std::string("yes") : std::string("no")));
										window.create(sf::VideoMode(window.getSize().x, window.getSize().y), "Worms Clone",
													  sf::Style::Titlebar | sf::Style::Close | sf::Style::Fullscreen);
									  });

*/

  auto exit_button = std::make_unique<Button>(_textures, _fonts);
  exit_button->setText("Exit");
  exit_button->setSize(play_button->getGlobalBounds().width, play_button->getGlobalBounds().height);
  exit_button->setPositionBelow(*play_button, 10.f);
  exit_button->setActiveFunction([&window](Button &self)
								 { window.close(); });

  _buttons.store(std::move(exit_button));
  _buttons.store(std::move(play_button));
}