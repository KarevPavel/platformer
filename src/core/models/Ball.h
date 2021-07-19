//
// Created by yacopsae on 14/11/2020.
//

#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "PointOfView.h"

class Ball {

private:
    PointOfView pointOfView;
    sf::CircleShape circleShape;
    sf::RenderWindow &window;
    float &posX, &posY, &oX, &oY, radius;

public:

    explicit Ball(float &x,
                  float &y,
                  float &oX,
                  float &oY,
                  float radius,
                  float pointOfViewGrad,
                  float visibleDistance,
                  sf::RenderWindow &window) :
            posX(x),
            posY(y),
            oY(oY),
            oX(oX),
            radius(radius),
            pointOfView(oX, oY, pointOfViewGrad, visibleDistance, window),
            window(window) {
        circleShape = sf::CircleShape{radius};
        circleShape.setOutlineColor(sf::Color::Red);
        circleShape.setOutlineThickness(2);
        circleShape.setFillColor(sf::Color::Black);
        circleShape.setPosition(x, y);
    }

    float MOVEMENT_SPEED = 10.0;

    void rotateRight();

    void rotateLeft();

    void moveForward();

    void moveBackward();

    void updatePosXY(sf::Vector2<float> xy);

    void basicRotate(float movementDirection);

    void basicMovement(float movementDirection);
};