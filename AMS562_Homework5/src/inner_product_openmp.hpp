// src/inner_product_openmp.hpp

#ifndef INNER_PRODUCT_OPENMP_HPP
#define INNER_PRODUCT_OPENMP_HPP

#include <vector>
#include <omp.h>
#include <stdexcept>


// Function to compute the inner product using OpenMP
template <typename T>
T parallel_inner_product_openmp(const std::vector<T>& a,
                                const std::vector<T>& b) {
  if (a.size() != b.size()) {
    throw std::invalid_argument("Vectors must be of the same size");
  }

  T result = T(0);
  const size_t n = a.size();
  const unsigned int num_threads = omp_get_max_threads();
  size_t chunk_size = (n + num_threads - 1) / num_threads;  // Ceiling division

  if (n == 0) return result; // Handle empty vectors

  // Create a parallel region
  #pragma omp parallel
  {    
      // Create a single thread to manage tasks
      #pragma omp single
      {
        // Use taskgroup to ensure all tasks complete before proceeding
        #pragma omp taskgroup  
        {
            // Divide the work using taskloop  
            #pragma omp taskloop reduction(+ : result) grainsize(chunk_size)
            for (size_t i = 0; i < n; ++i) {
              result += a[i] * b[i];
            }
        } 
     }
      
  }

  return result;
}

#endif  // INNER_PRODUCT_OPENMP_HPP
