#include <stdlib.h>
#include <stdio.h>

#define COLUMNS 6

void print_number(int n){
    printf("%10d", n);
}

void print_sieves(int n){
    char *sieve = malloc(n + 1); // Allocate memory

    // Initiate all bits to 1 (true)
    for (int i = 0; i <= n; i++) {
        sieve[i] = 0xFF;
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

int main(int argc, char *argv[]){
    if(argc == 2){
        int limit = atoi(argv[1]);
        if (limit < 2) {
            printf("Please provide an integer greater than 1.\n");
        } else {
        print_sieves(limit);
        }
    } else {
        printf("Please state an integer number.\n");
    }
  return 0;
}