//
// Created by yacopsae on 13/10/2021.
//

#include <SFML/Graphics/RectangleShape.hpp>

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

  registry->view<GameComponents::RenderableSprite,
				 GameComponents::PlayerPosition,
				 GameComponents::PlayerBody,
				 GameComponents::Weapon>()
	  .each([this](const GameComponents::RenderableSprite &texurable,
				   const GameComponents::PlayerPosition &playerPosition,
				   const GameComponents::PlayerBody &playerBody,
				   const GameComponents::Weapon &weapon) {

		engine->getWindow().draw(*texurable.sprite);
		engine->getWindow().draw(weapon.weapon);
		engine->getWindow().draw(*weapon.crosshair);
		engine->getWindow().draw(weapon.moveVector);
		engine->getWindow().draw(weapon.circleShape);

		auto &view = engine->getView();
		view.setCenter(playerPosition.position);
		engine->getWindow().setView(view);
	  });

  auto bulletView = registry->view<GameComponents::Bullet>();
  bulletView.each([this](GameComponents::Bullet &bullet) {
	engine->getWindow().draw(bullet.rectangleShape);
  });

  this->engine->getBox2DWorld().DebugDraw();
}