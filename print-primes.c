/*
 print-primes.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6

void print_number(int n){
    printf("%10d", n);
}

int is_prime(int n){
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0; 
        }
    }
    return 1; 
}

void print_primes(int n){
    // Should print out all prime numbers less than 'n'
    // with the following formatting. Note that
    // the number of columns is stated in the define
    // COLUMNS
    int count = 0;
    for(int i = 2; i <= n; i++){
        if(is_prime(i)){
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

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
    if(argc == 2){
        int limit = atoi(argv[1]);
        if (limit < 2) {
            printf("Please provide an integer greater than 1.\n");
        } else {
        print_primes(limit);
        }
    } else {
        printf("Please state an integer number.\n");
    }
  return 0;
}

 
