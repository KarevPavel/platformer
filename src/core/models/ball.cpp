//
// Created by yacopsae on 14/11/2020.
//

#include <cmath>
#include <ball.h>

void ball::rotateRight(float timeElapsed) {
    basicRotate(MOVEMENT_SPEED * timeElapsed);
}

sf::Vector2i pixelPos_;
void ball::mouseRotate(float timeElapsed) {
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

double ball::distance(sf::Vector2f a, sf::Vector2f b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

void ball::rotateLeft(float timeElapsed) {
    basicRotate(-MOVEMENT_SPEED * timeElapsed);
}

void ball::moveForward(float timeElapsed) {
    basicMovement(MOVEMENT_SPEED * timeElapsed);
}

void ball::moveBackward(float timeElapsed) {
    basicMovement(-MOVEMENT_SPEED * timeElapsed);
}

void ball::basicRotate(const float rotateAngle) {
    pointOfView.rotate(rotateAngle);
    window.clear();
    drawMe();
}

void ball::drawMe() {
    window.draw(circleShape);
    pointOfView.drawMe();
}

void ball::basicMovement(const float movementDirection) {
    sf::Vector2<float> xy = pointOfView.getPointsOnVector(x, y, movementDirection);

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

void ball::updatePosXY(sf::Vector2<float> & xy) {
    y = xy.y;
    x = xy.x;
    circleShape.setPosition(xy.x, xy.y);
}


void ball::processEvent(sf::Event event, float timeElapsed) {

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
