#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"

/**
 * @file Rectangle.h
 * @brief Declaration of the Rectangle class.
 */

/**
 * @class Rectangle
 * @brief Represents an axis-aligned rectangle (edges are parallel to the x and y axes).
 */

class Rectangle {
protected:
    Point top_left;     /**< top-left vertex of the rectangle */
    Point bottom_right; /**< bottom-right vertex of the rectangle */

public:    
    /**
     * @brief Constructor that initializes a rectangle with two given points (top-left and bottom-right) .
     * @param point1 The top-left corner of the rectangle.
     * @param point2 The bottom-right corner of the rectangle.
     */ 
    Rectangle(const Point& point1, const Point& point2);
    
    /** @brief Calculates the area of the rectangle 
     *  @return The area of the rectangle
     */
    virtual double area() const;
    
    /** @brief Calculates the perimeter of the rectangle 
     *  @return The perimeter of the rectangle
     */
    double perimeter() const;
    
    /** @brief Check if a given point lies inside the rectangle (excluding the edges)
     *  @param point The point to check 
     *  @return True if point is inside the rectangle, False otherwise
     */
    bool is_inside_rectangle(const Point& point) const;

};
#endif // RECTANGLE_H