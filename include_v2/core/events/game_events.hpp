//
// Created by yacopsae on 13/10/2021.
//

#pragma once

#include <string>
#include <utility>

namespace GameEvent {


struct GameStart {
  explicit GameStart(std::string level) : level(std::move(level)) {

  }

  GameStart() = default;

  std::string level;
};

}