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
#pragma once
#pragma disable warning 4996

#define HEADER_H

struct CompNum {
   float real;
   float img;
};

/// <summary>To add two complex numbers.</summary>
void Add (float r1, float img1, float r2, float img2, float* resultReal, float* resultImg);

/// <summary>To subtract two complex numbers.</summary>
void Subtract (float r1, float img1, float r2, float img2, float* resultReal, float* resultImg);

/// <summary>To multiply two complex numbers.</summary>
void Multiply (float r1, float img1, float r2, float img2, float* resultReal, float* resultImg);

/// <summary>To modulus a complex number.</summary>
float Modulus (float real, float img);

/// <summary>To conjugate a complex number.</summary>
void Conjugate (float real, float img, float* resultReal, float* resultImg);