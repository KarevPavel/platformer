//
// Created by yacopsae on 16/09/2021.
//

#include "world.hpp"
#include "textures.hpp"

World::World(sf::RenderWindow &window) :
	_window(window),
	_worldView(window.getDefaultView()),
	b2_World(b2Vec2(0.f, 9.8f)),
	debugDraw(window) {

  // Tells the physical world what to draw
  b2_World.SetDebugDraw(&debugDraw);
  loadResources();

  backgroundSprite.setTexture(texture_manager.getResourceReference(constants::BLACK_PATH));
  backgroundSprite.setTextureRect(sf::IntRect(0, 0, _worldView.getSize().x, _worldView.getSize().y));

  // Connects the listener responsible for collision handling inside
  // the physical game world with the physical game world
  b2_World.SetContactListener(&worldListener);

}
void World::update(sf::Time deltaTime) {
  moveScreenWithMouse();

  // Update sound player position to the position of the camera
  worldSounds.setListenerPosition(_worldView.getCenter());
  worldSounds.removeFinishedSounds();

  // Update the Game World
  //rootScene.update(deltaTime);

  // Check if there is anything to remove
  //rootScene.removeDestroyed();

  // Update the physical world
  b2_World.Step(1 / 60.f, 8, 3);
}

void World::draw() const {
  // Draw Background
  _window.draw(backgroundSprite);

  // Draw World
  //_window.draw(rootScene);

  // Some hack as Box2D drawDebug is non-const
  const_cast<World *>(this)->box2DdrawDebug();
}

void World::box2DdrawDebug() {
  b2_World.DebugDraw();
}

void World::processEvents(const sf::Event &event) {

  // Zoom in & zoom out the view
  if (event.type == sf::Event::MouseWheelScrolled) {
	// Saves coordinates of the mouse on the screen
	const sf::Vector2f oldCoordinates{
		_window.mapPixelToCoords({event.mouseWheelScroll.x, event.mouseWheelScroll.y})
	};

	// Zoom in & out, and also scales the timer size
	const auto currentZoom = _worldView.getSize().x;
	const auto maximumZoom = _window.getDefaultView().getSize().x * maxZoomFactor;
	const auto minimumZoom = _window.getDefaultView().getSize().x / maxZoomFactor;


	// Zooming in
	if (event.mouseWheelScroll.delta > 0) {
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
}

bool World::isGameFinished() const {
  return false;
}

void World::loadResources() {

}

void World::createWorld() {

}

void World::updateWorldBoundaries(sf::Vector2f position, sf::Vector2f dimensions) {

}

void World::moveScreenWithMouse() {

}

