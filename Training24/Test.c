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

// ANSI escape codes for color styling in console
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"

// Function declaration from external file
extern void DisplayChessboard (FILE* outputStream);

///<summary>Compares two files character by character and checks if they match.</summary>
static int CompareFiles (FILE* refFile, FILE* outputFile, int* rowNum, int* colNum) {
   wchar_t refChar = getwc (refFile);
   wchar_t outputChar = getwc (outputFile);
   *rowNum = 1;
   *colNum = 0;

   // Compare the files character by character
   while (refChar != WEOF && outputChar != WEOF) {
      (*colNum)++;
      if (refChar != outputChar) return -3;  // Mismatch found

      // If newline is encountered, move to the next row
      if (refChar == L'\n') {
         (*rowNum)++;
         *colNum = 0;
      }

      // Fetch next characters from both files
      refChar = getwc (refFile);
      outputChar = getwc (outputFile);
   }

   // Check if both files reached the end at the same time
   if (refChar != outputChar) return (refChar != WEOF) ? -1 : -2;

   return 0;  // Files match
}

int main () {
   // Set stdout to use UTF-8 encoding
   int k = _setmode (_fileno (stdout), _O_U8TEXT);
   FILE* outputStream;
   FILE* refFile;

   // Open output file for writing chessboard content
   errno_t error = fopen_s (&outputStream, "ChessboardOutput.txt", "w+,ccs=UTF-8");
   if (error != 0) {
      wprintf (L"Error opening ChessboardOutput.txt for writing\n");
      return -1;
   }
   fwprintf (outputStream, L"Generating Chessboard...\n");
   DisplayChessboard (outputStream);
   fclose (outputStream);

   wprintf (L"\nWould you like to run a test case? (y/n): ");
   char userChoice = _getch ();
   if (tolower (userChoice) == 'y') {
      // Open the output file for reading
      error = fopen_s (&outputStream, "ChessboardOutput.txt", "r+,ccs=UTF-8");
      if (error != 0) {
         wprintf (L"Error opening ChessboardOutput.txt for reading\n");
         return -1;
      }
      // Open reference file for comparison
      error = fopen_s (&refFile, "ChessboardReference.txt", "r+,ccs=UTF-8");
      if (error != 0) {
         wprintf (L"Error opening ChessboardReference.txt\n");
         fclose (outputStream);
         return -1;
      }
      // Initialize row and column to track comparison position
      int rowNum = 1, colNum = 0;
      int comparisonResult = CompareFiles (refFile, outputStream, &rowNum, &colNum);
      switch (comparisonResult) {
      case 0:
         wprintf (GREEN L"Files match! TEST PASSED\n" RESET);
         break;
      case -1: case -3:
         wprintf (RED L"Mismatch at row %d, col %d.\n" RESET, rowNum, colNum);
         break;
      case -2:
         wprintf (YELLOW L"One file ended prematurely at row %d, col %d.\n" RESET, rowNum, colNum);
         break;
      default:
         wprintf (YELLOW L"Unknown error at row %d, col %d.\n" RESET, rowNum, colNum);
         break;
      }
      fclose (outputStream);
      fclose (refFile);
   }
   return 0;
}