// src/inclusive_scan_threads.hpp
#ifndef INCLUSIVE_SCAN_THREADS_HPP
#define INCLUSIVE_SCAN_THREADS_HPP

#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <algorithm>

/**
 * @brief This header file implements a parallel inclusive scan (prefix sum)
 * algorithm using C++ threads and futures. An inclusive scan computes the
 * running sum of elements where each output element includes its corresponding
 * input element.
 */

/**
 * @brief Helper function that performs inclusive scan on a portion of the input
 * vector
 * @param input The input vector to scan
 * @param output The output vector to store results
 * @param start_idx Starting index of the chunk to process
 * @param end_idx Ending index (exclusive) of the chunk to process
 */
template <typename T>
void partial_inclusive_scan(const std::vector<T>& input, std::vector<T>& output,
                            size_t start_idx, size_t end_idx) {
  std::partial_sum(input.begin() + start_idx, input.begin() + end_idx,
                   output.begin() + start_idx, std::plus<T>());
}

/**
 * @brief Performs parallel inclusive scan using C++ threads and futures
 * @param input The input vector to scan
 * @param output The output vector to store results
 * @param num_threads Number of threads to use (defaults to hardware
 * concurrency)
 *
 * Implementation details:
 * 1. Divides the input into chunks and processes each chunk in parallel
 * 2. Performs local inclusive scan on each chunk
 * 3. Adjusts results by adding the sum from previous chunks
 */
template <typename T>
void parallel_inclusive_scan_threads(
    const std::vector<T>& input, std::vector<T>& output,
    unsigned int num_threads = std::thread::hardware_concurrency()) {
  // TODO: Implement parallel inclusive scan using C++ threads and futures
  size_t n = input.size();
  if (n == 0) return;

  // Resize output vector to match input size
  output.resize(n);
  
  // Ensure num_threads is at least 1 and does not exceed input size
  if (num_threads == 0) num_threads = 1;  
  if (num_threads > n) num_threads = n;  

  // Step 1: Calculate chunk size with better load balancing
  size_t chunk_size = (n + num_threads - 1) / num_threads;  // Ceiling division
  
  std::vector<std::future<void>> futures;
  std::vector<T> partial_sums(num_threads);

  // Step 2: Create threads and futures to process each chunk by calling
  // partial_inclusive_scan
  for (unsigned int i = 0; i < num_threads; ++i) {
    size_t start_idx = i * chunk_size;
    size_t end_idx = (i == num_threads - 1) ? n : start_idx + chunk_size;

    futures.emplace_back(std::async(std::launch::async, [&, start_idx, end_idx, i]() {
                                      partial_inclusive_scan(input, output,
                                                             start_idx, end_idx);
                                      if (start_idx < end_idx ) {
                                        partial_sums[i] = output[end_idx - 1];
                                      }
                                    }));
  }

  // Step 3: Wait for all partial scans to complete
  for (auto& f : futures) {
    f.get();
  }
  futures.clear();
  
  // Compute the total sums for each chunk
  for (unsigned int i = 1; i < num_threads; ++i) {
    partial_sums[i] += partial_sums[i - 1];
  }

  // Step 4: Adjust the results to account for the sums from previous chunks
  for (unsigned int i = 1; i < num_threads; ++i) {
    size_t start_idx = i * chunk_size;
    size_t end_idx = (i == num_threads - 1) ? n : start_idx + chunk_size;
    
    // Value to add to each element in the current chunk
    T add_value = partial_sums[i - 1];

    futures.emplace_back(std::async(std::launch::async, [&, start_idx, end_idx, add_value]() {                                 
                                      for (size_t j = start_idx; j < end_idx; ++j) {
                                        output[j] += add_value;
                                      }
                                    }));
  }
  // Wait for all adjustment operations to complete
  for (auto& f : futures) {
    f.get();
  }
}

#endif  // INCLUSIVE_SCAN_THREADS_HPP
