//
// Created by yacopsae on 17/09/2021.
//

#pragma once

#include <string>
#include <map>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/Sound.hpp>
#include <utility>

template<typename Resource, typename Identifier>
class ResourceManager {

 public:
  inline Resource &getResourceRef(Identifier resourcePath);

 private:
  std::map<Identifier, Resource &> resourceMap;
};

/*template<typename Resource, typename Identifier>
inline Resource *ResourceManager<Resource, Identifier>::getResource(Identifier resourceId) const {
  auto found_texture = resourceMap.find(resourceId);
  if (found_texture != resourceMap.cend()) {

	std::string str{resourcePath + "/" + resourceId};

	if (!found_texture->loadFromFile(str)) {
	  resourceMap.insert(std::make_pair(str, std::move(found_texture)));
	}
  }
  return resourceMap.find(resourceId);
}*/

template<typename Resource, typename Identifier>
inline Resource &ResourceManager<Resource, Identifier>::getResourceRef(Identifier resourcePath) {
  auto resource = resourceMap.find(resourcePath);
  if (resource != resourceMap.cend()) {
	auto res = resource->second;
	if (res.loadFromFile(resourcePath)) {
	  resourceMap.emplace(resourcePath, res);
	}
  }
  return resourceMap.find(resourcePath)->second;
}

using FontManager = ResourceManager<sf::Font, std::string>;
using TextureManager = ResourceManager<sf::Texture, std::string>;
/*
using SoundManager = ResourceManager<sf::Sound, std::string>;*/
