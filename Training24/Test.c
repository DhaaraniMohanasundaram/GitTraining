// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// Test.c
// Program on A5 branch.
// Program that implements test cases and checks the user input for sort & search.
// ------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdbool.h>
#include "Header.h"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"
#define MAX_SIZE 100

/// <summary>Function to clear the newline characters.</summary>
void ClearInputBuffer ();

/// <summary>Function to print the test table row.</summary>
void PrintTestTableRow (const int* unsortedArr, int n, const int* sortedArr, const int* expectedSortedArr, int searchElement, int actualIndex, int expectedIndex);

int main () {
   int choice;

   while (1) {
      printf ("\nChoose an option:\n" "1. Run Test Cases\n" "2. Enter User Input\n" "3. Exit\n" "\nEnter your choice (1-3): ");
      if (scanf ("%d", &choice) != 1) {
         printf ("Invalid input. Please enter a number between 1 and 3.\n");
         ClearInputBuffer ();
         continue;
      }
      switch (choice) {
      case 1:
         ExecuteTestCases ();
         break;
      case 2:
         ExecuteUserInput ();
         break;
      case 3:
         printf ("\nExiting the program...!\n");
         return 0;
      default:
         printf ("Invalid choice. Please enter a number between 1 and 3.\n");
         break;
      }
   }
}


void ExecuteTestCases () {
   int testCases[][MAX_SIZE] = { {1, 2, 3, 4, 5, 6, 7, 8}, {0, -3, 1, 3, 5, 7, -9}, {10, -20, -30, 40, 0}, {3, -3, 3, -3, -3, -3} };
   int expectedSorted[][MAX_SIZE] = { {1, 2, 3, 4, 5, 6, 7, 8}, {-9, -3, 0, 1, 3, 5, 7}, {-30, -20, 0, 10, 40}, {-3, -3, -3, -3, 3, 3} };
   int expectedIndex[][2] = { {4, 3}, {5, 5}, {20, -1}, {3, 4} }; // -1 is element not found
   int sizes[] = { 8, 7, 5, 6 }; // Sizes of each test case
   printf (CYAN "\n\t\t       -----------------    TEST CASES FOR SORTING AND SEARCHING    -----------------\n" RESET);
   printf ("\n\t+-------------------------+------------------------+----------------+--------------+--------+\n");
   printf ("\t|   UNSORTED   ARRAY      |      SORTED ARRAY      | ELEMENT SEARCH | ACTUAL INDEX | RESULT |\n");
   printf ("\t+-------------------------+------------------------+----------------+--------------+--------+\n");
   for (int i = 0; i < 4; i++) {
      int n = sizes[i];
      int unsortedArr[MAX_SIZE] = { 0 };
      for (int j = 0; j < n; j++) unsortedArr[j] = testCases[i][j];
      int sortedArr[MAX_SIZE] = { 0 };
      for (int j = 0; j < n; j++) sortedArr[j] = unsortedArr[j];
      BubbleSort (sortedArr, n);
      int searchElement = expectedIndex[i][0];
      int actualIndex = BinarySearch (sortedArr, n, searchElement);
      PrintTestTableRow (unsortedArr, n, sortedArr, expectedSorted[i], searchElement, actualIndex, expectedIndex[i][1]);
   }
}

void ExecuteUserInput () {
   int arr[MAX_SIZE] = { 0 }, n = 0, input = 0;

   while (1) {
      printf ("\nHow many integers would you like to input? (max %d): ", MAX_SIZE);
      if (scanf ("%d", &n) != 1 || n <= 0 || n > MAX_SIZE) {
         printf ("Invalid number. Please enter a positive integer up to %d.\n", MAX_SIZE);
         ClearInputBuffer ();
         continue;
      }
      for (int i = 0; i < n; i++) {
         printf ("\nEnter integer %d: ", i + 1);
         if (scanf ("%d", &input) != 1) {
            printf ("Invalid input. Please enter integers only.\n");
            ClearInputBuffer ();
            i--;
            continue;
         }
         arr[i] = input;
      }
      int unsortedArr[MAX_SIZE] = { 0 };
      for (int i = 0; i < n; i++) unsortedArr[i] = arr[i];
      BubbleSort (arr, n);
      printf ("\nUnsorted Array: [ ");
      for (int i = 0; i < n; i++) printf ("%d ", unsortedArr[i]);
      printf ("]\n");
      printf ("\nSorted Array: [ ");
      for (int i = 0; i < n; i++) printf ("%d ", arr[i]);
      printf ("]\n");
      printf ("\nEnter the element to search: ");
      if (scanf ("%d", &input) != 1) {
         printf ("Invalid input. Please enter an integer.\n");
         ClearInputBuffer ();
         continue;
      }
      int searchResult = BinarySearch (arr, n, input);
      printf (searchResult != -1 ? "\nElement %d is found at index %d.\n" : "\nElement %d is not found in array.\n", input, searchResult);
      char choice;
      do {
         printf ("\nDo you want to continue? (y/n): ");
         if (scanf (" %c", &choice) != 1) {
            printf ("Invalid input. Please enter 'y' or 'n'.\n");
            ClearInputBuffer ();
            continue;
         }
      } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
      if (choice == 'n' || choice == 'N') {
         printf ("\nExiting the user input testcases...!\n");
         break;
      }
   }
}

void ClearInputBuffer () {
   while (getchar () != '\n'); // Clear until newline
}

void PrintTestTableRow (const int* unsortedArr, int n, const int* sortedArr, const int* expectedSortedArr, int searchElement, int actualIndex, int expectedIndex) {
   printf ("\t| [ ");
   for (int j = 0; j < n; j++) printf ("%d ", unsortedArr[j]);
   printf ("] %-3s | [ ", "  ");
   for (int j = 0; j < n; j++) printf ("%d ", sortedArr[j]);
   printf ("] %-1s | ", "  ");
   bool indexTestPass = (actualIndex == expectedIndex);
   bool sortingTestPass = true;
   for (int j = 0; j < n; j++) {
      if (sortedArr[j] != expectedSortedArr[j]) {
         sortingTestPass = false;
         break;
      }
   }
   bool finalPass = indexTestPass && sortingTestPass;
   printf (" %-13d |  %-11d | %-15s |\n", searchElement, actualIndex, finalPass ? GREEN "PASS" RESET : RED "FAIL" RESET);
   printf ("\t+-------------------------+------------------------+----------------+--------------+--------+\n");
}