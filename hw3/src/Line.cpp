/**
 * @file Line.cpp
 * @brief Implementation of the Line class for scientific programming.
 */

#include "Line.h"
#include <cmath>
#include <stdexcept>

Line::Line(const Point& point1, const Point& point2): point1(point1), point2(point2) {
    if (point1.getX() == point2.getX() && point1.getY() == point2.getY()){
        throw std::invalid_argument("Input point of the line cannot be the same.");
    }
}

double Line::length() const {
    return point1.distanceTo(point2);
}

double Line::slope() const {
    double dy = point2.getY() - point1.getY();
    double dx = point2.getX() - point1.getX();

    if (dx == 0) {
        throw std::runtime_error("Vertical lines have undefined slope.");
    }
    
    return dy / dx;
}

double Line::y_intercept() const {
    if (point1.getX() == point2.getX()) {
        throw std::runtime_error("Vertical lines does not have y-intercept.");
    } 
    
    return point1.getY() - slope() * point1.getX();
}

