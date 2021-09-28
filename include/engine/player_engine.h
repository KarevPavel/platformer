//
// Created by yacopsae on 06/10/2020.
//

#pragma once

#include <SFML/Graphics.hpp>

#include "player_model.h"
#include "keyboard.h"

namespace core::engine {

class PlayerEngine : public core::keyboard::KeyboardEngine<PlayerModel> {

 private:
  float elapsed;

 public:
  explicit PlayerEngine(PlayerModel &model);

  void processEvent(sf::Event::KeyEvent keyevent, float elapsedSec);

  void D_click();

  void A_click();

  void W_click();

  void S_click();

  void Space_click();
};
}