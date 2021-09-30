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
  inline Resource &getResourceReference(const Identifier &resourcePath);

 private:
  std::map<Identifier, std::unique_ptr<Resource>> resourceMap;
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
inline Resource &ResourceManager<Resource, Identifier>::getResourceReference(const Identifier &resourcePath) {
  auto found_texture = resourceMap.find(resourcePath);
  if (found_texture == resourceMap.cend()) {
	std::unique_ptr<Resource> resource = std::make_unique<Resource>();
	if (!resource->loadFromFile(resourcePath))
	  throw std::runtime_error("This file does not exist: " + resourcePath);

	auto insertedResource = resourceMap.insert(std::make_pair(resourcePath, std::move(resource)));
	//TODO: явно глупость, зачем ещё раз выоплнять поиск?
	//Но у меня иначе не получилось
	return *resourceMap.find(resourcePath) -> second;
  }
  return *found_texture->second;
}

using FontManager = ResourceManager<sf::Font, std::string>;
using TextureManager = ResourceManager<sf::Texture, std::string>;
using SoundManager = ResourceManager<sf::SoundBuffer, std::string>;
