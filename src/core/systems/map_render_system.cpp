//
// Created by yacopsae on 13/10/2021.
//

#include <SFML/Graphics/RectangleShape.hpp>

#include "game_components.hpp"
#include "map_render_system.hpp"
#include "engine.hpp"
#include "utils.hpp"

MapRenderSystem::MapRenderSystem() = default;

void MapRenderSystem::onInit() {
}

void MapRenderSystem::update(const float dt) {
  auto view = registry->view<GameComponents::Map, GameComponents::LevelEnd>();
  view.each([this, dt](const GameComponents::Map &map,
					   GameComponents::LevelEnd &levelEnd) {
	for (const auto &entry: map.mapLayers) {
	  engine->getWindow().draw(*entry.second);
	}
  });

  auto playerView = registry->view<GameComponents::RenderableSprite, GameComponents::PlayerPosition, GameComponents::PlayerBody, GameComponents::Weapon>();
  playerView.each([this](const GameComponents::RenderableSprite &texurable,
						 const GameComponents::PlayerPosition &playerPosition,
						 const GameComponents::PlayerBody &playerBody,
						 const GameComponents::Weapon &weapon) {

	texurable.sprite->setRotation(Utils::radiansToAngle(playerPosition.angle));
	texurable.sprite->setPosition(playerPosition.position);


	engine->getWindow().draw(*texurable.sprite);

	auto &view = engine->getView();
	view.setCenter(playerPosition.position);
	engine->getWindow().setView(view);
  });

  auto bulletView = registry->view<GameComponents::Bullet>();
  bulletView.each([this](const GameComponents::Bullet &bullet) {

    auto sfPosition = Utils::b2VecToVector2(bullet.body->GetPosition());

	sf::RectangleShape rectangleShape{{1, 1}};
	rectangleShape.setFillColor(sf::Color::Magenta);
	rectangleShape.setOutlineColor(sf::Color::Black);
	rectangleShape.setOutlineThickness(0.1f);
	rectangleShape.setPosition(sfPosition);

	engine->getWindow().draw(rectangleShape);
  });

  this->engine->getBox2DWorld().DebugDraw();
}