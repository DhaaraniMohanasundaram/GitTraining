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

/// <summary>Checks if a phrase is a palindrome.</summary>
bool CheckPhrasePalindrome (const char* phrase);

/// <summary>Reverse the integer and check for overflow.</summary>
bool ReverseAndCheckOverflow (int number, int* reversedNumber);

/// <summary>Checks the reversed number for palindrome.</summary>
bool IsNumPalindrome (int number);