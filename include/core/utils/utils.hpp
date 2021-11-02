//
// Created by yacopsae on 23/10/2021.
//

#pragma once

#include <array>
#include <memory>

#include <box2d/b2_fixture.h>
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_world.h>
#include <box2d/b2_math.h>
#include <box2d/b2_body.h>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Vector2.hpp>

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
  return tile[2].position - sf::Vector2f{pos.x / 2, pos.y / 2};
}

static b2Vec2 toBox2DPos(const std::array<sf::Vertex, 4u> &tile) {
  return Utils::sfVectorToB2Vec(Utils::centerOfTile(tile));
}

static sf::Vector2f b2VecToVector2(const b2Vec2 &vector) {
  return sf::Vector2f{vector.x * B2_SCALAR, vector.y * B2_SCALAR};
}

static void centerOrigin(sf::Text &text) {
  const sf::FloatRect rect = text.getLocalBounds();
  text.setOrigin(rect.left + rect.width / 2.f, rect.top + rect.height / 2.f);
}

static void centerOrigin(sf::Sprite &sprite) {
  const sf::FloatRect rect = sprite.getLocalBounds();
  sprite.setOrigin(rect.left + rect.width / 2.f, rect.top + rect.height / 2.f);
}

static sf::Vector2f getPositionBelow(const sf::Text &text) {
  sf::Vector2f position = text.getPosition();
  sf::Vector2f heightFromPosition =
	  sf::Vector2f(0, text.getGlobalBounds().height - text.getLocalBounds().top);
  return sf::Vector2f(position + heightFromPosition);
}

//Not working!!!!
static b2Body *createBody(
	b2World &b2World_,
	sf::Vector2f position,
	b2BodyType bodyType,
	sf::Vector2f size,
	float density,
	float friction) {
  auto bodyDef = std::make_unique<b2BodyDef>();
  bodyDef->position = Utils::sfVectorToB2Vec(position);
  bodyDef->type = bodyType;
  b2Body *playerBody = b2World_.CreateBody(bodyDef.get());
  auto fixtureDef = std::make_unique<b2FixtureDef>();
  const auto &shape = std::make_unique<b2PolygonShape>();
  shape->SetAsBox(size.x / 2, size.y / 2);
  fixtureDef->shape = shape.get();
  fixtureDef->density = 1.0f;
  fixtureDef->friction = 0.7f;
  playerBody->CreateFixture(fixtureDef.get());
  return playerBody;
}

}