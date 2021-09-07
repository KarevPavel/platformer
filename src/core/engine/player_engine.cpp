#include <player_engine.h>

namespace core::engine {

PlayerEngine::PlayerEngine(PlayerModel &player) : KeyboardEngine(player), elapsed(0.f) {}

void PlayerEngine::D_click() {
  //control.moveRight();
}

void PlayerEngine::A_click() {
  // control.moveLeft();
}

void PlayerEngine::W_click() {
  //control.moveUp();
}

void PlayerEngine::S_click() {
  //control.crouch();
}

void PlayerEngine::Space_click() {
  // control.jump();
}

void PlayerEngine::processEvent(sf::Event::KeyEvent keyevent, float elapsedSec) {

}
}
