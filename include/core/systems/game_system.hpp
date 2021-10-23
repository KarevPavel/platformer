//
// Created by yacopsae on 14/10/2021.
//

#pragma once

#include <map>
#include <list>

#include <tmxlite/Tileset.hpp>
#include <tmxlite/TileLayer.hpp>

#include <SFML/Graphics/Sprite.hpp>

#include "map/map_layer.hpp"

#include "base_system.hpp"
#include "game_events.hpp"
#include "game_components.hpp"

// TODO: ВООБЩЕ НАФИГ ВСЁ НЕПРАВИЛЬНО!!!!
class GameSystem : public BaseSystem {

  void onInit() override;

 public:
  explicit GameSystem();

  void receiveGameStart(const GameEvent::GameStart &event);
  bool LoadFromFile(const std::string &filepath);

 private:
  std::map<std::string, MapLayer::Ptr> mapLayers;
  GameComponents::LevelStart levelStart;
  GameComponents::LevelEnd levelEnd;
  GameComponents::PlayerPosition playerSpawn;
  std::vector<std::unique_ptr<GameComponents::EnemyPosition>> enemySpawns;
};

