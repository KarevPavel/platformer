//
// Created by yacopsae on 22/10/2021.
//

#include <utils.hpp>
#include "physics_system.hpp"
#include "game_components.hpp"
#include "engine.hpp"

PhysicsSystem::PhysicsSystem() = default;

void PhysicsSystem::onInit() {

}

void PhysicsSystem::update(const float dt) {
  this->engine->getBox2DWorld().Step(dt * 0.1f, 1, 1);
}