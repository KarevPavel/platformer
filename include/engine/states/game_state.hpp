//
// Created by yacopsae on 16/09/2021.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "state_stack.hpp"
#include "world.hpp"

class GameState : public State {

 public:
  GameState(StateStack &stack, sf::RenderWindow &window);
  std::string getId() override;
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  bool update(sf::Time deltaTime) override;
  bool handleEvent(const sf::Event &event) override;

 private:
  sf::RenderWindow &_window;
  World _gameWorld;
};


