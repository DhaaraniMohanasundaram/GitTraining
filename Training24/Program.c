// --------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
//  Dhaarani Mohanasundaram
// --------------------------------------------------------------------------------
// Program.c
// Program on branch A4.
// Checks for phrase palindrome and Reverse the number then checks for palindrome.
// --------------------------------------------------------------------------------
#include <ctype.h>
#include <string.h> 
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include "Header.h"

bool IsPhrasePalindrome (const char* phrase) {
   if (phrase == NULL) return false;  // NULL pointer check
   size_t start = 0, end = strlen (phrase) - 1;
   while (start < end) {
      if (!isalnum (phrase[start])) {
         start++;
         continue;
      }
      if (!isalnum (phrase[end])) {
         end--;
         continue;
      }
      if (tolower (phrase[start]) != tolower (phrase[end])) return false;  // Not a palindrome
      start++;
      end--;
   }
   return true;  // It's a palindrome
}

int IsValidInput (const char* input) {
   if (input == NULL || input[0] == '\0') return INVALID_INPUT;
   char* endPtr;
   long inputNumber = strtol (input, &endPtr, 10);
   if (*endPtr != '\0' && *endPtr != '\n') return INVALID_INPUT;
   if (inputNumber < INT_MIN || inputNumber > INT_MAX) return OVERFLOW_ERROR;
   return SUCCESS;
}

int ReverseAndCheckOverflow (int number, int* reversedNumber) {
   *reversedNumber = 0;
   while (number != 0) {
      int digit = number % 10;
      if (*reversedNumber > (INT_MAX - digit) / 10) {
         return OVERFLOW_ERROR;  // Indicate overflow during reversal
      }
      *reversedNumber = *reversedNumber * 10 + digit;
      number /= 10;
   }
   return SUCCESS;  // No overflow
}

int IsIntPalindrome (int number) {
   if (number < 0) {
      return NEGATIVE_NUMBER;  // Negative numbers are never palindromes
   }
   int reversedNumber = 0;
   int result = ReverseAndCheckOverflow (number, &reversedNumber);
   if (result == OVERFLOW_ERROR) {
      return OVERFLOW_ERROR;
   }
   return (number == reversedNumber) ? PALINDROME : NOT_PALINDROME;
}