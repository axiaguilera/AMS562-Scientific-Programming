#include "Square.h"
#include <stdexcept>

Square::Square(const Point& point, double side_length) : 
    Rectangle(point, Point(point.getX() + side_length,point.getY() - side_length)) {
        if (side_length <= 0){
            throw std::invalid_argument("The side lenght can not be negative");
        }
    }

double Square::area() const {
    double side_length = std::abs(top_left.getY() - bottom_right.getY());
    return side_length * side_length;
}    
