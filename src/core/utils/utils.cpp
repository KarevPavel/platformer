#include "utils.hpp"

void Utils::centerOrigin(sf::Text &text) {
  const sf::FloatRect rect = text.getLocalBounds();
  text.setOrigin(rect.left + rect.width / 2.f, rect.top + rect.height / 2.f);
}

void Utils::centerOrigin(sf::Sprite &sprite) {
  const sf::FloatRect rect = sprite.getLocalBounds();
  sprite.setOrigin(rect.left + rect.width / 2.f, rect.top + rect.height / 2.f);
}

sf::Vector2f Utils::getPositionBelow(const sf::Text &text) {
  sf::Vector2f position = text.getPosition();
  sf::Vector2f heightFromPosition =
	  sf::Vector2f(0, text.getGlobalBounds().height - text.getLocalBounds().top);
  return sf::Vector2f(position + heightFromPosition);
}