//
// Created by yacopsae on 14/10/2021.
//

#include <textures.hpp>
#include "game_system.hpp"
#include "engine.hpp"
#include "tmxlite/Map.hpp"
#include "levels.hpp"
#include "utils.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

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
		  enemySpawns.emplace_back( obj.getPosition().x, obj.getPosition().y);
		} else if (obj.getName() == "PLAYER_SPAWN") {
		  playerSpawn.x = obj.getPosition().x;
		  playerSpawn.y = obj.getPosition().y;
		}
	  }
	}
  }


  createPlayer();
  createEnemies();

  auto entity = this->registry->create();
  this->registry->emplace<GameComponents::Map>(entity, mapLayers, enemySpawns);
  this->registry->emplace<GameComponents::LevelStart>(entity, levelStart.position);
  this->registry->emplace<GameComponents::LevelEnd>(entity, levelEnd.position);

  auto defView = this->engine->getWindow().getDefaultView();
  this->engine->getView().setCenter(levelStart.position);
  this->engine->getWindow().setView(this->engine->getView());

  return true;
}

void GameSystem::createPlayer() {
  auto playerEntity = this->registry->create();

  const sf::Texture &texture = engine->getTextureManager().getResource(constants::PAPER_TEXTURE_PATH);

  auto weapon = sf::RectangleShape(sf::Vector2f{2.f, 20.f});
  weapon.setPosition(levelStart.position);
  weapon.setFillColor(sf::Color::Black);

  sf::Texture &crosshairTexture = engine->getTextureManager().getResource(constants::CROSSHAIR_PATH);

  auto bodyDef = std::make_unique<b2BodyDef>();
  bodyDef->position = Utils::sfVectorToB2Vec(levelStart.position);

  bodyDef->type = b2BodyType::b2_dynamicBody;
  b2Body *playerBody = engine->getBox2DWorld().CreateBody(bodyDef.get());
  auto fixtureDef = std::make_unique<b2FixtureDef>();

  auto shapeSize = Utils::sfVectorToB2Vec(sf::Vector2{21, 21});  //TODO: REMOVE MAGIC!!!!
  const auto &shape = std::make_unique<b2PolygonShape>();

  shape->SetAsBox(shapeSize.x / 2, shapeSize.y / 2);
  fixtureDef->shape = shape.get();
  fixtureDef->density = 1.0f;
  fixtureDef->friction = 0.7f;
  fixtureDef->userData.pointer =
	  reinterpret_cast<uintptr_t>(new GameComponents::Collision(std::make_unique<entt::entity>(playerEntity),
																GameComponents::ObjectType::PLAYER));
  playerBody->CreateFixture(fixtureDef.get());

  this->registry->emplace<GameComponents::Player>(playerEntity,
												  levelStart.position,
												  weapon,
												  crosshairTexture,
												  texture,
												  0,
												  100,
												  0,
												  false,
												  playerBody);
}

void GameSystem::createEnemies() {
	for(const auto &enemy: enemySpawns) {
	  auto enemiesEntity = this->registry->create();

	  const sf::Texture &texture = engine->getTextureManager().getResource(constants::ZOMBIE_IDLE_0_PATH);

	  auto bodyDef = std::make_unique<b2BodyDef>();
	  bodyDef->position = Utils::sfVectorToB2Vec(enemy);

	  bodyDef->type = b2BodyType::b2_dynamicBody;
	  b2Body *enemyBody = engine->getBox2DWorld().CreateBody(bodyDef.get());
	  auto fixtureDef = std::make_unique<b2FixtureDef>();

	  auto shapeSize = Utils::sfVectorToB2Vec(sf::Vector2{16, 16});  //TODO: REMOVE MAGIC!!!!
	  const auto &shape = std::make_unique<b2PolygonShape>();

	  shape->SetAsBox(shapeSize.x / 2, shapeSize.y / 2);
	  fixtureDef->shape = shape.get();
	  fixtureDef->density = 1.0f;
	  fixtureDef->friction = 0.7f;
	  fixtureDef->userData.pointer =
		  reinterpret_cast<uintptr_t>(new GameComponents::Collision(std::make_unique<entt::entity>(enemiesEntity), GameComponents::ObjectType::ENEMY));
	  enemyBody->CreateFixture(fixtureDef.get());


	  this->registry->emplace<GameComponents::Enemy>(enemiesEntity, enemy, texture, 0, enemyBody, 100);
	}
}