//
// Created by yacopsae on 12/10/2021.
//

#include "entity_manager.hpp"

EntityManager::EntityManager() {
}

EntityManager::~EntityManager() {
}

void EntityManager::init(Engine *engine) {
  this->engine = engine;
}

void EntityManager::addSystem(std::unique_ptr<BaseSystem> system) {
  system->init(engine, registry, eventDispatcher);
  systems.push_back(std::move(system));
}

void EntityManager::addRenderSystem(std::unique_ptr<BaseSystem> system) {
  system->init(engine, registry, eventDispatcher);
  renderSystems.push_back(std::move(system));
}

void EntityManager::addCleanUpSystem(std::unique_ptr<BaseSystem> system) {
  system->init(engine, registry, eventDispatcher);
  cleanUpSystems.push_back(std::move(system));
}

void EntityManager::onEvent(sf::Event event) {
  for (auto &s : systems)
	s->onEvent(event);
  for (auto &s : renderSystems)
	s->onEvent(event);
}

void EntityManager::onUpdate(float dt) {
  for (auto &s : cleanUpSystems)
	s->update(dt);

  for (auto &s : systems)
	s->update(dt);
}

void EntityManager::onRender(float alpha_lerp) {
  for (auto &s : renderSystems)
	s->update(alpha_lerp);
}