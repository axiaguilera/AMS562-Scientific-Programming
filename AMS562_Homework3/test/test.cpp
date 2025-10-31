#include "Point.h"
#include "Line.h"
#include "Rectangle.h"
#include "Square.h"

#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>

/**
 * @brief Test suite for the Point class.
 * 
 * Verifies constructors, distance computations,
 * translation, scaling, operator overloading, and string formatting.
 */
void test_point() {
    Point p1;
    assert(p1.getX() == 0.0 && p1.getY() == 0.0);
    std::cout << "Point default constructor PASSED" << std::endl;

    Point p2(3, 4);
    assert(p2.getX() == 3.0 && p2.getY() == 4.0);
    std::cout << "Point parameterized constructor PASSED" << std::endl;
    
    assert(std::abs(p2.distanceFromOrigin() - 5.0) < 1e-9);
    std::cout << "Point distanceFromOrigin PASSED" << std::endl;

    Point p3(0, 0);
    assert(std::abs(p3.distanceTo(p2) - 5.0) < 1e-9);
    std::cout << "Point distanceTo PASSED" << std::endl;
    
    p2.translate(1, 1);
    assert(p2.getX() == 4.0 && p2.getY() == 5.0);
    std::cout << "Point translate PASSED" << std::endl;

    Point p4 = p3 + p2;
    assert(p4.getX() == 4.0 && p4.getY() == 5.0);
    std::cout << "Point operator+ PASSED" << std::endl;
    
    Point p5 = p2.scale(2);
    assert(p5.getX() == 8.0 && p5.getY() == 10.0);
    std::cout << "Point scale PASSED" << std::endl;
    
    assert(p2.toString() == "(4, 5)");
    std::cout << "Point toString PASSED" << std::endl;
}

/**
 * @brief Test suite for the Line class.
 * 
 * Checks length, slope, y-intercept, and exception handling
 * for invalid construction (identical points).
 */
void test_line() {
    Point p1(1, 1), p2(4, 5);
    Line line(p1, p2);
    
    assert(std::abs(line.length() - 5.0) < 1e-9);
    std::cout << "Line length PASSED" << std::endl;

    assert(std::abs(line.slope() - 4.0/3.0) < 1e-9);
    std::cout << "Line slope PASSED" << std::endl;
    
    assert(std::abs(line.y_intercept() + 1.0/3.0) < 1e-9);
    std::cout << "Line y_intercept PASSED" << std::endl;

    // Expect exception when both points are identical
    try {
        Line line2(p1, p1);
    } catch (const std::invalid_argument& e) {
        std::cout << "Line constructor exception for same points PASSED" << std::endl;
    }
}

/**
 * @brief Test suite for the Rectangle class.
 * 
 * Validates area, perimeter, and point containment
 * (inside, outside, and boundary cases).
 */
void test_rectangle() {
    Point top_left(1, 5), bottom_right(6, 1);
    Rectangle rectangle(top_left, bottom_right);

    assert(std::abs(rectangle.area() - 20.0) < 1e-9);
    std::cout << "Rectangle area PASSED" << std::endl;

    assert(std::abs(rectangle.perimeter() - 18.0) < 1e-9);
    std::cout << "Rectangle perimeter PASSED" << std::endl;

    // Inside point
    Point p_in(3, 3);
    assert(rectangle.is_inside_rectangle(p_in));
    std::cout << "Rectangle contains (inside) PASSED" << std::endl;
    
    // Outside point
    Point p_out(7, 3);
    assert(!rectangle.is_inside_rectangle(p_out));
    std::cout << "Rectangle contains (outside) PASSED" << std::endl;
    
    // Boundary point (on edge) – not considered inside
    Point p_edge(1, 3);
    assert(!rectangle.is_inside_rectangle(p_edge));
    std::cout << "Rectangle contains (on edge) PASSED" << std::endl;
}

/**
 * @brief Test suite for the Square class.
 * 
 * Checks area, perimeter, and exception for invalid side length.
 */
void test_square() {
    Point top_left(1, 5);
    Square square(top_left, 4);

    assert(std::abs(square.area() - 16.0) < 1e-9);
    std::cout << "Square area PASSED" << std::endl;
    
    assert(std::abs(square.perimeter() - 16.0) < 1e-9);
    std::cout << "Square perimeter PASSED" << std::endl;

    // Expect exception when side length is negative
    try {
        Square s_neg(top_left, -4);
    } catch (const std::invalid_argument& e) {
        std::cout << "Square constructor exception for negative side length PASSED" << std::endl;
    }
}

/**
 * @brief Main entry point for geometric tests.
 */
int main() {
    test_point();
    std::cout << "--------------------" << std::endl;
    
    test_line();
    std::cout << "--------------------" << std::endl;
    
    test_rectangle();
    std::cout << "--------------------" << std::endl;
    
    test_square();
    std::cout << "--------------------" << std::endl;
    
    return 0;
}
