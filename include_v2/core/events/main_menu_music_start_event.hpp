//
// Created by yacopsae on 13/10/2021.
//

#pragma once

#include <string>
#include <utility>

namespace GameEvent {
struct MusicStart {

  explicit MusicStart(std::string musicPath) : musicPath(std::move(musicPath)) {
  }
  MusicStart() = default;
  std::string musicPath;

};

struct MusicStop {
  MusicStop() = default;
};
}