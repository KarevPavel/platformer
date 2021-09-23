//
// Created by yacopsae on 18/08/2021.
//
#pragma once

#include <SFML/Graphics.hpp>
#include <keyboard.h>
#include <player_model.h>
#include "general.h"

class Player : public core::model::Position, public core::model::Health {
 public:
  explicit Player(PlayerModel &model);
  const int MOVEMENT_SPEED = 5;
  Player(double totalHp, float x, float y);
  void moveRight();
  void moveLeft();
  void moveUp();
  void crouch();
  void jump();
 private:
  sf::Sprite sprite;
  sf::Texture texture;
};