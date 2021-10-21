//
// Created by yacopsae on 18/10/2021.
//

#pragma once

#include <map>

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Vertex.hpp>

#include <tmxlite/Tileset.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/detail/Log.hpp>

#include "chunk_array.hpp"

class Chunk final : public sf::Transformable, public sf::Drawable {
 public:
  using Ptr = std::unique_ptr<Chunk>;
  using Tile = std::array<sf::Vertex, 4u>;
  using TextureResource = std::map<std::string, std::unique_ptr<sf::Texture>>;

  Chunk(const tmx::TileLayer &layer, std::vector<const tmx::Tileset *> tilesets,
		const sf::Vector2f &position, const sf::Vector2f &tileCount, const sf::Vector2u &tileSize,
		std::size_t rowSize, TextureResource &tr);

  Chunk(const Chunk &) = delete;
  Chunk &operator=(const Chunk &) = delete;

  void generateTiles();
  tmx::TileLayer::Tile getTile(int x, int y) const;
  void setTile(int x, int y, tmx::TileLayer::Tile tile, bool refresh);
  sf::Color getColor(int x, int y) const;
  void setColor(int x, int y, sf::Color color, bool refresh);
  void maybeRegenerate(bool refresh);
  int calcIndexFrom(int x, int y) const;
  bool empty() const;
  void flipY(sf::Vector2f *v0, sf::Vector2f *v1, sf::Vector2f *v2, sf::Vector2f *v3);
  void flipX(sf::Vector2f *v0, sf::Vector2f *v1, sf::Vector2f *v2, sf::Vector2f *v3);
  void flipD(sf::Vector2f *v0, sf::Vector2f *v1, sf::Vector2f *v2, sf::Vector2f *v3);
  void doFlips(std::uint8_t bits, sf::Vector2f *v0, sf::Vector2f *v1, sf::Vector2f *v2, sf::Vector2f *v3);

 private:
  sf::Uint8 layerOpacity;     // opacity of the layer
  sf::Vector2f layerOffset;   // Layer offset
  sf::Vector2u mapTileSize;   // general Tilesize of Map
  sf::Vector2f chunkTileCount;   // chunk tilecount
  std::vector<tmx::TileLayer::Tile> m_chunkTileIDs; // stores all tiles in this chunk for later manipulation
  std::vector<sf::Color> m_chunkColors; // stores colors for extended color effects
  std::vector<ChunkArray::Ptr> m_chunkArrays;

  void draw(sf::RenderTarget &rt, sf::RenderStates states) const override;
};

