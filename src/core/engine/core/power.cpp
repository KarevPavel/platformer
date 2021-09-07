//
// Created by yacopsae on 07/09/2021.
//

#include <directions.h>
#include "power.h"

Power::Power(DIRECTIONS direction, float power) : _direction((float)direction), _power(power) {}

float Power::getDirection() const {
  return _direction;
}

void Power::setDirection(float direction) {
  Power::_direction = direction;
}

float Power::getPower() const {
  return _power;
}
