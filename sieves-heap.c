#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define COLUMNS 6

void print_number(int n){
    printf("%10d", n);
}

void print_sieves(int n){
    char *sieve = malloc(n + 1); // Allocate memory on heap

    // Initiate all bits to 1 (true)
    for (int i = 0; i <= n; i++) {
        sieve[i] = 1;
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
    

    free(sieve);
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