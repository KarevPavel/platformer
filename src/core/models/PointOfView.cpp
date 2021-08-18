
#include "PointOfView.h"
#include <cmath>

void PointOfView::drawMe(){
    window.draw(rightRect);
    window.draw(leftRect);
    window.draw(moveVector);
}

void PointOfView::rotate(float newAngle){
    //        leftRect.setFillColor(sf::Color::Green);
    //        rightRect.setFillColor(sf::Color::Blue);
    rightRect.setRotation(newAngle - 45);
    leftRect.setRotation(newAngle - 135);
    moveVector.setRotation(newAngle - 90);
}

void PointOfView::updatePosXY(sf::Vector2<float> & coordinates) {
    rightRect.setPosition(coordinates);
    leftRect.setPosition(coordinates);
    moveVector.setPosition(coordinates);
    x_ = coordinates.x;
    y_ = coordinates.y;
}

sf::Vector2<float> PointOfView::getPointsOnVector(const float x, const float y, float lenght) const {
    //Remark: Т.к. у  SFML система координат по Y перевёрнута
    std::cout << "lenght " << lenght << std::endl;
    std::cout << "moveVector.getRotation() " << moveVector.getRotation() << std::endl;
    std::cout << "getRadians() " << getRadians() << std::endl;
    sf::Vector2<float> result = {x + lenght * std::cos(getRadians()), y + lenght * std::sin(getRadians())};
    std::cout << "old x: " << x_  << " new x: " << result.x << std::endl;
    std::cout << "old y_: " << y_  << " new y_: " << result.y << std::endl;

    return result;
}

float PointOfView::getRadians() const {
    const float halfC = M_PI / 180;
    return (moveVector.getRotation() + 90) * halfC;
}

float PointOfView::getDegrees() const {
    return moveVector.getRotation();
}

sf::Vector2<float> PointOfView::getCenter() const {
    return {x_, y_};
}
