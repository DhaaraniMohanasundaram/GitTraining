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
#include <stdlib.h>

#define PRIME 1
#define NOT_PRIME 0

/// <summary>To check if a number is prime.</summary>
int PrimeChecker (int num);

/// <summary>To run few test cases with PrimeChecker.</summary>
void TestCases ();

/// <summary>To check PrimeChecker with user input.</summary>
void CheckPrimeForUserInput ();

int main () {
   TestCases ();
   CheckPrimeForUserInput ();
   return 0;
}

int PrimeChecker (int num) {
   if (num <= 1) return NOT_PRIME;
   if (num == 2) return PRIME;
   for (int i = 2; i <= num / 2; i++) {
      if (num % i == 0) return NOT_PRIME;
   }
   return PRIME;
}

void TestCases () {
   int testNumbers[] = { 113, 15, 2, 1, 29 },
   expectedResults[] = { PRIME, NOT_PRIME, PRIME, NOT_PRIME, PRIME },
   numTests = sizeof (testNumbers) / sizeof (testNumbers[0]), failedCount = 0;
   for (int i = 0; i < numTests; i++) {
      int num = testNumbers[i], result = PrimeChecker (num);
      printf ("Test %d\nNumber: %d\n%s number.\n\n", i + 1, num, result == PRIME ? "Prime" : "Not Prime");
      if (result != expectedResults[i]) {
         failedCount++;
         printf ("Test %d failed: Expected %s, but got %s\n\n", i + 1,
            expectedResults[i] == PRIME ? "Prime" : "Not Prime",
            result == PRIME ? "Prime" : "Not Prime");
      }
   }
   printf (failedCount > 0 ? "Test(s) failed: %d\n" : "All the tests has passed.\n", failedCount);
}

void CheckPrimeForUserInput () {
   char input[100];
   int num;
   printf ("\n\n     ~~~~~~~ PRIME CHECKER ~~~~~~~~\n");
   while (true) {
      printf ("\nEnter a positive number or (E or e to exit): ");
      fgets (input, sizeof (input), stdin);
      input[strcspn (input, "\n")] = 0;
      if (input[0] == 'E' || input[0] == 'e') {
         printf ("Exiting program...\n");
         break;
      }
      char* endptr;
      num = strtol (input, &endptr, 10);
      if (*endptr != '\0' || endptr == input || num <= 0) printf ("Invalid input. Please enter a positive number or 'E' to exit.\n");
      else {
         int result = PrimeChecker (num);
         printf ("%d is %s number.\n\n", num, result == PRIME ? "Prime" : "Not Prime");
      }
   }
}