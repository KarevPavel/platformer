//
// Created by yacopsae on 14/10/2021.
//

#pragma once

#include <utility>
#include <map>
#include <string>
#include "memory"
#include "iostream"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "tmxlite/Types.hpp"

#include "updatable_map.hpp"

#include <box2d/b2_body.h>
#include <entt/entity/fwd.hpp>

namespace GameComponents {

enum ObjectType {
  BULLET,
  STATIC,
  PLAYER,
  ENEMY
};

struct Collision {

  std::unique_ptr<entt::entity> entity;
  ObjectType objectType;

  Collision(ObjectType objectType) : objectType(objectType) {}
  Collision(std::unique_ptr<entt::entity> entity, ObjectType objectType) : entity(std::move(entity)), objectType(objectType) {}
};

struct Position {
  Position() = default;
  explicit Position(const sf::Vector2<float> &position) : position(position), angle(0) {}
  sf::Vector2<float> position;
  float angle;
};

struct Bullet {
  Bullet(b2Body *body, sf::Vector2f startPosition) : body(body), rectangleShape({1, 1}) {
	rectangleShape.setFillColor(sf::Color::Magenta);
	rectangleShape.setOutlineColor(sf::Color::Black);
	rectangleShape.setOutlineThickness(0.1f);
	rectangleShape.setPosition(startPosition);
  }

  b2Body *body;
  sf::RectangleShape rectangleShape;
};

struct LevelStart : Position {
  LevelStart() = default;
  explicit LevelStart(const sf::Vector2f &position) : Position(position) {}
};

struct LevelEnd : Position {
  LevelEnd() = default;
  explicit LevelEnd(const sf::Vector2f &position) : Position(position) {}
};

struct PlayerPosition : Position {
  PlayerPosition() = default;
  explicit PlayerPosition(const sf::Vector2f &position) : Position(position) {}
};

struct EnemyPosition : Position {
  EnemyPosition() = default;
  explicit EnemyPosition(const sf::Vector2f &position) : Position(position) {}
  explicit EnemyPosition(const tmx::Vector2f &position) : Position({position.x, position.y}) {}

  long health = 100;
};

struct Map {
  explicit Map(std::map<std::string, UpdatableMap::Ptr> &mapLayers,
			   std::vector<std::unique_ptr<EnemyPosition>> &enemySpawns) :
	  mapLayers(std::move(mapLayers)),
	  enemySpawns(std::move(enemySpawns)) {}

  std::map<std::string, UpdatableMap::Ptr> mapLayers;
  std::vector<std::unique_ptr<EnemyPosition>> enemySpawns;

};

struct RenderableSprite {
  RenderableSprite() = default;

  explicit RenderableSprite(const sf::Texture &texture_) {
	texture = std::make_unique<sf::Texture>(texture_);
	auto size = texture->getSize();
	sprite = std::make_unique<sf::Sprite>(*texture);
	sprite->setOrigin(size.x / 2.f, size.y / 2.f);
  }

  RenderableSprite(const std::string &texturePath, const sf::IntRect &spritePos) {
	texture = std::make_unique<sf::Texture>();
	if (!texture->loadFromFile(texturePath)) {
	  std::cout << "Something going wrong!" << std::endl;
	}
	sprite = std::make_unique<sf::Sprite>(*texture, spritePos);
	sprite->setOrigin(spritePos.width / 2.f, spritePos.width / 2.f);
  }
  std::unique_ptr<sf::Texture> texture;
  std::unique_ptr<sf::Sprite> sprite;
};

struct PlayerBody {

  explicit PlayerBody(b2Body *body) : body(body), isOnAir(false) {}

  bool isOnAir;
  b2Body *body;
};

struct Weapon {
  explicit Weapon(const sf::RectangleShape &weapon, const sf::Texture &crosshairTexture_) :
	  weapon(weapon),
	  moveVector(),
	  circleShape(20) {

	moveVector = sf::RectangleShape({1, 900});
	moveVector.setFillColor(sf::Color::Black);
	moveVector.setPosition(weapon.getPosition());

	circleShape.setOutlineColor(sf::Color::Black);
	circleShape.setFillColor(sf::Color::Transparent);
	circleShape.setOutlineThickness(1.f);
	circleShape.setOrigin(20, 20);
	circleShape.setPosition(weapon.getPosition());

	crosshairTexture = std::make_unique<sf::Texture>(crosshairTexture_);
	auto size = crosshairTexture->getSize();
	crosshair = std::make_unique<sf::Sprite>(*crosshairTexture);
	crosshair->setOrigin(size.x / 2.f, size.y / 2.f);
	crosshair->setScale(0.3, 0.3);
  }

  sf::CircleShape circleShape;
  sf::RectangleShape moveVector;
  sf::RectangleShape weapon;
  std::unique_ptr<sf::Texture> crosshairTexture;
  std::unique_ptr<sf::Sprite> crosshair;
};
}
