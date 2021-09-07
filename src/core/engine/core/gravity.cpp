//
// Created by yacopsae on 06/09/2021.
//

#include "gravity.h"

void Gravity::update(sf::Time elapsed) {

}

Gravity::Gravity(float &x, float &y) : Power(DIRECTIONS::DOWN, 9.780), x(x), y(y) {}
