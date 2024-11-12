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
void TestPalindromes ();

/// <summary>Test and print results for reversed number palindrome.</summary>
void TestReversal ();

/// <summary>Print the table header for phrase and Integer testcases.</summary>
void PrintTableHeader (enum HeaderType type);

/// <summary>Print a single row in the table for phrase.</summary>
void PrintPhraseTableRow (const char* input, const char* expectedOutput, const char* actualOutput, const char* result);

/// <summary>Print a single row in the table for integer.</summary>
void PrintIntegerTableRow (int number, const char* outputStr, const char* actualOutput, const char* expectedOutput, const char* testCase);

/// <summary>Test the user input for phrase palindrome.</summary>
void GetUserPhrase ();

/// <summary>Test the user input for reverse number palindrome.</summary>
void GetUserInteger ();

int main () {
   TestPalindromes ();
   TestReversal ();
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
      while (*start && isspace (*start)) start++;
      char* end = start + strlen (start) - 1;
      while (end > start && isspace (*end)) end--;
      *(end + 1) = '\0';
      if (strlen (start) == 1 && (*start == '1' || *start == '2' || *start == '3')) {
         int choice = *start - '0';
         switch (choice) {
         case 1:
            printf (CYAN "\n   -------------  TESTING PHRASE PALINDROME  -------------\n" RESET);
            GetUserPhrase (); break;
         case 2:
            printf (CYAN "\n   -------------  TESTING INTEGER PALINDROME  -------------\n" RESET);
            GetUserInteger (); break;
         case 3:
            printf ("\nExiting program.\n"); return 0;
         default: break;
         }
      }
      else printf ("Invalid choice. Please enter 1, 2, or 3.\n");
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

void PrintPhraseTableRow (const char* input, const char* expectedOutput, const char* actualOutput, const char* result) {
   printf ("\t| %-20s | %-17s | %-17s | %-15s |\n", input, expectedOutput, actualOutput, result);
   printf ("\t+----------------------+-------------------+-------------------+--------+\n");
}

void PrintIntegerTableRow (int number, const char* outputStr, const char* expectedOutput, const char* actualOutput, const char* testCase) {
   const char* resultStr = (strcmp (actualOutput, expectedOutput) == 0) ? GREEN "PASS" RESET : RED "FAIL" RESET;
   printf ("\t| %-19s | %-24s | %-17s | %-17s | %-15s |\n", testCase, outputStr, expectedOutput, actualOutput, resultStr);
   printf ("\t+---------------------+--------------------------+-------------------+-------------------+--------+\n");
}

void TestPalindromes () {
   PrintTableHeader (Phrase);
   const char* phrases[] = { "tacOcAT", "hello", "D", "Don't nod", "Race!Car", " ", "22 / 02 / 2022",
                             "12345678987654321", "0123456789" },
      * expectedResults[] = { "Palindrome", "Not a Palindrome", "Palindrome", "Palindrome",
                              "Palindrome", "Palindrome", "Palindrome", "Palindrome", "Not a Palindrome" };
   for (int i = 0; i < sizeof (phrases) / sizeof (phrases[0]); i++) {
      const char* actualResult = IsPhrasePalindrome (phrases[i]) ? "Palindrome" : "Not a Palindrome",
         * output = !strcmp (actualResult, expectedResults[i]) ? GREEN "PASS" RESET : RED "FAIL" RESET;
      PrintPhraseTableRow (phrases[i], expectedResults[i], actualResult, output);
   }
   printf ("\n");
}

void TestReversal () {
   const char* testCases[] = { "212", "-121", "123.45", "-9876789", "999999999", "2147447412",
                               "2147483647", "-2147483648", "123abc" },
      * expectedOutputs[] = { "Palindrome", "Not a Palindrome", "Not a Palindrome", "Not a Palindrome", "Palindrome",
                              "Palindrome", "Failed to process", "Not a Palindrome", "Not a Palindrome" };
   PrintTableHeader (Integer);
   for (int i = 0; i < sizeof (testCases) / sizeof (testCases[0]); i++) {
      char outputStr[256];
      int number;
      bool overflow = false;
      char* endPtr;
      number = strtol (testCases[i], &endPtr, 10);
      if (*endPtr != '\0') {
         strcpy (outputStr, "Invalid(Non Integer)");
         const char* actualOutput = "Not a Palindrome";
         PrintIntegerTableRow (0, outputStr, expectedOutputs[i], actualOutput, testCases[i]);
      }
      else {
         if (number < 0) {
            strcpy (outputStr, "Invalid(Negative number)");
            const char* actualOutput = "Not a Palindrome";
            PrintIntegerTableRow (number, outputStr, expectedOutputs[i], actualOutput, testCases[i]);
         }
         else {
            overflow = ReverseAndCheckOverflow (number, &number);
            if (!overflow) {
               strcpy (outputStr, "Integer Overflow");
               const char* actualOutput = "Failed to process";
               PrintIntegerTableRow (number, outputStr, expectedOutputs[i], actualOutput, testCases[i]);
            }
            else {
               sprintf (outputStr, "%d", number);
               const char* actualOutput = IsIntPalindrome (number) ? "Palindrome" : "Not a Palindrome";
               PrintIntegerTableRow (number, outputStr, expectedOutputs[i], actualOutput, testCases[i]);
            }
         }
      }
   }
}

void GetUserPhrase () {
   char userPhrase[500];
   while (1) {
      printf ("\nEnter a phrase to test (max 499 characters, or type 'r' or 'R' to return menu): ");
      if (fgets (userPhrase, sizeof (userPhrase), stdin) == NULL) {
         printf (YELLOW "Error: Input not received. Exiting function." RESET "\n");
         return;
      }
      userPhrase[strcspn (userPhrase, "\n")] = 0;
      if (!strcmp (userPhrase, "r") || !strcmp (userPhrase, "R")) return;
      if (strlen (userPhrase) >= sizeof (userPhrase) - 1) {
         printf (YELLOW "Error: Input exceeds maximum length." RESET "\n");
         while (getchar () != '\n' && getchar () != EOF);
         continue;
      }
      if (strlen (userPhrase) == 0) {
         printf ("Result: %s\n", GREEN "It's a Palindrome" RESET);
         continue;
      }
      printf ("Result: %s\n", IsPhrasePalindrome (userPhrase)
         ? GREEN "It's a Palindrome" RESET
         : RED "Not a Palindrome" RESET);
   }
}

void GetUserInteger () {
   char userInput[256];
   while (1) {
      printf ("\nEnter a positive integer to test or type 'r' or 'R' to return menu: ");
      if (!fgets (userInput, sizeof (userInput), stdin) || userInput[0] == '\n' || userInput == NULL) {
         printf ("Result: %s\n", YELLOW "Invalid input (Empty string)" RESET);
         continue;
      }
      if (!strcmp (userInput, "r\n") || !strcmp (userInput, "R\n") ) return;   // Return to menu command
      char* endPtr;
      int inputNumber = strtol (userInput, &endPtr, 10);
      if (endPtr == userInput || *endPtr != '\n' || inputNumber < 0) {
         printf ("Result: %s\n", (endPtr == userInput || *endPtr != '\n')
            ? YELLOW "Invalid (Non-integer input)" RESET
            : YELLOW "Invalid (Negative number is not a palindrome)" RESET);
         continue;
      }
      int reversedNumber;
      if (!ReverseAndCheckOverflow (inputNumber, &reversedNumber)) printf ("Result: %s\n", YELLOW "Integer overflow" RESET);
      else printf ("Output: %d\nResult: %s\n", reversedNumber, IsIntPalindrome (inputNumber)
         ? GREEN "It's a Palindrome" RESET
         : RED "Not a Palindrome" RESET);
   }
}