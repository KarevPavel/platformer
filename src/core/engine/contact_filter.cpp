//
// Created by yacopsae on 02/11/2021.
//

#include <game_components.hpp>
#include "contact_filter.hpp"

ContactFilter::ContactFilter(b2World *box2DWorld): box2DWorld(box2DWorld) {}

bool ContactFilter::ShouldCollide(b2Fixture *fixture1, b2Fixture *fixture2) {

  auto res = Default(fixture1, fixture2);

  return res;
}



/*
bool ContactFilter::anyOf(GameComponents::ObjectType suspect, GameComponents::ObjectType... types) {

}*/

bool ContactFilter::Default(b2Fixture *fixtureA, b2Fixture *fixtureB) {
  const b2Filter &filterA = fixtureA->GetFilterData();
  const b2Filter &filterB = fixtureB->GetFilterData();

  if (filterA.groupIndex == filterB.groupIndex && filterA.groupIndex != 0) {
	return filterA.groupIndex > 0;
  }

  bool collideA = (filterA.maskBits & filterB.categoryBits) != 0;
  bool collideB = (filterA.categoryBits & filterB.maskBits) != 0;
  bool collide = collideA && collideB;
  return collide;
}