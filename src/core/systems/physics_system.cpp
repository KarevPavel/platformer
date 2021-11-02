//
// Created by yacopsae on 22/10/2021.
//

#include "physics_system.hpp"
#include "engine.hpp"

PhysicsSystem::PhysicsSystem() = default;

void PhysicsSystem::onInit() {

}

void PhysicsSystem::update(const float dt) {
  this->engine->getBox2DWorld().Step(dt, 1, 1);
}