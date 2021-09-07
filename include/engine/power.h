//
// Created by yacopsae on 07/09/2021.
//
#pragma once

#include <SFML/System.hpp>
#include <list>
#include "directions.h"

class Power {

//ctors
public:
    Power(DIRECTIONS direction, float power);

//Functions
    float getDirection() const;

    void setDirection(float direction);

    float getPower() const;

    void setPower(float power);

//Fields
private:
    //angle
    float _direction;
    //В Ньютонах
    float _power;
};
