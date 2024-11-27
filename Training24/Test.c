// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
//  Dhaarani Mohanasundaram
// -------------------------------------
// Test.c
// Program on A6 branch.
// ------------------------------------------------------------------------------------
#include <stdio.h>
#include <corecrt.h>
#include <io.h>
#include <fcntl.h>
#include <conio.h>
#include <ctype.h>

#define RESET   "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW   "\033[33m"

extern void DisplayChessboard (FILE* output);

///<summary>Compares two files character by character and checks for differences.</summary>
int CompareFilesContent (FILE* expectedFile, FILE* actualFile, int* row, int* col) {
   wchar_t expectedChar = getwc (expectedFile);
   wchar_t actualChar = getwc (actualFile);
   *row = 1;
   *col = 1;
   while (expectedChar != WEOF && actualChar != WEOF) {
      (*col)++;
      if (expectedChar != actualChar) return -3;  // Mismatch detected
      if (expectedChar == L'\n') {
         (*row)++;
         *col = 1;
      }
      expectedChar = getwc (expectedFile);
      actualChar = getwc (actualFile);
   }
   // Check if both files ended at the same time
   if (expectedChar != actualChar) return (expectedChar != WEOF) ? -1 : -2;

   return 0;  // Files match
}

int main () {
   int outputMode = _setmode (_fileno (stdout), _O_U8TEXT);
   FILE* outputFile;
   FILE* referenceFile;
   errno_t fileError = fopen_s (&outputFile, "ChessboardOutput.txt", "w+,ccs=UTF-8");
   if (fileError != 0) {
      wprintf (L"Failed to open ChessboardOutput.txt for writing.\n");
      return -1;
   }
   DisplayChessboard (outputFile);
   fclose (outputFile);
   wprintf (L"\nWould you like to run a comparison test? (y/n): ");
   char userResponse = _getche ();
   while (tolower (userResponse) != 'y' && tolower (userResponse) != 'n') {
      wprintf (L"\nInvalid choice. Please enter 'y' for yes or 'n' for no: ");
      userResponse = _getche ();
   }
   wprintf (L"\n");
   if (tolower (userResponse) == 'y') {
      fileError = fopen_s (&outputFile, "ChessboardOutput.txt", "r+,ccs=UTF-8");
      if (fileError != 0) {
         wprintf (L"Error opening ChessboardOutput.txt for reading.\n");
         return -1;
      }
      fileError = fopen_s (&referenceFile, "ChessboardReference.txt", "r+,ccs=UTF-8");
      if (fileError != 0) {
         wprintf (L"Error opening ReferenceChessboard.txt.\n");
         fclose (outputFile);
         return -1;
      }
      int rowNumber = 1, columnNumber = 0;
      int compareResult = CompareFilesContent (referenceFile, outputFile, &rowNumber, &columnNumber);
      switch (compareResult) {
      case 0:
         wprintf (GREEN L"Files are identical. TEST PASSED.\n" RESET);
         break;
      case -1: case -3:
         wprintf (RED L"Mismatch found at row %d, col %d.\n" RESET, rowNumber, columnNumber);
         break;
      case -2:
         wprintf (YELLOW L"One file ended prematurely at row %d, col %d.\n" RESET, rowNumber, columnNumber);
         break;
      default:
         wprintf (YELLOW L"Unknown error\n" RESET);
         break;
      }
      fclose (outputFile);
      fclose (referenceFile);
   }
   return 0;
}