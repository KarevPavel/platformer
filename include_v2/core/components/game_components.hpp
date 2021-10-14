//
// Created by yacopsae on 14/10/2021.
//

#pragma once

#include <SFML/System/Vector2.hpp>
#include <utility>
#include <vector>
#include <SFML/Graphics/Sprite.hpp>

namespace GameComponents {

struct Bullet {
  Bullet(const sf::Vector2f &position,
		 const sf::Vector2f &direction) :
	  position(position), direction(direction) {
  }

  sf::Vector2f position, direction;

};


struct Map {
  explicit Map(std::vector<sf::Sprite*> sprites): sprites(std::move(sprites)) {

  }
  std::vector<sf::Sprite*> sprites;

};

}