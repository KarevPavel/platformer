//
// Created by yacopsae on 06/09/2021.
//
#pragma once

#include <SFML/System/Time.hpp>
#include "power.h"
#include "directions.h"

class Gravity: public Power {

public:
    Gravity(float &x, float &y);

private:
    void update(sf::Time elapsed);
    float &x, &y;
};
