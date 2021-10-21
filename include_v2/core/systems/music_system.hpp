//
// Created by yacopsae on 12/10/2021.
//

#pragma once

#include <sound_events.hpp>
#include "base_system.hpp"
#include "game_events.hpp"

class MusicSystem : public BaseSystem {
  void onInit() override;

 public:
  MusicSystem();

  void receiveMusicStart(const SoundEvent::MusicStart &event);
  void receiveMusicStop(const SoundEvent::MusicStop &event);
};


