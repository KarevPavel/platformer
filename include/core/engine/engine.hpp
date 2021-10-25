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
#include "contact_listener.hpp"

class Engine {
  bool isRunning = true;

  sf::RenderWindow window;
  sf::View view;
  SceneManager sceneManager;
  TextureManager textureManager;
  FontManager fontManager;
  SoundManager soundManager;
  MusicPlayer musicPlayer;
  SoundPlayer soundPlayer;
  b2World box2DWorld;
  ContactListener contactListener;
  DebugBox2D debugDraw;

 public:
  Engine();
  ~Engine();

  void start();
  void stop();

  inline sf::RenderWindow &getWindow() { return window; }
  inline SceneManager &getSceneManager() { return sceneManager; }
  inline TextureManager &getTextureManager() { return textureManager; }
  inline SoundManager &getSoundManager() { return soundManager; }
  inline MusicPlayer &getMusicPlayer() { return musicPlayer; }
  inline SoundPlayer &getSoundPlayer() { return soundPlayer; }
  inline b2World &getBox2DWorld() { return box2DWorld; }
  inline DebugBox2D &getDebugBox2D() { return debugDraw; }
  inline sf::View &getView() { return view; }
  inline FontManager &getFontManager() { return fontManager; }
};


