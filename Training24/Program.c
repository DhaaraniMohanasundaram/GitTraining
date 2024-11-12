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

bool IsPhrasePalindrome (const char* phrase) {
   if (phrase == NULL) return false;  // Not a palindrome
   size_t start = 0, end = strlen (phrase) - 1;
   while (start < end) {
      while (start < end && !isalnum (phrase[start])) start++;
      while (start < end && !isalnum (phrase[end])) end--;
      if (tolower (phrase[start]) != tolower (phrase[end])) return false;
      start++;
      end--;
   }
   return true;
}

bool ReverseAndCheckOverflow (int number, int* reversedNumber) {
   *reversedNumber = 0;
   while (number > 0) {
      int digit = number % 10;
      // Check for overflow before reversing the number
      if (*reversedNumber > (INT_MAX - digit) / 10) return false;   // Indicate overflow during reversal
      *reversedNumber = *reversedNumber * 10 + digit;
      number /= 10;
   }
   return true;   // No overflow
}

bool IsIntPalindrome (int number) {
   if (number < 0) return false;   // Negative numbers are not palindromes
   int reversedNumber;
   return ReverseAndCheckOverflow (number, &reversedNumber) && (number == reversedNumber);
}
