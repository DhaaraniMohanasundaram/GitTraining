// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ---------------------------------------------------------------
// Program that tests for the phrase or integer for a palindrome. 
// ----------------------------------------------------------------
// Test.c
// Program on branch A4.
// ------------------------------------------------------------------------------------
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

int main () {
   TestPhrasePalindromes ();
   TestReverseNumbers ();

   char phrase[256];
   char numberStr[256];
   long long number;
   long long reversed;
   int isPalindromeResult;
   int isOverflow;
   char* endPtr;
   // Handle phrase input
   printf ("\nEnter a phrase to test: ");
   fgets (phrase, sizeof (phrase), stdin);
   phrase[strcspn (phrase, "\n")] = 0;
   if (strlen (phrase) == 0) printf ("Result: %s\n", BLUE "Invalid (Empty string)" RESET);
   else {
      int isPhrasePalindrome = CheckPalindrome (phrase);
      printf ("Result: %s\n", isPhrasePalindrome ? GREEN "It's a Palindrome" RESET : RED "Not a Palindrome" RESET);
   }
   // Handle integer input
   printf ("\nEnter an integer to test: ");
   if (fgets (numberStr, sizeof (numberStr), stdin) != NULL) {
      if (strlen (numberStr) == 1 && numberStr[0] == '\n') {
         printf ("Output: %s\n", BLUE "Invalid (Empty string)" RESET);
         printf ("Result: %s\n", YELLOW "Failed to Process" RESET);
      }
      else {
         number = strtoll (numberStr, &endPtr, 10);
         if (*endPtr != '\0' && *endPtr != '\n') {   // Check if the input contains only a newline character or a non-integer input
            printf ("Output: %s\n", BLUE "Invalid (Non-integer input)" RESET);
            printf ("Result: %s\n", YELLOW "Failed to Process" RESET);
         }
         else {
            ReverseNumber (number, &reversed, &isPalindromeResult);
            if (number < 0) {
               printf ("Output: %s\n", CYAN "Invalid (Negative number)" RESET);
               printf ("Result: %s\n", RED "Not a Palindrome" RESET);
            }
            else {
               isOverflow = (number < INT_MIN || number > INT_MAX);
               if (isOverflow) {
                  printf ("Output: %s\n", MAGENTA "Overflow" RESET);
                  printf ("Result: %s\n", YELLOW "Failed to Process" RESET);
               }
               else {
                  printf ("Output: %lld\n", reversed);
                  printf ("Result: %s\n", isPalindromeResult ? GREEN "It's a Palindrome" RESET : RED "Not a Palindrome" RESET);
               }
            }
         }
      }
   }
   else {
      printf ("Output: %s\n", BLUE "Invalid (Input error)" RESET);
      printf ("Result: %s\n", YELLOW "Failed to Process" RESET);
   }
   return 0;
}

/// <summary>Function to print the table header for phrases</summary>
void PhraseTableHeader () {
   printf ("+-------------------------------------+-----------------------+\n");
   printf ("|         Phrase - Test Case          |         Result        |\n");
   printf ("+-------------------------------------+-----------------------+\n");
}

/// <summary>Function to print a single row in the table for phrases</summary>
void PhraseTableRow (const char* input, const char* result) {
   printf ("| %-35s | %-30s |\n", input, result);
   printf ("+-------------------------------------+-----------------------+\n");
}

/// <summary>Function to print a single row in the table for phrases</summary>
void IntegerTableHeader () {
   printf ("+-----------------------+--------------------------+-------------------+\n");
   printf ("|  Integer - Test Case  |        Output            |        Result     |\n");
   printf ("+-----------------------+--------------------------+-------------------+\n");
}

/// <summary>Function to print a single row in the table for phrases</summary>
void IntegerTableRow (long long number, long long output, int isPalindrome, int isOverflow) {
   char outputStr[256];
   if (number < 0) {
      snprintf (outputStr, sizeof (outputStr), "%sInvalid(Negative number)%s", CYAN, RESET);
      printf ("| %-21lld | %-24s | %-26s |\n", number, outputStr, RED "Not a Palindrome" RESET);
   }
   else if (isOverflow) {
      snprintf (outputStr, sizeof (outputStr), "%-13sOverflow%-12s", MAGENTA, RESET);
      printf ("| %-21lld | %-24s | %-18s |\n", number, outputStr, YELLOW "Failed to Process" RESET);
   }
   else {
      snprintf (outputStr, sizeof (outputStr), "%lld", output);
      printf ("| %-21lld | %-24s | %-26s |\n", number, outputStr, isPalindrome ? GREEN "It's a Palindrome" RESET : RED "Not a Palindrome" RESET);
   }
   printf ("+-----------------------+--------------------------+-------------------+\n");
}

void TestPhrasePalindromes () {
   PhraseTableHeader ();
   const char* phrases[] = { "Race Car", "hello", "D", "Don't nod", "", "A man, a Plan, a canal, Panama", "99999999999999999999999999999999999", "22 / 02 / 2022", "No lemon, No Melon", "2136564321540215230549784653214", "123aA32", "2Aba2" };
   for (int i = 0; i < sizeof (phrases) / sizeof (phrases[0]); i++) {
      if (strlen (phrases[i]) == 0) PhraseTableRow (phrases[i], BLUE "Invalid(Empty string)" RESET);
      else {
         int isPhrasePalindrome = CheckPalindrome (phrases[i]);
         PhraseTableRow (phrases[i], isPhrasePalindrome ? GREEN "It's a Palindrome" RESET : RED "Not a Palindrome" RESET);
      }
   }
   printf ("\n\n");
}

void TestReverseNumbers () {
   long long number;
   long long reversed;
   int isPalindromeResult;
   int isOverflow;
   IntegerTableHeader ();
   long long testCases[] = { 212, -121, 12321, -9876789, 2147447412, 2147483647ll, -2147483648ll, 999999999999999999ll, 123454321 };
   for (int i = 0; i < sizeof (testCases) / sizeof (testCases[0]); i++) {
      number = testCases[i];
      ReverseNumber (number, &reversed, &isPalindromeResult);
      isOverflow = (number < INT_MIN || number > INT_MAX);
      IntegerTableRow (number, reversed, isPalindromeResult, isOverflow);
   }
}
