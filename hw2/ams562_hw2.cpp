
#include <iostream>
#include "prime.h"

// Main program that loops over tasks until the user inputs '0' to exit
int main() {
    int choice;

    do {
        // Display menu options to the user
        std::cout << "Select an option (0 to exit):\n";
        std::cout << "1. Check if a number is divisible by another\n";
        std::cout << "2. Check if a number is prime\n";
        std::cout << "3. Print prime factorization of a number\n";
        std::cout << "4. Print first N prime numbers\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Handle the user's choice
        if (choice == 1) {
            int number, divisor;
            std::cout << "Enter a number: ";
            std::cin >> number;
            std::cout << "Enter a divisor: ";
            std::cin >> divisor;
            if (is_divisor(number, divisor)) {
                std::cout << divisor << " is a divisor of " << number << "\n";
            } else {
                std::cout << divisor << " is not a divisor of " << number << "\n";
            }
        } else if (choice == 2) {
            int number;
            std::cout << "Enter a number: ";
            std::cin >> number;
            if (is_prime(number)) {
                std::cout << number << " is prime\n";
            } else {
                std::cout << number << " is not prime\n";
            }
        } else if (choice == 3) {
            int number;
            std::cout << "Enter a number: ";
            std::cin >> number;
            std::cout << "Prime factors: ";
            print_prime_factors(number);
        } else if (choice == 4) {
            int n;
            std::cout << "How many primes to print? ";
            std::cin >> n;
            print_primes(n);
        } else if (choice != 0) {
            std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);  // Exit loop if choice is '0'

    std::cout << "Exiting...\n";
    return 0;
}
