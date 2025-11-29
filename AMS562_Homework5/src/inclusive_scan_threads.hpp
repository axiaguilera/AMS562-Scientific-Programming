#ifndef INCLUSIVE_SCAN_THREADS_HPP
#define INCLUSIVE_SCAN_THREADS_HPP

#include <vector>
#include <thread>
#include <future>
#include <numeric>

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

  // Step 1: Calculate chunk size with better load balancing

  // Step 2: Create threads and futures to process each chunk by calling
  // partial_inclusive_scan

  // Step 3: Wait for all partial scans to complete

  // Step 4: Adjust the results to account for the sums from previous chunks
}

#endif  // INCLUSIVE_SCAN_THREADS_HPP
