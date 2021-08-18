//
// Created by yacopsae on 14/11/2020.
//

#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Vector.h"
#include <iostream>

class PointOfView {
private:
    sf::RectangleShape leftRect;
    sf::RectangleShape rightRect;
    sf::RectangleShape moveVector;
    float &x_, &y_;
    sf::RenderWindow &window;

public:
    PointOfView(float &x, float &y, float pointOfViewRad,
                float distance,
                sf::RenderWindow &window) :
            x_(x),
            y_(y),
            window(window) { //pointOfViewRad(pointOfViewRad),
        leftRect = sf::RectangleShape({1, distance});
        leftRect.rotate(pointOfViewRad / 2);
        leftRect.setPosition(x, y);
        leftRect.setFillColor(sf::Color::Green);

        rightRect = sf::RectangleShape({1, distance});
        rightRect.rotate(- pointOfViewRad / 2);
        rightRect.setPosition(x, y);
        rightRect.setFillColor(sf::Color::Blue);

        moveVector = sf::RectangleShape({1, distance});
        moveVector.setPosition(x, y);
    }

    sf::RectangleShape& getMoveVector() {
        return moveVector;
    }

    void drawMe();

    void rotate(float angle);

    void updatePosXY(sf::Vector2<float> & xy);

    sf::Vector2<float> getPointsOnVector(float lenght, float d, const float d1) const;

    float getRadians() const;

    sf::Vector2<float> getCenter() const;

    float getDegrees() const;
};
