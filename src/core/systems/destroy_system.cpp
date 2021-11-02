//
// Created by yacopsae on 02/11/2021.
//

#include "destroy_system.hpp"
#include "game_components.hpp"
#include "engine.hpp"
#include <entt/entity/fwd.hpp>

DestroySystem::DestroySystem() = default;

void DestroySystem::onInit() {}

void DestroySystem::update(const float dt) {
  for (auto &d : deletions)
	engine->getBox2DWorld().DestroyBody(d);
  deletions.clear();
}

void DestroySystem::BeginContact(b2Contact *contact) {
  const auto &fixture1 = contact->GetFixtureA();
  const auto &fixture2 = contact->GetFixtureB();

  auto ObjType1 = reinterpret_cast<GameComponents::Collision *>(fixture1->GetUserData().pointer);
  auto ObjType2 = reinterpret_cast<GameComponents::Collision *>(fixture2->GetUserData().pointer);

  doIfAny(
	  ObjType1,
	  ObjType2,
	  GameComponents::ObjectType::BULLET,
	  GameComponents::ObjectType::STATIC,
	  [this, ObjType1, fixture1, fixture2]() {

		if (ObjType1->objectType == GameComponents::ObjectType::BULLET)
		  deletions.push_back(fixture1->GetBody());
		else
		  deletions.push_back(fixture2->GetBody());
	  }
  );

  doIfAny(
	  ObjType1,
	  ObjType2,
	  GameComponents::ObjectType::BULLET,
	  GameComponents::ObjectType::ENEMY,
	  [this, ObjType1, ObjType2, fixture1, fixture2]() {

		if (ObjType1->objectType == GameComponents::ObjectType::BULLET)
		  deletions.push_back(fixture1->GetBody());
		else
		  deletions.push_back(fixture2->GetBody());

		if (ObjType1->objectType == GameComponents::ObjectType::ENEMY) {
		  auto enemy = registry->get<GameComponents::EnemyPosition>(*ObjType1->entity);
		  enemy.health -= 50;
		  if (enemy.health <= 0) {
			deletions.push_back(fixture1->GetBody());
		  }
		  registry->emplace_or_replace<GameComponents::EnemyPosition>(*ObjType1->entity, enemy);
		} else {
		  auto enemy = registry->get<GameComponents::EnemyPosition>(*ObjType2->entity);
		  enemy.health -= 50;
		  if (enemy.health <= 0) {
			deletions.push_back(fixture2->GetBody());
		  }
		  registry->emplace_or_replace<GameComponents::EnemyPosition>(*ObjType2->entity, enemy);
		}
	  }
  );
}

void DestroySystem::EndContact(b2Contact *contact) {

}