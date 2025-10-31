/**
 * @file Point.cpp
 * @brief Implementation of the Point class for scientific programming.
 */

#include "Point.h"
#include <cmath>
#include <sstream>

Point::Point() : x(0.0), y(0.0) {}

Point::Point(double x_val, double y_val) : x(x_val), y(y_val) {}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

void Point::setX(double x_val) {
    x = x_val;
}

void Point::setY(double y_val) {
    y = y_val;
}

double Point::distanceFromOrigin() const {
    return std::hypot(x, y);
}

double Point::distanceTo(const Point& point2) const {
    return std::hypot(point2.x - x, point2.y - y);
}

void Point::translate(double dx, double dy) {
    x += dx;
    y += dy;
}

Point Point::operator+(const Point& point2) const {
    return Point(x + point2.x, y + point2.y);
}

Point Point::scale(double factor) const {
    return Point(factor * x, factor * y);
}

std::string Point::toString() const {
    std::ostringstream oss;
    oss << "(" << x << ", " << y << ")";
    return oss.str();
}
