//
// Created by yacopsae on 16/09/2021.
//

#pragma once

#include <box2d/box2d.h>
#include <SFML/Config.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class DebugBox2D : public b2Draw {
 public:
  explicit DebugBox2D(sf::RenderWindow &);
  ~DebugBox2D() override;

  sf::Color b2ColorConvert(const b2Color &, sf::Uint8 alpha = 255);
  sf::Vector2f b2VecConvert(const b2Vec2 &);

  // Draw a closed polygon provided in CCW order.
  void DrawPolygon(const b2Vec2 *vertices, int32 vertices_number, const b2Color &color) override;

  // Draw a solid closed polygon provided in CCW order.
  void DrawSolidPolygon(const b2Vec2 *vertices, int32 vertices_number, const b2Color &color) override;

  //Draw a circle.
  void DrawCircle(const b2Vec2 &center, float radius, const b2Color &color) override;

  // Draw a solid circle.
  void DrawSolidCircle(const b2Vec2 &center, float radius, const b2Vec2 &axis, const b2Color &color) override;

  // Draw a line segment.
  void DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color) override;

  // Draw a transform
  void DrawTransform(const b2Transform &xf) override;

  // Draw a point.
  void DrawPoint(const b2Vec2 &p, float size, const b2Color &color) override;

 private:
  sf::RenderWindow *window;
  const float SCALE = 30.f;
};