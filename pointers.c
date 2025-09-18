/*
 pointers.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>

char* text1 = "This is a string.";
char* text2 = "Yet another thing.";
int counter = 0;

int list1[20];
int list2[20]; 

void copycodes(const char* text, int* list, int* count) {
  while (*text != '\0') {
    *list++ = *text++;
    (*count)++;
  }
}

void work() {
  copycodes(text1, list1, counter);
  copycodes(text2, list2, counter);
}

void printlist(const int* lst){
  printf("ASCII codes and corresponding characters.\n");
  while(*lst != 0){
    printf("0x%03X '%c' ", *lst, (char)*lst);
    lst++;
  }
  printf("\n");
}

void endian_proof(const char* c){
  printf("\nEndian experiment: 0x%02x,0x%02x,0x%02x,0x%02x\n", 
         (int)*c,(int)*(c+1), (int)*(c+2), (int)*(c+3));
  
}

int main(void){
 
    work();
    printf("\nlist1: ");
    printlist(list1);
    printf("\nlist2: ");
    printlist(list2);
    printf("\nCount = %d\n", counter);

    endian_proof((char*) &counter);
}

// Explain how you get the pointer adresses to the two char arrays (text1 and text2)
// and the counter variable (count) in work()

// text1, text2 and counter are global variables and can be accessed inside any function in the file

// What does it mean to increment a pointer? What is the difference between incrementing a pointer to a 
// ASCII text string and incrementing a pointer to an integer array? How is the ASM code different to C?

// Incrementing a pointer means moving the pointer to the next memory location based on the data type it points to
// For a char pointer, incrementing it moves to the next byte (1 byte)
// For an int pointer, incrementing it moves to the next integer (typically 4 bytes on most systems)
// In ASM, the increment operation will differ based on the size of the data type and will use different instructions

// What is the difference between incrementing a pointer and incrementing a variable that a pointer points to?
// Explain how your code increments the variable "count"

// In line 22, in order to increment the variable "count" we dereference the pointer and then increment

// Explain a statement in your code where you are dereferencing a pointer. What does this mean?
// Compare it to the ASM code

// As stated before, we dereference the pointer in line 22 to modify the value it points to. 
// This means we are not modifying the memory adress the pointer holds, but the value at that adress
// In ASM this is done by loading, modifying and then storing the value back

// Is your computer using big-endian or little-endian representation? How did you come to your conclusion?
// Is there any benefit of using one representation over the other?

// My computer is using little-endian representation, since the least significant byte is stored first