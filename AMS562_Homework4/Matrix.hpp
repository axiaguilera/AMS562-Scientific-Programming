#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "Vector.hpp"
#include <vector>
#include <numeric>
#include <stdexcept>

/**
 * @class Matrix
 * @brief A templated class for representing a square matrix.
 * @tparam T The numeric type of the matrix's elements (e.g., float, double).
 */
template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> matrix;
    size_t size;

public:
    /**
     * @brief Constructs a square matrix of a given size, initialized to zeros.
     * @param s The size of the matrix (s = number of pages).
     * @param initialValue The value to initialize all elements with.
     */
    Matrix(size_t s, T initialValue = 0) : size(s), matrix(s, std::vector<T>(s, initialValue)) {}

    /**
     * @brief Constructs a matrix from a 2D vector.
     * @param initialData The initial data for the matrix.
     */
    Matrix(const std::vector<std::vector<T>>& initialData) {
        if (initialData.empty() || initialData.size() != initialData[0].size()) {
            throw std::invalid_argument("Matrix must be square.");
        }
        size = initialData.size();
        matrix = initialData;
    }

    /**
     * @brief Gets the size of the matrix (the number of pages).
     * @return The size of the matrix.
     */
    size_t getSize() const {
        return size;
    }

    /**
     * @brief Overloads the () operator for element access.
     * @param i The row index of the element.
     * @param j The column index of the element.
     * @return A reference to the element at position (i, j).
     */ 
    
    

    T& operator()(size_t i, size_t j) {
        if (i >= size || j >= size) {
            throw std::out_of_range("Matrix index out of range");
        }
        return matrix[i][j];
    }

    /**
     * @brief Overloads the const () operator for element access.
     * @param i The row index of the element.
     * @param j The column index of the element.
     * @return A const reference to the element at position (i, j).
     */

    const T& operator()(size_t i, size_t j) const {
        if (i >= size || j >= size) {
            throw std::out_of_range("Matrix index out of range");
        }
        return matrix[i][j];
    }

    /**
     * @brief Normalize the columns of the matrix to have unit 1-norm.
     *        Handles dangling nodes by setting their entries as 1 / N, where N is the number of pages.
     */
    void normalizeColumns()  {
        for (size_t j = 0; j < size; ++j) {
            T columnSum = T(0);
            for (size_t i = 0; i < size; ++i) {
                columnSum += std::abs(matrix[i][j]);
            }
            if (columnSum == 0) {
                // Handle dangling node by setting the entire column to 1/N
                for (size_t i = 0; i< size; ++i) {
                    matrix[i][j] = T(1) / size;
                }
            } else {
                // Normalize the column
                for (size_t i = 0; i < size; ++i) {
                    matrix[i][j] /= columnSum;            
                }
            }    
        }
        
    }
};

/**
 * @brief Overloads the * operator for matrix-vector multiplication.
 * @tparam T The numeric type.
 * @param matrix The matrix.
 * @param vector The vector.
 * @return The resulting vector.
 */
template<typename T>
Vector<T> operator*(const Matrix<T>& matrix, const Vector<T>& vector) {
    if (matrix.getSize() != vector.getSize()) {
        throw std::invalid_argument("Matrix and vector dimensions must match for multiplication.");
    }
    Vector<T> result(matrix.getSize());
    for (size_t i = 0; i < matrix.getSize(); ++i) {
        for (size_t j = 0; j < matrix.getSize(); ++j) {
            result(i) += matrix(i, j) * vector(j);
        }
    }
    return result;
}


#endif //  MATRIX_HPP