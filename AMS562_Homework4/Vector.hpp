#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <numeric>
#include <cmath>
#include <stdexcept>
#include <iostream>

/**
 * @class Vector
 * @brief A templated class for representing a mathematical vector.
 * @tparam T The numeric type of the vector's elements (e.g., float, double).
 */
template<typename T>
class Vector {
private:
    std::vector<T> data;
    size_t size;

public:
    /**
     * @brief Constructs a vector of a given size, initialized to zeros.
     * @param s The size of the vector.
     */
    Vector(size_t s) : data(s, T(0)), size(s) {}

    /**
     * @brief Constructs a vector of a given size with a specific initial value.
     * @param s The size of the vector.
     * @param initialValue The value to initialize all elements with.
     */
    Vector(size_t s, T initialValue) : data(s, initialValue), size(s) {}

    /**
     * @brief Gets the size of the vector.
     * @return The size of the vector.
     */
    size_t getSize() const {
        return size;
    }

    /**
     * @brief Overloads the () operator for element access.
     * @param i The index of the element.
     * @return A reference to the element at index i.
     */
    T& operator()(size_t i) {
        if (i >= size) {
            throw std::out_of_range("Vector index out of range");
        }
        return data[i];
    }

    /**
     * @brief Overloads the const () operator for element access.
     * @param i The index of the element.
     * @return A const reference to the element at index i.
     */
    const T& operator()(size_t i) const {
        if (i >= size) {
            throw std::out_of_range("Vector index out of range");
        }
        return data[i];
    }

    /**
     * @brief Calculates the 1-norm of the vector.
     * @return The 1-norm value.
     */
    T norm1() const {
        T sum = 0;
        for (const auto& val : data) {
            sum += std::abs(val);
        }
        return sum;
    }

    /**
     * @brief Prints the vector to the console.
     */
    void print() const {
        std::cout << "[";
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << (i == size - 1 ? "" : ", ");
        }
        std::cout << "]" << std::endl;
    }
};


/**
 * @brief Overloads the + operator for vector addition.
 * @tparam T The numeric type.
 * @param v1 The first vector.
 * @param v2 The second vector.
 * @return The resulting vector from the addition.
 */
template<typename T>
Vector<T> operator+(const Vector<T>& v1, const Vector<T>& v2) {
    if (v1.getSize() != v2.getSize()) {
        throw std::invalid_argument("Vector sizes must match for addition.");
    }
    Vector<T> result(v1.getSize());
    for (size_t i = 0; i < v1.getSize(); ++i) {
        result(i) = v1(i) + v2(i);
    }
    return result;
}

/**
 * @brief Overloads the - operator for vector subtraction.
 * @tparam T The numeric type.
 * @param v1 The first vector.
 * @param v2 The second vector.
 * @return The resulting vector from the subtraction.
 */
template<typename T>
Vector<T> operator-(const Vector<T>& v1, const Vector<T>& v2) {
    if (v1.getSize() != v2.getSize()) {
        throw std::invalid_argument("Vector sizes must match for subtraction.");
    }
    Vector<T> result(v1.getSize());
    for (size_t i = 0; i < v1.getSize(); ++i) {
        result(i) = v1(i) - v2(i);
    }
    return result;
}

/**
 * @brief Overloads the * operator for scalar multiplication.
 * @tparam T The numeric type.
 * @param scalar The scalar value.
 * @param vec The vector.
 * @return The resulting vector.
 */
template<typename T>
Vector<T> operator*(T scalar, const Vector<T>& vec) {
    Vector<T> result(vec.getSize());
    for (size_t i = 0; i < vec.getSize(); ++i) {
        result(i) = scalar * vec(i);
    }
    return result;
}

/**
 * @brief Overloads the * operator for dot product.
 * @tparam T The numeric type.
 * @param v1, v2 the vectors.
 * @return The resulting scalar.
 */
template<typename T>
T dot_product(const Vector<T>& v1, const Vector<T>& v2) {
    if (v1.getSize() != v2.getSize()) {
        throw std::invalid_argument("Vector sizes must match for dot product.");
    }
    T result = T(0);
    for (size_t i = 0; i < v1.getSize(); ++i) {
        result += v1(i) * v2(i); 
    }
    return result;    
}

#endif // VECTOR_HPP
