//
// Created by yacopsae on 15/11/2020.
//

#include <vector.h>
#include <cmath>
#include <math.h>

void vector::setPosition(float x, float y) {
  endPoint.setPosition(x, y);
}

float vector::calculateK() {
  return (startPoint.getX() + endPoint.getY() - startPoint.getY()) / (1 + endPoint.getX());
}

float vector::calculateB() {
  return endPoint.getY() - calculateK() * endPoint.getX();
}

float vector::calculateB(float k) {
  return endPoint.getY() - k * endPoint.getX();
}

float vector::calculateAngle() {
  return calculateAngle(calculateK());
}

float vector::calculateAngle(float k) {
  if (k < 0) {
	return M_PI - atan(k);
  }
  return atan(k);
}

void vector::rotate(float angle) {
  float k = tan(angle);
  float b = calculateB();

  if (k < 0) {
	float x = endPoint.getX();
	if (x != 0) {
	  float y = k * x + b;
	  endPoint.setPosition(x, y);
	}
  }
}

sf::Vector2f vector::pointAt(int distance) {
  float xMax = fmax(endPoint.getX(), startPoint.getX());
  float xMin = xMax == endPoint.getX() ? xMax : startPoint.getX();
  float yMax = fmax(endPoint.getY(), startPoint.getY());
  float yMin = yMax == endPoint.getY() ? yMax : startPoint.getY();
  float cathetus1 = xMax - xMin;
  if (cathetus1 == 0) {
	return {xMax, yMin + distance};
  }
  float cathetus2 = yMax - yMin;
  if (cathetus2 == 0) {
	return {xMin + distance, yMax};
  }

  return {xMin + distance, yMax + distance};
}

void DirectionalPoint::setPosition(float x0, float y0) {
  x = x0;
  y = y0;
}

float DirectionalPoint::getX() {
  return x;
}

float DirectionalPoint::getY() {
  return y;
}