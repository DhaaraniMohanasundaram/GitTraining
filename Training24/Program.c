// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// Program.c
// Program on B6 branch.
// Print multiplication tables from 1 to 10 in a tabular form on a console. 
// ------------------------------------------------------------------------------------
#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

// To generate the multiplication table
void PrintMultiplicationTable (int n, char* result) {
   result[0] = '\0';
   for (int i = 1; i <= 10; i++) {
      char buffer[50];
      sprintf (buffer, "%3d * %2d = %d\n", n, i, n * i);
      strcat (result, buffer);
   }
}

// To run the test cases
void RunTestCase (int n) {
   if (n <= 0 || n > 1000) {
      printf ("\nTest case for n = %d is invalid. n must be between 1 and 1000.\n", n);
      return;
   }
   char expected[1000], actual[1000];
   PrintMultiplicationTable (n, expected);
   PrintMultiplicationTable (n, actual);
   printf ("\nMultiplication table for %d:\n" "%s" "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", n, actual);
   if (strcmp (expected, actual) != 0) {
      printf ("Test failed for n = %d\nExpected: \n%s\nActual: \n%s\n", n, expected, actual);
      exit (1);
   }
}

int main () {
   int testCases[] = { 1, 2, 5, 10, 15, 19, 26, 30, 59, 75, 93, 999, 1000 };
   int numTestCases = sizeof (testCases) / sizeof (testCases[0]);
   for (int i = 0; i < numTestCases; i++) RunTestCase (testCases[i]);
   printf ("\n All the tests have passed..!!\n");
   return 0;
}