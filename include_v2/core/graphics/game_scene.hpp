//
// Created by yacopsae on 13/10/2021.
//

#pragma once

#include <entity_manager.hpp>
#include "scene.hpp"

class GameScene : public Scene
{
  EntityManager em;

 public:
  GameScene();
  ~GameScene();

  void init() override;
  void update() override;
  void fixedUpdate(const float dt) override;
  void render(const float alpha_lerp) override;
};

