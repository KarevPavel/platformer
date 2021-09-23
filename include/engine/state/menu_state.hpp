//
// Created by yacopsae on 08/09/2021.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "state.hpp"
#include "font_manager.hpp"
#include "music_manager.hpp"

class MenuState : public State {

 public:
  MenuState(StateList &state_list, sf::RenderWindow &window, FontManager &fonts, MusicPlayer &music);
  std::string getId() override;
  void update(sf::Time deltaTime) override;
  void draw(sf::RenderTarget &target, sf::RenderStates state) const override;
  void handleEvent(const sf::Event &event) override;

 private:
  void createButtons(sf::RenderWindow &window);

  sf::Sprite _backgroundTexture;
  sf::RenderWindow &_window;
  FontManager &_fonts;
  MusicPlayer &_music;
};