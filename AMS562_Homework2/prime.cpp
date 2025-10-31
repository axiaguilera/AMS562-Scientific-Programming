
#include <iostream>
#include <cmath>
#include "prime.h"

// Check if divisor divides number exactly
bool is_divisor(int number, int divisor) {
    // Boundary case: Division by zero is not defined
    if(divisor == 0) return false; 

    // Check if residual is zero and return boolean value
    return number % divisor == 0;
}

// Check if a number is prime by testing divisibility up to sqrt(number)
bool is_prime(int number) {    
    // Boundary cases
    if(number <= 1) return false;
    if(number == 2) return true;    
    if(number % 2 == 0) return false;
    
    // Check for odd factors from 3 to sqrt(number)
    bool flag = true;
    for(int i=3; i<=sqrt(number); i+=2){
        if(is_divisor(number, i)){
            return false;
        }
    }

    return flag;
}

// Print prime factors of a number directly
void print_prime_factors(int number) {
    //Boundary case
    if (number <= 1) { 
        std::cout << '\n'; 
        return; 
    }

    // Check if number is prime (prime factor is the number itself)
    if(is_prime(number)){
        std::cout << number << std::endl;
        return;
    }
    
    int temp = number;
    int temp_half = ceil(temp / 2);
    int factor = 2;
    
    // Check for prime factors from 2 to temp/2
    while(temp > 1 && factor <= temp_half){
        // If factor is a divisor and prime, print it and reduce temp
        if(is_divisor(temp, factor) && is_prime(factor)){
            std::cout << factor << " ";
            temp = temp / factor;
            bool flag = true;
            // Check for multiple occurrences of the same prime factor
            while(temp % factor == 0){
                if(flag) std::cout << factor << " ";
                else flag = false;
                temp = temp / factor;
            }
            temp_half = floor(temp / 2);
            factor++;
        } else {
            factor++;
        }
    }

    if(temp > 1){
        std::cout << temp; // Print the remaining prime factor
    }

    std::cout << std::endl;

}

// Print the first n prime numbers
void print_primes(int n) {    
    // Boundary case
    if (n <= 0) {
        std::cout << "\n";
        return;
    }
     
    // Print 2 as the first prime number
    std::cout << 2 << "\n"; 
    int count = 1;
    
    // Check only odd numbers starting from 3
    int candidate = 3;
    while(count < n){
        if(is_prime(candidate)){
            std::cout << candidate << "\n";
            ++count;
        }
        candidate+= 2; 
    
    }
}
