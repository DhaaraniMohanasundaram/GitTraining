// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// Program.c
// Program on B2 branch.
// Write a program to display the Fibonacci series for given input.
// ------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GenerateFibonacciSeries (int n, char* result) {
   int a = 0, b = 1, next, index = 0;
   if (n >= 1) index += sprintf (result + index, "%d", a);
   if (n >= 2) index += sprintf (result + index, ", %d", b);
   for (int i = 3; i <= n; i++) {
      next = a + b;
      index += sprintf (result + index, ", %d", next);
      a = b;
      b = next;
   }
}

void RunTestCase (int n) {
   char expected[1000], actual[1000];
   if (n < 0 || n > 48) {
      printf ("Test failed: n = %d, Error n must be between 0 and 47.\n", n);
      exit (1);
   }
   GenerateFibonacciSeries (n, expected);
   GenerateFibonacciSeries (n, actual);
   printf ("\nf(%d) =  %s \n\n", n, actual);
   if (strcmp (expected, actual) != 0) {
      printf ("Test failed: n = %d\n" "Expected: %s\n" "Actual: %s\n", n, expected, actual);
      exit (1);
   }
}

int main () {
   int testCases[] = { 1, 2, 6, 10, 15, 18, 23, 27, 30, 35, 38, 43, 47 },
      numTestCases = sizeof (testCases) / sizeof (testCases[0]);
   for (int i = 0; i < numTestCases; i++) RunTestCase (testCases[i]);
   printf ("\nAll tests are passed!!\n");
   return 0;
}