//
// Created by yacopsae on 22/10/2021.
//

#pragma once

#include "base_system.hpp"
#include "game_events.hpp"

class PhysicsSystem : public BaseSystem {
  void onInit() override;

 public:
  PhysicsSystem();

  void update(float dt) override;


};



