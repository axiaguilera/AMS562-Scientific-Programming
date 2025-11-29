#ifndef INNER_PRODUCT_THREADS_HPP
#define INNER_PRODUCT_THREADS_HPP

#include <vector>
#include <thread>
#include <future>
#include <numeric>

// Function to compute the inner product of two vectors in parallel using C++
// threads Parameters:
//   a, b: input vectors
//   num_threads: number of threads to use (defaults to hardware concurrency)
// Returns: inner product of vectors a and b
template <typename T>
T parallel_inner_product_threads(
    const std::vector<T>& a, const std::vector<T>& b,
    unsigned int num_threads = std::thread::hardware_concurrency()) {
  // Verify input vectors have same size
  if (a.size() != b.size()) {
    throw std::invalid_argument("Vectors must be of the same size");
  }

  // Calculate work distribution using ceiling division for better load
  // balancing
  size_t n = a.size();
  size_t chunk_size = (n + num_threads - 1) / num_threads;  // Ceiling division
  std::vector<std::future<T>> futures;  // Container to store future results

  // Launch threads to compute partial inner products
  for (unsigned int i = 0; i < num_threads; ++i) {
    // Calculate start and end indices for this thread
    size_t start_idx = i * chunk_size;
    // For last thread, process remaining elements
    size_t end_idx = (i == num_threads - 1) ? n : start_idx + chunk_size;

    // Launch async task for this chunk
    // Each task computes inner product for its assigned portion
    futures.emplace_back(
        std::async(std::launch::async, [&, start_idx, end_idx]() -> T {
          return std::inner_product(
              a.begin() + start_idx,  // Start of first vector chunk
              a.begin() + end_idx,    // End of first vector chunk
              b.begin() + start_idx,  // Start of second vector chunk
              T(0)                    // Initial sum value
          );
        }));
  }

  // Combine results from all threads
  T result = T(0);
  for (auto& f : futures) {
    result += f.get();  // Wait for and add each thread's result
  }

  return result;
}

#endif  // INNER_PRODUCT_THREADS_HPP
