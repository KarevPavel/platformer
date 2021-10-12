//
// Created by yacopsae on 17/09/2021.
//

#pragma once

#include <string>
#include <map>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/Sound.hpp>

template<typename Resource, typename Identifier>
class ResourceManager {

 public:
  inline Resource &get(const Identifier &resourcePath);

 private:
  std::map<Identifier, std::unique_ptr<Resource>> resourceMap;
};

template<typename Resource, typename Identifier>
inline Resource &ResourceManager<Resource, Identifier>::get(const Identifier & identifier) {
  auto found_texture = resourceMap.find(identifier);
  if (found_texture == resourceMap.cend()) {
	resourceMap[identifier] = std::make_unique<Resource>();
	if (resourceMap[identifier].loadFromFile(identifier))
	  throw std::runtime_error("RESOURCE: " + identifier + " NOT FOUND!");
  }
  return resourceMap[identifier];
}

using FontManager = ResourceManager<sf::Font, std::string>;
using TextureManager = ResourceManager<sf::Texture, std::string>;
using SoundManager = ResourceManager<sf::SoundBuffer, std::string>;
