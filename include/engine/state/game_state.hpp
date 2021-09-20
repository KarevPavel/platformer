//
// Created by yacopsae on 16/09/2021.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "state.hpp"

class GameState: public State {

 public:
  GameState(StateList &state_list, sf::RenderWindow &window);
  std::string getId() override;
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  void update(sf::Time deltaTime) override;
  void handleEvent(const sf::Event& event) override;

 private:
  sf::RenderWindow & _window;
};


