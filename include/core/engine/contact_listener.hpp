//
// Created by yacopsae on 25/10/2021.
//

#pragma once

#include <box2d/box2d.h>
//Derecated
class ContactListener : public b2ContactListener {
 public:
  explicit ContactListener(b2World *box2DWorld);

  void BeginContact(b2Contact *contact) override;
  void EndContact(b2Contact *contact) override;

 private:
  b2World *box2DWorld;
};


