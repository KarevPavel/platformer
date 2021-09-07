//
// Created by yacopsae on 07/09/2021.
//
#pragma once

#include "power.h"
#include "directions.h"
#include "iostream"

class Jump: public Power {

public:
    explicit Jump(float &x, float &y, float power);

    void jump(float timeElapsed) {
        std::cout << "Jump" << std::endl;
    }

private:
    float &x, &y;
};
