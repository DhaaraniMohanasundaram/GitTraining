// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// TestComplex.c
// Program on Test1.2 branch.
// ------------------------------------------------------------------------------------
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "Complex.h"

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"

/// <summary>To check if both the imaginary and real part of two complex number are equal.</summary>
bool Equal (ComplexNumber c1, ComplexNumber c2) {
   return (c1.Real == c2.Real) && (c1.Img == c2.Img);
}

void RunTestCases () {   // TestCase Array as  C1 {r1, img1}, C2 {r2, img2}, C3 {r3, img3} 
   ComplexNumber input[] = { {5, 4}, {6, -5}, {2, 3} },
      // Operations for add,sub,mul as { C1 & C2} ,{ C2 & C3 },{ C3 & C1 }
      expAdd[] = { {11, -1}, {8, -2}, {7, 7} },
      expSub[] = { {-1, 9}, {4, -8}, {-3, -1} },
      expMul[] = { {50, -1}, {27, 8}, {-2, 23} },
      expConj[] = { {5, -4}, {6, 5}, {2, -3} };   // C1, C2, C3
   float expMod[] = { 6.4031, 7.8102, 3.6056 };
   for (int i = 0; i < 3; i++) {
      ComplexNumber resultAdd = Add (input[i], input[(i + 1) % 3]),
         resultSub = Subtract (input[i], input[(i + 1) % 3]),
         resultMul = Multiply (input[i], input[(i + 1) % 3]),
         resultConj = Conjugate (input[i]);
      float resultMod = Modulus (input[i]);
      printf ("\nTest %d:\n" "Addition: %.2f + %.2fi -> %s\n", i + 1, resultAdd.Real, resultAdd.Img,
         Equal (resultAdd, expAdd[i]) ? GREEN"Passed"RESET : RED"Failed"RESET);
      printf ("Subtraction: %.2f + %.2fi -> %s\n", resultSub.Real, resultSub.Img,
         Equal (resultSub, expSub[i]) ? GREEN"Passed"RESET : RED"Failed"RESET);
      printf ("Multiplication: %.2f + %.2fi -> %s\n", resultMul.Real, resultMul.Img,
         Equal (resultMul, expMul[i]) ? GREEN"Passed"RESET : RED"Failed"RESET);
      if (i == 2) {  // For modulus and conjugate tests
         for (int j = 0; j < 3; j++) {
            float resultMod = Modulus (input[j]);
            ComplexNumber resultConj = Conjugate (input[j]);
            printf ("\nModulus of %d: %.2f -> %s\n", j + 1, resultMod,
               (fabs (resultMod - expMod[j]) < 0.0001) ? GREEN"Passed"RESET : RED"Failed"RESET);
            printf ("Conjugate of %d: %.2f + %.2fi -> %s\n", j + 1, resultConj.Real, resultConj.Img,
               Equal (resultConj, expConj[j]) ? GREEN"Passed"RESET : RED"Failed"RESET);
         }
      }
   }
}

int main () {
   RunTestCases ();
   return 0;
}