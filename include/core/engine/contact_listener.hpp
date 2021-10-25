//
// Created by yacopsae on 25/10/2021.
//

#pragma once

#include <box2d/box2d.h>

class ContactListener : public b2ContactListener {
  void BeginContact(b2Contact *contact) override;
  void EndContact(b2Contact *contact) override;
};


