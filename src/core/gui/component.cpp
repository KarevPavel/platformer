//
// Created by yacopsae on 23/09/2021.
//

#include "component.hpp"

Component::Component() :
	_isSelected(false),
	_isActive(false) {}

bool Component::isSelected() const {
  return _isSelected;
}

void Component::onEnter() {
  _isSelected = true;
}

void Component::onLeave() {
  _isSelected = false;
}

bool Component::isActive() const {
  return _isActive;
}

void Component::activate() {
  _isActive = true;
}

void Component::deactivate() {
  _isActive = false;
}

void Component::setPositionBelow(const Component &object, float padding) {
  const sf::Vector2f pos(object.getPosition().x, object.getPosition().y);

  sf::Vector2f offset(0, object.getGlobalBounds().height);

  padding *= getScale().y;
  offset *= getScale().y;
  setPosition(pos + offset + sf::Vector2f(0, padding));
}
