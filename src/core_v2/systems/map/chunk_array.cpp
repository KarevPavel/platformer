//
// Created by yacopsae on 18/10/2021.
//

#include "chunk_array.hpp"

ChunkArray::ChunkArray(const sf::Texture &t, const tmx::Tileset &ts)
	: m_texture(t) {
  auto texSize = getTextureSize();
  tileSetSize = ts.getTileSize();
  tsTileCount.x = texSize.x / tileSetSize.x;
  tsTileCount.y = texSize.y / tileSetSize.y;
  m_firstGID = ts.getFirstGID();
  m_lastGID = ts.getLastGID();
}

void ChunkArray::reset() {
  m_vertices.clear();
}

void ChunkArray::addTile(const std::array<sf::Vertex, 4u> &tile) {
  for (const auto &v : tile) {
	m_vertices.push_back(v);
  }
}

sf::Vector2u ChunkArray::getTextureSize() const { return m_texture.getSize(); }

void ChunkArray::draw(sf::RenderTarget &rt, sf::RenderStates states) const {
  states.texture = &m_texture;
  rt.draw(m_vertices.data(), m_vertices.size(), sf::Quads, states);
}