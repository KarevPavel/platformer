//
// Created by yacopsae on 25/10/2021.
//

#include "iostream"

#include "contact_listener.hpp"


void ContactListener::BeginContact(b2Contact *contact) {
  const auto& userDataA = contact->GetFixtureA();
  const auto& userDataB = contact->GetFixtureB();
/*
  std::cout << "userDataA: " << userDataA->GetUserData().pointer << std::endl;
  std::cout << "userDataB: " << userDataB->GetUserData().pointer << std::endl;*/

}

void ContactListener::EndContact(b2Contact *contact) {

}