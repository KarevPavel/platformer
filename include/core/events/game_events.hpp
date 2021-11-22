//
// Created by yacopsae on 13/10/2021.
//

#pragma once

#include <string>
#include <utility>

namespace GameEvent {


struct LoadLevelEvent {
  explicit LoadLevelEvent(std::string level) : level(std::move(level)) {

  }

  LoadLevelEvent() = default;

  std::string level;
};

}