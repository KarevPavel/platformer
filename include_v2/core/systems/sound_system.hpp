//
// Created by yacopsae on 20/10/2021.
//

#pragma once

#include <sound_events.hpp>
#include "base_system.hpp"
#include "game_events.hpp"

class SoundSystem : public BaseSystem {
  void onInit() override;

 public:
  SoundSystem();

  void playSound(const SoundEvent::MusicStart &event);
};




