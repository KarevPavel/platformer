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

namespace GameComponents {

struct Position {
  Position() = default;
  explicit Position(const sf::Vector2<float> &position) : position(position) {}
  sf::Vector2<float> position;
};

struct Bullet {
  Bullet(const sf::Vector2f &position,
		 const sf::Vector2f &direction) :
	  position(position), direction(direction) {
  }

  sf::Vector2f position, direction;
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

  RenderableSprite(const std::string &texturePath, const sf::IntRect &spritePos) {
	texture = std::make_unique<sf::Texture>();
	if (!texture->loadFromFile(texturePath)) {
	  std::cout << "Something going wrong!" << std::endl;
	}
	sprite = std::make_unique<sf::Sprite>(*texture, spritePos);
  }
  std::unique_ptr<sf::Texture> texture;
  std::unique_ptr<sf::Sprite> sprite;
};

struct Body {

  explicit Body(b2Body *body, const Position &wrappedObjPos): body(body), wrappedObjPos(wrappedObjPos) {}

  b2Body *body;
  Position wrappedObjPos;
};

}