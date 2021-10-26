//
// Created by yacopsae on 23/10/2021.
//

#pragma once

#include "base_system.hpp"
#include <box2d/b2_math.h>

class MovementSystem:  public BaseSystem {
  void onInit() override;

 public:
  MovementSystem();

  void update(float dt) override;

 private:
  /**
   * Обработка нажатий клавиатуры/мыши
   */
  void inputProcessing();

  /**
   * Обработка положения пуль
   */
  void bulletsMovement();

  /**
   * Обработка положения игрока (текстуры игрока, оружия)
   */
  void playerMovement();

  void shoot(const b2Vec2& bulletStartPos, const b2Vec2& bulletDirection);

};


