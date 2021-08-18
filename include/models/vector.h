//
// Created by yacopsae on 15/11/2020.
//

#ifndef PLATFORMER_VECTOR_H
#define PLATFORMER_VECTOR_H

#include <SFML/System/Vector2.hpp>

class DirectionalPoint {
public:
    DirectionalPoint(float x, float y, bool mainDirection) : x(x), y(y), mainDirection(mainDirection) {}

    void setPosition(float x, float y);
    float getX();
    float getY();


private:
    float x, y;
    bool mainDirection;
};

class vector {

public:
    vector(const DirectionalPoint &startPoint = DirectionalPoint(0, 0, false),
           const DirectionalPoint &endPoint = DirectionalPoint(0, 0, false)) : startPoint(startPoint),
                                                                               endPoint(endPoint) {}

    void setPosition(float x, float y);
    sf::Vector2f pointAt(int distance);
    void rotate(float angle);

private:
    DirectionalPoint startPoint;
    DirectionalPoint endPoint;


    float calculateK();
    float calculateB();
    float calculateB(float k);
    float calculateAngle();
    float calculateAngle(float k);

};

#endif //PLATFORMER_VECTOR_H
