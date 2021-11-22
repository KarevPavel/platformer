//
// Created by yacopsae on 02/11/2021.
//

#include "contact_system.hpp"
#include "game_components.hpp"
#include "engine.hpp"
#include <entt/entity/fwd.hpp>
#include <game_events.hpp>
#include <levels.hpp>

ContactSystem::ContactSystem() = default;

void ContactSystem::onInit() {}

void ContactSystem::update(const float dt) {
  if (cleanUpAll) {
	cleanUpAll = false;
	registry->clear<>();
	engine->getWindow().clear();
	eventDispatcher->trigger<GameEvent::LoadLevelEvent>(nextLevel);
  }

  for (auto &deletion : deletions) {
	registry->destroy(deletion.entityId);
	engine->getBox2DWorld().DestroyBody(deletion.body);
  }
  deletions.clear();
}

void ContactSystem::BeginContact(b2Contact *contact) {
  const auto &fixture1 = contact->GetFixtureA();
  const auto &fixture2 = contact->GetFixtureB();

  auto ObjType1 = reinterpret_cast<GameComponents::Collision *>(fixture1->GetUserData().pointer);
  auto ObjType2 = reinterpret_cast<GameComponents::Collision *>(fixture2->GetUserData().pointer);

  doIfAny(
	  ObjType1,
	  ObjType2,
	  GameComponents::ObjectType::BULLET,
	  GameComponents::ObjectType::STATIC,
	  [this, ObjType1, ObjType2, fixture1, fixture2]() {
		if (ObjType1->objectType == GameComponents::ObjectType::BULLET) {
		  deletions.emplace(fixture1->GetBody(), *ObjType1->entity);
		} else {
		  deletions.emplace(fixture2->GetBody(), *ObjType2->entity);
		}
	  }
  );

  doIfAny(
	  ObjType1,
	  ObjType2,
	  GameComponents::ObjectType::PLAYER,
	  GameComponents::ObjectType::LEVEL_END,
	  [this, ObjType1, ObjType2, fixture1, fixture2]() {
		std::cout << "Level end and player contact!!!" << std::endl;
		//deletions.emplace(fixture2->GetBody(), *ObjType2->entity);
		//auto levelEnd = registry->get<GameComponents::LevelEnd>(*ObjType2->entity);
		//eventDispatcher->trigger<GameEvent::LoadLevelEvent>(constants::LEVEL2_PATH);
		nextLevel = constants::LEVEL2_PATH;
		cleanUpAll = true;
	  }
  );

  doIfAny(
	  ObjType1,
	  ObjType2,
	  GameComponents::ObjectType::BULLET,
	  GameComponents::ObjectType::ENEMY,
	  [this, ObjType1, ObjType2, fixture1, fixture2]() {

		if (ObjType1->objectType == GameComponents::ObjectType::BULLET)
		  deletions.emplace(fixture1->GetBody(), *ObjType1->entity);
		else
		  deletions.emplace(fixture2->GetBody(), *ObjType2->entity);

		if (ObjType1->objectType == GameComponents::ObjectType::ENEMY) {
		  auto enemy = registry->get<GameComponents::Enemy>(*ObjType1->entity);
		  enemy.health -= 50;
		  if (enemy.health <= 0) {
			deletions.emplace(fixture1->GetBody(), *ObjType1->entity);
		  }
		  registry->emplace_or_replace<GameComponents::Enemy>(*ObjType1->entity, enemy);
		} else {
		  auto enemy = registry->get<GameComponents::Enemy>(*ObjType2->entity);
		  enemy.health -= 50;
		  if (enemy.health <= 0) {
			deletions.emplace(fixture2->GetBody(), *ObjType2->entity);
		  }
		  registry->emplace_or_replace<GameComponents::Enemy>(*ObjType2->entity, enemy);
		}
	  }
  );
}

void ContactSystem::EndContact(b2Contact *contact) {

}
ContactSystem::DeletionEntry::DeletionEntry(b2Body *body, entt::entity entity_id) : body(body), entityId(entity_id) {}
