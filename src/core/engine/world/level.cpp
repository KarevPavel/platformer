//
// Created by yacopsae on 04/10/2021.
//

#include "iostream"
#include <limits>

#include <tmxlite/TileLayer.hpp>
#include <tmxlite/Object.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <cmath>
#include <box2d/box2d.h>

#include "level.hpp"

void Level::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}

sf::Vector2f Level::levelStart() {
  return lvl_start;
}

void Level::loadAndSaveTextures(const std::vector<const tmx::Tileset *> &usedTileSets) {
  sf::Image fallback;
  fallback.create(2, 2, sf::Color::Magenta);
  for (const auto &ts : usedTileSets) {
	const auto &path = ts->getImagePath();
	//std::unique_ptr<sf::Texture> newTexture = std::make_unique<sf::Texture>();
	std::unique_ptr<sf::Texture> newTexture = std::make_unique<sf::Texture>();
	sf::Image img;
	if (!img.loadFromFile(path)) {
	  newTexture->loadFromImage(fallback);
	} else {
	  if (ts->hasTransparency()) {
		auto transparency = ts->getTransparencyColour();
		img.createMaskFromColor({transparency.r, transparency.g, transparency.b, transparency.a});
	  }
	  newTexture->loadFromImage(img);
	}
	_textureResource.insert(std::make_pair(path, std::move(newTexture)));
  }
}

std::vector<const tmx::Tileset *>
Level::usedTiles(const std::vector<tmx::Tileset> &tileSets,
				 const std::vector<tmx::TileLayer::Tile> &tiles) {
  std::uint32_t maxID = std::numeric_limits<std::uint32_t>::max();
  std::vector<const tmx::Tileset *> usedTileSets;

  //Just save all tilesets
  for (auto i = tileSets.rbegin(); i != tileSets.rend(); ++i) {
	for (const auto &tile : tiles) {
	  if (tile.ID >= i->getFirstGID() && tile.ID < maxID) {
		usedTileSets.push_back(&(*i));
		break;
	  }
	}
	maxID = i->getFirstGID();
  }
  return usedTileSets;
}

void Level::loadMap(const tmx::Map &map) {
  const auto &layers = map.getLayers();
  const auto &tileSize = sf::Vector2u{map.getTileSize().x, map.getTileSize().y};
  auto mapSize = map.getBounds();

  global_bounds.width = mapSize.width;
  global_bounds.height = mapSize.height;

  chunk_size.x = std::floor(chunk_size.x / tileSize.x) * tileSize.x;
  chunk_size.y = std::floor(chunk_size.y / tileSize.y) * tileSize.y;

  for (const auto &layer : layers) {
	if (layer->getType() == tmx::TileLayer::Type::Tile) {

	  auto tileLayer = layer->getLayerAs<tmx::TileLayer>();
	  const auto &tileSets = map.getTilesets();
	  const auto &layerIDs = tileLayer.getTiles();
	  const auto &usedTileSets = usedTiles(tileSets, layerIDs);
	  loadAndSaveTextures(usedTileSets);

	  const auto bounds = map.getBounds();
	  chunk_count.x = static_cast<sf::Uint32>(std::ceil(bounds.width / chunk_size.x));
	  chunk_count.y = static_cast<sf::Uint32>(std::ceil(bounds.height / chunk_size.y));

	  sf::Vector2f tileCount(chunk_size.x / tileSize.x, chunk_size.y / tileSize.y);

	  for (auto y = 0u; y < chunk_count.y; ++y) {
		for (auto x = 0u; x < chunk_count.x; ++x) {
		  if ((x + 1.f) * chunk_size.x > bounds.width) {
			tileCount.x = (bounds.width - x * chunk_size.x) / map.getTileSize().x;
		  }
		  if ((y + 1.f) * chunk_size.y > bounds.height) {
			tileCount.y = (bounds.height - y * chunk_size.y) / map.getTileSize().y;
		  }

		  /*m_chunks.emplace_back(std::make_unique<Chunk>(tileLayer, usedTileSets,
														sf::Vector2f(x * chunk_size.x, y * chunk_size.y),
														tileCount, tileSize, map.getTileCount().x,
														_textureResource));*/
		}
	  }
	} else if (layer->getType() == tmx::TileLayer::Type::Object) {

	  //std::cout << "Type: Object" << std::endl;
	  auto obj = layer->getLayerAs<tmx::ObjectGroup>();

	  for (const auto &obj : obj.getObjects()) {
		//std::cout << "Object name >>" << obj.getName() << "<<" << std::endl;
		if (obj.getName() == "LEVEL_START") {
		  lvl_start.x = obj.getPosition().x;
		  lvl_start.y = obj.getPosition().y;
		}
	  }
	} else {
	  std::cout << "IGNORE! Undefined type, can handle Tile or Object" << std::endl;
	}

	for (const auto &prop : layer->getProperties()) {
	  //std::cout << "Property >>" << prop.getName() << "<< has value: >>" << prop.getStringValue() << "<<" << std::endl;
	}
  }

}

void VerticleArray::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(m_vertices.data(), m_vertices.size(), sf::Quads, states);
}

void VerticleArray::clear() {
  m_vertices.clear();
}

void VerticleArray::addVertex(const sf::Vertex &v) {
  m_vertices.push_back(v);
}

Chunk::Chunk(const tmx::TileLayer &layer,
			 const std::vector<const tmx::Tileset *> &tilesets,
			 const sf::Vector2f &position,
			 const sf::Vector2f &tileCount,
			 const sf::Vector2u &tileSize,
			 std::size_t rowSize,
			 TextureResource &tr) :
	opacity(static_cast<sf::Uint8>(layer.getOpacity() / 1.f * 255.f)),
	tile_count(tileCount) {
  setPosition(position);

}
void Chunk::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}

void Chunk::createBody() {
  // Defines its shape
/*  b2PolygonShape Shape;
  Shape.SetAsBox(sprite.getLocalBounds().width / 2.f / B2_SCALAR, sprite.getLocalBounds().height / 2.f / B2_SCALAR);
  b2FixtureDef FixtureDef;
  FixtureDef.density = 1.f;
  FixtureDef.friction = 0.7f;
  FixtureDef.restitution = 0.2f;
  FixtureDef.shape = &Shape;
  fixture = Body->CreateFixture(&FixtureDef);*/
}
