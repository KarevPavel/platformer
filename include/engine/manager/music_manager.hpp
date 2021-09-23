//
// Created by yacopsae on 22/09/2021.
//

#pragma once

#include <string>
#include <map>
#include <SFML/Audio/Music.hpp>

class MusicPlayer
{
 public:
  /**
   * \brief Loads available songs
   */
  MusicPlayer();

  /**
   * \brief Plays the song associated with the specified ID.
   * \param musicID Identifier of the music track.
   */
  void play(std::string musicId);


  /**
   * \brief Stops the currently playing song.
   */
  void stop();

  /**
   * \brief Pauses or unpauses the song.
   * \param paused Pauses if true, unpauses otherwise
   */
  void setPaused(bool paused);

  /**
   * \brief Sets the volume from 0 (muted) to 100 (loudest).
   * \param volume Music volume from 0 to 100
   */
  void setVolume(float volume);


  /**
   * \brief It returns currently playing (or paused) music
   * \return Identifier of currently playing music
   */
  std::string getCurrentMusic() const noexcept;


  /**
   * \brief Plays the same song again from beginning
   * \warning If no music was set, nothing happens
   */
  void reset();

 private:
  sf::Music music; //!< Streamed music from the audio file
  std::map<std::string, std::string> filePaths; //!< Assigns a music identifier to the corresponding file path
  float volume = 100.f; //!< Music volume from 0 to 100
  std::string currentMusic = ""; //!< Identifier of currently playing music
};


