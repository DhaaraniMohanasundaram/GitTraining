// -------------------------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -------------------------------------------------------------------------------
// Dhaarani Mohanasundaram
// -------------------------------------------------------------------------------------------------------------------
// Number conversion game - Program to get user input and convert given decimal number to Hexadecimal and Binary
// Numconversion.c
// Program on A3 Branch.
// -------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define BITS_PER_HEX_DIGIT 4
#define MAX_INPUT_LENGTH 100
#define MAX_HEX_DIGITS 8   // For 32 bits: 32/4 = 8 hex digits
#define MAX_BINARY_DIGITS 33   // 32 bits + null terminator

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define RESET   "\033[0m"

/// <summary> Converts an integer to its binary representation as a string. </summary>
void ConvertToBinary (int number, int bitWidth, char* binaryString) {
   for (int i = 0; i < bitWidth; i++) binaryString[i] = ((number >> (bitWidth - i - 1)) & 1) ? '1' : '0';
   binaryString[bitWidth] = '\0';
}

/// <summary>Function to get a valid integer from the user and returns error message if input is invalid.</summary>
bool GetValidInteger (int* number, char* errorMessage) {
   char input[MAX_INPUT_LENGTH];
   char* num;
   if (fgets (input, sizeof (input), stdin) == NULL) {
      strcpy_s (errorMessage, MAX_INPUT_LENGTH, "Failed to read input.");
      return false;
   }
   input[strcspn (input, "\n")] = '\0';
   if (strlen (input) == 0) {
      strcpy_s (errorMessage, MAX_INPUT_LENGTH, "Input cannot be empty.");
      return false;
   }
   long long tempNumber = strtoll (input, &num, 10);   // Reads input safely using long long without overflow
   if (*num != '\0' || tempNumber > INT_MAX || tempNumber < INT_MIN) {
      strcpy_s (errorMessage, MAX_INPUT_LENGTH, (*num != '\0') ? "Invalid integer format." : "Number is out of 32 - bit range.");
      return false;
   }
   *number = (int)tempNumber; // Casts to int, after valid input
   return true;
}

/// <summary>Function to convert the Binary into hexadecimal representation.</summary>
void BinaryToHex (const char binary[], char hex[], int bitWidth) {
   int hexDigits = bitWidth / BITS_PER_HEX_DIGIT, binaryIndex = 0;
   for (int i = 0; i < hexDigits; i++) {
      int n = 0;
      for (int j = 0; j < BITS_PER_HEX_DIGIT; j++) n = (n << 1) | (binary[binaryIndex++] - '0');
      hex[i] = (n < 10) ? '0' + n : 'A' + (n - 10);
   }
   hex[hexDigits] = '\0';
}

/// <summary>Function to determine the appropriate bit width based on the integer value.</summary>
int DetermineBitWidth (int number) {
   if (number == INT_MIN) return 32;
   if (number < -(1 << 16) || number >= (1 << 16)) return 32;
   if (number < -(1 << 8) || number >= (1 << 8)) return 16;
   return 8;   // Default bit width
}

/// <summary> Test binary and hexadecimal conversions with various inputs and checks for correctness.</summary>
void TestCases () {
   struct {
      long long number;
      char expectedBinary[MAX_BINARY_DIGITS], expectedHex[MAX_HEX_DIGITS + 1];
   } testCases[] = {
       {0, "00000000", "00"},
       {-128, "10000000", "80"},
       {255, "11111111", "FF"},
       {INT_MAX, "01111111111111111111111111111111", "7FFFFFFF"},
       {INT_MIN, "10000000000000000000000000000000", "80000000"},
       {2147483649, "", ""}, // Out of range
       {(INT_MIN - 1ll), "", ""} // Out of range
   };
   int numTests = sizeof (testCases) / sizeof (testCases[0]);
   for (int i = 0; i < numTests; i++) {
      long long number = testCases[i].number;
      if (number < INT_MIN || number > INT_MAX) printf ("Number = %lld\n" YELLOW "Error: Number is out of 32 - bit range.\n" RESET "\n", number);
      else {
         int numberRange = (int)number;
         int bitWidth = DetermineBitWidth (numberRange);
         char binary[MAX_BINARY_DIGITS], hex[MAX_HEX_DIGITS + 1];
         ConvertToBinary (numberRange, bitWidth, binary);
         BinaryToHex (binary, hex, bitWidth);
         printf ("Number = %lld\nBinary value: %s\nBinary Test: %s\nHexadecimal value: %s\nHexadecimal Test: %s\n\n",
            number, binary, strcmp (binary, testCases[i].expectedBinary) == 0 ? GREEN "PASS" RESET : RED "FAIL" RESET,
            hex, strcmp (hex, testCases[i].expectedHex) == 0 ? GREEN "PASS" RESET : RED "FAIL" RESET);
      }
   }
}

int main () {
   int number;
   char errorMessage[100], binary[MAX_BINARY_DIGITS], hex[MAX_HEX_DIGITS + 1];
   TestCases ();
   while (true) {
      printf ("Enter an integer: ");
      if (GetValidInteger (&number, errorMessage)) {
         int bitWidth = DetermineBitWidth (number);
         ConvertToBinary (number, bitWidth, binary);
         BinaryToHex (binary, hex, bitWidth);
         printf ("Binary: %s\nHexadecimal: %s\n\n", binary, hex);
         break;
      }
      else printf (MAGENTA "Error: %s\n\n" RESET, errorMessage);   // Print the error message returned from GetValidInteger
   }
   return 0;
}