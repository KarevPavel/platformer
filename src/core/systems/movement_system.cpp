//
// Created by yacopsae on 23/10/2021.
//
#include <SFML/Window/Event.hpp>

#include "engine.hpp"
#include "utils.hpp"

#include "game_components.hpp"
#include "movement_system.hpp"


MovementSystem::MovementSystem() = default;
void MovementSystem::onInit() {}

void MovementSystem::update(const float dt) {

  //По сути управление работает так:
  //Передаём физическому движку значения ускорения и пр.
  auto view = registry->view<GameComponents::PlayerPosition, GameComponents::PlayerBody>();
  view.each([this](GameComponents::PlayerPosition &playerPosition, GameComponents::PlayerBody &playerBody) {

    if (!playerBody.isOnAir) {
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		//playerPosition.position.x += MOVEMENT_SPEED;
		playerBody.body->ApplyLinearImpulseToCenter(Utils::sfVectorToB2Vec(sf::Vector2f{5, 0}), true);

	  }

	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		playerBody.body->ApplyLinearImpulseToCenter(Utils::sfVectorToB2Vec(sf::Vector2f{0, -5}), true);
	  }

	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		playerBody.body->ApplyLinearImpulseToCenter(Utils::sfVectorToB2Vec(sf::Vector2f{-5, 0}), true);
	  }

	  if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		auto coords = engine->getWindow().mapPixelToCoords(sf::Mouse::getPosition());
		shoot(playerBody.body->GetPosition(), Utils::sfVectorToB2Vec(coords));
	  }
	}
  });
}

void MovementSystem::shoot(const b2Vec2& bulletStartPos, const b2Vec2& bulletDirection) {
  auto bulletEntity = this->registry->create();
  auto bodyDef = std::make_unique<b2BodyDef>();
  bodyDef->position = bulletStartPos;
  bodyDef->type = b2BodyType::b2_dynamicBody;
  //bodyDef->bullet = true;
  b2Body *body = engine->getBox2DWorld().CreateBody(bodyDef.get());

  auto fixtureDef = std::make_unique<b2FixtureDef>();
  const auto &shape = std::make_unique<b2PolygonShape>();

  shape->SetAsBox(0.01, 0.01);
  fixtureDef->shape = shape.get();
  fixtureDef->density = 1.0f;
  fixtureDef->friction = 0;
  body->CreateFixture(fixtureDef.get());
  body->ApplyLinearImpulseToCenter(bulletDirection, true);

  this->registry->emplace<GameComponents::Bullet>(bulletEntity, body);
}