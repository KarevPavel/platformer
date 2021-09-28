#pragma once


#include <functional>
#include <map>
#include <vector>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include "state.hpp"
#include "states.hpp"


class StateStack {

 public:
  enum class Perform {
	Push,
	Pop,
	Clear,
  };

  StateStack() = default;

  template<typename State, typename... Args>
  void saveState(State_ID stateID, Args &&...args);

  void update(sf::Time deltaTime);

  void draw(sf::RenderTarget &target, sf::RenderStates state) const;

  void handleEvent(const sf::Event &event);

  void push(State_ID stateID);

  void pop();

  void clear();

  bool empty() const;

 private:

  struct Change {
	Perform operation; //!< Operation to be performed on the stack
	State_ID stateID; //!< Identifier of the state that should be pushed on the stack
  };

  State *createState(State_ID stateID);

  void applyChanges();

  std::vector<State * > stack;

  std::vector<Change> changesQueue;

  std::map<State_ID, std::function<State::Ptr()>> factory;
};


template<typename State, typename... Args>
inline void StateStack::saveState(State_ID stateID, Args &&... args) {
  factory[stateID] = [&args..., this]() {
	return std::make_unique<State>(*this, std::forward<Args>(args)...);
  };
}