//
// Created by yacopsae on 22/10/2021.
//

#include "physics_system.hpp"
#include "game_components.hpp"
#include "engine.hpp"

PhysicsSystem::PhysicsSystem() = default;

void PhysicsSystem::onInit() {
}

void PhysicsSystem::update(const float dt) {
  auto view = registry->view<GameComponents::Body>();
  view.each([this, dt](GameComponents::Body &body) {
	auto pos = body.body->GetPosition();
	body.wrappedObjPos.position.x = pos.x;
	body.wrappedObjPos.position.y = pos.y;
	body.body->ApplyForceToCenter({90, 90}, true);
  });
  this->engine->getBox2DWorld().Step(1 / 60.f, 8, 3);

}