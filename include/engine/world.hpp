//
// Created by yacopsae on 16/09/2021.
//

#pragma once

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <box2d/box2d.h>
#include <box2d/debug_box_2_d.hpp>
#include <box2d/world_listener.hpp>
#include <sound/sound_player.hpp>

class World : sf::NonCopyable {

 public:
  World(sf::RenderWindow &window);

 private:
  sf::RenderWindow &_window;
  sf::View _worldView;

  // === Scene-related objects === //
  b2World b2_World; //!< Physical simulation of the game world
  DebugBox2D debugDraw; //!< Object for displaying hitboxes
  //NodeScene rootScene; //!< Main stage of the game
  WorldListener worldListener; //!< It carries all collisions inside the world
  SoundPlayer worldSounds; //!< A player that allows to play sounds in the game world
};


