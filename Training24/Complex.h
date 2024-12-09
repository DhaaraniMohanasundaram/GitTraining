// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// Complex.h
// Program on Test1.2 branch.
// Test1: Add, Subtract and Multiply two complex numbers; 
//        also modulus and conjugate a complex number.
// ------------------------------------------------------------------------------------
#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct {
   float Real, Img;
} ComplexNumber;

/// <summary>To add two complex numbers.</summary>
ComplexNumber Add (ComplexNumber a, ComplexNumber b);

/// <summary>To subtract two complex numbers.</summary>
ComplexNumber Subtract (ComplexNumber a, ComplexNumber b);

/// <summary>To multiply two complex numbers.</summary>
ComplexNumber Multiply (ComplexNumber a, ComplexNumber b);

/// <summary>To modulus a complex number.</summary>
float Modulus (ComplexNumber a);

/// <summary>To conjugate a complex number.</summary>
ComplexNumber Conjugate (ComplexNumber a);
#endif