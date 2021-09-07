//
// Created by yacopsae on 14/10/2020.
//

#include <player.h>

Player::Player(double totalHp, float x, float y) : Health(totalHp), Position(x, y) {
  texture.loadFromFile("./resources/3dsoldier.png", sf::IntRect(10, 10, 32, 60));
  sprite.setTexture(texture);
  sprite.setPosition(50, 50);
}

void Player::moveRight() {
  sprite.move(MOVEMENT_SPEED, 0);;
}

void Player::moveLeft() {
  sprite.move(-MOVEMENT_SPEED, 0);
}

void Player::moveUp() {
  sprite.move(0, -MOVEMENT_SPEED);
}

void Player::crouch() {
  sprite.move(0, MOVEMENT_SPEED);
}

void Player::jump() {
  sprite.move(0, -MOVEMENT_SPEED);
}