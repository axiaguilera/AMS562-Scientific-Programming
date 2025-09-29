cat > README.md <<'EOF'
# HW2: Prime Numbers

This assignment implements a C++ program for working with prime numbers.  
It provides a text-based menu where the user can:

1. Check if one number is a divisor of another
2. Check if a number is prime
3. Print the prime factorization of a number
4. Print the first *N* prime numbers

---

## 📂 Files

- `ams562_hw2.cpp` — main program with menu and user interaction  
- `prime.cpp` — implementation of prime number functions  
- `prime.h` — header file with function declarations  
- `Makefile` — build instructions  
- `test_input.txt` — sample input for automated testing  
- `reference_test_output.txt` — reference output to compare against  

---

## ⚙️ Build Instructions

Using the provided `Makefile`:
```bash
make

This creates an executable named ams562_hw2.

Manual compile (alternative):
clang++ -std=c++17 ams562_hw2.cpp prime.cpp -o ams562_hw2

---

## ▶️ Run Instructions
Interactive run:
./ams562_hw2
You should see a menu like:
Prime Numbers Menu
0. Exit
1. Check if one number is a divisor of another
2. Check if a number is prime
3. Print prime factorization of a number
4. Print first N prime numbers

---

## 🧪 Testing
Batch run with prepared input and compare to the reference:

./ams562_hw2 < test_input.txt > test_output.txt 
diff -u test_output.txt reference_test_output.txt

There is another .txt for test purpose named extra_test_input.txt, you can tested in the same way 

If diff shows no output, your result matches exactly.
Any differences will be listed line-by-line.

---

## 📌 Notes & Conventions
Numbers ≤ 1 are not prime.
For factorization of numbers ≤ 1, the program prints just a newline (no text).
Divisor check avoids division by zero.
Generated artifacts like ams562_hw2 and test_output.txt should be ignored by Git (use a .gitignore).
