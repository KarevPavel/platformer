//
// Created by yacopsae on 14/11/2020.
//

#pragma once

#include <SFMLOrthogonalLayer.h>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <list>
#include <SFMLOrthogonalLayer.h>
#include "point_of_view.h"

class Ball {

private:
    point_of_view pointOfView;
    sf::CircleShape circleShape;
    sf::RenderWindow &window;
    float &x, &y, radius_;

public:

    explicit Ball(float &x,
                  float &y,
                  float &oX,
                  float &oY,
                  float radius,
                  float pointOfViewGrad,
                  float visibleDistance,
                  sf::RenderWindow &window);

    float MOVEMENT_SPEED = 0.2;

    void rotateRight(float timeElapsed);

    void rotateLeft(float timeElapsed);

    void moveLeft(float timeElapsed);

    void moveRight(float timeElapsed);

    void dummyMovement(const float movementDirection);

    void moveForward(float timeElapsed);

    void moveBackward(float timeElapsed);

    void updatePosXY(sf::Vector2<float> & xy);

    void basicRotate(float movementDirection);

    void basicMovement(float movementDirection);

    void update(sf::Time timeElapsed, std::list<MapLayer> & list);

    void drawMe();

    sf::Vector2f getCord() const;

    void mouseRotate(float timeElapsed);

    static double distance(sf::Vector2f a, sf::Vector2f b);
};