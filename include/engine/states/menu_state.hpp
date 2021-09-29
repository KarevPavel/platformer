#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "resource_manager.hpp"
#include "fixed_container.hpp"
#include "music_player.hpp"
#include "state_stack.hpp"

class MenuState : public State {

 public:
  MenuState(StateStack &state_list,
			sf::RenderWindow &window,
			FontManager &fonts,
			MusicPlayer &music,
			TextureManager &textures);
  std::string getId() override;
  void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
  bool update(sf::Time deltaTime) override;
  bool handleEvent(const sf::Event &event) override;

 private:
  void createButtons(sf::RenderWindow &window, sf::Vector2f position);

  FixedContainer _buttons;

  sf::Sprite _backgroundTexture;
  sf::RenderWindow &_window;
  FontManager &_fonts;
  TextureManager &_textures;
  MusicPlayer &_music;
};