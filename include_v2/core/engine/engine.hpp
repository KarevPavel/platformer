//
// Created by yacopsae on 12/10/2021.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "sound_player.hpp"
#include "scene_manager.hpp"
#include "resource_manager.hpp"
#include "music_player.hpp"

class Engine {
  bool isRunning = true;

  sf::RenderWindow window;
  SceneManager scene_manager;
  TextureManager texture_manager;
  SoundManager sound_manager;
  MusicPlayer music_player;
  SoundPlayer sound_player;

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
};


