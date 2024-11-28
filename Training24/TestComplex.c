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

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"

void RunTestCases () {   // TestCase Array as  C1 {r1, img1}, C2 {r2, img2}, C3 {r3, img3} 
   ComplexNumber input[] = { {5, 4}, {6, -5}, {2, 3} },
      // Operations as { C1 & C2} ,{ C2 & C3 },{ C3 & C1 }
      expAdd[] = { {11, -1}, {8, -2}, {7, 7} },
      expSub[] = { {-1, 9}, {4, -8}, {-3, -1} },
      expMul[] = { {50, -1}, {27, 8}, {-2, 23} },
      expConj[] = { {5, -4}, {6, 5}, {2, -3} };
   float expMod[] = { 6.4031, 7.8102, 3.6056 };
   for (int i = 0; i < 3; i++) {
      ComplexNumber resultAdd = Add (input[i], input[(i + 1) % 3]),
         resultSub = Subtract (input[i], input[(i + 1) % 3]),
         resultMul = Multiply (input[i], input[(i + 1) % 3]),
         resultConj = Conjugate (input[i]);
      float resultMod = Modulus (input[i]);
      printf ("\nTest %d:\n" "Addition: %.2f + %.2fi -> %s\n", i + 1, resultAdd.real, resultAdd.img,
         (resultAdd.real == expAdd[i].real && resultAdd.img == expAdd[i].img) ? GREEN"Passed"RESET : RED"Failed"RESET);
      printf ("Subtraction: %.2f + %.2fi -> %s\n", resultSub.real, resultSub.img,
         (resultSub.real == expSub[i].real && resultSub.img == expSub[i].img) ? GREEN"Passed"RESET : RED"Failed"RESET);
      printf ("Multiplication: %.2f + %.2fi -> %s\n", resultMul.real, resultMul.img,
         (resultMul.real == expMul[i].real && resultMul.img == expMul[i].img) ? GREEN"Passed"RESET : RED"Failed"RESET);
      if (i == 2) {
         for (int j = 0; j < 3; j++) {
            float resultMod = Modulus (input[j]);
            ComplexNumber resultConj = Conjugate (input[j]);
            printf ("\nModulus of %d: %.2f -> %s\n", j + 1, resultMod,
               (fabs (resultMod - expMod[j]) < 0.0001) ? GREEN"Passed"RESET : RED"Failed"RESET);
            printf ("Conjugate of %d: %.2f + %.2fi -> %s\n", j + 1, resultConj.real, resultConj.img,
               (resultConj.real == expConj[j].real && resultConj.img == expConj[j].img) ? GREEN"Passed"RESET : RED"Failed"RESET);
         }
      }
   }
}

int main () {
   RunTestCases ();
   return 0;
}