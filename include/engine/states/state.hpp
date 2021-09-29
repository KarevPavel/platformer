#pragma once

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include "states.hpp"

class StateStack;

class State {

 public:

  using Ptr = std::unique_ptr<State>;

  explicit State(StateStack &state): stack(&state) { }
  virtual std::string getId() = 0;
  virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const = 0;
  virtual bool update(sf::Time deltaTime) = 0;
  virtual bool handleEvent(const sf::Event &event) = 0;
 protected:
  void requestPush(State_ID stateID) const;
  void requestPop() const;
  void requestClear() const;

 private:
  StateStack *stack;
};
