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
#pragma warning (disable:4996)
#ifndef COMPLEX_H
#define COMPLEX_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>

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

/// <summary>To check if both the imaginary and real part of two complex number are equal.</summary>
bool IsEqual (ComplexNumber c1, ComplexNumber c2);
#endif