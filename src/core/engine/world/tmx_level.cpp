//
// Created by yacopsae on 06/10/2021.
//

#include <iostream>
#include <limits>

#include <tmxlite/Map.hpp>

#include <SFML/System.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <SFML/Graphics/Image.hpp>

#include "tmx_level.hpp"

//std::map<std::string,

bool TmxLevel::LoadFromFile(const std::string &filepath) {
  tmx::Map map;
  map.load(filepath);

  for (auto const &layer : map.getLayers()) {
	if (layer->getType() == tmx::TileLayer::Type::Tile) {
	  auto const tileLayer = layer->getLayerAs<tmx::TileLayer>();
	  std::cout << "TileLayer name: " << tileLayer.getName() << std::endl;
	  std::cout << "TileLayer tiles size: " << tileLayer.getTiles().size() << std::endl;
	  std::cout << "TileLayer offset: { " << tileLayer.getOffset().x << " : " << tileLayer.getOffset().y << " } "
				<< std::endl;
	  std::cout << "TileLayer size: { " << tileLayer.getSize().x << " : " << tileLayer.getSize().y << " } "
				<< std::endl;
	  std::cout << "Used tiles [" << std::endl;

	  const auto &usedTileSets = usedTiles(map.getTilesets(), tileLayer.getTiles());
	  loadAndSaveTextures(usedTileSets);

	  int column = 0;
	  int row = 0;
	  for (const auto &tile : tileLayer.getTiles()) {
		if (column > 0 && column % tileLayer.getSize().x == 0) {
		  column = 0;
		  row++;
		  std::cout << std::endl;
		}

		//Ищём какая именно текстура нам нужна
		if (tile.ID > 0) {
		  for (auto &it : textureResource_test) {
			if (it.first.first <= tile.ID && tile.ID <= it.first.second) {

			  auto &tileset = it.second;

			  const auto &tile_source = tileset->getTile(tile.ID);

			  auto &imgPos = tile_source->imagePosition;
			  auto &imgSize = tile_source->imageSize;
			  const sf::Rect rect{
				  sf::Vector2i{(int)imgPos.x, (int)imgPos.y},
				  sf::Vector2i{(int)imgSize.x, (int)imgSize.y}
			  };

			  const auto &texture = textureFromImage(tile_source->imagePath);

			  sf::Sprite sprite;
			  sprite.setTexture(texture);
			  sprite.setTextureRect(rect);
			  sprite.setPosition(static_cast<float>(column * 30), static_cast<float>(row * 10));
			  /*sprite.setColor(sf::Color(255, 255, 255, 0));*/
			  spriteList.push_back(sprite);
			}
		  }
		}

		std::cout << "" << tile.ID << " ";
		column++;
	  }
	  std::cout << "]" << std::endl;

	}
  }
  return false;
}

std::vector<std::unique_ptr<tmx::Tileset>> TmxLevel::usedTiles(const std::vector<tmx::Tileset> &tileSets,
															   const std::vector<tmx::TileLayer::Tile> &tiles) {
  std::uint32_t maxID = std::numeric_limits<std::uint32_t>::max();
  std::vector<std::unique_ptr<tmx::Tileset>> usedTileSets;

  //Just save all tilesets
  for (const auto &i : tileSets) {
	for (const auto &tile : tiles) {
	  if (tile.ID >= i.getFirstGID() && tile.ID < maxID) {
		usedTileSets.push_back(std::make_unique<tmx::Tileset>(i));
		break;
	  }
	}
	maxID = i.getFirstGID();
  }
  return usedTileSets;
}

sf::Texture TmxLevel::textureFromImage(const std::string &imagePath) {
  sf::Image fallback;
  sf::Texture newTexture{};
  sf::Image img;

  if (textureResource_2.find(imagePath) == textureResource_2.cend()) {
	if (!img.loadFromFile(imagePath)) {
	  newTexture.loadFromImage(fallback);
	} else {
	  newTexture.loadFromImage(img);
	}
	textureResource_2.insert(std::make_pair(imagePath, &newTexture));

	return newTexture;
  } else {
	return *textureResource_2.find(imagePath)->second;
  }
}

void TmxLevel::loadAndSaveTextures(const std::vector<std::unique_ptr<tmx::Tileset>> &usedTileSets) {
  sf::Image fallback;
  fallback.create(2, 2, sf::Color::Magenta);
  for (auto &ts : usedTileSets) {
	std::pair<std::uint32_t, std::uint32_t> pair = std::make_pair(ts->getFirstGID(), ts->getLastGID());
	if (textureResource_test.find(pair) == textureResource_test.end()) {

	  auto test = std::forward(std::move(ts));
	  auto p = std::make_pair (pair, std::move(ts));

	  //textureResource_test.insert();
	}
  }
}


void TmxLevel::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  for (const auto &sprite : spriteList) {
	window_.draw(sprite);
  }
}

TmxLevel::TmxLevel(sf::RenderWindow &window) : window_(window) {}
