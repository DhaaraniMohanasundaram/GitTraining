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
#include "Complex.h"

#define EPSILON 0.0001
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"

void RunTestCases () {   // TestCase Array as  C1 {r1, img1}, C2 {r2, img2}, C3 {r3, img3} 
   ComplexNumber input[] = { {5, 4}, {6, -5}, {2, 3} },
      // Operations for add,sub,mul as { C1 & C2} ,{ C2 & C3 },{ C3 & C1 }
      expAdd[] = { {11, -1}, {8, -2}, {7, 7} },
      expSub[] = { {-1, 9}, {4, -8}, {-3, -1} },
      expMul[] = { {50, -1}, {27, 8}, {-2, 23} },
      expConj[] = { {5, -4}, {6, 5}, {2, -3} };   // C1, C2, C3
   float expMod[] = { 6.4031f, 7.8102f, 3.6056f };
   int numTests = sizeof (input) / sizeof (input[0]);
   for (int i = 0; i < numTests; i++) {
      ComplexNumber resultAdd = Add (input[i], input[(i + 1) % numTests]),
         resultSub = Subtract (input[i], input[(i + 1) % numTests]),
         resultMul = Multiply (input[i], input[(i + 1) % numTests]),
         resultConj = Conjugate (input[i]);
      float resultMod = Modulus (input[i]);
      printf ("\nTest %d:\n" "Addition: %.2f + %.2fi -> %s\n", i + 1, resultAdd.Real, resultAdd.Img,
         IsEqual (resultAdd, expAdd[i]) ? GREEN"Passed"RESET : RED"Failed"RESET);
      printf ("Subtraction: %.2f + %.2fi -> %s\n", resultSub.Real, resultSub.Img,
         IsEqual (resultSub, expSub[i]) ? GREEN"Passed"RESET : RED"Failed"RESET);
      printf ("Multiplication: %.2f + %.2fi -> %s\n", resultMul.Real, resultMul.Img,
         IsEqual (resultMul, expMul[i]) ? GREEN"Passed"RESET : RED"Failed"RESET);
      if (i == numTests - 1) {   // For modulus and conjugate tests
         for (int j = 0; j < numTests; j++) {
            float resultMod = Modulus (input[j]);
            ComplexNumber resultConj = Conjugate (input[j]);
            printf ("\nModulus of %d: %.2f -> %s\n", j + 1, resultMod,
               (fabs (resultMod - expMod[j]) < EPSILON) ? GREEN"Passed"RESET : RED"Failed"RESET);
            printf ("Conjugate of %d: %.2f + %.2fi -> %s\n", j + 1, resultConj.Real, resultConj.Img,
               IsEqual (resultConj, expConj[j]) ? GREEN"Passed"RESET : RED"Failed"RESET);
         }
      }
   }
}

int main () {
   RunTestCases ();
   return 0;
}