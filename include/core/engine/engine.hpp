//
// Created by yacopsae on 12/10/2021.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include <box2d/box2d.h>

#include "sound_player.hpp"
#include "scene_manager.hpp"
#include "resource_manager.hpp"
#include "music_player.hpp"
#include "debug_box_2_d.hpp"

class Engine {
  bool isRunning = true;

  sf::RenderWindow window;
  sf::View view;
  SceneManager scene_manager;
  TextureManager texture_manager;
  SoundManager sound_manager;
  MusicPlayer music_player;
  SoundPlayer sound_player;
  b2World box2DWorld;
  DebugBox2D debugDraw;

 public:
  Engine();
  ~Engine();

  void start();
  void stop();

  inline sf::RenderWindow &getWindow() { return window; }
  inline SceneManager &getSceneManager() { return scene_manager; }
  inline TextureManager &getTextureManager() { return texture_manager; }
  inline SoundManager &getSoundManager() { return sound_manager; }
  inline MusicPlayer &getMusicPlayer() { return music_player; }
  inline SoundPlayer &getSoundPlayer() { return sound_player; }
  inline b2World &getBox2DWorld() { return box2DWorld; }
  inline DebugBox2D &getDebugBox2D() { return debugDraw; }
};


