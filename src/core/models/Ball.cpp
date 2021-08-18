//
// Created by yacopsae on 14/11/2020.
//

#include <cmath>
#include "Ball.h"

void Ball::rotateRight(float timeElapsed) {
    basicRotate(MOVEMENT_SPEED * timeElapsed);
}

sf::Vector2i pixelPos_;
void Ball::mouseRotate(float timeElapsed) {
    // get the current mouse position in the window
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    if (pixelPos_ != pixelPos) {
        pixelPos_ = pixelPos;
        // convert it to world coordinates
        sf::Vector2f mPos = window.mapPixelToCoords(pixelPos, window.getView());
        sf::Vector2f oPos = pointOfView.getCenter();

        float dX = mPos.x - oPos.x;//вектор , колинеарный прямой, которая пересекает спрайт и курсор
        float dY = mPos.y - oPos.y;//он же, координата y
        float rotation = (std::atan2(dY, dX)) * 180 / M_PI ;//получаем угол в радианах и переводим его в градусы
        pointOfView.rotate(rotation);//поворачиваем спрайт на эти градусы
        window.clear();
        drawMe();
    }
}

double Ball::distance(sf::Vector2f a, sf::Vector2f b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

void Ball::rotateLeft(float timeElapsed) {
    basicRotate(-MOVEMENT_SPEED * timeElapsed);
}

void Ball::moveForward(float timeElapsed) {
    basicMovement(MOVEMENT_SPEED * timeElapsed);
}

void Ball::moveBackward(float timeElapsed) {
    basicMovement(-MOVEMENT_SPEED * timeElapsed);
}

void Ball::basicRotate(const float rotateAngle) {
    pointOfView.rotate(rotateAngle);
    window.clear();
    drawMe();
}

void Ball::drawMe() {
    window.draw(circleShape);
    pointOfView.drawMe();
}

void Ball::basicMovement(const float movementDirection) {
    sf::Vector2<float> xy = pointOfView.getPointsOnVector(x, y, movementDirection);

    //std::cout << "Circle shape has collision: " << (level.hasCollision(circleShape.getGlobalBounds())) << std::endl;
    //std::cout << "MoveVector has collision: " << (level.hasCollision(pointOfView.getMoveVector().getGlobalBounds())) << std::endl;


    if (!level.hasCollision(circleShape.getGlobalBounds()) ||
    !level.hasCollision(pointOfView.getMoveVector().getGlobalBounds())) {
        updatePosXY(xy);

        window.clear();
        window.draw(circleShape);

        xy.x += radius_;
        xy.y += radius_;
        pointOfView.updatePosXY(xy);
        pointOfView.drawMe();
    }
}

void Ball::updatePosXY(sf::Vector2<float> & xy) {
    y = xy.y;
    x = xy.x;
    circleShape.setPosition(xy.x, xy.y);
}


void Ball::processEvent(sf::Event event, float timeElapsed) {

    mouseRotate(timeElapsed);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        rotateLeft(timeElapsed);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        moveForward(timeElapsed);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        moveBackward(timeElapsed);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        rotateRight(timeElapsed);
    }
}
