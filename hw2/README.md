# HW2: Prime Numbers

This assignment implements a C++ program for working with prime numbers.  
It provides a text-based menu where the user can:
1. Check if one number is a divisor of another
2. Check if a number is prime
3. Print the prime factorization of a number
4. Print the first *N* prime numbers

---

## 📋 Prerequisites

- C++17 compatible compiler (clang++ or g++)
- Make (for building with Makefile)

---

## 📂 Files

- `ams562_hw2.cpp` — main program with menu and user interaction  
- `prime.cpp` — implementation of prime number functions  
- `prime.h` — header file with function declarations  
- `Makefile` — build instructions  
- `test_input.txt` — sample input for automated testing  
- `reference_test_output.txt` — reference output to compare against  
- `extra_test_input.txt` — additional test input file

---

## ⚙️ Build Instructions

### Using the provided `Makefile`:

```bash
make
```

This creates an executable named `ams562_hw2`.

### Manual compile (alternative):

```bash
clang++ -std=c++17 ams562_hw2.cpp prime.cpp -o ams562_hw2
```

---

## ▶️ Run Instructions

### Interactive run:

```bash
./ams562_hw2
```

You should see a menu like:

```
Prime Numbers Menu
0. Exit
1. Check if one number is a divisor of another
2. Check if a number is prime
3. Print prime factorization of a number
4. Print first N prime numbers
```

### Example usage:

```bash
$ ./ams562_hw2
Prime Numbers Menu
0. Exit
1. Check if one number is a divisor of another
2. Check if a number is prime
3. Print prime factorization of a number
4. Print first N prime numbers
Enter your choice: 2
Enter a number: 17
17 is prime
```

---

## 🧪 Testing

### Batch run with prepared input:

```bash
./ams562_hw2 < test_input.txt > test_output.txt 
diff -u test_output.txt reference_test_output.txt
```

If `diff` shows no output, your result matches exactly.  
If there are differences, they will be listed line-by-line.

### Additional testing:

There is another `.txt` file for test purposes named `extra_test_input.txt`. You can test it the same way:

```bash
./ams562_hw2 < extra_test_input.txt > extra_test_output.txt
```

---

## 🧹 Cleanup

To remove compiled files:

```bash
make clean
```

---

## 📌 Notes & Conventions

- Numbers ≤ 1 are not prime.
- For factorization of numbers ≤ 1, the program prints just a newline (no text).
- Divisor check avoids division by zero.
- Generated artifacts like `ams562_hw2` and `test_output.txt` should be ignored by Git (use a `.gitignore`).

---

## 📚 Function Overview

### `is_divisor(int number, int divisor)`
Checks if `divisor` divides `number` evenly (with no remainder).

### `is_prime(int number)`
Determines if a number is prime using an optimized algorithm that checks divisors up to √number.

### `print_prime_factors(int number)`
Prints the prime factorization of a number (e.g., 12 → 2, 2, 3).

### `print_first_n_primes(int n)`
Prints the first N prime numbers (e.g., N=5 → 2, 3, 5, 7, 11).

---

## 🐛 Troubleshooting

**Compilation errors:**
- Ensure you have a C++17 compatible compiler installed
- Check that all three files (`ams562_hw2.cpp`, `prime.cpp`, `prime.h`) are in the same directory

**Runtime errors:**
- Make sure the executable has proper permissions: `chmod +x ams562_hw2`

**Test failures:**
- Verify your input file format matches the expected format
- Check for extra whitespace or newlines in your output

---

## 📄 License

This is an academic assignment for AMS 562.
