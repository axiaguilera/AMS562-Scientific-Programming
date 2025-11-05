#ifndef PAGERANK_HPP
#define PAGERANK_HPP

#include "Matrix.hpp"
#include "Vector.hpp"
#include <iostream>
#include <iomanip>

/**
 * @brief Computes the PageRank for a given transition matrix.
 * @tparam T The numeric type (e.g., float, double).
 * @param M The column-normalized transition probability matrix.
 * @param r The rank vector (output parameter).
 * @param alpha The damping factor.
 * @param tolerance The convergence tolerance.
 */
template<typename T>
void pageRank(const Matrix<T>& M, Vector<T>& r, T alpha = 0.85, T tolerance = 1e-6) {
    size_t N = M.getSize();
    if (N == 0) return;

    // Initialize rank vector r
    r = Vector<T>(N, static_cast<T>(1.0) / N);
    
    // Initialize teleportation vector s
    Vector<T> s(N, static_cast<T>(1.0) / N);

    Vector<T> r_new(N);
    //int iteration = 0;
    
    while (true) {
        // r' = a * M * r + (1 - a) * s
        r_new = alpha * (M * r) + (1 - alpha) * s;
        
        // Check for convergence
        T diff = (r_new - r).norm1();
        
        // Update r for the next iteration
        r = r_new;
        
        //iteration++;
        
        if (diff < tolerance) {
            //std::cout << "Convergence reached after " << iteration << " iterations." << std::endl;
            break;
        }
    }
}

#endif // PAGERANK_HPP