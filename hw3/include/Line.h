#ifndef LINE_H
#define LINE_H

#include "Point.h"
#include <string>
/**
 * @file Line.h
 * @brief Declaration of the Line class for scientific programming.
 */

/**
 * @class Line
 * @brief Represents a line segment defined by two points in 2D space.
 */
class Line {
private:
    Point point1; /**< The first endpoint of the line. */
    Point point2; /**< The second endpoint of the line. */     
public:

    /**
     * @brief Constructor that initializes a line with two given points.
     * @param point1 The first endpoint of the line.
     * @param point2 The second endpoint of the line.
     * @throws std::invalid_argument if the pointq and point2 are the same.
     */ 

    Line (const Point& point1, const Point& point2);

    /**
     * @brief Calculates the length of the line segment.
     * @return Length of the line segment.
     */

    double length() const;

    /**
     * @brief Calculates the slope of the line.
     * @return Slope of the line.
     * @throws std::runtime_error if the line is vertical (undefined slope).
     */
    
    double slope() const;

    /**
     * @brief Calculates the y-intercept of the line.
     * @return y-intercept of the line.
     * @throws std::runtime_error if the line is vertical (no y-intercept).
     */
    
    double y_intercept() const;

};
#endif // LINE_H
