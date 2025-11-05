#include "Matrix.hpp"
#include "Vector.hpp"
#include "PageRank.hpp"
#include <iostream>
#include <vector>
#include <cassert>

void runUnitTests() {
    std::cout << "-------------- Running Unit Tests --------------" << std::endl;

    // Vector tests
    Vector<double> v1(3, 1.0);
    v1(1) = 2.0;
    assert(v1(0) == 1.0 && v1(1) == 2.0 && v1(2) == 1.0);
    assert(v1.getSize() == 3);

    Vector<double> v2(3, 2.0);
    Vector<double> v_sum = v1 + v2;
    assert(v_sum(0) == 3.0 && v_sum(1) == 4.0 && v_sum(2) == 3.0);

    Vector<double> v_scaled = 3.0 * v1;
    assert(v_scaled(0) == 3.0 && v_scaled(1) == 6.0 && v_scaled(2) == 3.0);
    
    assert(abs(v1.norm1() - 4.0) < 1e-9);
    std::cout << "Vector tests passed." << std::endl;

    // Matrix tests
    std::vector<std::vector<double>> adj_data = {{0, 0, 1}, {1, 0, 0}, {0, 1, 0}};
    Matrix<double> adj_matrix(adj_data);
    assert(adj_matrix(0, 2) == 1.0);

    adj_matrix.normalizeColumns();
    assert(abs(adj_matrix(0, 2) - 1.0) < 1e-9);
    assert(abs(adj_matrix(1, 0) - 1.0) < 1e-9);

    // Test dangling node normalization
    std::vector<std::vector<double>> dangling_data = {{1, 0}, {1, 0}};
    Matrix<double> matrix_dangle(dangling_data);
    matrix_dangle.normalizeColumns();
    assert(abs(matrix_dangle(0, 0) - 0.5) < 1e-9);
    assert(abs(matrix_dangle(0, 1) - 0.5) < 1e-9); // Dangling column should be 1/N
    assert(abs(matrix_dangle(1, 1) - 0.5) < 1e-9);
    
    std::cout << "Matrix tests passed." << std::endl;


    // Test PageRank function: when alpha = 1.0 (no teleportation) the ranks should converge to the  principal eigenvector of the transition
    // probability matrix 
    std::vector<std::vector<double>> adjacency_data = {
        {0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0}
    };
    Matrix<double> A(adjacency_data);
    A.normalizeColumns();
    Vector<double> rank_vec(6);
    pageRank(A, rank_vec, 1.0, 1e-6);
    double rank_sum = rank_vec.norm1();
    double expected_ranks[] = {0.230769,0.230769,0.230769,0.153846,0.1153846,0.038462};
    for (size_t i = 0; i < 6; ++i) {
        assert(abs(rank_vec(i) - expected_ranks[i]) < 1e-6);
    }
    assert(abs(rank_sum - 1.0) < 1e-6);
    std::cout << "PageRank test passed." << std::endl;
    std::cout << "------------------------------------------------" << std::endl << std::endl;
}


int main() {
    // Run unit tests first
    runUnitTests();

    // The number of pages
    const int N = 6;

    // Adjacency Matrix A (A_ij = 1 if j links to i)
    // Columns: A, B, C, D, E, F
    // Rows:    A, B, C, D, E, F
    std::vector<std::vector<double>> adjacency_data = {
        {0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0}
    };
    
    Matrix<double> A(adjacency_data);

    std::cout << "------------- PageRank Algorithm Test Case -------------" << std::endl;
    
    // Create the transition probability matrix M by normalizing A
    Matrix<double> M = A;
    M.normalizeColumns();

    // Create the rank vector
    Vector<double> rank_vec(N);

    // Alpha (damping factor)
    double alpha = 0.85; // No teleportation for this test case
    
    // Compute the PageRank
    pageRank(M, rank_vec, alpha);
    
    // Print the final PageRank vector
    std::cout << "Final PageRank Vector:" << std::endl;
    rank_vec.print();
    
    // Verification: Check if the rank vector sums to 1
    double rank_sum = rank_vec.norm1();
    std::cout << "\nSum of ranks: " << rank_sum << std::endl;
    assert(abs(rank_sum - 1.0) < 1e-6);
    std::cout << "Verification successful: Ranks sum to 1.\n" << std::endl;
    
    return 0;
}