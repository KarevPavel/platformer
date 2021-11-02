//
// Created by yacopsae on 23/10/2021.
//
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "engine.hpp"
#include "utils.hpp"

#include "map_layer.hpp"
#include "game_components.hpp"
#include "movement_system.hpp"

MovementSystem::MovementSystem() = default;
void MovementSystem::onInit() {}

void MovementSystem::update(const float dt) {
  registry->view<GameComponents::PlayerPosition,
				 GameComponents::PlayerBody,
				 GameComponents::Weapon>()
	  .each([this](GameComponents::PlayerPosition &playerPosition,
				   GameComponents::PlayerBody &playerBody,
				   GameComponents::Weapon &weapon) {

		sf::Vector2i pixelPos = sf::Mouse::getPosition(engine->getWindow());
		sf::Vector2f pos = engine->getWindow().mapPixelToCoords(pixelPos);

		weapon.crosshair->setPosition(pos);

		float dX = pos.x - weapon.moveVector.getPosition().x;
		float dY = pos.y - weapon.moveVector.getPosition().y;

		//TODO: Пока не разобрался почнму приходится писать -90 =(
		float rotation = ((atan2(dY, dX)) * 180 / M_PI) - 90;
		weapon.moveVector.setRotation(rotation);
		weapon.weapon.setRotation(rotation);

		if (!playerBody.isOnAir) {
		  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			playerBody.body->ApplyLinearImpulseToCenter(Utils::sfVectorToB2Vec(sf::Vector2f{5, 0}), true);
		  }
		  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			playerBody.body->ApplyLinearImpulseToCenter(Utils::sfVectorToB2Vec(sf::Vector2f{0, -20}), true);
		  }

		  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			playerBody.body->ApplyLinearImpulseToCenter(Utils::sfVectorToB2Vec(sf::Vector2f{-5, 0}), true);
		  }
		}
	  });

  playerMovement();
  bulletsMovement();
}

void MovementSystem::onEvent(sf::Event event) {
  inputProcessing(event);
}

void MovementSystem::inputProcessing(sf::Event event) {

  if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
	registry->view<GameComponents::Weapon>()
		.each([this](GameComponents::Weapon &weapon) {

		  sf::Vector2i pixelPos = sf::Mouse::getPosition(engine->getWindow());
		  sf::Vector2f pos = engine->getWindow().mapPixelToCoords(pixelPos);
		  float dX = pos.x - weapon.moveVector.getPosition().x;
		  float dY = pos.y - weapon.moveVector.getPosition().y;

		  //TODO: Пока не разобрался почнму приходится писать -90 =(
		  float rotation = ((atan2(dY, dX)) * 180 / M_PI) - 90;

		  //TODO: Пока не разобрался почнму приходится писать +90 =(
		  rotation = weapon.moveVector.getRotation() + 90;
		  float r = weapon.circleShape.getRadius();
		  auto Opos = weapon.circleShape.getPosition();
		  float x = Opos.x + (r * cos(rotation / (180 / M_PI)));
		  float y = Opos.y + (r * sin(rotation / (180 / M_PI)));

		  float weaponPower = 10000;
		  float rotation_2 = weapon.moveVector.getRotation() + 90;
		  float x_2 = Opos.x + (weaponPower * cos(rotation_2 / (180 / M_PI)));
		  float y_2 = Opos.y + (weaponPower * sin(rotation_2 / (180 / M_PI)));

		  auto startCoords = sf::Vector2f{x, y};

		  auto finalCoords = sf::Vector2f{x_2, y_2};

		  shoot(Utils::sfVectorToB2Vec(startCoords), Utils::sfVectorToB2Vec(finalCoords));

		});
  }
}

void MovementSystem::playerMovement() {
  registry->view<GameComponents::PlayerBody,
				 GameComponents::RenderableSprite,
				 GameComponents::PlayerPosition,
				 GameComponents::Weapon>().each([](GameComponents::PlayerBody &body,
												   GameComponents::RenderableSprite &playerSprite,
												   GameComponents::PlayerPosition &playerPosition,
												   GameComponents::Weapon &weapon) {
	auto pos = body.body->GetPosition();

	playerPosition.position = Utils::b2VecToVector2(pos);
	playerPosition.angle = Utils::radiansToAngle(body.body->GetAngle());

	playerSprite.sprite->setRotation(playerPosition.angle);
	playerSprite.sprite->setPosition(playerPosition.position);

	weapon.weapon.setPosition(playerPosition.position);
	weapon.moveVector.setPosition(playerPosition.position);
	weapon.circleShape.setPosition(playerPosition.position);
  });
}

void MovementSystem::shoot(const b2Vec2 &bulletStartPos, const b2Vec2 &bulletDirection) {
  auto bulletEntity = this->registry->create();
  auto bodyDef = std::make_unique<b2BodyDef>();
  bodyDef->position = bulletStartPos;
  bodyDef->type = b2BodyType::b2_dynamicBody;
  bodyDef->bullet = true;
  b2Body *body = engine->getBox2DWorld().CreateBody(bodyDef.get());
  auto fixtureDef = std::make_unique<b2FixtureDef>();
  const auto &shape = std::make_unique<b2PolygonShape>();
  shape->SetAsBox(0.001, 0.001);
  fixtureDef->shape = shape.get();
  fixtureDef->density = 1000.f;
  fixtureDef->friction = 0.01;
  fixtureDef->userData.pointer =
	  reinterpret_cast<uintptr_t>(new GameComponents::Collision(std::make_unique<entt::entity>(bulletEntity), GameComponents::ObjectType::BULLET));

  body->CreateFixture(fixtureDef.get());
  body->ApplyLinearImpulseToCenter(bulletDirection, true);

  this->registry->emplace<GameComponents::Bullet>(bulletEntity, body, Utils::b2VecToVector2(bulletStartPos));
}

void MovementSystem::bulletsMovement() {
  auto bulletView = registry->view<GameComponents::Bullet>();
  bulletView.each([](GameComponents::Bullet &bullet) {
	bullet.rectangleShape.setPosition(Utils::b2VecToVector2(bullet.body->GetPosition()));
  });
}
