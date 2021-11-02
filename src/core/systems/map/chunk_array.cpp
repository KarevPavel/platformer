//
// Created by yacopsae on 18/10/2021.
//

#include "chunk_array.hpp"

#include <box2d/b2_body.h>
#include <box2d/b2_fixture.h>
#include <box2d/b2_polygon_shape.h>

#include <iostream>

#include "utils.hpp"
#include "game_components.hpp"

ChunkArray::ChunkArray(const sf::Texture &t, const tmx::Tileset &ts, const std::string &layerName)
	: m_texture(t), layerName(layerName) {
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

void ChunkArray::addTile(const std::array<sf::Vertex, 4u> &tile, b2World& world) {
  for (const auto &v : tile) {
	m_vertices.push_back(v);
  }
  if (layerName == "SOLID_LAYER") {
	auto pos = Utils::toBox2DPos(tile);
	createBody(world, pos);
  }
}

sf::Vector2u ChunkArray::getTextureSize() const { return m_texture.getSize(); }

void ChunkArray::draw(sf::RenderTarget &rt, sf::RenderStates states) const {
  states.texture = &m_texture;
  rt.draw(m_vertices.data(), m_vertices.size(), sf::Quads, states);
}

void ChunkArray::createBody(b2World& world, const b2Vec2 &pos) {
  auto bodyDef = std::make_unique<b2BodyDef>();
  bodyDef->type = b2BodyType::b2_staticBody;
  bodyDef->position = pos;
  bodyDef->enabled = true;
  body = world.CreateBody(bodyDef.get());
  auto fixtureDef = std::make_unique<b2FixtureDef>();
  //auto type = std::make_unique<GameComponents::ObjectType>(GameComponents::ObjectType::STATIC);
  //fixtureDef->userData.pointer = reinterpret_cast<uintptr_t>(type.get());
  fixtureDef->userData.pointer =
	  reinterpret_cast<uintptr_t>(new GameComponents::Collision(GameComponents::ObjectType::STATIC));

  fixtureDef->density = 1.f;
  fixtureDef->friction = 0.7f;
  fixtureDef->restitution = 0.2f;
  auto shapeSize = Utils::sfVectorToB2Vec(sf::Vector2{16, 16}); //TODO: REMOVE MAGIC!!!!
  const auto &shape = std::make_unique<b2PolygonShape>();
  shape->SetAsBox(shapeSize.x / 2, shapeSize.y / 2);
  fixtureDef->shape = shape.get();
  body->CreateFixture(fixtureDef.get());
}
