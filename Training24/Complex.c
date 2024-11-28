// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// Complex.c
// Program on Test1.2 branch.
// ------------------------------------------------------------------------------------
#include <math.h>
#include "Complex.h"

ComplexNumber Add (ComplexNumber a, ComplexNumber b) {
   return (ComplexNumber) { a.real + b.real, a.img + b.img };
}

ComplexNumber Subtract (ComplexNumber a, ComplexNumber b) {
   return (ComplexNumber) { a.real - b.real, a.img - b.img };
}

ComplexNumber Multiply (ComplexNumber a, ComplexNumber b) {
   return (ComplexNumber) { a.real* b.real - a.img * b.img, a.real* b.img + a.img * b.real };
}

ComplexNumber Conjugate (ComplexNumber a) {
   return (ComplexNumber) { a.real, -a.img };
}

float Modulus (ComplexNumber a) {
   return sqrt (a.real * a.real + a.img * a.img);
}