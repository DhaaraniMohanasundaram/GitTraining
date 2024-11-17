// --------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// --------------------------------------------------------------------------------------
// Header.h
// Program on branch A4.
// A4: Palindrome Checker: Check the Phrase & integer for palindrome.
// --------------------------------------------------------------------------------------
#pragma once
#pragma warning (disable:4996)

#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS

#define INVALID_INPUT -3
#define OVERFLOW_ERROR -2
#define NEGATIVE_NUMBER -1
#define SUCCESS 1
#define PALINDROME 2
#define NOT_PALINDROME 3

/// <summary>Checks if a phrase is a palindrome.</summary>
bool IsPhrasePalindrome (const char* phrase);

/// <summary>Reverse the integer and check for overflow.</summary>
int ReverseAndCheckOverflow (int number, int* reversedNumber);

/// <summary>Checks the reversed number for palindrome.</summary>
int IsIntPalindrome (int number);

/// <summary>Checks if the input is valid (integer and non-empty).</summary>
int IsValidInput (const char* input);