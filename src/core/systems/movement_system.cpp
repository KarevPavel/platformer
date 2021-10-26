//
// Created by yacopsae on 23/10/2021.
//
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "engine.hpp"
#include "utils.hpp"

#include "game_components.hpp"
#include "movement_system.hpp"

MovementSystem::MovementSystem() = default;
void MovementSystem::onInit() {}

void MovementSystem::update(const float dt) {
  inputProcessing();
  playerMovement();
  bulletsMovement();
}

void MovementSystem::inputProcessing() {
  //TODO: Переписать на "ожидание" собития sf::Event
  registry->view<GameComponents::PlayerPosition,
				 GameComponents::PlayerBody,
				 GameComponents::Weapon>()
	  .each([this](GameComponents::PlayerPosition &playerPosition,
				   GameComponents::PlayerBody &playerBody,
				   GameComponents::Weapon &weapon) {

		sf::Vector2i pixelPos = sf::Mouse::getPosition(engine->getWindow());
		sf::Vector2f pos = engine->getWindow().mapPixelToCoords(pixelPos);
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

		  if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			float r = weapon.circleShape.getRadius();

			//rotation -= 90;
			//rotation = rotation < 0 ? 360 + rotation : rotation;
			//rotation-=90;
			rotation = weapon.weapon.getRotation();
			float x = r * sin(M_PI * 2 * rotation / 360);
			float y = r * cos(M_PI * 2 * rotation / 360);

			std::cout << "Rotation: " << rotation << std::endl;
			auto coords = weapon.circleShape.getPosition() + sf::Vector2f { x, y };

			sf::RectangleShape rect ({ 5, 5 });
			rect.setFillColor(sf::Color::Cyan);
			rect.setPosition(coords);
			engine->getWindow().draw(rect);

			shoot(Utils::sfVectorToB2Vec(coords), Utils::sfVectorToB2Vec(pos));
		  }
		}
	  });
}

void MovementSystem::playerMovement() {
  auto view = registry->view<GameComponents::PlayerBody,
							 GameComponents::RenderableSprite,
							 GameComponents::PlayerPosition,
							 GameComponents::Weapon>();

  view.each([](GameComponents::PlayerBody &body,
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
  b2Body *body = engine->getBox2DWorld().CreateBody(bodyDef.get());
  auto fixtureDef = std::make_unique<b2FixtureDef>();
  const auto &shape = std::make_unique<b2PolygonShape>();
  shape->SetAsBox(0.01, 0.01);
  fixtureDef->shape = shape.get();
  fixtureDef->density = 1000.f;
  fixtureDef->friction = 1.f;
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
