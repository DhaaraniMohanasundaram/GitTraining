// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// Test.c
// Program on A6 branch.
// Implements comparison test for chess board and also display them in console.
// ------------------------------------------------------------------------------------
#include <corecrt.h>
#include <io.h>
#include <stdio.h>
#include <fcntl.h>
#include <conio.h>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"

extern void DisplayChessboard (FILE* output);
extern int CompareFilesContent (FILE* expectedFile, FILE* actualFile, int* row, int* col);

int main () {
   int outputMode = _setmode (_fileno (stdout), _O_U8TEXT);
   FILE* outputFile, * referenceFile;
   errno_t fileError;
   char userChoice;
   do {
      wprintf (L"\nDo you want to (1)Print the Chessboard, (2)Run a comparison test, or (3)Exit (Enter 1, 2, or 3): ");
      userChoice = _getche ();
      while (userChoice != '1' && userChoice != '2' && userChoice != '3') {
         wprintf (L"\nInvalid choice. Please enter '1' to print the chessboard, '2' to run the comparison test, or '3' to exit: ");
         userChoice = _getche ();
      }
      wprintf (L"\n");
      if (userChoice == '1') {
         if ((fileError = fopen_s (&outputFile, "ChessboardOutput.txt", "w+,ccs=UTF-8")) != 0) {
            wprintf (L"Failed to open ChessboardOutput.txt for writing.\n");
            return -1;
         }
         DisplayChessboard (outputFile);
         fclose (outputFile);
      }
      else if (userChoice == '2') {
         if ((fileError = fopen_s (&outputFile, "ChessboardOutput.txt", "r+,ccs=UTF-8")) != 0 ||
            (fileError = fopen_s (&referenceFile, "ChessboardReference.txt", "r+,ccs=UTF-8")) != 0) {
            wprintf (L"Error opening files.\n");
            return -1;
         }
         int rowNumber = 1, colNumber = 1;
         int result = CompareFilesContent (referenceFile, outputFile, &rowNumber, &colNumber);
         result == 0 ? wprintf (GREEN L"Files are identical. COMPARISON TEST PASSED.\n" RESET) :
            result == -1 || result == -3 ? wprintf (RED L"Mismatch found at row %d, column %d.\n" RESET, rowNumber, colNumber) :
            result == -2 ? wprintf (YELLOW L"File termination occurred early at row %d, column %d.\n" RESET, rowNumber, colNumber) :
            wprintf (YELLOW L"Unknown error.\n" RESET);
         fclose (outputFile);
         fclose (referenceFile);
      }
   } while (userChoice != '3');
   wprintf (L"\nExiting the program...!\n");
   return 0;
}