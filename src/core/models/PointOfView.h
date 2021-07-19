//
// Created by yacopsae on 14/11/2020.
//

#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <math.h>
#include <SFML/Graphics/Text.hpp>
#include "Vector.h"
#include <iostream>

class PointOfView {
private:
    sf::RectangleShape leftRect;
    sf::RectangleShape rightRect;
    sf::RectangleShape moveVector;
    float angle;
    //sf::CircleShape shape;
    float &x, &y;
    float distance; //pointOfViewRad,
    sf::RenderWindow &window;

public:
    PointOfView(float &x, float &y, float pointOfViewRad,
                float distance,
                sf::RenderWindow &window) :
            x(x),
            y(y),
            distance(distance),
            window(window) { //pointOfViewRad(pointOfViewRad),
        leftRect = sf::RectangleShape({1, distance});
        leftRect.rotate(pointOfViewRad / 2);
        leftRect.setPosition(x, y);

        rightRect = sf::RectangleShape({1, distance});
        rightRect.rotate(-pointOfViewRad / 2);
        rightRect.setPosition(x, y);

        moveVector = sf::RectangleShape({1, distance});
        moveVector.setPosition(x, y);
        angle = 270.f;
    }

    void drawMe();

    void rotate(float angle);

    sf::Vector2<float> getPointsOnVector(sf::Vector2<float> xy, float lenght) const;

    static float getDegrees(float angle);
};
