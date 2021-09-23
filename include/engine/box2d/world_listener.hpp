//
// Created by yacopsae on 16/09/2021.
//

#pragma once

#include <box2d/box2d.h>

class WorldListener final : public b2ContactListener {
  /**
   * \brief A function that executes when a collision starts.
   * \param contact Information on the collision that took place
   */
  void BeginContact(b2Contact *contact) override;
  /**
   * \brief A function that executes when a collision end
   * \param contact Information on the collision that took place
   */
  void EndContact(b2Contact *contact) override;
};