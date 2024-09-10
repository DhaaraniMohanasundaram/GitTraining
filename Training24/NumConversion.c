// -------------------------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -------------------------------------------------------------------------------
// Dhaarani Mohanasundaram
// -------------------------------------------------------------------------------------------------------------------
// Number conversion game - Program to get user input and convert given decimal number to Hexadecimal and Binary
// -------------------------------------------------------------------------------------------------------------------
// Numconversion.c
// Program on A3 Branch.
// -------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>

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
   binaryString[bitWidth] = '\0';  // Null-terminate the string
}

/// <summary>Function to  check if input is a valid integer.</summary>
bool IsValidInteger (const char* str) {
   if (str == NULL || *str == '\0') return false;
   if (*str == '-' || *str == '+') str++;   // Skip sign if present
   if (!*str) return false;   // If string is empty after sign
   while (*str) {   
      if (!isdigit (*str)) return false; 
      str++;
   }
   return true;
}

/// <summary> Checks if the number is within the 32-bit integer range defined by INT_MIN and INT_MAX. </summary>
bool IsWithinRange (long long number) {
   return number >= INT_MIN && number <= INT_MAX;   
}

/// <summary>Function to get a valid integer from the user.</summary>
bool GetValidInteger (long long* number) {
   char input[MAX_INPUT_LENGTH];
   if (fgets (input, sizeof (input), stdin) == NULL) return false;
   input[strcspn (input, "\n")] = '\0';   // Remove newline character
   if (strlen (input) == 0) return false;
   char* num;    
   *number = strtoll (input, &num, 10);
   return (*num == '\0');
}

/// <summary>Function to convert an integer into hexadecimal representation.</summary>
void BinaryToHex (const char binary[], char hex[], int bitWidth) {
   int hexDigits = bitWidth / BITS_PER_HEX_DIGIT;
   int binaryIndex = 0;
   for (int i = 0; i < hexDigits; i++) {
      int n = 0;
      for (int j = 0; j < BITS_PER_HEX_DIGIT; j++) n = (n << 1) | (binary[binaryIndex++] - '0');
      hex[i] = (n < 10) ? '0' + n : 'A' + (n - 10);
   }
   hex[hexDigits] = '\0';  // Null-terminate the string
}

/// <summary>Function to determine the appropriate bit width based on the integer value.</summary>
int DetermineBitWidth (int number) {   
   if (number == INT_MIN) return 32;   // Determine the minimum bit width required to represent the number
   if (number < -(1 << 15) || number >= (1 << 15)) return 32;
   if (number < -(1 << 7) || number >= (1 << 7)) return 16;
   return 8;   // Default bit width
}

/// <summary> Test binary and hexadecimal conversions with various inputs and checks for correctness.</summary>
void TestCases () {
   struct {
      long long number;
      char expectedBinary[MAX_BINARY_DIGITS]; char expectedHex[MAX_HEX_DIGITS + 1];
   } testCases[] = {
       {0, "00000000", "00"},
       {-128, "10000000", "80"},
       {255, "0000000011111111", "00FF"},
       {INT_MAX, "01111111111111111111111111111111", "7FFFFFFF"},
       {INT_MIN, "10000000000000000000000000000000", "80000000"},
       {2147483649ll, "00000000000000000000000000000000", "00000000"},   
       {-2147483649ll, "10000000000000000000000000000000", "80000000"}   // Error cases: Out of range
   };
   int numTests = sizeof (testCases) / sizeof (testCases[0]);  
   for (int i = 0; i < numTests; i++) {
      long long number = testCases[i].number;
      if (IsWithinRange (number)) {
         int numberRange = (int)number;
         int bitWidth = DetermineBitWidth (numberRange);
         char binary[MAX_BINARY_DIGITS]; char hex[MAX_HEX_DIGITS + 1];
         ConvertToBinary (numberRange, bitWidth, binary);
         BinaryToHex (binary, hex, bitWidth);
         printf ("Number = %lld\n", number);
         printf ("Binary value: %s\n", binary);
         printf ("Binary Test: %s\n", strcmp (binary, testCases[i].expectedBinary) == 0 ? GREEN"PASS" RESET : RED "FAIL" RESET);
         printf ("Hexadecimal value: %s\n", hex);
         printf ("Hexadecimal Test: %s\n\n", strcmp (hex, testCases[i].expectedHex) == 0 ? GREEN "PASS" RESET : RED "FAIL" RESET);
      }
      else {
         printf ("Number = %lld\n", number);
         printf (YELLOW "Error: Number is out of 32-bit range.\n" RESET "\n");
      }
   }
}
int main () {
   long long number;
   char binary[MAX_BINARY_DIGITS];
   char hex[MAX_HEX_DIGITS + 1];
   TestCases ();
   while (true) {
      printf ("Enter an integer: ");
      if (GetValidInteger (&number)) {
         if (IsWithinRange (number)) {
            int numberRange = (int)number;
            int bitWidth = DetermineBitWidth (numberRange);
            ConvertToBinary (numberRange, bitWidth, binary);
            BinaryToHex (binary, hex, bitWidth);
            printf ("Binary: %s\n", binary);
            printf ("Hexadecimal: %s\n\n", hex);
            break;
         }
         else printf (YELLOW "Error: Number is out of 32-bit range.\n" RESET "\n");
      }
      else printf (MAGENTA "Invalid input. Please enter a valid integer.\n" RESET "\n");
   }
   return 0;
}