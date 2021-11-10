//
// Created by yacopsae on 13/10/2021.
//

#include "game_components.hpp"
#include "render_system.hpp"
#include "engine.hpp"
#include "utils.hpp"
#include "map_layer.hpp"

RenderSystem::RenderSystem() = default;

void RenderSystem::onInit() {
}

void RenderSystem::update(const float dt) {
  registry->view<GameComponents::Map, GameComponents::LevelEnd>()
	  .each([this](const GameComponents::Map &map,
				   GameComponents::LevelEnd &levelEnd) {
		for (const auto &entry: map.mapLayers) {
		  engine->getWindow().draw(*entry.second);
		}
	  });

  registry->view<GameComponents::Player>()
	  .each([this](GameComponents::Player& player) {

		engine->getWindow().draw(*player.sprite);
		engine->getWindow().draw(player.weapon);
		engine->getWindow().draw(*player.crosshair);
		engine->getWindow().draw(player.moveVector);
		engine->getWindow().draw(player.circleShape);

		auto &view = engine->getView();
		view.setCenter(player.position);
		engine->getWindow().setView(view);
	  });

  auto bulletView = registry->view<GameComponents::Bullet>();
  bulletView.each([this](GameComponents::Bullet &bullet) {
	engine->getWindow().draw(bullet.rectangleShape);
  });

  this->engine->getBox2DWorld().DebugDraw();
}