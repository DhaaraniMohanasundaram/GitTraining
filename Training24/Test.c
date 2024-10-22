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
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include "Header.h"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"
#define MAX_SIZE 100

int main () {
   char input[MAX_SIZE];
   while (1) {
      printf ("\nChoose an option:\n"
         "1. Run Test Cases\n"
         "2. Enter User Input\n"
         "3. Exit\n"
         "\nEnter your choice (1-3): ");
      if (fgets (input, sizeof (input), stdin) != NULL) {
         int len = (int) strlen (input);
         if (len > 0 && input[len - 1] != '\n') while (getchar () != '\n');
      }
      int choice = atoi (input);
      switch (choice) {
      case 1:
         ExecuteTestCases ();
         break;
      case 2:
         ExecuteUserInput ();
         break;
      case 3:
         printf (MAGENTA "\n   EXITING THE PROGRAM.....!!\n" RESET);
         return 0;
      default:
         printf ("Invalid choice. Please enter 1 or 2 or 3.\n");
         break;
      }
   }
}

void ExecuteTestCases () {
   int testCases[][MAX_SIZE] = { {1, 2, 3, 4, 5, 6, 7, 8}, {0, -3, 1, 3, 5, 7, -9}, {10, -20, -30, 40, 0},
                                 {3, -3, 3, -3, -3, -3}, {5, 5, 5, 5, 5, 5, 5, 5} },
      expectedSorted[][MAX_SIZE] = { {1, 2, 3, 4, 5, 6, 7, 8}, {-9, -3, 0, 1, 3, 5, 7}, {-30, -20, 0, 10, 40},
                                     {-3, -3, -3, -3, 3, 3}, {5, 5, 5, 5, 5, 5, 5, 5} },
      expectedIndex[][2] = { {4, 3}, {7, 6}, {20, -1}, {3, 4}, {5, 0} },
      sizes[] = { 8, 7, 5, 6, 8 },
      unsortedArr[MAX_SIZE] = { 0 }, sortedArr[MAX_SIZE] = { 0 };
   printf (CYAN "\n\t       -----------------    TEST CASES FOR SORTING AND SEARCHING    -----------------\n" RESET
      "\n\t+-----------------------+-----------------------+----------------+--------------+--------+\n"
      "\t|   UNSORTED   ARRAY    |     SORTED ARRAY      | ELEMENT SEARCH | ACTUAL INDEX | RESULT |\n"
      "\t+-----------------------+-----------------------+----------------+--------------+--------+\n");
   for (int i = 0; i < 5; i++) {
      int n = sizes[i];
      for (int j = 0; j < n; j++) sortedArr[j] = unsortedArr[j] = testCases[i][j];
      BubbleSort (sortedArr, n);
      int searchElement = expectedIndex[i][0];
      int actualIndex = BinarySearch (sortedArr, n, searchElement);
      printf ("\t|  [ ");
      for (int j = 0; j < n; j++) printf ("%d ", unsortedArr[j]);
      printf ("]  | " " [ ");
      for (int j = 0; j < n; j++) printf ("%d ", sortedArr[j]);
      printf ("]  | ");
      bool indexTestPass = (actualIndex == expectedIndex[i][1]);
      bool sortingTestPass = true;
      for (int j = 0; j < n; j++) {
         if (sortedArr[j] != expectedSorted[i][j]) {
            sortingTestPass = false;
            break;
         }
      }
      bool finalPass = indexTestPass && sortingTestPass;
      printf ("  %-12d |  %-11d |  %-14s |\n"
         "\t+-----------------------+-----------------------+----------------+--------------+--------+\n",
         searchElement, actualIndex, finalPass ? GREEN "PASS" RESET : RED "FAIL" RESET);
   }
}

int GetUserInput (const char* input) {
   char buff[MAX_SIZE];
   while (1) {
      printf ("%s", input);
      if (!fgets (buff, sizeof (buff), stdin)) return -1;
      buff[strcspn (buff, "\n")] = 0;
      if (strlen (buff) > 11) {   // 11 for int + sign; checks for too large values
         printf (RED "Invalid input. Please try again.\n" RESET);
         continue;
      }
      char* endptr;
      errno = 0;
      long number = strtol (buff, &endptr, 10);
      if (endptr == buff || *endptr != '\0' || errno == ERANGE || number < INT_MIN || number > INT_MAX) {
         printf (RED "Invalid input (Out of Range or Not a number). Please try again.\n" RESET);
         continue;
      }
      return (int)number;
   }
}

void ExecuteUserInput () {
   int arr[MAX_SIZE] = { 0 }, n = 0, input = 0, unsortedArr[MAX_SIZE] = { 0 };
   char buffer[MAX_SIZE], choice;
   printf (CYAN "\n\t       -----------------    SORTING AND SEARCHING    -----------------\n" RESET);
   while (1) {
      n = GetUserInput ("\nHow many integers would you like to input? (max 100): ");
      if (n <= 0 || n > MAX_SIZE) {
         printf (RED "Invalid number. Please enter a positive integer up to %d.\n" RESET, MAX_SIZE);
         continue;
      }
      for (int i = 0; i < n; i++) {
         input = GetUserInput ("\nEnter integer : ");
         arr[i] = input;
      }
      for (int i = 0; i < n; i++) unsortedArr[i] = arr[i];
      BubbleSort (arr, n);
      printf ("\nUnsorted Array: [ ");
      for (int i = 0; i < n; i++) printf ("%d ", unsortedArr[i]);
      printf ("]\n" "\nSorted Array: [ ");
      for (int i = 0; i < n; i++) printf ("%d ", arr[i]);
      printf ("]\n");
      input = GetUserInput ("\nEnter the element to search: ");
      int searchResult = BinarySearch (arr, n, input);
      printf (searchResult != -1 ? "\nElement %d is found at index %d.\n"
                                 : "\nElement %d is not found in array.\n", input, searchResult);
      while (1) {
         printf ("\nDo you want to continue? (y/n): ");
         if (!fgets (buffer, sizeof (buffer), stdin))  return;
         choice = buffer[0];
         if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N') break;
         else  printf (RED "Invalid input. Please enter 'y' or 'n'.\n" RESET);
      }
      if (choice == 'n' || choice == 'N') {
         printf (BLUE "\n       EXITING USER INPUT.......!!\n" RESET);
         break;
      }
   }
}