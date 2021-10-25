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
  auto view = registry->view<GameComponents::PlayerBody,
							 GameComponents::RenderableSprite,
							 GameComponents::PlayerPosition,
							 GameComponents::Weapon>();
  //Обработка модели игрока
  view.each([](GameComponents::PlayerBody &body,
			   GameComponents::RenderableSprite &renderableSprite,
			   GameComponents::PlayerPosition &playerPosition,
			   GameComponents::Weapon &weapon) {
	auto pos = body.body->GetPosition();

	playerPosition.position = Utils::b2VecToVector2(body.body->GetPosition());
	playerPosition.angle = body.body->GetAngle();
	//weapon.weapon.setRotation(body.body->GetAngle());
	weapon.weapon.setPosition(Utils::b2VecToVector2(pos));
  });

  this->engine->getBox2DWorld().Step(dt, 6, 2);
}