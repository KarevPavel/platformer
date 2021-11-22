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

struct Collision;
struct Angle;
struct Position;
struct Bullet;

enum ObjectType {
  BULLET,
  STATIC,
  PLAYER,
  ENEMY,
  LEVEL_END
};

struct Collision {

  std::unique_ptr<entt::entity> entity;
  ObjectType objectType;

  explicit Collision(ObjectType objectType) : objectType(objectType) {}
  Collision(std::unique_ptr<entt::entity> entity, ObjectType objectType)
	  : entity(std::move(entity)), objectType(objectType) {}
};

struct Angle {
  Angle() : angle(0) {}
  explicit Angle(float angle) : angle(angle) {}
  float angle;
};

struct Position {
  Position() = default;

  explicit Position(const sf::Vector2<float> &position) : position(position) {}

  sf::Vector2<float> position;

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
  explicit LevelEnd(const sf::Vector2f &position,
					const sf::RectangleShape &rectangleShape) :
					Position(position),
					rectangleShape(rectangleShape){}

  sf::RectangleShape rectangleShape;
};

struct Map {
  explicit Map(std::map<std::string, UpdatableMap::Ptr> &mapLayers,
			   std::vector<sf::Vector2f> &enemySpawns) :
	  mapLayers(std::move(mapLayers)),
	  enemySpawns(std::move(enemySpawns)) {}

  std::map<std::string, UpdatableMap::Ptr> mapLayers;
  std::vector<sf::Vector2f> enemySpawns;
};

struct Health {
  Health() = default;
  explicit Health(long health) : health(health) {}
  long health;
};

struct Experience {
  Experience() = default;
  explicit Experience(long experience) : experience(experience) {}
  long experience;
};

struct RenderableSprite {
  RenderableSprite() = default;

  RenderableSprite &operator=(RenderableSprite lhs) {
	this->texture.swap(lhs.texture);
	this->sprite.swap(lhs.sprite);
	return *this;
  }

  RenderableSprite(RenderableSprite &sprite) {
	this->texture.swap(sprite.texture);
	this->sprite.swap(sprite.sprite);
  }

  explicit RenderableSprite(const std::unique_ptr<sf::Texture> &texture_) {
	texture = std::make_unique<sf::Texture>(*texture_);
	auto size = texture->getSize();
	this->sprite = std::make_unique<sf::Sprite>(*this->texture);
	sprite->setOrigin(size.x / 2.f, size.y / 2.f);
  }

  explicit RenderableSprite(const sf::Texture &texture_) {
	texture = std::make_unique<sf::Texture>(texture_);
	auto size = texture->getSize();
	sprite = std::make_unique<sf::Sprite>(*texture);
	sprite->setOrigin(size.x / 2.f, size.y / 2.f);
  }

  std::unique_ptr<sf::Texture> texture;
  std::unique_ptr<sf::Sprite> sprite;
};

struct Weapon {

  Weapon &operator=(Weapon &&lhs) noexcept {
	this->weapon = lhs.weapon;
	this->crosshairSprite.swap(lhs.crosshairSprite);
	this->crosshairTexture.swap(lhs.crosshairTexture);
	this->moveVector = lhs.moveVector;
	this->circleShape = lhs.circleShape;
	return *this;
  }

  Weapon(Weapon &&lhs)  noexcept {
	this->weapon = lhs.weapon;
	this->crosshairSprite.swap(lhs.crosshairSprite);
	this->crosshairTexture.swap(lhs.crosshairTexture);
	this->moveVector = lhs.moveVector;
	this->circleShape = lhs.circleShape;
  }

  Weapon(Weapon &lhs) {
	this->weapon = lhs.weapon;
	this->crosshairSprite.swap(lhs.crosshairSprite);
	this->crosshairTexture.swap(lhs.crosshairTexture);
	this->moveVector = lhs.moveVector;
	this->circleShape = lhs.circleShape;
  }

  Weapon(sf::RectangleShape &weapon, std::unique_ptr<sf::Texture> &crosshairTexture_) :
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

