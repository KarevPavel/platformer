//
// Created by yacopsae on 14/10/2021.
//

#pragma once

#include <utility>
#include <map>
#include <string>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <map/map_layer.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace GameComponents {

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
  explicit EnemyPosition(const tmx::Vector2f &position) : Position({position.x, position.y}) {}
};

struct Map {
  explicit Map(std::map<std::string, std::unique_ptr<MapLayer>> &mapLayers,
			   std::vector<std::unique_ptr<EnemyPosition>> &enemySpawns) :
	  mapLayers(std::move(mapLayers)),
	  enemySpawns(std::move(enemySpawns)) {}

  std::map<std::string, std::unique_ptr<MapLayer>> mapLayers;
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
	sprite->setOrigin(spritePos.width / 2, spritePos.width / 2);
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
  explicit Weapon(const sf::RectangleShape &weapon) : weapon(weapon), moveVector(), circleShape(20) {
	moveVector = sf::RectangleShape({1, 900});
	moveVector.setFillColor(sf::Color::Black);
	moveVector.setPosition(weapon.getPosition());

	circleShape.setOutlineColor(sf::Color::Black);
	circleShape.setFillColor(sf::Color::Transparent);
	circleShape.setOutlineThickness(1.f);
	circleShape.setOrigin(20,20);
	circleShape.setPosition(weapon.getPosition());
  }

  sf::CircleShape circleShape;
  sf::RectangleShape moveVector;
  sf::RectangleShape weapon;
};

}