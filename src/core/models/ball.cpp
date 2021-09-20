//
// Created by yacopsae on 14/11/2020.
//

#include "ball.h"

Ball::Ball(float &x,
		   float &y,
		   float &oX,
		   float &oY,
		   float radius,
		   float pointOfViewGrad,
		   float visibleDistance,
		   sf::RenderWindow &window) :
	x(x),
	y(y),
	radius_(radius),
	pointOfView(oX, oY, pointOfViewGrad, visibleDistance, window),
	window(window) {
  circleShape = sf::CircleShape{radius};
  circleShape.setOutlineColor(sf::Color::Red);
  circleShape.setOutlineThickness(2);
  circleShape.setFillColor(sf::Color::Black);
  circleShape.setPosition(x, y);
}

void Ball::rotateRight(float timeElapsed) {
  basicRotate(MOVEMENT_SPEED * timeElapsed);
}

sf::Vector2i pixelPos_;

void Ball::mouseRotate(float timeElapsed) {
  // get the current mouse position in the _window
  sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
  if (pixelPos_ != pixelPos) {
	pixelPos_ = pixelPos;
	// convert it to world coordinates
	sf::Vector2f mPos = window.mapPixelToCoords(pixelPos, window.getView());
	sf::Vector2f oPos = pointOfView.getCenter();

	float dX = mPos.x - oPos.x;//вектор , колинеарный прямой, которая пересекает спрайт и курсор
	float dY = mPos.y - oPos.y;//он же, координата y
	float rotation = (std::atan2(dY, dX)) * 180 / M_PI;//получаем угол в радианах и переводим его в градусы
	pointOfView.rotate(rotation);//поворачиваем спрайт на эти градусы
	//_window.clear();
	drawMe();
  }
}

double Ball::distance(sf::Vector2f a, sf::Vector2f b) {
  return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

void Ball::rotateLeft(float timeElapsed) {
  basicRotate(-MOVEMENT_SPEED * timeElapsed);
}

void Ball::moveLeft(float timeElapsed) {
  dummyMovement(-MOVEMENT_SPEED * timeElapsed);
}

void Ball::moveRight(float timeElapsed) {
  dummyMovement(MOVEMENT_SPEED * timeElapsed);
}

void Ball::moveForward(float timeElapsed) {
  basicMovement(MOVEMENT_SPEED * timeElapsed);
}

void Ball::moveBackward(float timeElapsed) {
  basicMovement(-MOVEMENT_SPEED * timeElapsed);
}

void Ball::basicRotate(const float rotateAngle) {
  pointOfView.rotate(rotateAngle);
  window.clear();
  drawMe();
}

void Ball::drawMe() {
  window.draw(circleShape);
  pointOfView.drawMe();
}

void Ball::basicMovement(const float movementDirection) {
  sf::Vector2<float> xy = pointOfView.getPointsOnVector(x, y, movementDirection);

  /* if (!level.hasCollision(circleShape.getGlobalBounds()) ||
   !level.hasCollision(pointOfView.getMoveVector().getGlobalBounds())) {
	   updatePosXY(xy);

	   _window.clear();
	   _window.draw(circleShape);

	   xy.x += radius_;
	   xy.y += radius_;
	   pointOfView.updatePosXY(xy);
	   pointOfView.drawMe();
   }*/
}

void Ball::dummyMovement(const float movementDirection) {
  auto v = sf::Vector2{x + movementDirection, y};
  updatePosXY(v);

}

void Ball::updatePosXY(sf::Vector2<float> &xy) {
  y = xy.y;
  x = xy.x;
  circleShape.setPosition(xy.x, xy.y);
}

sf::Vector2f Ball::getCord() const {
  return {x, y};
}

void Ball::update(sf::Time timeElapsed, std::list<MapLayer> &list) {

  mouseRotate(timeElapsed.asMilliseconds());


  //calc collisions
  bool hasCollision = false;

  if (!hasCollision) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
	  //rotateLeft(timeElapsed.asMilliseconds());
	  moveLeft(timeElapsed.asMilliseconds());
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && hasCollision) {
	  //moveForward(timeElapsed.asMilliseconds());
	  //jump(timeElapsed.asMilliseconds());
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
	  //moveBackward(timeElapsed.asMilliseconds());
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
	  //rotateRight(timeElapsed.asMilliseconds());
	  moveRight(timeElapsed.asMilliseconds());
	}
  }
  drawMe();
}
