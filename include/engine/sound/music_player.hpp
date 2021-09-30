//
// Created by yacopsae on 23/09/2021.
//

#pragma once

#include <SFML/Audio/Music.hpp>
#include <string>

class MusicPlayer {

 public:
  explicit MusicPlayer();
  void play(const std::string& musicPath);
  void stop();
  void setPaused(bool paused);
  void setVolume(float volume);
  std::string getCurrentMusic() const noexcept;
  void reset();

 private:
  sf::Music _music; //!< Streamed music from the audio file
  float _volume; //!< Music volume from 0 to 100
  std::string _current_music; //!< Identifier of currently playing music


};


