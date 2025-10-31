#include "Rectangle.h"
#include <cmath>

Rectangle::Rectangle(const Point& point1, const Point& point2):top_left(point1), bottom_right(point2){}

double Rectangle::area() const {
    double width = std::abs(top_left.getX() - bottom_right.getX());
    double height = std::abs(top_left.getY() - bottom_right.getY());
    
    return height * width;
}


double Rectangle::perimeter() const {
    double width = std::abs(bottom_right.getX() - top_left.getX());
    double height = std::abs(top_left.getY() - bottom_right.getY());
    
    return 2 * (height + width);
}


bool Rectangle::is_inside_rectangle(const Point& point) const{
    bool in_x = point.getX() > top_left.getX() && point.getX() < bottom_right.getX();
    bool in_y = point.getY() > bottom_right.getY() && point.getY() < top_left.getY();
    
    return in_x && in_y;

}



