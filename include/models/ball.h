//
// Created by yacopsae on 14/11/2020.
//

#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "point_of_view.h"

class ball {

private:
    point_of_view pointOfView;
    sf::CircleShape circleShape;
    sf::RenderWindow &window;
    float &x, &y, radius_;

public:

    explicit ball(float &x,
                  float &y,
                  float &oX,
                  float &oY,
                  float radius,
                  float pointOfViewGrad,
                  float visibleDistance,
                  sf::RenderWindow &window) :
            x(x),
            y(y),
            radius_(radius),
            pointOfView(oX, oY, pointOfViewGrad, visibleDistance, window),
            window(window) {
        circleShape = sf::CircleShape{radius};
        circleShape.setOutlineColor(sf::Color::Red);
        circleShape.setOutlineThickness(2);
        circleShape.setFillColor(sf::Color::Black);
        circleShape.setPosition(x, y);
    }

    float MOVEMENT_SPEED = 0.2;

    void rotateRight(float d);

    void rotateLeft(float d);

    void moveForward(float d);

    void moveBackward(float d);

    void updatePosXY(sf::Vector2<float> & xy);

    void basicRotate(float movementDirection);

    void basicMovement(float movementDirection);

    void update(sf::Time timeElapsed);

    void drawMe();

    void mouseRotate(float timeElapsed);

    static double distance(sf::Vector2f a, sf::Vector2f b);
};