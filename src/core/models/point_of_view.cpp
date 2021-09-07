
#include <point_of_view.h>
#include <cmath>

void point_of_view::drawMe() {
  window.draw(rightRect);
  window.draw(leftRect);
  window.draw(moveVector);
}

void point_of_view::rotate(float newAngle) {
  //        leftRect.setFillColor(sf::Color::Green);
  //        rightRect.setFillColor(sf::Color::Blue);
  rightRect.setRotation(newAngle - 45);
  leftRect.setRotation(newAngle - 135);
  moveVector.setRotation(newAngle - 90);
}

void point_of_view::updatePosXY(sf::Vector2<float> &coordinates) {
  rightRect.setPosition(coordinates);
  leftRect.setPosition(coordinates);
  moveVector.setPosition(coordinates);
  x_ = coordinates.x;
  y_ = coordinates.y;
}

sf::Vector2<float> point_of_view::getPointsOnVector(const float x, const float y, float lenght) const {
  //Remark: Т.к. у  SFML система координат по Y перевёрнута
  std::cout << "lenght " << lenght << std::endl;
  std::cout << "moveVector.getRotation() " << moveVector.getRotation() << std::endl;
  std::cout << "getRadians() " << getRadians() << std::endl;
  sf::Vector2<float> result = {x + lenght * std::cos(getRadians()), y + lenght * std::sin(getRadians())};
  std::cout << "old x: " << x_ << " new x: " << result.x << std::endl;
  std::cout << "old y_: " << y_ << " new y_: " << result.y << std::endl;

  return result;
}

float point_of_view::getRadians() const {
  const float halfC = M_PI / 180;
  return (moveVector.getRotation() + 90) * halfC;
}

float point_of_view::getDegrees() const {
  return moveVector.getRotation();
}

sf::Vector2<float> point_of_view::getCenter() const {
  return {x_, y_};
}
