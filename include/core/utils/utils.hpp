//
// Created by yacopsae on 23/10/2021.
//

#pragma once

#include <box2d/b2_math.h>

namespace Utils {

constexpr const static float B2_SCALAR = 30.f;

template<typename Vector2>
static b2Vec2 sfVectorToB2Vec(const Vector2 &vec) {
  return b2Vec2(vec.x / B2_SCALAR, vec.y / B2_SCALAR);
}

static float radiansToAngle(const float &radians) {
  return radians * 180 / b2_pi;
}
}