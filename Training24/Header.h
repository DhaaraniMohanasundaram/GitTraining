// --------------------------------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ---------------------------------
//  Dhaarani Mohanasundaram
// --------------------------------------------------------------------------------------------------------------------------
// Palindrome Checker :
// Program that checks whether the given input(Phrase or integer) is a palindrome or not and test few cases automatically.
// --------------------------------------------------------------------------------------------------------------------------
// Header.h
// Program on branch A4.
// --------------------------------------------------------------------------------------------------------------------------
#pragma once
#define HEADER_H

/// <summary>Function to check if a string is a palindrome</summary>
int CheckPalindrome (const char* str);

/// <summary>Function to reverse the integer for checking palindrome.</summary>
void ReverseNumber (long long number, long long* reversed, int* isPalindromeResult);

/// <summary>Function to test and print results for palindrome checker with phrases</summary>
void TestPhrasePalindromes ();

/// <summary>Function to test and print results for reverse number function</summary>
void TestReverseNumbers ();
