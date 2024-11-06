// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// Test.c
// Program on A5 branch.
// Implements test cases and checks the user input for sort & search in integer array.
// ------------------------------------------------------------------------------------
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Header.h"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"
#define MAX_SIZE 100

/// <summary>Runs few testcases automatically.</summary>
void TestCases ();

/// <summary>Sorts and search for user input.</summary>
void ExecuteUserInput ();

int main () {
   char input[MAX_SIZE];
   while (1) {
      printf ("\nChoose an option:\n"
         "1. Run Test Cases\n"
         "2. Enter User Input\n"
         "3. Exit\n"
         "\nEnter your choice (1-3): ");
      if (fgets (input, sizeof (input), stdin) != NULL) {
         int len = (int)strlen (input);
         if (len > 0 && input[len - 1] != '\n') while (getchar () != '\n');
      }
      int choice = atoi (input);
      switch (choice) {
      case 1: TestCases (); break;
      case 2: ExecuteUserInput (); break;
      case 3: printf (MAGENTA "\n\tEXITING THE PROGRAM.....!!\n" RESET); return 0;
      default: printf ("Invalid choice. Please enter 1 or 2 or 3.\n"); break;
      }
   }
}

void TestCases () {
   int testCases[][MAX_SIZE] = { {1, 2, 3, 4, 5, 6, 7, 8}, {0, -3, 1, 3, 5, 7, -9}, {10, -20, -30, 40, 0},
                                 {3, -3, 3, -3, -3, -3}, {5, 5, 5, 5, 5, 5, 5, 5} },
      expectedSorted[][MAX_SIZE] = { {1, 2, 3, 4, 5, 6, 7, 8}, {-9, -3, 0, 1, 3, 5, 7}, {-30, -20, 0, 10, 40},
                                     {-3, -3, -3, -3, 3, 3}, {5, 5, 5, 5, 5, 5, 5, 5} },
      expectedIndex[][2] = { {4, 3}, {7, 6}, {20, -1}, {3, 4}, {5, 0} },
      sizes[] = { 8, 7, 5, 6, 8 },
      sortedArr[MAX_SIZE] = { 0 };
   printf (CYAN "\n\t       -----------------    TEST CASES FOR SORTING AND SEARCHING    -----------------\n" RESET
      "\n\t+-----------------------+-----------------------+----------------+--------------+--------+\n"
      "\t|    UNSORTED  ARRAY    |     SORTED  ARRAY     | ELEMENT SEARCH | ACTUAL INDEX | RESULT |\n"
      "\t+-----------------------+-----------------------+----------------+--------------+--------+\n");
   for (int i = 0; i < 5; i++) {
      int n = sizes[i], searchElement = expectedIndex[i][0], k = 0;
      for (int j = 0; j < n; j++) sortedArr[j] = testCases[i][j];
      BubbleSort (sortedArr, n);
      int actualIndex = BinarySearch (sortedArr, n, searchElement);
      for (k = 0; k < n; k++) if (sortedArr[k] != expectedSorted[i][k]) break;
      printf ("\t|  [ ");
      for (int j = 0; j < n; j++) printf ("%d ", testCases[i][j]);
      printf ("]  |  [ ");
      for (int j = 0; j < n; j++) printf ("%d ", sortedArr[j]);
      printf ("]  |  %-13d |  %-11d |  %-14s |\n",
               searchElement, actualIndex,
               k == n && actualIndex == expectedIndex[i][1] ? GREEN "PASS" RESET : RED "FAIL" RESET);
      printf ("\t+-----------------------+-----------------------+----------------+--------------+--------+\n");
   }
}

int GetUserInput (const char* input) {
   char buff[MAX_SIZE];
   while (1) {
      printf ("%s", input);
      if (!fgets (buff, sizeof (buff), stdin)) return -1;
      buff[strcspn (buff, "\n")] = 0;
      char* endptr;
      errno = 0;
      int number = strtol (buff, &endptr, 10);
      if (endptr == buff || *endptr != '\0' || errno == ERANGE) {
         printf (RED "Invalid input (Out of Range or Not a number). Please try again.\n" RESET);
         continue;
      }
      return number;
   }
}

void ExecuteUserInput () {
   int arr[MAX_SIZE] = { 0 }, n = 0, input = 0;
   char buffer[MAX_SIZE], choice;
   printf (CYAN "\n\t       -----------------    SORTING AND SEARCHING    -----------------\n" RESET);
   while (1) {
      n = GetUserInput ("\nHow many integers would you like to input? (max 100): ");
      if (n <= 0 || n > MAX_SIZE) {
         printf (RED "Invalid number. Please enter a positive integer up to %d.\n" RESET, MAX_SIZE);
         continue;
      }
      for (int i = 0; i < n; i++) arr[i] = GetUserInput ("\nEnter integer: ");
      printf ("\nUnsorted Array: [ ");
      for (int i = 0; i < n; i++) printf ("%d ", arr[i]);
      BubbleSort (arr, n);
      printf ("]\n\nSorted Array: [ ");
      for (int i = 0; i < n; i++) printf ("%d ", arr[i]);
      printf ("]\n");
      input = GetUserInput ("\nEnter the element to search: ");
      int searchResult = BinarySearch (arr, n, input);
      printf (searchResult != -1 ? "\nElement %d is found at index %d.\n" : "\nElement %d is not found in array.\n", input, searchResult);
      while (1) {
         printf ("\nDo you want to continue? (y/n): ");
         if (!fgets (buffer, sizeof (buffer), stdin)) return;
         buffer[strcspn (buffer, "\n")] = 0;
         int i = 0;
         while (isspace (buffer[i])) {
            i++;
         }
         if ((buffer[i] == 'y' || buffer[i] == 'Y' || buffer[i] == 'n' || buffer[i] == 'N') && buffer[i + 1] == '\0') {
            choice = buffer[i];
            break;  // Valid input, exit the loop
         }
         printf (RED "Invalid input. Please enter only a single 'y' or 'n'.\n" RESET);
      }
      if (choice == 'n' || choice == 'N') {
         printf (BLUE "\n\tEXITING USER INPUT.......!!\n" RESET);
         break;
      }
   }
}
