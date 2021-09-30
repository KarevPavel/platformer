//
// Created by yacopsae on 16/09/2021.
//

#pragma once

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <box2d/box2d.h>
#include <box2d/debug_box_2_d.hpp>

#include <sound_player.hpp>
#include "world_listener.hpp"
#include "resource_manager.hpp"

class World : sf::NonCopyable {

 public:
  explicit World(sf::RenderWindow &window);

  void update(sf::Time deltaTime);

  void draw() const;

  void box2DdrawDebug();

  void processEvents(const sf::Event& event);

  bool isGameFinished() const;

 private:

  void loadResources();

  void createWorld();

  void updateWorldBoundaries(sf::Vector2f position, sf::Vector2f dimensions);

  void moveScreenWithMouse();

  sf::RenderWindow &_window;
  sf::View _worldView;

  float mostPositionedX = _window.getSize().x; //!< The furthest object at the X axis position
  float mostPositionedY = _window.getSize().y; //!< The furthest object at the Y axis position
  float lessPositionedX = 0.f; //!< Closest object at X axis position
  float lessPositionedY = 0.f; //!< Closest object at Y axis position
  float maxZoomFactor = 3.f; //!< Maximum zoom in/out ratio

  sf::Sprite backgroundSprite;

  TextureManager texture_manager;

  // === Scene-related objects === //
  b2World b2_World; //!< Physical simulation of the game world
  DebugBox2D debugDraw; //!< Object for displaying hitboxes
  //NodeScene rootScene; //!< Main stage of the game
  WorldListener worldListener; //!< It carries all collisions inside the world
  SoundPlayer worldSounds; //!< A player that allows to play sounds in the game world
};


