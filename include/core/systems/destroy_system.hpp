//
// Created by yacopsae on 02/11/2021.
//

#pragma once

#include "base_system.hpp"
#include <box2d/b2_math.h>
#include <box2d/box2d.h>
#include <SFML/Window/Event.hpp>
#include <game_components.hpp>
#include "set"


class DestroySystem:  public BaseSystem, public b2ContactListener {
  void onInit() override;

 public:
  DestroySystem();

  void update(float dt) override;

  void BeginContact(b2Contact *contact) override;
  void EndContact(b2Contact *contact) override;

  struct DeletionEntry {
	b2Body * body;
	entt::entity entityId;
	DeletionEntry(b2Body *body, entt::entity entity_id);

	bool operator<(const DeletionEntry& other) const {
		return this->entityId < other.entityId;
	}
  };

 private:
  template<typename Functor>
  void doIfAny(GameComponents::Collision * collision1, GameComponents::Collision * collision2,
			   GameComponents::ObjectType expectedType1, GameComponents::ObjectType expectedType2,
			   Functor functor);

  std::set<DeletionEntry> deletions;
};

template<typename Functor>
inline void DestroySystem::doIfAny(GameComponents::Collision *collision1,
							GameComponents::Collision *collision2,
							GameComponents::ObjectType expectedType1,
							GameComponents::ObjectType expectedType2,
							Functor functor) {
  if (collision1 != nullptr && collision2 != nullptr)
	if (collision1->objectType != collision2->objectType)
	  if (collision1->objectType == expectedType1 || collision1->objectType == expectedType2)
		if (collision2->objectType == expectedType1 || collision2->objectType == expectedType2)
		  functor();
}