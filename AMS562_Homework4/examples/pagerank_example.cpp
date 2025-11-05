#include "Matrix.hpp"
#include "Vector.hpp"
#include "PageRank.hpp"
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

/**
 * @file pagerank_example.cpp
 * @brief A demonstration and usage example for the PageRank C++ template library.
 *
 * @example pagerank_example.cpp
 * This example illustrates how to use the PageRank library to compute the
 * importance scores for nodes in a directed graph.
 *
 * The demonstration covers the following core workflow:
 * - Representing a directed graph with an adjacency matrix.
 * - Creating a valid transition probability matrix by normalizing the columns.
 * - Invoking the templated `pageRank` function to compute the rank vector.
 * - Displaying the final PageRank scores.
 * - Verifying the correctness of the result.
 */

/// Runs a lightweight validation suite before executing the main example.
void runUnitTests();

/**
 * @brief Entry point for the example program.
 * Initializes the example graph, runs PageRank, and verifies the output.
 */
int main() {
    runUnitTests();

    std::cout << "--- PageRank Library Demonstration ---" << std::endl;

    // Step 1: Define the Graph Structure with an Adjacency Matrix.
    // The convention used here is that A_ij = 1 if a link exists from page j to page i.
    // Columns represent the source node, and rows represent the destination node.
    const std::vector<std::vector<double>> adjacency_data = {
        {0, 0, 1, 0, 0, 0}, // Page A links to pages B and C
        {1, 0, 0, 1, 1, 0}, // Page B links to pages C and D.
        {1, 1, 0, 0, 0, 0}, // Page C links to page A.
        {0, 1, 0, 0, 1, 0}, // Page D links to pages B and E.
        {0, 0, 0, 1, 0, 1}, // Page E links to pages B, D, and F.
        {0, 0, 0, 0, 1, 0}  // Page F links to page E.
    };
    Matrix<double> A(adjacency_data);

    // Step 2: Create the Transition Probability Matrix M.
    // The PageRank algorithm requires a column-stochastic matrix where each column
    // sums to 1. This is achieved by normalizing the adjacency matrix.
    Matrix<double> M = A;
    M.normalizeColumns();

    // Step 3: Compute the PageRank Scores.
    // A Vector is initialized to store the results. The `pageRank` function
    // will populate this vector with the computed scores.
    Vector<double> ranks(A.getSize());
    pageRank(M, ranks);

    // Step 4: Display the Final Results.
    std::cout << "\nComputed PageRank Scores:" << std::endl;
    ranks.print();

    // Step 5: Verify the Result.
    // A valid PageRank vector is a probability distribution, meaning the sum of
    // all scores must equal 1. This check confirms the algorithm's correctness.
    double rank_sum = 0.0;
    for (size_t i = 0; i < ranks.getSize(); ++i) {
        rank_sum += ranks(i);
    }
    std::cout << "\nVerification Check:" << std::endl;
    std::cout << "Sum of all rank scores: " << rank_sum << std::endl;
    
    // An assertion provides a programmatic check that the sum is within a small tolerance of 1.
    assert(std::abs(rank_sum - 1.0) < 1e-6);
    std::cout << "Verification successful: Ranks form a valid probability distribution." << std::endl;

    return 0;
}

/**
 * @brief Executes basic checks on Vector and Matrix utilities used in the example.
 */
void runUnitTests() {
    Vector<double> v1(3, 1.0);
    v1(1) = 2.0;
    assert(v1(0) == 1.0 && v1(1) == 2.0 && v1(2) == 1.0);

    Matrix<double> dangling({{1, 0}, {1, 0}});
    dangling.normalizeColumns();
    assert(std::abs(dangling(0, 0) - 0.5) < 1e-9);
    assert(std::abs(dangling(0, 1) - 0.5) < 1e-9);
    assert(std::abs(dangling(1, 1) - 0.5) < 1e-9);
}