	std::swap(crosshairTexture, crosshairTexture_);
	auto size = crosshairTexture->getSize();
	crosshairSprite = std::make_unique<sf::Sprite>(*crosshairTexture);
	crosshairSprite->setOrigin(size.x / 2.f, size.y / 2.f);
	crosshairSprite->setScale(0.3, 0.3);
  }

  Weapon(sf::RectangleShape &weapon, sf::Texture &crosshairTexture_) :
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
	crosshairSprite = std::make_unique<sf::Sprite>(*crosshairTexture);
	crosshairSprite->setOrigin(size.x / 2.f, size.y / 2.f);
	crosshairSprite->setScale(0.02, 0.02);
  }

  sf::CircleShape circleShape;
  sf::RectangleShape moveVector;
  sf::RectangleShape weapon;
  std::unique_ptr<sf::Sprite> weaponSprite;
  std::unique_ptr<sf::Texture> weaponTexture;
  std::unique_ptr<sf::Texture> crosshairTexture;
  std::unique_ptr<sf::Sprite> crosshairSprite;
};

//TODO: ??? Действительно расширяем Weapon ???
struct Player : Position, Weapon, RenderableSprite, Angle, Health, Experience {

  Player &operator=(Player &&lhs) noexcept {
	this->body = lhs.body;
	this->position = lhs.position;
	this->angle = lhs.angle;
	this->health = lhs.health;
	this->texture.swap(lhs.texture);
	this->sprite.swap(lhs.sprite);
	this->isOnAir = lhs.isOnAir;
	this->experience = lhs.experience;
	return *this;
  }

  Player(Player &&lhs)  noexcept :
	  Position(lhs.position),
	  Weapon(lhs.weapon, lhs.crosshairTexture),
	  RenderableSprite(lhs.texture),
	  Angle(lhs.angle),
	  Health(lhs.health),
	  Experience(lhs.experience),
	  isOnAir(lhs.isOnAir),
	  body(lhs.body) {}

  Player(Player &lhs) :
	  Position(lhs.position),
	  Weapon(lhs.weapon, lhs.crosshairTexture),
	  RenderableSprite(lhs.texture),
	  Angle(lhs.angle),
	  Health(lhs.health),
	  Experience(lhs.experience),
	  isOnAir(lhs.isOnAir),
	  body(lhs.body) {}

  Player(sf::Vector2<float> &position,
		 sf::RectangleShape &weapon,
		 sf::Texture &crosshairTexture,
		 sf::Texture &texture,
		 float angle,
		 long health,
		 long experience,
		 bool isOnAir,
		 b2Body *body) :
	  Position(position),
	  Weapon(weapon, crosshairTexture),
	  RenderableSprite(texture),
	  Angle(angle),
	  Health(health),
	  Experience(experience),
	  isOnAir(isOnAir),
	  body(body) {}

  bool isOnAir;
  b2Body *body;
};

struct Enemy : Position, RenderableSprite, Angle, Health {

  virtual ~Enemy() {
    std::cout << "Enemy dtor call for: " << this << std::endl;
  }

  Enemy &operator=(const Enemy &lhs) {
	std::cout << "Enemy move assignment for: " << std::addressof(lhs) << std::endl;
	this->body = lhs.body;
	this->position = lhs.position;
	this->angle = lhs.angle;
	this->health = lhs.health;
	this->texture = std::make_unique<sf::Texture>(*lhs.texture);
	this->sprite = std::make_unique<sf::Sprite>(*lhs.sprite->getTexture(), lhs.sprite->getTextureRect());
	return *this;
  }

  Enemy(Enemy &&lhs)  noexcept : Health() {
	std::cout << "Enemy Move ctor for: " << std::addressof(lhs) << std::endl;
	this->body = lhs.body;
	this->position = lhs.position;
	this->angle = lhs.angle;
	this->health = lhs.health;
	//TODO: Действительно? Мы же делаем move?
	this->texture = std::make_unique<sf::Texture>(*lhs.texture);
	this->sprite = std::make_unique<sf::Sprite>(*lhs.sprite->getTexture(), lhs.sprite->getTextureRect());
  }

  Enemy(Enemy &lhs)  : Position(lhs),
  RenderableSprite(lhs),
  Angle(lhs),
  Health(lhs) {
	std::cout << "Enemy copy ctor for: " << std::addressof(lhs) << std::endl;
	this->body = lhs.body;
	this->position = lhs.position;
  }

  Enemy(const sf::Vector2<float> &position,
		const sf::Texture &texture,
		float angle,
		b2Body *body,
		long health) :
	  Position(position),
	  RenderableSprite(texture),
	  Angle(angle),
	  body(body),
	  Health(health) {}

  b2Body *body;
};
}