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

## Compilation Instructions

To compile the project, you need to have `g++` and `make` installed. Navigate to the project's root directory in your terminal and run the following command:

```sh
make