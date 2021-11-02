//
// Created by yacopsae on 02/11/2021.
//

#pragma once

#include <box2d/box2d.h>

class ContactFilter : public b2ContactFilter {
 public:
  explicit ContactFilter(b2World *box2DWorld);
  bool ShouldCollide(b2Fixture* fixtureA, b2Fixture* fixtureB) override;


  bool Default(b2Fixture* fixtureA, b2Fixture* fixtureB);
 private:
  b2World *box2DWorld;
};