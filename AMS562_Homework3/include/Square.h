#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

/**
 * @file Square.h
 * @brief Declaration of the square class.
 */

/**
 * @class Square
 * @brief Represents an axis-aligned square (edges are parallel to the x and y axes).
 */

class Square : public Rectangle {

public:    
    /**
     * @brief Constructor that initializes a square with the top-left corner vertex and the side length.
     * @param point The top-left corner of the square.
     * @param length The side length of the square.
     * @throw std:invalid_argument if the side length is negative.
     */ 
    Square(const Point& point, double side_length);
    
    /** @brief Calculates the area of the rectangle 
     *  @return The area of the rectangle
     */
    double area() const override;

};
#endif // SQUARE_H