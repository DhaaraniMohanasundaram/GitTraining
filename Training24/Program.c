// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// Program.c
// Program on B17 branch.
// Program to print the factorial for the given number. 
// ------------------------------------------------------------------------------------
#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int factorial (int n) {
   if (n < 1 || n > 12) {
      printf ("Please enter a number between 1 and 12.\n");
      return -1;
   }
   int result = 1;
   for (int i = 1; i <= n; i++) result *= i;
   return result;
}

int main () {
   char input[20];
   int n;
   while (true) {
      printf ("\nEnter a number to compute its factorial (between 1 and 12), or 'e/E' to exit: ");
      if (fgets (input, sizeof (input), stdin) != NULL) {
         if (input[0] == 'e' || input[0] == 'E') {
            printf ("Exiting program.\n");
            break;
         }
         int i = 0;
         while (input[i] != '\0' && input[i] != '\n') {
            if (!isdigit (input[i])) {
               printf ("Invalid input. Please enter a valid integer (between 1 and 12).\n");
               break;
            }
            i++;
         }
         if (input[i] == '\n' && sscanf (input, "%d", &n) == 1) if (factorial (n) != -1)
            printf ("%d! = %d\n", n, factorial (n));
      }
      else {
         printf ("Error reading input.\n");
         return 1;
      }
   }
   return 0;
}