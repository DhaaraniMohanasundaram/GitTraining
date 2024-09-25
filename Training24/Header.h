// -------------------------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------------------------------------------------------------------------------------
// Header.h
// Program on branch A4.
// Palindrome Checker :
// Program that checks whether the given input(Phrase and integer) is a palindrome and test few cases automatically.
// -------------------------------------------------------------------------------------------------------------------
#pragma once
#pragma warning (disable:4996)
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS

/// <summary>Function to check if a string is a palindrome</summary>
int CheckPhrasePalindrome (const char* phrase);

/// <summary>Function to reverse the integer and check overflow.</summary>
bool ReverseNumber (int number, int* reversedNumber);

/// <summary>Function to check the reversed number for palindrome.</summary>
bool IsNumPalindrome (int number);

/// <summary>Function to test and print results for palindrome checker with phrases</summary>
void TestPhrasePalindromes ();

/// <summary>Function to test and print results for reversed number palindrome.</summary>
void TestReverseNumbers ();
