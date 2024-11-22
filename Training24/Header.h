// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -------------------------------------
//  Dhaarani Mohanasundaram
// -------------------------------------
// Header.h
// Program on Test1 branch.
// Design a Struct ComplexNumber with two parts: a real part (float) and an imaginary part (float). 
// Define functions that perform arithmetic operations (+, -, *) on 2 complex numbers and returns the result.
// You may call the functions called Op_Add (), Op_Sub () and so on.Also write a function to calculate the Modulus and Conjugate of a complex number.
// Write a test to ensure the result of the functions is as expected. (It is sufficient to display which test is being run and whether it passes).
// ------------------------------------------------------------------------------------
#pragma once
#pragma disable warning 4996

#define HEADER_H

struct CompNum {
   float real;
   float img;
};

/// <summary>To add two comp num.</summary>
void Op_Add (float r1, float img1, float r2, float img2, float* resultReal, float* resultImg);

/// <summary>To subtract two comp num.</summary>
void Op_Sub (float r1, float img1, float r2, float img2, float* resultReal, float* resultImg);

/// <summary>To multiply two comp nums.</summary>
void Op_Mul (float r1, float img1, float real2, float img2, float* resultReal, float* resultImg);

float Mod (float real, float img);

void Conjugate (float real, float img, float* resultReal, float* resultImg);