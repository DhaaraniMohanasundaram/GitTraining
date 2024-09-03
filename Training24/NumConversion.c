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

/// <summary>Function to  convert an integer to binary.</summary>
void ConvertToBinary (int number, int binaryArray[], int bitWidth) {
   for (int i = bitWidth - 1; i >= 0; i--) binaryArray[bitWidth - 1 - i] = (number >> i) & 1;
   return;
}

/// <summary>Function to print the binary representation from the binary array.</summary>
void PrintBinary (const int binaryArray[], int bitWidth) {
   for (int i = 0; i < bitWidth; i++) printf ("%d", binaryArray[i]);
   printf ("\n");
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
   char input[100];
   if (fgets (input, sizeof (input), stdin) != NULL) {
      input[strcspn (input, "\n")] = '\0';     // Remove newline character if present
      if (IsValidInteger (input) && sscanf_s (input, "%d", number) == 1) return true;
   }
   return false;
}

/// <summary>Function to convert an integer into hexadecimal representation.</summary>
void ConvertToHex (int number, char hex[], int bitWidth) {
   int value;
   int hexDigits = bitWidth / 4;   // Calculate number of hex digits based on bit width
   // Handle negative numbers by computing two's complement
   if (number < 0) value = (1 << bitWidth) + number;
   else value = number;
   int index = 0;
   do {
      int remainder = value % 16;
      if (remainder < 10) hex[index++] = '0' + remainder;
      else hex[index++] = 'A' + (remainder - 10);
      value /= 16;
   } while (value > 0);
   while (index < hexDigits) hex[index++] = '0';   // Pad with leading zeros for the required bit width
   for (int j = 0; j < index / 2; j++) {   // Reverse the hex string
      char temp = hex[j];
      hex[j] = hex[index - j - 1];
      hex[index - j - 1] = temp;
   }
   hex[index] = '\0';   // Ensure null-termination
   return;
}

/// <summary>Function to determine the appropriate bit width based on the integer value.</summary>
int DetermineBitWidth (int number) {   
   if (number == INT_MIN) return 32;   // Determine the minimum bit width required to represent the number
   if (number < -(1 << 15) || number >= (1 << 15)) return 32;
   if (number < -(1 << 7) || number >= (1 << 7)) return 16;
   return 8;   // Default bit width
}

int main () {
   int number;
   int binaryArray[32];
   char hex[9];

   while (true) {
      printf ("Enter an integer: ");
      if (GetValidInteger (&number)) break;
      printf ("Invalid input. Please enter a valid integer.\n");
   }

   int bitWidth = DetermineBitWidth (number);
   ConvertToBinary (number, binaryArray, bitWidth);
   printf ("Binary: ");
   PrintBinary (binaryArray, bitWidth);

   ConvertToHex (number, hex, bitWidth);
   printf ("Hexadecimal: %s\n", hex);
   return 0;
}

