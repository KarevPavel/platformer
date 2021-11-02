//
// Created by yacopsae on 12/10/2021.
//

#pragma once

#include "base_system.hpp"
#include <SFML/Window/Event.hpp>

class EntityManager
{
  class Engine *engine;
  entt::registry registry;
  entt::dispatcher eventDispatcher;

  std::vector<std::unique_ptr<BaseSystem>> systems;
  std::vector<std::unique_ptr<BaseSystem>> renderSystems;
  std::vector<std::unique_ptr<BaseSystem>> cleanUpSystems;
 public:
  EntityManager();
  ~EntityManager();

  void init(Engine *engine);

  void onUpdate(float dt);
  void onRender(float alpha_lerp);

  void addSystem(std::unique_ptr<BaseSystem>);
  void addRenderSystem(std::unique_ptr<BaseSystem>);
  void addCleanUpSystem(std::unique_ptr<BaseSystem>);

  inline entt::registry *getDefaultRegistry() { return &registry; }
  inline entt::dispatcher *getEventDispatcher() { return &eventDispatcher; }
  void onEvent(sf::Event);
};
