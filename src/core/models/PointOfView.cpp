
#include "PointOfView.h"

void PointOfView::drawMe(){
    rightRect.setPosition(x, y);
    leftRect.setPosition(x, y);
    window.draw(moveVector);
    window.draw(rightRect);
    window.draw(leftRect);
}

void PointOfView::rotate(float newAngle){
    rightRect.rotate(newAngle);
    leftRect.rotate(newAngle);
    moveVector.rotate(newAngle);
    angle += newAngle;
}

sf::Vector2<float> PointOfView::getPointsOnVector(sf::Vector2<float> xy, float lenght) const {
    //Remark: Т.к. у  SFML система координат по Y перевёрнута
    sf::Vector2<float> result = {xy.x - lenght * cos(getDegrees(angle)), xy.y - lenght * sin(getDegrees(angle))};
    return result;
}

float PointOfView::getDegrees(float angle) {
    const float halfC = M_PI / 180;
    return angle * halfC;
}