// -------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -------------------------------------
//  Dhaarani Mohanasundaram
// ------------------------------------------------------------------------------------------------
// Program has functions that checks if the phrase is a palindrome or not and reverse the integer.
// -------------------------------------------------------------------------------------------------
// Program.c
// Program on branch A4.
// -------------------------------------------------------------------------------------------------
#include <string.h>
#include <ctype.h>
#include <limits.h>

int CheckPalindrome (const char* phrase) {
   if (phrase == NULL || *phrase == '\0') return -1;   // An empty string or NULL is not considered as palindrome
   int start = 0;
   int end = strlen (phrase) - 1;
   while (start < end) {
      while (start < end && !isalnum (phrase[start])) start++;
      while (start < end && !isalnum (phrase[end])) end--;
      if (tolower (phrase[start]) != tolower (phrase[end])) return 0;   // Not a Palindrome
      start++;
      end--;
   }
   return 1;   // Is a Palindrome
}

void ReverseNumber (long long number, long long* reversed, int* isPalindromeResult) {
   long long temp = number;
   long long rev = 0;
   int isOverflow = 0;
   // Handle negative numbers
   if (number < 0) {
      *reversed = LLONG_MIN;
      *isPalindromeResult = 0;   // Negative numbers are not palindromes
      return -1;
   }
   while (temp != 0) {
      if (rev > (LLONG_MAX - (temp % 10)) / 10) {
         isOverflow = 1;
         break;
      }
      rev = rev * 10 + (temp % 10);
      temp /= 10;
   }
   *reversed = isOverflow ? LLONG_MAX : rev;
   *isPalindromeResult = (isOverflow || (number == rev));
}