//
// Created by yacopsae on 17/09/2021.
//

#pragma once

#include <string>
#include <SFML/System.hpp>
#include <SFML/Audio/Sound.hpp>

#include <list>


class SoundPlayer {

 public:
  SoundPlayer();

  void play(std::string sound);
  void play(std::string sound, sf::Vector2f position);
  sf::Time getSoundLength(std::string sound) const;
  void removeFinishedSounds();
  void setListenerPosition(sf::Vector2f position);
  sf::Vector2f getListenerPosition() const;

 private:
  //SoundManager soundPaths; //!< A manager that maps sound IDs to their file paths

  // List is used instead of vector, as vector may reallocate
  // and this way invalidate them when they're playing
  // And many more similar aspects
  std::list<sf::Sound> soundList; //!< List of currently playing sounds

  const float listenerZ = 300.f; //!< The distance of the listener (virtual ear) from the two-dimensional game plane.
  const float attenuation = 8.f; //!< The ratio of how fast a sound fades away as a function of distance
  const float minDistance = 300.f; //!< The minimum distance from the virtual ear at which sound begins to fade (to become more silent).

};


