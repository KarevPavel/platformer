//
// Created by yacopsae on 18/10/2021.
//

#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Vertex.hpp>

#include <box2d/b2_world.h>

#include <tmxlite/Tileset.hpp>

class ChunkArray final : public sf::Drawable {
 public:
  using Ptr = std::unique_ptr<ChunkArray>;
  tmx::Vector2u tileSetSize;
  sf::Vector2u tsTileCount;
  std::uint32_t m_firstGID, m_lastGID;
  std::string layerName;

  explicit ChunkArray(const sf::Texture &t, const tmx::Tileset &ts, const std::string & layerName);

  ~ChunkArray() override = default;
  ChunkArray(const ChunkArray &) = delete;
  ChunkArray &operator=(const ChunkArray &) = delete;

  void reset();
  void addTile(const std::array<sf::Vertex, 4u> &tile, b2World& world);

  sf::Vector2u getTextureSize() const;

 private:
  const sf::Texture &m_texture;
  std::vector<sf::Vertex> m_vertices;
  b2Body *body;

  void draw(sf::RenderTarget &rt, sf::RenderStates states) const override;
  void createBody(b2World &world, const b2Vec2 &pos);
};


