//
// Created by yacopsae on 12/10/2021.
//

#include <textures.hpp>
#include <sound.hpp>
#include <music_system.hpp>
#include <game_scene.hpp>
#include <fonts.hpp>
#include "menu_scene.hpp"
#include "engine.hpp"
#include "utils.hpp"

MenuScene::MenuScene()
	: Scene("menu") {
}

MenuScene::~MenuScene() {
}

void MenuScene::init() {
  em.init(engine);

  em.addSystem(std::make_unique<MusicSystem>());

  backgroundTexture.setTexture(engine->getTextureManager().getResource(constants::BLACK_PATH));
  backgroundTexture
	  .setTextureRect(sf::IntRect(0, 0, engine->getWindow().getSize().x, engine->getWindow().getSize().y));

  em.getEventDispatcher()->trigger<SoundEvent::MusicStart>(constants::MAIN_MENU_PATH);

  const sf::Vector2f
	  titlePosition(engine->getWindow().getView().getSize().x / 2.f, engine->getWindow().getView().getSize().y / 3.f);

  gameName = sf::Text{"AWERSOMESHOOTEREVER",
					  engine->getFontManager().getResource(constants::ANOTHER_DANGER_SLANTED___DEMO_PATH),
					  90};

  Utils::centerOrigin(gameName);
  gameName.setPosition(titlePosition.x, titlePosition.y);
  gameName.setOutlineThickness(2.f);
  gameName.setOutlineColor(sf::Color::Red);
  gameName.setFillColor(sf::Color::Black);

  createButtons(engine->getWindow(), Utils::getPositionBelow(gameName));
}

void MenuScene::update() {
  sf::Event event;
  while (window->pollEvent(event)) {
	handleDefaultEvents(&event);

	for (const auto &btn : buttons) {
	  btn->handleEvents(event);
	}

	//TODO:REMOVE!!!! ONLY FOR FAST TESTS!!!
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
	  this->engine->getSceneManager().addScene(std::make_unique<GameScene>());
	}
  }
}

void MenuScene::fixedUpdate(const float dt) {
  for (const auto &btn : buttons) {
	btn->update(window->mapPixelToCoords(sf::Mouse::getPosition()));
  }

  em.onUpdate(dt);
}

void MenuScene::render(const float alpha_lerp) {
  window->clear(sf::Color(255, 255, 255));
  window->draw(backgroundTexture);

  window->draw(gameName);
  for (const auto &btn : buttons) {
	window->draw(*btn);
  }
  em.onRender(alpha_lerp);

  window->display();
}

void MenuScene::createButtons(sf::RenderWindow &window, sf::Vector2f position) {
  // Play Button
  auto playButton = std::make_unique<Button>(engine->getTextureManager(), engine->getFontManager());
  playButton->setText("Play the game!");
  playButton->matchSizeToText(20.f);
  playButton->setPosition(position.x, position.y + playButton->getLocalBounds().height);
  playButton->setActiveFunction([this](Button &btn) {
	this->engine->getSceneManager().addScene(std::make_unique<GameScene>());
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

  auto exitButton = std::make_unique<Button>(engine->getTextureManager(), engine->getFontManager());
  exitButton->setText("Exit");
  exitButton->setSize(playButton->getGlobalBounds().width, playButton->getGlobalBounds().height);
  exitButton->setPositionBelow(*playButton, 10.f);
  exitButton->setActiveFunction([&window](Button &self) {
    window.close();
  	exit(0);
  });

  buttons.push_back(std::move(exitButton));
  buttons.push_back(std::move(playButton));
}