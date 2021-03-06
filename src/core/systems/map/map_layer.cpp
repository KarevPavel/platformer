//
// Created by yacopsae on 18/10/2021.
//

#include "map_layer.hpp"

MapLayer::MapLayer(const tmx::Map &map, const std::unique_ptr<tmx::Layer> &layer, b2World &box2DWorld) :
	box2DWorld(box2DWorld) {
  const auto tileSize = map.getTileSize();
  m_chunkSize.x = std::floor(m_chunkSize.x / tileSize.x) * tileSize.x;
  m_chunkSize.y = std::floor(m_chunkSize.y / tileSize.y) * tileSize.y;
  m_MapTileSize.x = tileSize.x;
  m_MapTileSize.y = tileSize.y;

  const auto tileLayer = layer->getLayerAs<tmx::TileLayer>();
  createChunks(map, tileLayer, box2DWorld);

  auto mapSize = map.getBounds();
  m_globalBounds.width = mapSize.width;
  m_globalBounds.height = mapSize.height;
}

const sf::FloatRect &MapLayer::getGlobalBounds() { return m_globalBounds; }

void MapLayer::setTile(int tileX, int tileY, tmx::TileLayer::Tile tile, bool refresh = true) {
  sf::Vector2u chunkLocale;
  const auto &selectedChunk = getChunkAndTransform(tileX, tileY, chunkLocale);
  selectedChunk->setTile(chunkLocale.x, chunkLocale.y, tile, refresh);
}

tmx::TileLayer::Tile MapLayer::getTile(int tileX, int tileY) {
  sf::Vector2u chunkLocale;
  const auto &selectedChunk = getChunkAndTransform(tileX, tileY, chunkLocale);
  return selectedChunk->getTile(chunkLocale.x, chunkLocale.y);
}

void MapLayer::setColor(int tileX, int tileY, sf::Color color, bool refresh = true) {
  sf::Vector2u chunkLocale;
  const auto &selectedChunk = getChunkAndTransform(tileX, tileY, chunkLocale);
  selectedChunk->setColor(chunkLocale.x, chunkLocale.y, color, refresh);
}

sf::Color MapLayer::getColor(int tileX, int tileY) {
  sf::Vector2u chunkLocale;
  const auto &selectedChunk = getChunkAndTransform(tileX, tileY, chunkLocale);
  return selectedChunk->getColor(chunkLocale.x, chunkLocale.y);
}

void MapLayer::update(const float dt) {
  for (auto &c : m_chunks) {
	c->updatePhysics();
  }
}

Chunk::Ptr &MapLayer::getChunkAndTransform(int x, int y, sf::Vector2u &chunkRelative) {
  uint32_t chunkX = floor((x * m_MapTileSize.x) / m_chunkSize.x);
  uint32_t chunkY = floor((y * m_MapTileSize.y) / m_chunkSize.y);
  chunkRelative.x = ((x * m_MapTileSize.x) - chunkX * m_chunkSize.x) / m_MapTileSize.x;
  chunkRelative.y = ((y * m_MapTileSize.y) - chunkY * m_chunkSize.y) / m_MapTileSize.y;
  return m_chunks[chunkX + chunkY * m_chunkCount.x];
}

void MapLayer::createChunks(const tmx::Map &map, const tmx::TileLayer &layer, b2World &box2DWorld) {
  //look up all the tile sets and load the textures
  const auto &tileSets = map.getTilesets();
  const auto &layerIDs = layer.getTiles();
  std::uint32_t maxID = std::numeric_limits<std::uint32_t>::max();
  std::vector<const tmx::Tileset *> usedTileSets;

  //Just save all tilesets
  for (auto i = tileSets.rbegin(); i != tileSets.rend(); ++i) {
	for (const auto &tile : layerIDs) {
	  if (tile.ID >= i->getFirstGID() && tile.ID < maxID) {
		usedTileSets.push_back(&(*i));
		break;
	  }
	}
	maxID = i->getFirstGID();
  }


  //Load all images of tiles
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
	m_textureResource.insert(std::make_pair(path, std::move(newTexture)));
  }

  //calculate the number of chunks in the layer
  //and create each one
  const auto bounds = map.getBounds();
  m_chunkCount.x = static_cast<sf::Uint32>(std::ceil(bounds.width / m_chunkSize.x));
  m_chunkCount.y = static_cast<sf::Uint32>(std::ceil(bounds.height / m_chunkSize.y));

  sf::Vector2u tileSize(map.getTileSize().x, map.getTileSize().y);

  for (auto y = 0u; y < m_chunkCount.y; ++y) {
	sf::Vector2f tileCount(m_chunkSize.x / tileSize.x, m_chunkSize.y / tileSize.y);
	for (auto x = 0u; x < m_chunkCount.x; ++x) {
	  // calculate size of each Chunk (clip against map)
	  if ((x + 1.f) * m_chunkSize.x > bounds.width) {
		tileCount.x = (bounds.width - x * m_chunkSize.x) / map.getTileSize().x;
	  }
	  if ((y + 1.f) * m_chunkSize.y > bounds.height) {
		tileCount.y = (bounds.height - y * m_chunkSize.y) / map.getTileSize().y;
	  }
	  m_chunks.emplace_back(std::make_unique<Chunk>(layer, usedTileSets,
													sf::Vector2f(x * m_chunkSize.x, y * m_chunkSize.y),
													tileCount, tileSize, map.getTileCount().x,
													m_textureResource, box2DWorld));
	}
  }
}

void MapLayer::updateVisibility(const sf::View &view) const {
  sf::Vector2f viewCorner = view.getCenter();
  viewCorner -= view.getSize() / 2.f;

  int posX = static_cast<int>(std::floor(viewCorner.x / m_chunkSize.x));
  int posY = static_cast<int>(std::floor(viewCorner.y / m_chunkSize.y));
  int posX2 = static_cast<int>(std::ceil((viewCorner.x + view.getSize().x) / m_chunkSize.x));
  int posY2 = static_cast<int>(std::ceil((viewCorner.y + view.getSize().x) / m_chunkSize.y));

  std::vector<Chunk *> visible;
  for (auto y = posY; y < posY2; ++y) {
	for (auto x = posX; x < posX2; ++x) {
	  std::size_t idx = y * int(m_chunkCount.x) + x;
	  if (idx >= 0u && idx < m_chunks.size() && !m_chunks[idx]->empty()) {
		visible.push_back(m_chunks[idx].get());
	  }
	}
  }

  std::swap(m_visibleChunks, visible);
}

void MapLayer::draw(sf::RenderTarget &rt, sf::RenderStates states) const {
//calc view coverage and draw nearest chunks
  updateVisibility(rt.getView());
  for (const auto &c : m_visibleChunks) {
	rt.draw(*c, states);
  }
}
