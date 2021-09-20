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
  StateList() = default;

  template<class State, typename... Args>
  inline void add(Args &&... args) {
	factory["TEST"] = [&args..., this]() {
	  return std::make_unique<State>(*this, std::forward<Args>(args)...);
	};
  }

  inline void draw(sf::RenderTarget &target, sf::RenderStates currState) {
	for (const auto &state : vector_) {
	  state->draw(target, currState);
	}
  }

  inline void update(sf::Time deltaTime) {
	for (auto &state : vector_) {
	  state->update(deltaTime);
	}
  }

 private:
  std::map<std::string, std::function<State::Ptr()>> factory;
  std::vector<State::Ptr> vector_;
};
