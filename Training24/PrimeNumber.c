// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// PrimeNumber.c
// Program on B4 branch.
// Program that takes a number as input and displays whether it is a prime number.
// ------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define PRIME 1
#define NOT_PRIME 0
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"

/// <summary>To check if a number is prime.</summary>
int IsPrime (int num);

/// <summary>To generate a random prime number between lower and upper limits.</summary>
int GenerateRandomPrime (int lower, int upper);

/// <summary>To run a few test cases with PrimeChecker using random numbers.</summary>
void RunTestCases ();

/// <summary>To check for prime with user input.</summary>
void CheckPrimeForUserInput ();

int main () {
   RunTestCases ();
   CheckPrimeForUserInput ();
   return 0;
}

int IsPrime (int num) {
   if (num <= 1) return NOT_PRIME;
   if (num == 2) return PRIME;
   if (num % 2 == 0) return NOT_PRIME;
   for (int i = 3; i * i <= num; i += 2) if (num % i == 0) return NOT_PRIME;   // Check divisibility by odd numbers from 3
   return PRIME;
}

int GenerateRandomPrime (int lower, int upper) {
   int num;
   if (lower % 2 == 0) lower++;   // If its even
   do {
      num = rand () % (upper - lower + 1) + lower;
      if (num % 2 == 0) num++;
   } while (IsPrime (num) != PRIME);
   return num;
}

void RunTestCases () {
   for (int i = 0; i < 20; i++) {
      int num = GenerateRandomPrime (1, 1000),   // Random number in 0 -1000
      expected = IsPrime (num);
      printf ("\nTest case %d:  %d is %s number\n", i + 1, num, expected == PRIME ? "a Prime" : "Not a Prime");
      if (IsPrime (num) != expected) {
         printf ("Test case %d failed: For Number %d -> Expected %s, but got %s\n", i + 1, num,
            expected == PRIME ? "Prime" : "Not Prime", IsPrime (num) == PRIME ? "Prime" : "Not Prime");
         return;
      }
   }
   printf (GREEN"\nAll the test cases passed.\n"RESET);
}

void CheckPrimeForUserInput () {
   char input[100];
   int num;
   printf ("\n     ~~~~~~~ PRIME CHECKER ~~~~~~~~\n");
   while (true) {
      printf ("\nEnter a positive number or (E/e to exit): ");
      fgets (input, sizeof (input), stdin);
      input[strcspn (input, "\n")] = 0;
      if (input[0] == 'E' || input[0] == 'e') {
         printf ("Exiting...!\n");
         break;
      }
      char* endptr;
      num = strtol (input, &endptr, 10);
      if (*endptr != '\0' || num <= 0) printf (RED"Invalid input. Please enter a positive number or 'E/e' to exit.\n"RESET);
      else printf ("%d is %s number.\n", num, IsPrime (num) == PRIME ? "Prime" : "Not Prime");
   }
}