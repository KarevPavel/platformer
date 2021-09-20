//
// Created by yacopsae on 16/09/2021.
//

#include "box2d/world_listener.hpp"

void WorldListener::BeginContact(b2Contact *contact) {
  // Takes information about the occured collision
  const auto &userData1 = contact->GetFixtureA()->GetUserData();
  const auto &userData2 = contact->GetFixtureB()->GetUserData();
}

void WorldListener::EndContact(b2Contact *contact) {

}