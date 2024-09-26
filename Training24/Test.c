// ---------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// ----------------------------------------------------------------
// Test.c
// Program on branch A4.
// Program that implements tests for the phrase or integer for a palindrome.
// ---------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Header.h"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

/// <summary>Function to print the table header for Phrase Testcases.</summary>
void PhraseTableHeader ();

/// <summary>Function to print a single row in the table for phrase.</summary>
void PhraseTableRow (const char* input, const char* result);

/// <summary>Function to print the table header for Integer Testcases.</summary>
void IntegerTableHeader ();

/// <summary>Function to print a single row in the table for integer.</summary>
void IntegerTableRow (int number, const char* outputStr, bool isPalindrome);

/// <summary>Function to test the user input for phrase palindrome.</summary>
void TestUserPhrase ();

/// <summary>Function to test the user input for reverse number palindrome.</summary>
void TestUserInteger ();

/// <summary>Function to clear the new line input characters.</summary>
void clearInputBuffer ();

int main () {
   TestPhrasePalindromes ();
   TestReverseNumbers ();
   printf ("\n1. In Phrase, empty strings are considered as palindrome.\n2. In Integers, negative integers are not considered as a palindrome.\n");

   while (1) {
      int choice;
      char option[100];
      printf ("\nChoose an option:\n1. Test Phrase\n2. Test Integer\n3. Exit\nEnter your choice (1 or 2 or 3): ");
      if (!fgets (option, sizeof (option), stdin) || option[0] == '\n' || sscanf (option, "%d", &choice) != 1 || choice < 1 || choice > 3) {
         printf ("Invalid choice. Please enter 1, 2, or 3.\n");
         continue;
      }
      switch (choice) {
      case 1:
         TestUserPhrase ();
         break;
      case 2:
         TestUserInteger ();
         break;
      case 3:
         printf ("Exiting program.\n");
         return 0;
      }
   }
   return 0;
}

void PhraseTableHeader () {
   printf ("+-------------------------------------+-------------------+\n");
   printf ("|         Phrase - Test Case          |       Result      |\n");
   printf ("+-------------------------------------+-------------------+\n");
}

void PhraseTableRow (const char* input, const char* result) {
   printf ("| %-35s | %-26s |\n", input, result);
   printf ("+-------------------------------------+-------------------+\n");
}

void IntegerTableHeader () {
   printf ("+-----------------------+--------------------------+-------------------+\n");
   printf ("|  Integer - Test Case  |        Output            |       Result      |\n");
   printf ("+-----------------------+--------------------------+-------------------+\n");
}

void IntegerTableRow (int number, const char* outputStr, bool isPalindrome) {
   const char* resultStr;
   if (strcmp (outputStr, "Integer Overflow") == 0) resultStr = YELLOW "Failed to process" RESET;
   else resultStr = isPalindrome ? GREEN "It's a Palindrome" RESET : RED "Not a Palindrome" RESET;
   printf ("| %-21d | %-24s | %-26s |\n", number, outputStr, resultStr);
   printf ("+-----------------------+--------------------------+-------------------+\n");
}


void TestPhrasePalindromes () {
   PhraseTableHeader ();
   const char* phrases[] = { "Race!Car", "hello", "D", "Don't nod", "A man, a Plan, a canal, Panama",
      " ","22 / 02 / 2022", "12345654321" };
   for (int i = 0; i < sizeof (phrases) / sizeof (phrases[0]); i++) {
      int isPhrasePalindrome = CheckPhrasePalindrome (phrases[i]);
      PhraseTableRow (phrases[i], isPhrasePalindrome ? GREEN "It's a Palindrome" RESET : RED "Not a Palindrome" RESET);
   }
   printf ("\n\n");
}

void TestReverseNumbers () {
   IntegerTableHeader ();
   int testCases[] = { 212, -121, 123421, -9876789, 2147447412, 2147483647, -2147483648LL, 999999999 };
   for (int i = 0; i < sizeof (testCases) / sizeof (testCases[0]); i++) {
      int number = testCases[i];
      if (number < 0) IntegerTableRow (number, "Invalid(Negative number)", false);
      else {
         int reversedNumber;
         bool overflow = ReverseAndCheckOverflow (number, &reversedNumber);
         char outputStr[256];
         if (overflow) IntegerTableRow (number, "Integer Overflow", false);
         else {
            sprintf (outputStr, "%d", reversedNumber);
            bool isPalindrome = (number == reversedNumber);
            IntegerTableRow (number, outputStr, isPalindrome);
         }
      }
   }
}

void clearInputBuffer () {
   while (getchar () != '\n');
}

void TestUserPhrase () {
   char phrase[256];
   printf ("\nEnter a phrase to test: ");
   fgets (phrase, sizeof (phrase), stdin);
   phrase[strcspn (phrase, "\n")] = 0;
   printf ("Result: %s\n", phrase[0] == '\0' ? GREEN "It's a Palindrome" RESET :
      CheckPhrasePalindrome (phrase) ? GREEN "It's a Palindrome" RESET : RED "Not a Palindrome" RESET);
}

void TestUserInteger () {
   long inputNumber;
   char userInput[256];
   while (1) {
      printf ("\nEnter a positive integer to test: ");
      if (!fgets (userInput, sizeof (userInput), stdin) || userInput[0] == '\n' || userInput == NULL) {
         printf ("Result: %s\n", YELLOW "Invalid input (Empty string)" RESET);
         continue;
      }
      char* endPtr;
      inputNumber = strtol (userInput, &endPtr, 10);
      if (endPtr == userInput || *endPtr != '\n' || inputNumber < 0) {
         printf ("Result: %s\n", (endPtr == userInput || *endPtr != '\n') ?
            YELLOW "Invalid (Non-integer input)" RESET :
            YELLOW "Invalid (Negative number is not a palindrome)" RESET);
         continue;
      }
      else {
         int validNumber = (int)inputNumber; // Cast to int after valid input
         int reversedNumber;
         bool overflow = ReverseAndCheckOverflow (validNumber, &reversedNumber);
         if (overflow) printf ("Result: %s\n", YELLOW "Invalid (Out of range)" RESET);
         else {
            bool isPalindrome = IsNumPalindrome (validNumber);
            printf ("Output: %d\nResult: %s\n", reversedNumber,
               isPalindrome ? GREEN "It's a Palindrome" RESET : RED "Not a Palindrome" RESET);
            break;
         }
      }
   }
}


