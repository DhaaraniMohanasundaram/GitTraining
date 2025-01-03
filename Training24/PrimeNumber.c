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
   for (int i = 2; i * i <= num; i++) if (num % i == 0) return NOT_PRIME;
   return PRIME;
}

void RunTestCases () {
   int failedTestCount = 0;
   for (int i = 0; i < 10; i++) {
      int num = rand () % 1000 + 1, expected;   // Random number in 1 -1000
      if (num <= 1) expected = NOT_PRIME;
      else if (num == 2) expected = PRIME;
      else {
         expected = PRIME;
         for (int j = 2; j * j <= num; j++) {
            if (num % j == 0) {
               expected = NOT_PRIME;
               break;
            }
         }
         printf ("Test %d: %d %s number.\n\n", i + 1, num, IsPrime (num) == 1 ? "Prime" : "Not Prime");
         if (IsPrime (num) != expected) {
            failedTestCount++;
            printf ("Test %d failed: Number %d -> Expected %s, but got %s\n", i + 1, num, expected
               ? "Prime" : "Not Prime", IsPrime (num) ? "Prime" : "Not Prime");
         }
      }
   }
   if (failedTestCount == 0) printf (GREEN"All the tests passed.\n"RESET);
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
         printf ("Exiting...\n");
         break;
      }
      char* endptr;
      num = strtol (input, &endptr, 10);
      if (*endptr != '\0' || num <= 0) printf (RED"Invalid input. Please enter a positive number or 'E/e' to exit.\n"RESET);
      else printf ("%d is %s number.\n", num, IsPrime (num) == PRIME ? "Prime" : "Not Prime");
   }
}