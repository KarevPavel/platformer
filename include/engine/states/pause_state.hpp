//
// Created by yacopsae on 16/09/2021.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "state_stack.hpp"

class PauseState : public State {

 public:
  PauseState(StateStack &state_list, sf::RenderWindow &window);
  std::string getId() override;
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  bool update(sf::Time deltaTime) override;
  bool handleEvent(const sf::Event &event) override;

 private:
  sf::RenderWindow &_window;

};