//
// Created by yacopsae on 23/10/2021.
//

#pragma once

#include <array>

#include <box2d/b2_math.h>

#include <SFML/Graphics/Vertex.hpp>

namespace Utils {

constexpr const static float B2_SCALAR = 30.f;

template<typename Vector2>
static b2Vec2 sfVectorToB2Vec(const Vector2 &vec) {
  return b2Vec2(vec.x / B2_SCALAR, vec.y / B2_SCALAR);
}

static float radiansToAngle(const float &radians) {
  return radians * 180 / b2_pi;
}

static sf::Vector2f centerOfTile(const std::array<sf::Vertex, 4u> &tile) {
  auto pos = tile[2].position - tile[0].position;
  return tile[2].position - sf::Vector2f{ pos.x / 2, pos.y / 2};
}

static b2Vec2 toBox2DPos(const std::array<sf::Vertex, 4u> &tile) {
  return Utils::sfVectorToB2Vec(Utils::centerOfTile(tile));
}

static sf::Vector2f b2VecToVector2(const b2Vec2 &vector) {
  return sf::Vector2f { vector.x * B2_SCALAR, vector.y * B2_SCALAR };
}

}