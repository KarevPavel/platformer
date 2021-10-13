//
// Created by yacopsae on 17/09/2021.
//

#pragma once

#include <string>
#include <map>
#include <memory>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/Sound.hpp>

template<typename Resource, typename Identifier>
class ResourceManager {

 public:
  inline Resource &get(const Identifier &identifier);

 private:
  std::map<Identifier, std::unique_ptr<Resource>> resourceMap;
};

template<typename Resource, typename Identifier>
inline Resource &ResourceManager<Resource, Identifier>::get(const Identifier &identifier) {

  auto found_texture = resourceMap.find(identifier);

  if (found_texture == resourceMap.cend()) {
	auto resource = std::make_unique<Resource>();
	if (!resource->loadFromFile(identifier))
	  throw std::runtime_error("RESOURCE: " + identifier + " NOT FOUND!");

	resourceMap[identifier] = std::move(resource);
  }
  return *resourceMap.at(identifier);
}

using FontManager = ResourceManager<sf::Font, std::string>;
using TextureManager = ResourceManager<sf::Texture, std::string>;
using SoundManager = ResourceManager<sf::SoundBuffer, std::string>;