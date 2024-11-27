// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// TestComplex.c
// Program on Test1.2 branch.
// ------------------------------------------------------------------------------------
#include <stdio.h>
#include "Complex.h"

/// <summary>To display a complex number.</summary>
void DisplayCompNum (float real, float img);

/// <summary>To get input from the user for a complex number.</summary>
void GetCompInput (float* real, float* img);

/// <summary>To display modulus and conjugate for a complex number.</summary>
void DisplayModulusAndConjugate (float real, float img, int complexNum);

void DisplayCompNum (float real, float img) {
   if (img < 0) printf ("%.2f - %.2fi\n", real, -img);
   else printf ("%.2f + %.2fi\n", real, img);
}

void GetCompInput (float* real, float* img) {
   printf ("Enter real num: ");
   scanf_s ("%f", real);
   printf ("Enter img num: ");
   scanf_s ("%f", img);
}

void DisplayModulusAndConjugate (float real, float img, int complexNum) {
   printf ("Modulus of %d: %.5f\n", complexNum, Modulus (real, img));
   float resultReal, resultImg;
   Conjugate (real, img, &resultReal, &resultImg);
   printf ("Conjugate of %d: ", complexNum);
   DisplayCompNum (resultReal, resultImg);
}

void RunTestCases () {
   // Array of test cases (r1, img1, r2, img2)
   float testCases[][4] = {
       {3, 2, 1, 7},
       {-3, -2, -1, -7},
       {11111111, 11111111, -11111111, -11111111},
       {0, 0, 0, 0},
       {5, 0, 0, 3},
   };
   for (int i = 0; i < 5; i++) {
      float r1 = testCases[i][0], img1 = testCases[i][1],
         r2 = testCases[i][2], img2 = testCases[i][3],
         resultReal, resultImg;
      Add (r1, img1, r2, img2, &resultReal, &resultImg);
      printf ("Test %d:" "\nAddition: ", i + 1);
      DisplayCompNum (resultReal, resultImg);
      Subtract (r1, img1, r2, img2, &resultReal, &resultImg);
      printf ("Subtraction: ");
      DisplayCompNum (resultReal, resultImg);
      Multiply (r1, img1, r2, img2, &resultReal, &resultImg);
      printf ("Multiplication: ");
      DisplayCompNum (resultReal, resultImg);
      DisplayModulusAndConjugate (r1, img1, 1);
      DisplayModulusAndConjugate (r2, img2, 2);
      printf ("\n");
   }
}

int main () {
   float r1, img1, r2, img2, resultReal, resultImg;
   GetCompInput (&r1, &img1);
   GetCompInput (&r2, &img2);
   Add (r1, img1, r2, img2, &resultReal, &resultImg);
   printf ("\nAddition: ");
   DisplayCompNum (resultReal, resultImg);
   Subtract (r1, img1, r2, img2, &resultReal, &resultImg);
   printf ("Subtraction: ");
   DisplayCompNum (resultReal, resultImg);
   Multiply (r1, img1, r2, img2, &resultReal, &resultImg);
   printf ("Multiplication: ");
   DisplayCompNum (resultReal, resultImg);
   DisplayModulusAndConjugate (r1, img1, 1);
   DisplayModulusAndConjugate (r2, img2, 2);
   printf ("\n-------TESTCASES--------\n");
   RunTestCases ();
   return 0;
}