//
// Created by yacopsae on 26/09/2021.
//

#include "state_stack.hpp"



void State::requestPush(State_ID stateID) const {
  stack->push(stateID);
}

void State::requestPop() const {
  stack->pop();
}

void State::requestClear() const {
  stack->clear();
}

