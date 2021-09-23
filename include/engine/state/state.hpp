#pragma once

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

class StateList;

class State {

 public:
  explicit State(StateList &state_list): _stateList(&state_list) {

  }
  virtual std::string getId() = 0;
  virtual void update(sf::Time deltaTime) = 0;
  virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const = 0;
  virtual void handleEvent(const sf::Event &event) = 0;

 private:
  StateList *_stateList;
};