//
// Created by yacopsae on 14/11/2020.
//

#include "Ball.h"

void Ball::rotateRight() {
    basicRotate(MOVEMENT_SPEED);
}

void Ball::rotateLeft() {
    basicRotate(-MOVEMENT_SPEED);
}

void Ball::moveForward() {
    basicMovement(MOVEMENT_SPEED);
}

void Ball::moveBackward() {
    basicMovement(-MOVEMENT_SPEED);
}

void Ball::basicRotate(const float rotateAngle) {
    pointOfView.rotate(rotateAngle);
    window.clear();
    window.draw(circleShape);
    pointOfView.drawMe();
}

void Ball::basicMovement(const float movementDirection) {
    sf::Vector2<float> xy = pointOfView.getPointsOnVector({ posX, posY }, movementDirection);
    updatePosXY(xy);
    window.clear();
    window.draw(circleShape);
    pointOfView.drawMe();
}

void Ball::updatePosXY(sf::Vector2<float> xy) {
    posY = xy.y;
    posX = xy.x;
    circleShape.setPosition(posX, posY);
}