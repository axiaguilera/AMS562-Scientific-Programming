#include <gtest/gtest.h>  // Include the Google Test framework
#include <vector>
#include <numeric>
#include <chrono>
#include <iostream>

#include "inclusive_scan_threads.hpp"
#include "inclusive_scan_openmp.hpp"

// Helper function that measures the average execution time of a function over
// multiple runs. Returns the average time in milliseconds.
template <typename Func>
double measure_time(Func&& func, int num_runs = 10) {
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < num_runs; ++i) {
    func();
  }
  auto end = std::chrono::high_resolution_clock::now();
  double total_time =
        std::chrono::duration<double, std::milli>(end - start).count();
  return total_time / num_runs;
}

// Test case: Verifies that the thread-based parallel implementation produces
// correct results by comparing with the standard library's inclusive_scan on a
// small vector
TEST(InclusiveScanTest, CorrectnessTestThreads) {
  std::vector<int> input(1000, 1);
  std::vector<int> expected(1000);
  std::inclusive_scan(input.begin(), input.end(), expected.begin());

  std::vector<int> output_threads(1000);  // Resized to match input

  parallel_inclusive_scan_threads(input, output_threads);

  EXPECT_EQ(expected, output_threads);
}

// Test case: Verifies that the OpenMP-based parallel implementation produces
// correct results by comparing with the standard library's inclusive_scan on a
// small vector
TEST(InclusiveScanTest, CorrectnessTestOpenMP) {
  std::vector<int> input(1000, 1);
  std::vector<int> expected(1000);
  std::inclusive_scan(input.begin(), input.end(), expected.begin());

  std::vector<int> output_openmp(1000);  // Resized to match input

  parallel_inclusive_scan_openmp(input, output_openmp);

  EXPECT_EQ(expected, output_openmp);
}

// Test case: Measures and compares performance between standard library and
// thread-based implementation using a large vector (1M elements). Also verifies
// correctness. Outputs timing results for comparison.
TEST(InclusiveScanTest, LargeVectorsTestThreads) {
  size_t n = 1000000;
  std::vector<int> input(n, 1);
  std::vector<int> expected(n);
  std::vector<int> output_threads(n);  // Resized to match input

  // Measure execution times
  double std_time = measure_time([&]() {
    std::inclusive_scan(input.begin(), input.end(), expected.begin());
  });

  double threads_time = measure_time(
      [&]() { parallel_inclusive_scan_threads(input, output_threads); });

  // Verify results
  std::inclusive_scan(input.begin(), input.end(), expected.begin());
  EXPECT_EQ(expected, output_threads);

  // Print timing results
  std::cout << "\nAverage execution times (ms) over 10 runs:\n"
            << "Standard inclusive_scan: " << std_time << "\n"
            << "Parallel threads: " << threads_time << "\n";
}

// Test case: Measures and compares performance between standard library and
// OpenMP-based implementation using a large vector (1M elements). Also verifies
// correctness. Outputs timing results for comparison.
TEST(InclusiveScanTest, LargeVectorsTestOpenMP) {
  size_t n = 1000000;
  std::vector<int> input(n, 1);
  std::vector<int> expected(n);
  std::vector<int> output_openmp(n);  // Resized to match input

  // Measure execution times
  double std_time = measure_time([&]() {
    std::inclusive_scan(input.begin(), input.end(), expected.begin());
  });

  double openmp_time = measure_time(
      [&]() { parallel_inclusive_scan_openmp(input, output_openmp); });

  // Verify results
  std::inclusive_scan(input.begin(), input.end(), expected.begin());
  EXPECT_EQ(expected, output_openmp);

  // Print timing results
  std::cout << "\nAverage execution times (ms) over 10 runs:\n"
            << "Standard inclusive_scan: " << std_time << "\n"
            << "OpenMP: " << openmp_time << "\n";
}
