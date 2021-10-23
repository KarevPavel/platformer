//
// Created by yacopsae on 12/10/2021.
//

#pragma once

#include "base_system.hpp"

class EntityManager
{
  class Engine *engine;
  entt::registry registry;
  entt::dispatcher eventDispatcher;

  std::vector<std::unique_ptr<BaseSystem>> systems;
  std::vector<std::unique_ptr<BaseSystem>> render_systems;
 public:
  EntityManager();
  ~EntityManager();

  void init(Engine *engine);

  void onUpdate(float dt);
  void onRender(float alpha_lerp);

  void addSystem(std::unique_ptr<BaseSystem>);
  void addRenderSystem(std::unique_ptr<BaseSystem>);

  inline entt::registry *getDefaultRegistry() { return &registry; }
  inline entt::dispatcher *getEventDispatcher() { return &eventDispatcher; }
};
