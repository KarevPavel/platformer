//
// Created by yacopsae on 25/09/2021.
//

#include "state_stack.hpp"

State::Ptr StateStack::createState(State_ID stateID) {
  auto found = factory.find(stateID);
  return found->second();
}

void StateStack::applyChanges() {
  for (auto &change : changesQueue) {
	switch (change.operation) {
	  case Perform::Push: stack.push_back(createState(change.stateID));
		break;

	  case Perform::Pop: stack.pop_back();
		break;

	  case Perform::Clear: stack.clear();
		break;
	}
  }
  changesQueue.clear();
}

void StateStack::update(sf::Time deltaTime) {
  applyChanges();

  for (auto state = stack.rbegin(), end = stack.rend(); state != end; ++state) {
	if (!(*state)->update(deltaTime))
	  return;
  }
}

void StateStack::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  for (const auto &state : stack)
	state->draw(target, states);
}

void StateStack::handleEvent(const sf::Event &event) {
  applyChanges();

  for (auto state = stack.rbegin(), end = stack.rend(); state != end; ++state) {
	if (!(*state)->handleEvent(event))
	  return;
  }
}

void StateStack::push(State_ID stateID) {
  changesQueue.push_back(Change{Perform::Push, stateID});
}

void StateStack::pop() {
  changesQueue.push_back(Change{Perform::Pop});
}

void StateStack::clear() {
  changesQueue.push_back(Change{Perform::Clear});
}

bool StateStack::empty() const {
  return changesQueue.empty();
}



