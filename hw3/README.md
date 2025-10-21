# C++ Scientific Computing Classes

## Project Overview

This project is a suite of C++ classes that model fundamental scientific entities: `Point`, `Line`, `Rectangle`, and `Square`. These classes are designed with Object-Oriented Programming (OOP) principles and can be utilized in various scientific computing applications, such as simulations and data analysis. The project also includes a comprehensive set of unit tests to ensure code reliability and correctness.

## File Structure

The project is organized into the following directory structure:

- `include/`: Contains all the header files (`.h`) for the classes.
  - `Point.h`: Declaration of the `Point` class.
  - `Line.h`: Declaration of the `Line` class.
  - `Rectangle.h`: Declaration of the `Rectangle` class.
  - `Square.h`: Declaration of the `Square` class.
- `src/`: Contains all the implementation files (`.cpp`) for the classes.
  - `Point.cpp`: Implementation of the `Point` class.
  - `Line.cpp`: Implementation of the `Line` class.
  - `Rectangle.cpp`: Implementation of the `Rectangle` class.
  - `Square.cpp`: Implementation of the `Square` class.
- `tests/`: Contains the unit tests.
  - `tests.cpp`: Unit tests for all classes.
- `Makefile`: For compiling the project using `g++`.
- `README.md`: This documentation file.

---

## Compilation Instructions

This project is built using **GNU Make** and **g++**.

1.  Ensure `g++` and `make` are installed on your system.
2.  Navigate to the root directory of the project.
3.  Run the following command to compile all files:

```bash
make
```

This command compiles all source files and generates an executable named: `hw3_tests`.

If you need to remove all compiled files, use:

```bash
make clean
```

Once the project has been successfully compiled, run the following command to execute all unit tests:

```bash
./hw3_tests
```

Each test case prints a confirmation message indicating whether it PASSED or raised an exception correctly.


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
- Assignment: Homework 3 — OOP in C++
- Author: Axi Fabricio Aguilera
- Institution: Stony Brook University, Department of Applied Mathematics and Statistics
- Date: October 2025