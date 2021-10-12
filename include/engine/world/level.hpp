//
// Created by yacopsae on 04/10/2021.
//

#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <tmxlite/Map.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <tmxlite/TileLayer.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include <map>

using TextureResource = std::map<std::string, std::unique_ptr<sf::Texture>>;

class Chunk : public sf::Transformable, public sf::Drawable {
 public:
  Chunk(const Chunk &) = delete;
  Chunk &operator=(const Chunk &) = delete;
  Chunk(const tmx::TileLayer &layer,
		const std::vector<const tmx::Tileset *> &tilesets,
		const sf::Vector2f &position,
		const sf::Vector2f &tileCount,
		const sf::Vector2u &tileSize,
		std::size_t rowSize,
		TextureResource &tr);

 protected:
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

 private:

  void createBody();

  sf::Uint8 opacity;     // opacity of the layer
  sf::Vector2f layer_offset;   // Layer offset
  sf::Vector2u map_tile_size;   // general Tilesize of Map
  sf::Vector2f tile_count;   // chunk tilecount

};

class VerticleArray : public sf::Drawable {

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  void clear();
  void addVertex(const sf::Vertex &v);

 private:
  std::vector<sf::Vertex> m_vertices;
  const sf::Texture &m_texture;
};

class Level : public sf::Drawable {
 public:
  ~Level() override = default;
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  void loadMap(const tmx::Map &map);
  sf::Vector2f levelStart();

 private:

  std::vector<const tmx::Tileset *> usedTiles(const std::vector<tmx::Tileset> &tileSets,
											  const std::vector<tmx::TileLayer::Tile> &tiles);

  void loadAndSaveTextures(const std::vector<const tmx::Tileset *> &usedTileSets);

  TextureResource _textureResource;
  sf::Vector2f lvl_start;
  sf::Vector2f lvl_fin;
  sf::FloatRect global_bounds;
  std::vector<VerticleArray> array;
  sf::Vector2f chunk_size;
  sf::Vector2u chunk_count;

};


