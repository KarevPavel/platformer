//
// Created by yacopsae on 01/11/2021.
//

#pragma once

#include "memory"

#include <SFML/Graphics/Drawable.hpp>

class UpdatableMap: public sf::Drawable {

 public:
  using Ptr = std::unique_ptr<UpdatableMap>;
  virtual void update(float dt) = 0;

 private:
  void draw(sf::RenderTarget &rt, sf::RenderStates states) const override = 0;

};


