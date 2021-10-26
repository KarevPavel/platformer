//
// Created by yacopsae on 13/10/2021.
//

#pragma once

#include "base_system.hpp"
#include "game_events.hpp"


class RenderSystem : public BaseSystem {
  void onInit() override;

 public:
  RenderSystem();

  void update(float dt) override;


};


