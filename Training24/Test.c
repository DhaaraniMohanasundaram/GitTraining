// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -------------------------------------
//  Dhaarani Mohanasundaram
// -------------------------------------
// Test.c
// Program on Test1 branch.
// ------------------------------------------------------------------------------------
#include <stdio.h>
#include "Header.h"

// To display a complex number
void DisplayCompNum (float real, float img) {
   if (img < 0) printf ("%.2f - %.2fi\n", real, -img);
   else printf ("%.2f + %.2fi\n", real, img);
}

// To get input from the user for a complex number
void GetCompInput (float* real, float* img) {
   printf ("Enter real num: ");
   scanf_s ("%f", real);
   printf ("Enter img num: ");
   scanf_s ("%f", img);
}


void RunTests () {
   float r1 = 3, img1 = 2;  // 3 + 2i
   float r2 = 1, img2 = 7;  // 1 + 7i
   float resultReal, resultImg;

   Op_Add (r1, img1, r2, img2, &resultReal, &resultImg);
   printf ("Add (Exp: 4 + 9i)\n");
   DisplayCompNum (resultReal, resultImg);
   printf (resultReal == 4 && resultImg == 9 ? "PASS\n\n" : "FAIL\n\n");

   Op_Sub (r1, img1, r2, img2, &resultReal, &resultImg);
   printf ("Sub (Exp: 2 - 5i)\n");
   DisplayCompNum (resultReal, resultImg);
   printf (resultReal == 2 && resultImg == -5 ? "PASS\n\n" : "FAIL\n\n");

   Op_Mul (r1, img1, r2, img2, &resultReal, &resultImg);
   printf ("Mul (Exp: -11 + 23i)\n");
   DisplayCompNum (resultReal, resultImg);
   printf (resultReal == -11 && resultImg == 23 ? "PASS\n\n" : "FAIL\n\n");

   float resultMod = Mod (r1, img1);
   printf (" Mod\n");
   printf ("Result: %.5f\n", resultMod);
   printf (resultMod == 3.60555 ? "PASS\n\n" : "FAIL\n\n");

   Conjugate (r1, img1, &resultReal, &resultImg);
   printf ("Test 5: Conjugate (Exp: 3 - 2i)\n");
   DisplayCompNum (resultReal, resultImg);
   printf (resultReal == 3 && resultImg == -2 ? "PASS\n" : "FAIL\n");
}

int main () {
   float r1, img1, r2, img2;
   GetCompInput (&r1, &img1);
   GetCompInput (&r2, &img2);

   float resultReal, resultImg;

   Op_Add (r1, img1, r2, img2, &resultReal, &resultImg);
   printf ("\nAdd: ");
   DisplayCompNum (resultReal, resultImg);

   Op_Sub (r1, img1, r2, img2, &resultReal, &resultImg);
   printf ("Sub: ");
   DisplayCompNum (resultReal, resultImg);

   Op_Mul (r1, img1, r2, img2, &resultReal, &resultImg);
   printf ("Mul: ");
   DisplayCompNum (resultReal, resultImg);

   printf ("Mod of 1st: %.5f\n", Mod (r1, img1));
   printf ("Conj of 1st: ");
   Conjugate (r1, img1, &resultReal, &resultImg);
   DisplayCompNum (resultReal, resultImg);

   printf ("Mod of 2nd: %.5f\n", Mod (r2, img2));
   printf ("Conj of 2nd: ");
   Conjugate (r2, img2, &resultReal, &resultImg);
   DisplayCompNum (resultReal, resultImg);

   printf ("\nTESTCASES...\n\n");
   RunTests ();

   return 0;
}

