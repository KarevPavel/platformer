//
// Created by yacopsae on 06/10/2021.
//

#pragma once

#include <string>
#include <map>

#include <tmxlite/TileLayer.hpp>
#include <tmxlite/Tileset.hpp>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

class TmxLevel : public sf::Drawable {

 public:
  explicit TmxLevel(sf::RenderWindow &window);
  bool LoadFromFile(const std::string &filepath);
  std::vector<std::unique_ptr<tmx::Tileset>> usedTiles(const std::vector<tmx::Tileset> &tileSets,
											  const std::vector<tmx::TileLayer::Tile> &tiles);
  void loadAndSaveTextures(const std::vector<std::unique_ptr<tmx::Tileset>> &usedTileSets);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
 private:
  sf::Texture textureFromImage(const std::string &imagePath);
  sf::RenderWindow &window_;


  std::map<std::string , std::unique_ptr<sf::Texture>> textureResource_2;
  std::map<std::pair<std::uint32_t, std::uint32_t>, std::unique_ptr<tmx::Tileset>> textureResource_test;
  std::vector<sf::Sprite> spriteList;
};
