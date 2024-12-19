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
#include <stdbool.h>
#include <conio.h> 
#include "Header.h"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"
#define MAX_SIZE 100

/// <summary>Run test for sortiing array.</summary>
void TestSorting ();

/// <summary>Run test for searching element in sorted array.</summary>
void TestSearching ();

/// <summary>Gets valid user input.</summary>
int GetUserInput (const char* input);

/// <summary>Sorts and search for user input.</summary>
void SortAndSearchUserInput ();

int main () {
   char choice;
   while (1) {
      printf ("\nChoose an option:\n"
         "1. Run Test Cases\n"
         "2. Enter User Input\n"
         "3. Exit\n"
         "\nEnter your choice (1-3): ");
      choice = getche ();
      printf ("\n");
      switch (choice) {
      case '1': TestSorting (); TestSearching (); break;
      case '2': SortAndSearchUserInput (); break;
      case '3': printf (MAGENTA "\n   EXITING THE PROGRAM.....!!\n" RESET); return 0;
      default: printf (RED "\nInvalid choice. Please enter 1, 2, or 3.\n" RESET); break;
      }
   }
}

void TestSorting () {
   int testCases[][MAX_SIZE] = {
      {1, 2, 3, 4, 5, 6, 7, 8},
      {0, -3, 1, 3, 5, 7, -9},
      {10, -20, -30, 40, 0},
      {3, -3, 3, -3, -3, -3},
      {5, 5, 5, 5, 5, 5, 5, 5},
   },
   arrSizes[] = { 8, 7, 5, 6, 8 };
   printf (CYAN "\n   ----- TEST CASES FOR SORTING -----\n" RESET);
   for (int i = 0; i < 5; i++) {
      int size = arrSizes[i];
      printf ("\nUnsorted Array: [ ");
      for (int j = 0; j < size; j++) printf ("%d ", testCases[i][j]);
      printf ("]\n");
      BubbleSort (testCases[i], size);
      printf ("Sorted Array: [ ");
      for (int j = 0; j < size; j++) printf ("%d ", testCases[i][j]);
      printf ("]\n");
      for (int k = 0; k < size - 1; k++) {
         if (testCases[i][k] > testCases[i][k + 1]) {
            printf (RED "Array is NOT sorted.\n" RESET);
            break;
         }
      }
      printf (GREEN"Array is sorted.\n"RESET);
   }
}

void TestSearching () {
   int testCases[][MAX_SIZE] = {
       {1, 2, 3, 4, 5, 6, 7, 8},
       {0, -3, 1, 3, 5, 7, -9},
       {10, -20, -30, 40, 0},
       {3, -3, 3, -3, -3, -3},
       {5, 5, 5, 5, 5, 5, 5, 5}
   },
      arrSizes[] = { 8, 7, 5, 6, 8 },
      expectedIndex[] = { 5, -1, 1, 4, 0 },
      searchElements[] = { 6, -8, -20, 3, 5 };
   printf (CYAN "\n   ----- TEST CASES FOR SEARCHING -----\n" RESET);
   for (int i = 0; i < 5; i++) {
      int size = arrSizes[i],
         searchElement = searchElements[i];
      BubbleSort (testCases[i], size);
      printf ("\nSorted Array: [ ");
      for (int j = 0; j < size; j++) printf ("%d ", testCases[i][j]);
      printf ("]\n");
      int actualIndex = BinarySearch (testCases[i], size, searchElement);
      printf ("Search Element: %d\n" "Actual Index: %d\n", searchElement, actualIndex);
      printf ("Result: %s\n", actualIndex == expectedIndex[i] ? GREEN "PASS" RESET : RED "FAIL" RESET);
   }
}

int GetUserInput (const char* input) {
   char buff[MAX_SIZE];
   while (true) {
      printf ("%s", input);
      if (!fgets (buff, sizeof (buff), stdin)) return -1;
      char* endptr;
      errno = 0;
      int number = strtol (buff, &endptr, 10);
      if (endptr == buff || *endptr != '\n' || errno == ERANGE) {
         printf (RED "Invalid input (Out of Range or Not a number). Please try again.\n" RESET);
         continue;
      }
      return number;
   }
}

void SortAndSearchUserInput () {
   int arr[MAX_SIZE] = { 0 }, arrSize = 0, searchElement = 0;
   char choice;
   printf (CYAN "\n          -----------------    SORTING AND SEARCHING    -----------------\n" RESET);
   while (1) {
      arrSize = GetUserInput ("\nHow many integers would you like to input? (max 100): ");
      if (arrSize <= 0 || arrSize > MAX_SIZE) {
         printf (RED "Invalid number. Please enter a positive integer up to %d.\n" RESET, MAX_SIZE);
         continue;
      }
      for (int i = 0; i < arrSize; i++) arr[i] = GetUserInput ("\nEnter integer: ");
      printf ("\nUnsorted Array: [ ");
      for (int i = 0; i < arrSize; i++) printf ("%d ", arr[i]);
      BubbleSort (arr, arrSize);
      printf ("]\n\nSorted Array: [ ");
      for (int i = 0; i < arrSize; i++) printf ("%d ", arr[i]);
      printf ("]\n");
      searchElement = GetUserInput ("\nEnter the element to search: ");
      int searchResult = BinarySearch (arr, arrSize, searchElement);
      printf (searchResult != -1 ? "\nElement %d is found at index %d.\n" : "\nElement %d is not found in array.\n", searchElement, searchResult);
      while (1) {
         printf ("\nDo you want to continue? (y/n): ");
         choice = getche ();
         printf ("\n");
         switch (choice) {
         case 'y': case 'Y': break;
         case 'n': case 'N': printf (BLUE "\nEXITING USER INPUT.......!!\n" RESET); return;
         default: printf (RED "Invalid input. Please enter only 'y' or 'n'.\n" RESET); continue;
         }
         break;
      }
   }
}