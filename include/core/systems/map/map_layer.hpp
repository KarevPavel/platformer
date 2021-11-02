//
// Created by yacopsae on 18/10/2021.
//

#pragma once

#include <cmath>
#include <iostream>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <tmxlite/Map.hpp>
#include <box2d/box2d.h>
#include "tmxlite/TileLayer.hpp"

#include "chunk.hpp"
#include "updatable_map.hpp"

class MapLayer final : public UpdatableMap {
 public:

  //MapLayer(const tmx::Map &map, std::size_t idx);
  MapLayer(const tmx::Map &map, const std::unique_ptr<tmx::Layer> &layer, b2World &box2DWorld);
  ~MapLayer() override = default;
  MapLayer(const MapLayer &) = delete;
  MapLayer &operator=(const MapLayer &) = delete;

  const sf::FloatRect &getGlobalBounds();
  void setTile(int tileX, int tileY, tmx::TileLayer::Tile tile, bool refresh);
  tmx::TileLayer::Tile getTile(int tileX, int tileY);
  void setColor(int tileX, int tileY, sf::Color color, bool refresh);
  sf::Color getColor(int tileX, int tileY);

  void update(const float dt);

  void draw(sf::RenderTarget &rt, sf::RenderStates states) const override;

 private:
  Chunk::Ptr &getChunkAndTransform(int x, int y, sf::Vector2u &chunkRelative);
  void createChunks(const tmx::Map &map, const tmx::TileLayer &layer, b2World &box2DWorld);
  void updateVisibility(const sf::View &view) const;


 private:
  //increasing m_chunkSize by 4; fixes render problems when mapsize != chunksize
  sf::Vector2f m_chunkSize = sf::Vector2f(2048.f, 2048.f);
  sf::Vector2u m_chunkCount;
  sf::Vector2u m_MapTileSize;   // general Tilesize of Map
  sf::FloatRect m_globalBounds;
  Chunk::TextureResource m_textureResource;
  std::vector<Chunk::Ptr> m_chunks;
  mutable std::vector<Chunk *> m_visibleChunks;
  b2World &box2DWorld;

};
