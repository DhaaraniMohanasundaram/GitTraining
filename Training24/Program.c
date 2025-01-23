// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// Program.c
// Program on B7 branch.
// Program to print a diamond using an asterisk.
// ------------------------------------------------------------------------------------
#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void PrintDiamond (int rows) {
   printf ("\n");
   for (int i = 1; i <= rows; i++) {
      for (int j = i; j < rows; j++) printf (" ");
      for (int j = 1; j <= (2 * i - 1); j++) printf ("*");
      printf ("\n");
   }
   for (int i = rows - 1; i >= 1; i--) {
      for (int j = rows; j > i; j--) printf (" ");
      for (int j = 1; j <= (2 * i - 1); j++) printf ("*");
      printf ("\n");
   }
}

void RunTestCase (int rows) {
   printf ("Test case for rows = %d:\n", rows);
   PrintDiamond (rows);
   printf ("\n----------------------------\n");
}

int main () {
   RunTestCase (14);
   RunTestCase (29);
   int rows;
   printf ("\nEnter the number of rows (half the height of the diamond): ");
   scanf_s ("%d", &rows);
   PrintDiamond (rows);
   return 0;
}