// tests/test_inner_product.cpp

// Overview:
// This file contains unit tests for verifying the correctness and performance
// of different implementations of the inner product function using Google Test framework.

#include <gtest/gtest.h>
#include <vector>
#include <numeric>
#include <chrono>
#include <iostream>

#include "inner_product_threads.hpp"
#include "inner_product_openmp.hpp"

// Helper function for timing measurements
// This function measures the average execution time of a given function over a specified number of runs.
template<typename Func>
double measure_time(Func&& func, int num_runs = 10) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num_runs; ++i) {
        func();
    }
    auto end = std::chrono::high_resolution_clock::now();
    double total_time = std::chrono::duration<double, std::milli>(end - start).count();
    return total_time / num_runs;
}

// Correctness Test for Threads
// This test verifies that the parallel_inner_product_threads function produces the correct result.
TEST(InnerProductTest, CorrectnessTest_Threads) {
    std::vector<double> a(1000, 1.0);
    std::vector<double> b(1000, 2.0);

    double expected = std::inner_product(a.begin(), a.end(), b.begin(), 0.0);
    double result_threads = parallel_inner_product_threads(a, b);

    EXPECT_DOUBLE_EQ(expected, result_threads);
}

// Correctness Test for OpenMP
// This test verifies that the parallel_inner_product_openmp function produces the correct result.
TEST(InnerProductTest, CorrectnessTest_OpenMP) {
    std::vector<double> a(1000, 1.0);
    std::vector<double> b(1000, 2.0);

    // TODO: Implement correctness test for parallel_inner_product_openmp
    double expected = std::inner_product(a.begin(), a.end(), b.begin(), 0.0);
    double result_openmp = parallel_inner_product_openmp(a, b);

    EXPECT_DOUBLE_EQ(expected, result_openmp);
}

// Large Vectors Test for Threads
// This test evaluates the performance of parallel_inner_product_threads with large vectors
// and ensures the result is correct.
TEST(InnerProductTest, LargeVectorsTest_Threads) {
    size_t n = 1000000;
    std::vector<double> a(n, 1.0);
    std::vector<double> b(n, 2.0);

    // Measure execution times
    double std_time = measure_time([&]() {
        std::inner_product(a.begin(), a.end(), b.begin(), 0.0);
    });
    double threads_time = measure_time([&]() {
        parallel_inner_product_threads(a, b);
    });

    // Verify results
    double expected = std::inner_product(a.begin(), a.end(), b.begin(), 0.0);
    double result_threads = parallel_inner_product_threads(a, b);
   
    EXPECT_DOUBLE_EQ(expected, result_threads);

    // Print timing results
    std::cout << "\nAverage execcution times (ms) over 10 runs:\n"
                << "Standard inner_product: " << std_time << " ms\n"
                << "Parallel threads: " << threads_time << " ms\n";  
}

// Large Vectors Test for OpenMP
// This test evaluates the performance of parallel_inner_product_openmp with large vectors
// and ensures the result is correct.
TEST(InnerProductTest, LargeVectorsTest_OpenMP) {
    size_t n = 1000000;
    std::vector<double> a(n, 1.0);
    std::vector<double> b(n, 2.0);
    
    // Measure execution times
    double std_time = measure_time([&]() {
        std::inner_product(a.begin(), a.end(), b.begin(), 0.0);
    });

    double openmp_time = measure_time([&]() {
        parallel_inner_product_openmp(a, b);
    });
    // Verify results
    double expected = std::inner_product(a.begin(), a.end(), b.begin(), 0.0);
    double result_openmp = parallel_inner_product_openmp(a, b);

    EXPECT_DOUBLE_EQ(expected, result_openmp);

    // Print timing results
    std::cout << "\nAverage execcution times (ms) over 10 runs:\n"
                << "Standard inner_product: " << std_time << " ms\n"
                << "Parallel OpenMP: " << openmp_time << " ms\n";
}
