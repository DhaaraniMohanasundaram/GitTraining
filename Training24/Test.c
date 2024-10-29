// ---------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// ----------------------------------------------------------------
// Test.c
// Program on branch A4.
// Implements tests for the phrase or integer for a palindrome.
// ---------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "Header.h"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

/// <summary>Test and print results for palindrome checker with phrases.</summary>
void TestPhrasePalindromes ();

/// <summary>Test and print results for reversed number palindrome.</summary>
void TestReverseNumbers ();

/// <summary>Print the table header for phrase and Integer testcases.</summary>
void PrintTableHeader (enum HeaderType type);

/// <summary>Print a single row in the table for phrase.</summary>
void PhraseTableRow (const char* input, const char* expectedOutput, const char* actualOutput, const char* result);

/// <summary>Print a single row in the table for integer.</summary>
void IntegerTableRow (int number, const char* outputStr, const char* actualOutput, const char* expectedOutput);

/// <summary>Test the user input for phrase palindrome.</summary>
void TestUserPhrase ();

/// <summary>Test the user input for reverse number palindrome.</summary>
void TestUserInteger ();

int main () {
   TestPhrasePalindromes ();
   TestReverseNumbers ();
   printf ("\n1. In Phrase, empty strings and whitespaces are considered as palindrome.\n"
      "2. In Phrase test, non-alphanumeric characters are filtered out.\n"
      "3. In Integers, negative integers are invalid because they're not a palindrome.\n");
   while (1) {
      char option[100];
      printf ("\nMENU - Choose an option:\n1. Test Phrase\n2. Test Integer\n3. Exit\nEnter your choice (1, 2, or 3): ");
      if (!fgets (option, sizeof (option), stdin) || option[0] == '\n') {
         printf ("Invalid choice. Please enter 1, 2, or 3.\n");
         continue;
      }
      char* start = option;
      while (isspace (*start)) start++;
      switch (*start) {
      case '1':
         printf (CYAN "\n\t   -------------  TESTING PHRASE PALINDROME  -------------\n" RESET);
         TestUserPhrase (); break;
      case '2':
         printf (CYAN "\n\t   -------------  TESTING INTEGER PALINDROME  -------------\n" RESET);
         TestUserInteger (); break;
      case '3':
         printf ("\nExiting program.\n"); return 0;
      default:
         printf ("Invalid choice. Please enter 1, 2, or 3.\n"); break;
      }
   }
   return 0;
}

enum HeaderType { Phrase, Integer };
void PrintTableHeader (enum HeaderType type) {
   switch (type) {
   case Phrase:
      printf ("\n\t+----------------------+-------------------+-------------------+--------+\n"
         "\t|  PHRASE - TEST CASE  |  EXPECTED OUTPUT  |   ACTUAL OUTPUT   | RESULT |\n"
         "\t+----------------------+-------------------+-------------------+--------+\n");
      break;
   case Integer:
      printf ("\n\t+---------------------+--------------------------+-------------------+-------------------+--------+\n"
         "\t| INTEGER - TEST CASE |     REVERSED INTEGER     |  EXPECTED OUTPUT  |   ACTUAL OUTPUT   | RESULT |\n"
         "\t+---------------------+--------------------------+-------------------+-------------------+--------+\n");
      break;
   default:
      printf ("\tInvalid header type.\n"); break;
   }
}

void PhraseTableRow (const char* input, const char* expectedOutput, const char* actualOutput, const char* result) {
   printf ("\t| %-20s | %-17s | %-17s | %-15s |\n", input, expectedOutput, actualOutput, result);
   printf ("\t+----------------------+-------------------+-------------------+--------+\n");
}

void IntegerTableRow (int number, const char* outputStr, const char* actualOutput, const char* expectedOutput) {
   const char* resultStr = (strcmp (actualOutput, expectedOutput) == 0) ? GREEN "PASS" RESET : RED "FAIL" RESET;
   printf ("\t| %-19d | %-24s | %-17s | %-17s | %-15s |\n", number, outputStr, actualOutput, expectedOutput, resultStr);
   printf ("\t+---------------------+--------------------------+-------------------+-------------------+--------+\n");
}

