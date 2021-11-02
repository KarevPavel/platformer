//
// Created by yacopsae on 25/10/2021.
//

#include "contact_listener.hpp"
#include "iostream"
#include "game_components.hpp"

[[deprecated]]
ContactListener::ContactListener(b2World *box2DWorld): box2DWorld(box2DWorld) {}

void ContactListener::BeginContact(b2Contact *contact) {
  const auto& fixture1 = contact->GetFixtureA();
  const auto& fixture2 = contact->GetFixtureB();

  auto ObjType1 = reinterpret_cast<GameComponents::Collision*>(fixture1->GetUserData().pointer);
  auto ObjType2 = reinterpret_cast<GameComponents::Collision*>(fixture2->GetUserData().pointer);

  if (ObjType1 != nullptr) {
	if (ObjType1->objectType == GameComponents::ObjectType::STATIC) {
	  std::cout << " STATIC " << std::endl;
	}
	if (ObjType1->objectType == GameComponents::ObjectType::BULLET) {
	  std::cout << " BULLET " << std::endl;
	  if (!box2DWorld->IsLocked()) {
		box2DWorld->DestroyBody(fixture1->GetBody());
	  }
	}
  }

  if (ObjType2 != nullptr) {
	if (ObjType2->objectType == GameComponents::ObjectType::STATIC) {
	  std::cout << " STATIC " << std::endl;
	}

	if (ObjType2->objectType == GameComponents::ObjectType::BULLET) {
	  std::cout << " BULLET " << std::endl;
	  if (!box2DWorld->IsLocked()) {
		box2DWorld->DestroyBody(fixture2->GetBody());
	  }
	}
  }
}

void ContactListener::EndContact(b2Contact *contact) {

}