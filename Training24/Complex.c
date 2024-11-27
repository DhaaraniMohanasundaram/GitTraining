// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// Complex.c
// Program on Test1.2 branch.
// ------------------------------------------------------------------------------------
#include <math.h>

void Add (float r1, float img1, float r2, float img2, float* resultReal, float* resultImg) {
   *resultReal = r1 + r2;
   *resultImg = img1 + img2;
}

void Subtract (float r1, float img1, float r2, float img2, float* resultReal, float* resultImg) {
   *resultReal = r1 - r2;
   *resultImg = img1 - img2;
}

void Multiply (float r1, float img1, float r2, float img2, float* resultReal, float* resultImg) {
   *resultReal = r1 * r2 - img1 * img2;
   *resultImg = r1 * img2 + img1 * r2;
}

float Modulus (float real, float img) {
   return sqrt (real * real + img * img);
}

void Conjugate (float real, float img, float* resultReal, float* resultImg) {
   *resultReal = real;
   *resultImg = -img;
}