void TestPhrasePalindromes () {
   PrintTableHeader (Phrase);
   const char* phrases[] = { "tacOcAT", "hello", "D", "Don't nod", "Race!Car", " ", "22 / 02 / 2022",
      "12345678987654321", "0123456789" },
      * expectedResults[] = { "Palindrome", "Not a Palindrome", "Palindrome", "Palindrome",
      "Palindrome", "Palindrome", "Palindrome", "Palindrome", "Not a Palindrome" };
   for (int i = 0; i < sizeof (phrases) / sizeof (phrases[0]); i++) {
      int isPhrasePalindrome = CheckPhrasePalindrome (phrases[i]);
      const char* actualResult = isPhrasePalindrome ? "Palindrome" : "Not a Palindrome",
         * output = (strcmp (actualResult, expectedResults[i]) == 0) ? GREEN "PASS" RESET : RED "FAIL" RESET;
      PhraseTableRow (phrases[i], expectedResults[i], actualResult, output);
   }
   printf ("\n");
}

void TestReverseNumbers () {
   int testCases[] = { 212, -121, 12345, -9876789, 999999999, 2147447412, 2147483647, -2147483648LL }, reversedNumber;
   const char* expectedOutputs[] = { "Palindrome", "Not a Palindrome", "Not a Palindrome",
      "Not a Palindrome", "Palindrome", "Palindrome", "Failed to process", "Not a Palindrome" };
   PrintTableHeader (Integer);
   for (int i = 0; i < sizeof (testCases) / sizeof (testCases[0]); i++) {
      int number = testCases[i];
      char outputStr[256];
      bool overflow = false;
      if (number < 0) IntegerTableRow (number, "Invalid(Negative number)", "Not a Palindrome", expectedOutputs[i]);
      else {
         overflow = ReverseAndCheckOverflow (number, &reversedNumber);
         if (overflow) {
            strcpy (outputStr, "Integer Overflow");
            IntegerTableRow (number, outputStr, "Failed to process", expectedOutputs[i]);
         }
         else {
            sprintf (outputStr, "%d", reversedNumber);
            const char* actualOutput = IsNumPalindrome (number) ? "Palindrome" : "Not a Palindrome";
            IntegerTableRow (number, outputStr, actualOutput, expectedOutputs[i]);
         }
      }
   }
}

void TestUserPhrase () {
   char userPhrase[500];
   while (1) {
      printf ("\nEnter a phrase to test (max 499 characters, or type 'r' to return menu): ");
      if (fgets (userPhrase, sizeof (userPhrase), stdin) == NULL) {
         printf (YELLOW "Error: Input not received. Exiting function." RESET "\n");
         return;
      }
      userPhrase[strcspn (userPhrase, "\n")] = 0;
      if (strcmp (userPhrase, "r") == 0 || strcmp (userPhrase, "R") == 0) return;   // Return to menu command
      if (strlen (userPhrase) >= sizeof (userPhrase) - 1) {
         printf (YELLOW "Error: Input exceeds maximum length." RESET "\n");
         while (getchar () != '\n' && getchar () != EOF);
         continue;
      }
      else printf ("Result: %s\n", CheckPhrasePalindrome (userPhrase) ? GREEN "It's a Palindrome" RESET : RED "Not a Palindrome" RESET);
   }
}

void TestUserInteger () {
   char userInput[256];
   while (1) {
      printf ("\nEnter a positive integer to test or type 'r' to return: ");
      if (!fgets (userInput, sizeof (userInput), stdin) || userInput[0] == '\n' || userInput == NULL) {
         printf ("Result: %s\n", YELLOW "Invalid input (Empty string)" RESET);
         continue;
      }
      if (strcmp (userInput, "r\n") == 0 || strcmp (userInput, "R\n") == 0) return;   // Return to menu command
      char* endPtr;
      long inputNumber = strtol (userInput, &endPtr, 10);
      if (endPtr == userInput || *endPtr != '\n' || inputNumber < 0) {   // Check if input is valid
         printf ("Result: %s\n", (endPtr == userInput || *endPtr != '\n')
            ? YELLOW "Invalid (Non-integer input)" RESET
            : YELLOW "Invalid (Negative number is not a palindrome)" RESET);
         continue;
      }
      int validNumber = (int)inputNumber,   // Cast to int after valid input
         reversedNumber;
      if (ReverseAndCheckOverflow (validNumber, &reversedNumber)) printf ("Result: %s\n", YELLOW "Integer overflow" RESET);
      else printf ("Output: %d\nResult: %s\n", reversedNumber, IsNumPalindrome (validNumber)
         ? GREEN "It's a Palindrome" RESET
         : RED "Not a Palindrome" RESET);
   }
}