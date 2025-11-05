# PageRank Template Library

## Project Overview
This project provides a lightweight, header-only C++ library for calculating the PageRank of nodes within a directed graph. The implementation leverages C++ templates to create generic and reusable Matrix and Vector classes, making the core logic type-agnostic and adaptable to various numeric precisions (e.g., float, double).

The primary objective is to offer a clean, efficient, and well-documented implementation of the PageRank algorithm, suitable for educational purposes and integration into larger systems requiring graph analysis.

## File Structure
- `Vector.hpp`: A templated `Vector<T>` class for representing and operating on mathematical vectors. It supports necessary operations for the PageRank algorithm (addition, scaling, dot product, 1-norm).
- `Matrix.hpp`: Templated `Matrix<T>` class for representing and manipulating square matrices. It includes essential functionalities such as element access and column normalization. 
- `PageRank.hpp`: Contains the core `pageRank<T>` templated function. This function iteratively computes the rank vector for a given transition matrix until the scores converge to a stable state.
- `main.cpp`: It includes a set of unit tests to validate the core library components. In addition, an example driver program that demonstrates a complete workflow: defining a graph, calculating its PageRank, and verifying the results.
- `examples/pagerank_example.cpp` – Standalone example referenced by Doxygen that mirrors the handout workflow.
- `README.md`: This file, providing an overview and instructions for the project.
- `Makefile`: Builds the main driver (`pagerank_calculator`).
- `Doxyfile`: Doxygen configuration used to regenerate documentation.

## Compilation Instructions
A C++17 compliant compiler (such as GCC or Clang) and the make utility are required to compile this project.

1. Ensure `g++` and `make` are installed on your system.
2. Navigate to the project's root directory using your terminal.
3. Build the driver with the provided Makefile:
   ```bash
   make
   ```
   This produces the executable `pagerank_calculator`.
4. If you need to remove all compiled files, use:
   ```bash
   make clean
   ```

## Usage Instructions
- **Run unit tests and PageRank demo**  
  The driver executes a small test suite before running the 6-node PageRank example.
  ```bash
  ./pagerank_calculator
  ```
  The program prints the rank vector, verifies it sums to 1, and reports convergence information.

- **Run the documented example**  
  The example in `examples/` can be built independently if you want an isolated demonstration:
  ```bash
  g++ -std=c++17 -Wall -I. examples/pagerank_example.cpp -o pagerank_example
  ./pagerank_example
  ```

## Doxygen Documentation

This project uses Doxygen-style comments in all header files to provide detailed documentation of classes, member functions, and exception behavior.
To generate the documentation:
1. Make sure Doxygen and graphviz is installed.
- On macOS: brew install doxygen, brew install graphviz
- On Linux: sudo apt install doxygen, sudo apt install graphviz
2. From the project root, run:

```bash
doxygen -g Doxyfile
doxygen Doxyfile
```

3. Open the generated HTML documentation:

```bash
open docs/html/index.html
```

This will display a navigable interface containing the API reference for all classes and methods.

## Author and Course Information
- Course: AMS 562 — Scientific Programming in C++
- Assignment: Homework 4 — C++ Template Programming
- Author: Axi Fabricio Aguilera
- Institution: Stony Brook University, Department of Applied Mathematics and Statistics
- Date: November 2025