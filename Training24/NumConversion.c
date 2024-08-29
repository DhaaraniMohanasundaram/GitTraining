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

// Function to  convert an integer to binary (8-bit: 256 values)
void ConvertToBinary (int number) {
   for (int i = 7; i >= 0; i--)    printf ("%d", (number >> i) & 1);   
   printf ("\n");
}

// Function to  check if input is a valid integer
bool IsValidInteger (const char* str) {
   if (*str == '-' || *str == '+') str++;   // Skip sign if present
   if (!*str) return false;   // If string is empty after sign
   while (*str) {   // Check each character to ensure it's a digit
      if (!isdigit (*str)) return false; 
      str++;
   }
   return true;
}

// Function to get a valid integer from the user
bool GetValidInteger (int* number) {
   char input[100];
   if (fgets (input, sizeof (input), stdin) != NULL) {
      input[strcspn (input, "\n")] = '\0';     // Remove newline character if present
      if (IsValidInteger (input) && sscanf_s (input, "%d", number) == 1) return true;
   }
   return false;
}

// Function to convert an integer to its 8-bit hexadecimal representation using modulus
void HexUsingModulus (int number) {
   unsigned char postiveInt = (unsigned char)number;    // To handle negative values
   char hex[3];   // Array to store hexadecimal representation (2 digits + null terminator)
   int index = 0;
   if (postiveInt == 0) hex[index++] = '0';   
   else {   
      while (postiveInt > 0) {
         int remainder = postiveInt % 16;   // Get the remainder
         switch (remainder) {    // Convert remainder to ASCII hexadecimal character
         case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
            hex[index++] = '0' + remainder;
            break;
         case 10: case 11: case 12: case 13: case 14: case 15:
            hex[index++] = 'A' + (remainder - 10);
            break;
         }
         postiveInt /= 16; // Divide to process the next digit
      }
   }
   hex[index] = '\0';   // Null-terminate the hex string
   for (int j = index - 1; j >= 0; j--) printf ("%c", hex[j]);   // Reverse the hex string
   printf ("\n");
}

int main () {
   int number;
   while (true) {
      printf ("Enter an integer: ");
      if (GetValidInteger (&number)) break;
      printf ("Invalid input. Please enter a valid integer.\n");
   }
   printf ("Hexadecimal (Using format specifier): %X\n", (unsigned char)number); 
   printf ("Hexadecimal (Using modulus function): ");
   HexUsingModulus (number); 
   printf ("Binary (8-bit): ");
   ConvertToBinary (number);
   return 0;
}
