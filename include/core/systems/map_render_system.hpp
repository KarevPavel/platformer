//
// Created by yacopsae on 13/10/2021.
//

#pragma once

#include "base_system.hpp"
#include "game_events.hpp"


class MapRenderSystem : public BaseSystem {
  void onInit() override;

 public:
  MapRenderSystem();

  void update(float dt) override;


};


