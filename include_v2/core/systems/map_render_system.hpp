//
// Created by yacopsae on 13/10/2021.
//

#pragma once

#include <map>

#include <tmxlite/TileLayer.hpp>
#include <tmxlite/Tileset.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "base_system.hpp"
#include "game_events.hpp"


class MapRenderSystem : public BaseSystem {
  void onInit() override;

 public:
  MapRenderSystem();

  //void receiveGameStart(const GameEvent::GameStart &event);

  void update(float dt);


};


