//
// Created by yacopsae on 12/10/2021.
//

#include "base_system.hpp"

BaseSystem::BaseSystem() {
}

BaseSystem::~BaseSystem() {
}

void BaseSystem::init(Engine *e, entt::registry &r, entt::dispatcher &d) {
  registry = &r;
  eventDispatcher = &d;
  engine = e;

  onInit();
}

void BaseSystem::update(const float dt) {

}
