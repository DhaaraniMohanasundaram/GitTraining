// --------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
//  Dhaarani Mohanasundaram
// --------------------------------------------------------------------------------
// Program.c
// Program on branch A4.
// Program has functions that checks if the phrase is a palindrome or not and
// Reverse the number and then checks for palindrome.
// --------------------------------------------------------------------------------
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

int CheckPhrasePalindrome (const char* phrase) {
   if (phrase == NULL) return 0;   // Not a palindrome
   char onlyAlphaNum[256] = "";
   int j = 0;
   // Filter out non-alphanumeric characters and convert to lowercase
   for (int i = 0; phrase[i] != '\0'; i++) if (isalnum (phrase[i])) onlyAlphaNum[j++] = tolower (phrase[i]);
   onlyAlphaNum[j] = '\0';
   int start = 0;
   int end = j - 1;
   while (start < end) {
      if (onlyAlphaNum[start] != onlyAlphaNum[end]) return 0;   // Not a palindrome
      start++;
      end--;
   }
   return 1;   // Is a palindrome
}

bool ReverseNumber (int number, int* reversedNumber) {
   *reversedNumber = 0;
   while (number > 0) {
      int digit = number % 10;
      // Check for overflow before reversing number
      if (*reversedNumber > (INT_MAX - digit) / 10) return true;   // Indicate overflow
      *reversedNumber = *reversedNumber * 10 + digit;
      number /= 10;
   }
   return false;   // No overflow 
}


bool IsNumPalindrome (int number) {
   if (number < 0) return false;
   int original = number;
   int reversed = 0;
   while (number > 0) {
      int digit = number % 10;
      reversed = reversed * 10 + digit;
      number /= 10;
   }
   return original == reversed;
}