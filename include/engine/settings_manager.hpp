//
// Created by yacopsae on 08/09/2021.
//

#pragma once

#include <SFML/Graphics.hpp>

#include "INIReader.h"
#include "iostream"

namespace Window {
static const std::string SECTION = "Window";
static const std::string WIDTH = "width";
static const std::string HEIGHT = "height";
static const std::string FRAMERATE = "framerate";
static const std::string ANTIALIASING = "antialiasing";
static const std::string VERTICAL_SYNC = "verticalSync";
}

namespace Game {
static const std::string SECTION = "Game";
static const std::string TIME_PER_FRAME = "timePerFrame";
}

class SettingsManager {

  static const std::string SETTINGS_FILE;

 public:
  SettingsManager();

 public:

  bool verticalSync() {
	return getParam(Window::SECTION, Window::VERTICAL_SYNC, false);
  }

  float timePerFrame() {
	return getParam(Game::SECTION, Game::TIME_PER_FRAME, 60.f);
  }

  unsigned int frameLimit() {
	return getParam(Window::SECTION, Window::FRAMERATE, 60);
  }

  unsigned int antialiasingLevel() {
	return getParam(Window::SECTION, Window::ANTIALIASING, 0);
  }

  sf::VideoMode videoMode() {
	return sf::VideoMode(getParam(Window::SECTION, Window::WIDTH, 800), getParam(Window::SECTION, Window::HEIGHT, 600));
  }

 private:
  INIReader reader;

  std::string getParam(const std::string &section,
					   const std::string &name,
					   const std::string &default_value) const;

  int getParam(const std::string &section,
			   const std::string &name,
			   const int default_value) const;

  long getParam(const std::string &section,
				const std::string &name,
				const long default_value) const;

  double getParam(const std::string &section,
				  const std::string &name,
				  double default_value) const;

  bool getParam(const std::string &section,
				const std::string &name,
				bool default_value) const;

  float getParam(const std::string &section,
				 const std::string &name,
				 float default_value) const;

};