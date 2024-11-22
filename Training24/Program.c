// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -------------------------------------
//  Dhaarani Mohanasundaram
// -------------------------------------
// Program.c
// Program on Test1 branch.
// ------------------------------------------------------------------------------------

#include <math.h>

void Op_Add (float r1, float img1, float r2, float img2, float* resultReal, float* resultImg) {
   *resultReal = r1 + r2;
   *resultImg = img1 + img2;
}

void Op_Sub (float r1, float img1, float r2, float img2, float* resultReal, float* resultImg) {
   *resultReal = r1 - r2;
   *resultImg = img1 - img2;
}

void Op_Mul (float r1, float img1, float real2, float img2, float* resultReal, float* resultImg) {
   *resultReal = r1 * real2 - img1 * img2;
   *resultImg = r1 * img2 + img1 * real2;
}

float Mod (float real, float img) {
   return sqrt (real * real + img * img);
}

void Conjugate (float real, float img, float* resultReal, float* resultImg) {
   *resultReal = real;
   *resultImg = -img;
}