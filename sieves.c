#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define COLUMNS 6

void print_number(int n){
    printf("%10d", n);
}

void print_sieves(int n){
    char sieve[n + 1]; // Create array on the stack

    // Initiate all bits to 1 (true)
    for (int i = 0; i <= n; i++) {
        sieve[i] = 0xFF; // All indices are primes until proven otherwise
    }

    // Sieve of Eratosthenes
    for (int i = 2; i*i <= n; i++) {
        if (sieve[i]) { // Check if array[i] is prime
            for (int j = i*i; j <= n; j += i) {
                sieve[j] = 0; // Mark array[j] as non-prime
            }
        }
    }

    // Print primes
    int count = 0;
    for(int i = 2; i <= n; i++){
        if(sieve[i]){
            print_number(i);
            count++;
            if(count % COLUMNS == 0){
                printf("\n");
            }
        }
    }
    if (count % COLUMNS != 0){
        printf("\n");
    }
    
}

void benchmark_sieves(int n) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    print_sieves(n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to compute primes up to %d: %f seconds\n", n, cpu_time_used);
}

int main(int argc, char *argv[]){
    if(argc == 2){
        int limit = atoi(argv[1]);
        if (limit < 2) {
            printf("Please provide an integer greater than 1.\n");
        } else {
        benchmark_sieves(limit);
        }
    } else {
        printf("Please state an integer number.\n");
    }
  return 0;
}

// How did you represent the marking of 'prime' and 'not a prime' in the memory array?

// I used a char array where each index represents a number. The value at each index is 1 (true)
// if the number is prime and 0 (false) if it is not.

// What are the main steps in the algorithm? How have you implemented these steps?

// 1. Initialize a char array to represent the sieve
// 2. Set all entries to 1 (true) initially
// 3. Implement the Sieve of Eratosthenes algorithm 
// 4. Print all numbers that are still marked as prime

// What is the largest prime number that you can print within 2 seconds of computation?

// Using the stack-based implementation, it was not possible to compute primes up to 10 million
// due to stack size limitations. The maximum limit that could be handled was around 1 million
// which took approximately 0.7 seconds on my machine.
// Using the heap-based implementation allows for larger limits. It took about 2 seconds to calculate
// primes up to 28500000 

// What is the largest number you can print within 10 seconds?

// The time complexity is O(n log log n), so the largest prime number that can be printed
// within 10 seconds should be around 5 times that of 2 seconds, which is 150 million

// Is it the same for print-primes.c, sieves.c and sieves-heap.c?

// print-primes.c is significantly slower due to its O(n^2) complexity.
// Approximately 130000 primes can be printed in 2 seconds.
// sieves.c and sieves-heap.c both have a time complexity of O(n log log n),
// but sieves-heap.c can handle larger limits due to dynamic memory allocation on the heap