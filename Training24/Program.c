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
#include <stdbool.h>
#include <limits.h>

bool CheckPhrasePalindrome (const char* phrase) {
   if (phrase == NULL) return 0;   // Not a palindrome
   char onlyAlphaNum[256] = "";
   int j = 0, start = 0, end = j - 1;
   // Filter out non-alphanumeric characters and convert to lowercase
   for (int i = 0; phrase[i] != '\0'; i++) if (isalnum (phrase[i])) onlyAlphaNum[j++] = tolower (phrase[i]);
   onlyAlphaNum[j] = '\0';
   while (start < end) {
      if (onlyAlphaNum[start] != onlyAlphaNum[end]) return false;
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
      if (*reversedNumber > (INT_MAX - digit) / 10) return true;   // Indicate overflow during reversal
      *reversedNumber = *reversedNumber * 10 + digit;
      number /= 10;
   }
   return false; // No overflow
}

bool IsNumPalindrome (int number) {
   if (number < 0) return false; // Negative numbers are not palindromes
   int reversedNumber;
   return !ReverseAndCheckOverflow (number, &reversedNumber) && (number == reversedNumber);
}