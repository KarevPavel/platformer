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
  auto view = registry->view<GameComponents::Map>();
  view.each([this, dt](const GameComponents::Map &map) {
	for (const auto &entry: map.mapLayers) {
	  entry.second->update(dt);
	  engine->getWindow().draw(*entry.second);
	}
  });
}