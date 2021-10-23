//
// Created by yacopsae on 13/10/2021.
//

#include "game_components.hpp"
#include "map_render_system.hpp"
#include "engine.hpp"

MapRenderSystem::MapRenderSystem() = default;

void MapRenderSystem::onInit() {
}

void MapRenderSystem::update(const float dt) {
  auto view = registry->view<GameComponents::Map, GameComponents::LevelEnd>();
  view.each([this, dt](const GameComponents::Map &map,
					   GameComponents::LevelEnd &levelEnd) {
	for (const auto &entry: map.mapLayers) {
	  //entry.second->update(dt);
	  engine->getWindow().draw(*entry.second);
	}
  });

  auto playerView = registry->view<GameComponents::RenderableSprite, GameComponents::PlayerPosition>();
  playerView.each([this](const GameComponents::RenderableSprite &texurable,
						 const GameComponents::PlayerPosition &playerPosition) {
	texurable.sprite->setPosition(playerPosition.position);
	engine->getWindow().draw(*texurable.sprite);
  });

  this->engine->getBox2DWorld().DebugDraw();
}