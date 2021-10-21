//
// Created by yacopsae on 14/10/2021.
//

#include "game_system.hpp"
#include "engine.hpp"
#include "tmxlite/Map.hpp"
#include "levels.hpp"

GameSystem::GameSystem() = default;

void GameSystem::onInit() {
  eventDispatcher->sink<GameEvent::GameStart>().connect<&GameSystem::receiveGameStart>(this);
}

void GameSystem::receiveGameStart(const GameEvent::GameStart &event) {

  LoadFromFile(constants::LEVEL1_PATH);

}

bool GameSystem::LoadFromFile(const std::string &filepath) {
  tmx::Map map;
  map.load(filepath);
  auto &layers = map.getLayers();
  for (const auto &layer : layers) {
	auto layerName = layer->getName();
	if (layer->getType() == tmx::Layer::Type::Tile) {
	  mapLayers.insert(std::make_pair(layerName, std::make_unique<MapLayer>(map, layer, engine->getBox2DWorld())));
	} else if (layer->getType() == tmx::Layer::Type::Object) {

	  const auto objectGroup = layer->getLayerAs<tmx::ObjectGroup>();
	  for (const auto &obj : objectGroup.getObjects()) {
		std::cout << obj.getName() << " [" << obj.getPosition().x << ":" << obj.getPosition().y << "]" << std::endl;
		if (obj.getName() == "LEVEL_START") {
		  levelStart.position.x = obj.getPosition().x;
		  levelStart.position.y = obj.getPosition().y;
		} else if (obj.getName() == "LEVEL_FINISH") {
		  levelEnd.position.x = obj.getPosition().x;
		  levelEnd.position.y = obj.getPosition().y;
		} else if (obj.getName() == "ENEMY_SPAWN") {
		  enemySpawns.push_back(
			  std::make_unique<GameComponents::EnemySpawn>(obj.getPosition())
		  );
		} else if (obj.getName() == "PLAYER_SPAWN") {
		  playerSpawn.position.x = obj.getPosition().x;
		  playerSpawn.position.y = obj.getPosition().y;
		}
	  }
	}
  }

  auto entity = this->registry->create();
  this->registry->emplace<GameComponents::Map>(entity,
											   mapLayers,
											   enemySpawns,
											   levelStart,
											   levelEnd,
											   playerSpawn);


  auto defView = this->engine->getWindow().getDefaultView();
  this->engine->getWindow().setView(sf::View{
	  levelStart.position,
	  {100, 100 },

  });
  return true;
}

void GameSystem::update(const float dt) {


}