// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// Test.c
// Program on A6 branch.
// Implements comparison test for chess board and also display them in console.
// ------------------------------------------------------------------------------------
#include <io.h>
#include <stdio.h>
#include <fcntl.h>
#include <conio.h>

#define RESET L"\033[0m"
#define GREEN L"\033[32m"
#define RED L"\033[31m"
#define YELLOW L"\033[33m"

extern void DisplayChessboard (FILE* output);
extern int CompareFilesContent (FILE* expectedFile, FILE* actualFile, int* row, int* col);

int main () {
   // Set the console to output UTF-8 characters
   if (_setmode (_fileno (stdout), _O_U8TEXT) == -1) {
      wprintf (RED L"Error setting the output mode to UTF-8.\n" RESET);
      return 1;
   }
   char userChoice;
   do {
      wprintf (L"\nChoose an option:\n1. Print Chessboard in console \n2. Generate file and Run Comparison Test\n3. Exit\nEnter 1, 2, or 3: ");
      userChoice = _getche ();
      wprintf (L"\n");
      switch (userChoice) {
      case '1': {   // Print Chessboard to console
         DisplayChessboard (stdout);
         break;
      }
      case '2': {   // Generate file and Run Comparison Test
         FILE* outputFile, * referenceFile;
         if (fopen_s (&outputFile, "ChessboardOutput.txt", "w, ccs=UTF-8") == 0) {
            DisplayChessboard (outputFile);
            fclose (outputFile);
         }
         else {
            wprintf (RED L"Failed to open ChessboardOutput.txt for writing.\n" RESET);
            break;
         }
         // Run the comparison test
         if (fopen_s (&outputFile, "ChessboardOutput.txt", "r, ccs=UTF-8") != 0 ||
            fopen_s (&referenceFile, "ChessboardReference.txt", "r, ccs=UTF-8") != 0) {
            wprintf (RED L"Error opening files for comparison.\n" RESET);
            break;
         }
         int row = 0, col = 0;
         if (CompareFilesContent (referenceFile, outputFile, &row, &col) == 0)
            wprintf (GREEN L"Files are identical. COMPARISON TEST PASSED.\n" RESET);
         else wprintf (RED L"Files have different length or content. COMPARISON TEST FAILED.\n" RESET);
         fclose (outputFile); fclose (referenceFile);
         break;
      }
      case '3': wprintf (L"\nExiting...\n"); break;
      default: wprintf (RED L"Invalid choice, try again.\n" RESET);
      }
   } while (userChoice != '3');
   return 0;
}