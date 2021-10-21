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
  explicit Position(sf::Vector2<float> position) : position(position) {}
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
  explicit LevelStart(sf::Vector2f position) : Position(position) {}
};

struct LevelEnd : Position {
  LevelEnd() = default;
  explicit LevelEnd(sf::Vector2f position) : Position(position) {}
  explicit LevelEnd(const sf::Vector2f &position) : Position(position) {}
};

struct PlayerSpawn : Position {
  PlayerSpawn() = default;
  explicit PlayerSpawn(sf::Vector2f position) : Position(position) {}
  explicit PlayerSpawn(const sf::Vector2f &position) : Position(position) {}
};

struct EnemySpawn : Position {
  EnemySpawn() = default;
  explicit EnemySpawn(sf::Vector2f position) : Position(position) {}
  explicit EnemySpawn(tmx::Vector2f position) : Position({position.x, position.y}) {}
};

struct Map {
  explicit Map(std::map<std::string, std::unique_ptr<MapLayer>> &mapLayers,
			   std::vector<std::unique_ptr<EnemySpawn>> &enemySpawns,
			   GameComponents::LevelStart levelStart,
			   GameComponents::LevelEnd levelEnd,
			   GameComponents::PlayerSpawn playerSpawn) :
	  mapLayers(std::move(mapLayers)),
	  enemySpawns(std::move(enemySpawns)),
	  levelStart(levelStart),
	  levelEnd(levelEnd),
	  playerSpawn(playerSpawn) {}

  std::map<std::string, std::unique_ptr<MapLayer>> mapLayers;
  std::vector<std::unique_ptr<EnemySpawn>> enemySpawns;
  GameComponents::LevelStart levelStart;
  GameComponents::LevelEnd levelEnd;
  GameComponents::PlayerSpawn playerSpawn;
};

}