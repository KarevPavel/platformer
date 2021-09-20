//
// Created by yacopsae on 08/09/2021.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "state.hpp"

class MenuState: public State {

 public:
  MenuState(StateList & state_list, sf::RenderWindow & window);
  std::string getId() override;
  void update(sf::Time deltaTime) override;
  void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
  void handleEvent(const sf::Event& event) override;

 private:
  sf::RenderWindow &_window;

};