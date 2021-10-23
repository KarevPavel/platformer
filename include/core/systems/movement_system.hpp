//
// Created by yacopsae on 23/10/2021.
//

#pragma once

#include "base_system.hpp"

class MovementSystem:  public BaseSystem {
  void onInit() override;

 public:
  MovementSystem();

  void update(float dt) override;
};


