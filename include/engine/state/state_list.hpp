//
// Created by yacopsae on 14/09/2021.
//

#pragma once

#include <functional>
#include <map>
#include <vector>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "state.hpp"

class StateList {

 public:
  StateList();

  void test(State *state);

  template<typename StateChild, typename... Args>
  void add(Args &&... args);

  void draw(sf::RenderTarget &target, sf::RenderStates currState);

  void update(sf::Time deltaTime);

 private:
  std::vector<State *> vector_;
};

template<typename StateChild, typename... Args>
inline void StateList::add(Args &&... args) {
  vector_.push_back(new StateChild(*this, std::forward<Args>(args)...));
}

inline void StateList::test(State *s) {
  vector_.push_back(s);
}

inline void StateList::draw(sf::RenderTarget &target, sf::RenderStates currState) {
  for (const auto &state : vector_) {
	state->draw(target, currState);
  }
}

inline void StateList::update(sf::Time deltaTime) {
  for (auto &state : vector_) {
	state->update(deltaTime);
  }
}

inline StateList::StateList() = default;
