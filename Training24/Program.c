// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// Program.c
// Program on B3 branch.
// Program to calculate the LCM and GCD of a number.
// ------------------------------------------------------------------------------------
#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// To calculate GCD using Euclidean algorithm
int gcd (int a, int b) {
   return (a == 0) ? b : gcd (b % a, a);
}

// To calculate LCM using the formula
int lcm (int a, int b) {
   if (a > INT_MAX / b) {
      printf ("Overflow detected.\n");
      exit (1);
   }
   return (a / gcd (a, b)) * b;
}

void RunTestCase (int num1, int num2, int expectedGCD, int expectedLCM) {
   int gcdResult = gcd (num1, num2), lcmResult = lcm (num1, num2);
   printf ("LCM & GCD of %d and %d:\n" "GCD is %d, LCM is %d\n\n", num1, num2, gcdResult, lcmResult);
   if (gcdResult != expectedGCD || lcmResult != expectedLCM) {
      printf ("Test Failed: Expected GCD = %d, LCM = %d, but got GCD = %d, LCM = %d\n", expectedGCD, expectedLCM, gcdResult, lcmResult);
      exit (1);
   }
}

int main () {
   printf ("~~~~~~~~~ Test Cases ~~~~~~~~~\n\n");
   int testCases[][4] = { {12, 15, 3, 60},   // Num = 12 & 15; Expected GCD = 3, LCM = 60
         {68, 104, 4, 1768}, {7, 9, 1, 63}, {0, 150, 150, 0} },
      numTestCases = sizeof (testCases) / sizeof (testCases[0]);
   for (int i = 0; i < numTestCases; i++) RunTestCase (testCases[i][0], testCases[i][1], testCases[i][2], testCases[i][3]);
   printf ("All tests are passed..!!\n");
   return 0;
}