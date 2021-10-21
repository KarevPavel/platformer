//
// Created by yacopsae on 13/10/2021.
//

#include <sound_system.hpp>
#include "scene.hpp"
#include "music_system.hpp"
#include "map_render_system.hpp"
#include "levels.hpp"
#include "game_system.hpp"
#include "game_scene.hpp"
#include "engine.hpp"

GameScene::GameScene() : Scene("game") {

}

GameScene::~GameScene() = default;

void GameScene::init() {
  em.init(engine);
  em.addSystem(std::make_unique<GameSystem>());
  em.addSystem(std::make_unique<MusicSystem>());
  em.addSystem(std::make_unique<SoundSystem>());

  //triggers level tmx file parsing
  em.getEventDispatcher()->trigger<GameEvent::GameStart>(constants::LEVEL1_PATH);


  em.addRenderSystem(std::make_unique<MapRenderSystem>());

  em.getEventDispatcher()->trigger<SoundEvent::MusicStop>();
}

void GameScene::update() {
  sf::Event event;
  while (window->pollEvent(event)) {
	handleDefaultEvents(&event);
  }
}

/*
void GameScene::test(sf::Event *event) {
  // Zoom in & zoom out the view
  if (event->type == sf::Event::MouseWheelScrolled) {
	// Saves coordinates of the mouse on the screen
	const sf::Vector2f oldCoordinates{
		window->mapPixelToCoords({event->mouseWheelScroll.x, event->mouseWheelScroll.y})
	};

	// Zoom in & out, and also scales the timer size
	const auto currentZoom = window->getView().getSize().x;
	const auto maximumZoom = window->getDefaultView().getSize().x * maxZoomFactor;
	const auto minimumZoom = window->getDefaultView().getSize().x / maxZoomFactor;

	// Zooming in
	if (event->mouseWheelScroll.delta > 0) {
	  if (currentZoom > minimumZoom)
		_worldView.zoom(1.f / 1.1f);
	}
	  // Zooming out
	else {
	  if (currentZoom < maximumZoom)
		_worldView.zoom(1.1f);


	  // This check if player do not scroll outside world boundaries

	  // First I create a boundary of the screen
	  const auto viewTopLeft = _window.mapPixelToCoords({0, 0});
	  sf::RectangleShape viewBorder(sf::Vector2f(_worldView.getSize()));
	  viewBorder.setPosition(viewTopLeft);

	  // And a proper parameters
	  const auto viewBottomRight = sf::Vector2f(viewBorder.getPosition().x + viewBorder.getGlobalBounds().width,
												viewBorder.getPosition().y + viewBorder.getGlobalBounds().height);

	  // Check if player do not zoom outside the world boundary
	  // If so, then zoom back again
	  if (viewBottomRight.x > mostPositionedX || viewBottomRight.y > mostPositionedY || viewTopLeft.x < lessPositionedX
		  || viewTopLeft.y < lessPositionedY)
		_worldView.zoom(1.f / 1.1f);
	}

	// Sets the new view to the window
	_window.setView(_worldView);

	// Reads the "new" position of the mouse (it changed since the zoom is different)
	const auto newCoordinates{
		_window.mapPixelToCoords({event.mouseWheelScroll.x, event.mouseWheelScroll.y})
	};

	// It moves the view, so it will "zoom into" the cursor, and not into the center of the screen
	_worldView.move({oldCoordinates - newCoordinates});
	_window.setView(_worldView);

	// Fixes the background
	backgroundSprite.setTextureRect(sf::IntRect(0,
												0,
												static_cast<int>(_worldView.getSize().x),
												static_cast<int>(_worldView.getSize().y)));
	backgroundSprite.setPosition(_window.mapPixelToCoords({0, 0}));
  }
}*/

void GameScene::fixedUpdate(const float dt) {
  em.onUpdate(dt);
}

void GameScene::render(const float alpha_lerp) {
  window->clear(sf::Color(255, 255, 255));

  em.onRender(alpha_lerp);

  window->display();
}

