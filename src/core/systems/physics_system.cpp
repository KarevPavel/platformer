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
  auto view = registry->view<GameComponents::PlayerBody, GameComponents::PlayerPosition>();

  //Обработка модели игрока
  view.each([](GameComponents::PlayerBody &body, GameComponents::PlayerPosition &playerPosition) {
	auto pos = body.body->GetPosition();
	//std::cout << "Prev Position: [" << pos.x << ":" << pos.y << "]"  << std::endl;
	playerPosition.position = Utils::b2VecToVector2(pos);
	//body.body->SetLinearVelocity({ 0.f, 0.f }); // this should avoid some incredibly high jumps
	//body.body->ApplyForceToCenter(Utils::sfVectorToB2Vec(sf::Vector2f{ 300.f, -3 * 300.f }), true);
	//std::cout << "New Position: [" << body.body->GetPosition().x << ":" << body.body->GetPosition().y << "]"  << std::endl;
  });

  this->engine->getBox2DWorld().Step(1.f/60.f, 6, 2);
}