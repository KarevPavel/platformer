//
// Created by yacopsae on 08/09/2021.
//

#include "settings_manager.hpp"

const std::string SettingsManager::SETTINGS_FILE = "/home/yacopsae/CLionProjects/platformer/resources/settings.ini";

SettingsManager::SettingsManager() : reader(SETTINGS_FILE) {
  if (reader.ParseError() != 0) {
	std::cout << "Failed to parse file " << SETTINGS_FILE << " cause" << reader.ParseError() << std::endl;
  }
}

std::string SettingsManager::getParam(const std::string &section,
									  const std::string &name,
									  const std::string &default_value) const {
  return reader.Get(section, name, default_value);
}

int SettingsManager::getParam(const std::string &section,
							  const std::string &name,
							  const int default_value) const {
  return reader.GetInteger(section, name, default_value);
}

long SettingsManager::getParam(const std::string &section,
							   const std::string &name,
							   const long default_value) const {
  return reader.GetInteger(section, name, default_value);
}

double SettingsManager::getParam(const std::string &section,
								 const std::string &name,
								 double default_value) const {
  return reader.GetReal(section, name, default_value);
}

float SettingsManager::getParam(const std::string &section,
								const std::string &name,
								float default_value) const {
  return reader.GetReal(section, name, default_value);
}

bool SettingsManager::getParam(const std::string &section,
							   const std::string &name,
							   bool default_value) const {
  return reader.GetBoolean(section, name, default_value);
}
