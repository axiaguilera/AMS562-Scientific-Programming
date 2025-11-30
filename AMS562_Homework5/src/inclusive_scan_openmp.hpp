// src/inclusive_scan_openmp.hpp

#ifndef INCLUSIVE_SCAN_OPENMP_HPP
#define INCLUSIVE_SCAN_OPENMP_HPP

#include <vector>
#include <omp.h>

/**
 * @brief Performs parallel inclusive scan using OpenMP tasks
 * @param input The input vector to scan
 * @param output The output vector to store results
 *
 * Implementation details:
 * 1. Uses OpenMP taskloop for dynamic task-based parallelism
 * 2. First performs local scans in parallel
 * 3. Then adjusts results using partial sums
 */
template <typename T>
void parallel_inclusive_scan_openmp(const std::vector<T>& input,
                                    std::vector<T>& output) {
  size_t n = input.size();
  if (n == 0) return;
  output.resize(n);

  unsigned int num_threads = omp_get_max_threads();
  size_t chunk_size =
      (n + num_threads - 1) / num_threads;  // Same chunk size calculation
  std::vector<T> partial_sums(num_threads, T(0));

// First phase: Local scans using taskloop
#pragma omp parallel
#pragma omp single nowait
  {
#pragma omp taskloop grainsize(chunk_size)
    for (unsigned int tid = 0; tid < num_threads; ++tid) {
      size_t start_idx = tid * chunk_size;
      size_t end_idx = std::min(start_idx + chunk_size, n);

      if (start_idx < n) {
        output[start_idx] = input[start_idx];
        for (size_t i = start_idx + 1; i < end_idx; ++i) {
          output[i] = output[i - 1] + input[i];
        }
        partial_sums[tid] = output[end_idx - 1];
      }
    }
#pragma omp taskwait

    // Accumulate partial sums in the single thread
    for (unsigned int i = 1; i < num_threads; ++i) {
      partial_sums[i] += partial_sums[i - 1];
    }

// Final phase: Adjust values using taskloop by reusing the same parallel region
#pragma omp taskloop grainsize(chunk_size)
    for (unsigned int tid = 1; tid < num_threads; ++tid) {
      size_t start_idx = tid * chunk_size;
      size_t end_idx = std::min(start_idx + chunk_size, n);
      T add_value = partial_sums[tid - 1];

      for (size_t i = start_idx; i < end_idx; ++i) {
        output[i] += add_value;
      }
    }
  }
#pragma omp taskwait
}

#endif  // INCLUSIVE_SCAN_OPENMP_HPP
