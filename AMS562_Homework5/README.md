# AMS 562 Homework #5: Multithreading with C++ Threads and OpenMP

## Project Overview

This project involves implementing parallel versions of the inner product and inclusive scan algorithms using both C++ threads/futures and OpenMP. The objectives are to:

- Gain practical experience with multithreading in C++.
- Understand and compare different parallel programming models.
- Use CMake and Google Test frameworks for building and testing C++ projects.
- Analyze and report on the performance of multithreaded applications.

## Directory Structure

```
project_root/
|– src/
    |– inner_product_threads.hpp
    |– inner_product_openmp.hpp
    |– inclusive_scan_threads.hpp
    |– inclusive_scan_openmp.hpp
|– tests/
    |– test_inner_product.cpp
    |– test_inclusive_scan.cpp
|– CMakeLists.txt
|– cmake/
    |- openmp_config.cmake
    |- gtest_config.cmake
|– README.md
```

## Prerequisites

- C++17 compatible compiler (e.g., GCC 7.0+, Clang 5.0+)
- CMake version 3.10 or higher
- **OpenMP support in your compiler**
- **Google Test installed on your system**

**Note:** You can perform this project either using the Docker image provided for the class or using a native UNIX environment such as macOS or WSL on Windows.

### Setup on macOS

1. **Install Homebrew** (if not already installed):

   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```

2. **Install Xcode Command Line Tools**:

   ```bash
   xcode-select --install
   ```

3. **Install libomp using Homebrew**:

   ```bash
   brew install libomp
   ```

### Setup on Windows with WSL

1. **Install WSL** and choose a Linux distribution like Ubuntu.

2. **Install necessary packages** inside WSL:

   ```bash
   sudo apt update
   sudo apt install build-essential cmake libomp-dev
   ```

## Build Instructions

### Steps

1. **Clone the Repository**

Note: Please update this part of your instruction:

```bash
   git clone https://github.com/yourusername/AMS562_Homework5.git
   cd AMS562_Homework5
```

2.	Create a Build Directory
```bash
    mkdir build
    cd build
```

3.	Configure the Project with CMake

To configure with the default debug level (0):
```
cmake ..
```

To set a specific debug level (e.g., 1):
```
cmake -DDEBUG_LEVEL=1 ..
```

To build in Release mode (recommended for performance testing):
```
cmake -DCMAKE_BUILD_TYPE=Release ..
```

4.	Build the Project
```
make
```

## Test Instructions

After building the project, you can run the tests using the following methods.

### Run All Tests Using CTest

Execute the following command inside the `build` directory:

```bash
make test
```

### Run Individual Tests

1.	Run Inner Product Tests
```bash
./test_inner_product
```

2.	Run Inclusive Scan Tests
```bash
./test_inclusive_scan
```

The tests use Google Test framework and will report the results of the test cases.

## Notes

- The `DEBUG_LEVEL` option in CMake allows you to set different levels of debugging information in your code. You can use it in your code with `#if DEBUG_LEVEL >= 1` preprocessor directives.

## Performance Measurement

To measure the performance of your implementations, you can use the `<chrono>` library to record the execution time of your functions. Here’s an example:

```c++
#include <chrono>

// Inside your test or main function
auto start = std::chrono::high_resolution_clock::now();

// Call your function
parallel_inclusive_scan_threads(input, output);

auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed = end - start;
std::cout << "Execution time: " << elapsed.count() << " seconds" << std::endl;
```

You can vary the size of the input and the number of threads to analyze the scalability and efficiency of your code.
