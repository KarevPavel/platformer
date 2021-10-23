//
// Created by yacopsae on 14/10/2021.
//

#include <textures.hpp>
#include "game_system.hpp"
#include "engine.hpp"
#include "tmxlite/Map.hpp"
#include "levels.hpp"
#include "utils.hpp"

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
															sf::IntRect{0, 0, 21, 21}); //TODO: REMOVE MAGIC!!!!
  this->registry->emplace<GameComponents::PlayerPosition>(playerEntity, levelStart.position);
  auto bodyDef = std::make_unique<b2BodyDef>();
  //b2BodyDef b2BodyDef {};

  bodyDef->position =
	  Utils::sfVectorToB2Vec(levelStart.position + sf::Vector2f{21.f / 2, 21.f / 2}); //TODO: REMOVE MAGIC!!!!

  bodyDef->type = b2BodyType::b2_dynamicBody;
  b2Body *body = engine->getBox2DWorld().CreateBody(bodyDef.get());
  auto fixtureDef = std::make_unique<b2FixtureDef>();

  auto shapeSize = Utils::sfVectorToB2Vec(sf::Vector2{21, 21});
  const auto &shape = std::make_unique<b2PolygonShape>();

  shape->SetAsBox(shapeSize.x / 2, shapeSize.y / 2);
  fixtureDef->shape = shape.get();
  fixtureDef->density = 1.0f;
  fixtureDef->friction = 0.3f;
  body->CreateFixture(fixtureDef.get());

  //GameComponents::Body{body, emplaced};

  this->registry->emplace<GameComponents::Body>(playerEntity, body);

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