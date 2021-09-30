#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

namespace Utils {
void centerOrigin(sf::Text &text);
void centerOrigin(sf::Sprite &sprite);
sf::Vector2f getPositionBelow(const sf::Text &text);
}