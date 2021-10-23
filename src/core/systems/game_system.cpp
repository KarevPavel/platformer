//
// Created by yacopsae on 14/10/2021.
//

#include <textures.hpp>
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
		  enemySpawns.push_back(std::make_unique<GameComponents::EnemyPosition>(obj.getPosition()));
		} else if (obj.getName() == "PLAYER_SPAWN") {
		  playerSpawn.position.x = obj.getPosition().x;
		  playerSpawn.position.y = obj.getPosition().y;
		}
	  }
	}
  }

  auto playerEntity = this->registry->create();
  this->registry->emplace<GameComponents::RenderableSprite>(playerEntity, constants::PAPER_TEXTURE_PATH,
															sf::IntRect{0, 0, 21, 21});
  auto emplaced = this->registry->emplace<GameComponents::PlayerPosition>(playerEntity, levelStart.position);
  auto bodyDef = std::make_unique<b2BodyDef>();
  //b2BodyDef b2BodyDef {};
  bodyDef->position.x = levelStart.position.x;
  bodyDef->position.y = levelStart.position.y;
  bodyDef->type = b2BodyType::b2_dynamicBody;
  b2Body *body = engine->getBox2DWorld().CreateBody(bodyDef.get());
  auto fixture = std::make_unique<b2FixtureDef>();
  const auto &shape = std::make_unique<b2PolygonShape>();
  shape->SetAsBox(21, 21);
  fixture->shape = shape.get();
  body->CreateFixture(fixture.get());

  //GameComponents::Body{body, emplaced};

  this->registry->emplace<GameComponents::Body>(playerEntity, body, emplaced);

  auto entity = this->registry->create();
  this->registry->emplace<GameComponents::Map>(entity, mapLayers, enemySpawns);
  this->registry->emplace<GameComponents::LevelStart>(entity, levelStart.position);
  this->registry->emplace<GameComponents::LevelEnd>(entity, levelEnd.position);

  auto defView = this->engine->getWindow().getDefaultView();
  this->engine->getWindow().setView(sf::View{
	  levelStart.position,
	  {300, 200},

  });
  return true;
}