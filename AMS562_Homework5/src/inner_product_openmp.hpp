#ifndef INNER_PRODUCT_OPENMP_HPP
#define INNER_PRODUCT_OPENMP_HPP

#include <vector>
#include <omp.h>

// Function to compute the inner product using OpenMP
template <typename T>
T parallel_inner_product_openmp(const std::vector<T>& a,
                                const std::vector<T>& b) {
  if (a.size() != b.size()) {
    throw std::invalid_argument("Vectors must be of the same size");
  }

  T result = T(0);
  size_t n = a.size();
  unsigned int num_threads = omp_get_max_threads();
  size_t chunk_size = (n + num_threads - 1) / num_threads;  // Ceiling division

  // TODO: Use OpenMP parallel, single, taskloop, and taskgroup (or taskwait) directives
  // to implement the parallel inner product

  return result;
}

#endif  // INNER_PRODUCT_OPENMP_HPP
