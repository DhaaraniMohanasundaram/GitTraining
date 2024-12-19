// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// Complex.c
// Program on Test1.2 branch.
// ------------------------------------------------------------------------------------
#include <math.h>
#include <stdbool.h>
#include "Complex.h"
#define EPSILON 0.0001

ComplexNumber Sum (ComplexNumber a, ComplexNumber b) {
   return (ComplexNumber) { a.Real + b.Real, a.Img + b.Img };
}

ComplexNumber Subtract (ComplexNumber a, ComplexNumber b) {
   return (ComplexNumber) { a.Real - b.Real, a.Img - b.Img };
}

ComplexNumber Multiply (ComplexNumber a, ComplexNumber b) {
   return (ComplexNumber) {
      a.Real* b.Real - a.Img * b.Img, a.Real* b.Img + a.Img * b.Real
   };
}

ComplexNumber Conjugate (ComplexNumber a) {
   return (ComplexNumber) {
      a.Real, -a.Img
   };
}

float Modulus (ComplexNumber a) {
   return sqrt (a.Real * a.Real + a.Img * a.Img);
}

bool IsEqual (ComplexNumber c1, ComplexNumber c2) {
   return (fabs (c1.Real - c2.Real) < EPSILON) && (fabs (c1.Img - c2.Img) < EPSILON);
}