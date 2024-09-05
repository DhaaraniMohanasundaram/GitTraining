// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Numconversion.c
// Program to get user input(only integer) and convert them to Hexadecimal and Binary.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define BITS_PER_HEX_DIGIT 4
#define MAX_INPUT_LENGTH 100
#define MAX_HEX_DIGITS 32

/// <summary> Function to convert an integer to binary and return it as a string</summary>
char* ConvertToBinary (int number, int bitWidth) {
   static char binaryString[33];
   for (int i = 0; i < bitWidth; i++) {
      binaryString[i] = ((number >> (bitWidth - i - 1)) & 1) ? '1' : '0';
   }
   binaryString[bitWidth] = '\0';
   return binaryString;
}


/// <summary>Function to  check if input is a valid integer.</summary>
bool IsValidInteger (const char* str) {
   if (*str == '-' || *str == '+') str++;   // Skip sign if present
   if (!*str) return false;   // If string is empty after sign
   while (*str) {   // Check each character to ensure it's a digit
      if (!isdigit (*str)) return false; 
      str++;
   }
   return true;
}

/// <summary>Function to get a valid integer from the user.</summary>
bool GetValidInteger (int* number) {
   char input[MAX_INPUT_LENGTH];
   if (fgets (input, sizeof (input), stdin) != NULL) {
      input[strcspn (input, "\n")] = '\0'; // Remove newline character
      if (IsValidInteger (input)) {
         long long temp = 0;
         int i = 0;
         bool negative = false;
         if (input[i] == '-') {   // Handle optional sign
            negative = true;
            i++;
         }
         else if (input[i] == '+') i++;
         while (input[i] != '\0') {   // Checks for the integer
            if (!isdigit (input[i])) return false;
            temp = temp * 10 + (input[i] - '0');
            if ((negative && -temp < INT_MIN) || (!negative && temp > INT_MAX)) {   // Check for overflow
               printf ("Error: Integer exceeds 32-bit range.\n");
               return false;
            }
            i++;
         }
         *number = negative ? -temp : (int)temp;
         return true;
      }
      else printf ("Error: Invalid integer format.\n");
   }
   return false;
}

/// <summary>Function to convert an integer into hexadecimal representation.</summary>
void ConvertToHex (int number, char hex[], int bitWidth) {
   int hexDigits = bitWidth / BITS_PER_HEX_DIGIT;   // 4 Hex digits for 32 bits
   int value = number < 0 ? (1 << bitWidth) + number : number;
   int index = hexDigits - 1;
   // Fill hex array in reverse order
   for (int i = 0; i < hexDigits; i++) {
      int remainder = value & 0xF; // Get last 4 bits
      hex[index--] = remainder < 10 ? '0' + remainder : 'A' + (remainder - 10);
      value >>= BITS_PER_HEX_DIGIT; // Shift right by 4 bits
   }
   hex[hexDigits] = '\0'; // Ensure null-termination
}

/// <summary>Function to determine the appropriate bit width based on the integer value.</summary>
int DetermineBitWidth (int number) {   
   if (number == INT_MIN) return 32;   // Determine the minimum bit width required to represent the number
   if (number < -(1 << 15) || number >= (1 << 15)) return 32;
   if (number < -(1 << 7) || number >= (1 << 7)) return 16;
   return 8;   // Default bit width
}

int main () {
   int number; char hex[MAX_HEX_DIGITS + 1];// Space for hex digits + null terminator
   while (true) {
      printf ("Enter an integer: ");
      if (GetValidInteger (&number)) break;
      printf ("Invalid input. Please enter a valid integer.\n");
   }
   int bitWidth = DetermineBitWidth (number);
   printf ("Binary: %s\n", ConvertToBinary (number, bitWidth));
   ConvertToHex (number, hex, bitWidth);
   printf ("Hexadecimal: %s\n", hex);

   return 0;
}

