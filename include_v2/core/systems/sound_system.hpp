//
// Created by yacopsae on 12/10/2021.
//

#pragma once

#include "base_system.hpp"
#include "main_menu_music_start_event.hpp"

class SoundSystem : public BaseSystem {
  void onInit() override;

 public:
  SoundSystem();

  void receiveMusicStart(const GameEvent::MusicStart &event);
  void receiveMusicStop(const GameEvent::MusicStop &event);
};


