// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// --------------------------------------
// Program.c
// Program on A6 branch.
// Displays chess board and compares files.
// ------------------------------------------------------------------------------------
#include <stdio.h>  

wchar_t PrintPieceAtPosition (int row, int col) {
   const wchar_t* blackPieces[8] = { L"♜", L"♞", L"♝", L"♛", L"♚", L"♝", L"♞", L"♜" },
      * whitePieces[8] = { L"♖", L"♘", L"♗", L"♕", L"♔", L"♗", L"♘", L"♖" };
   return (row == 0) ? blackPieces[col][0] :
      (row == 1) ? L"♟"[0] :
      (row == 6) ? L"♙"[0] :
      (row == 7) ? whitePieces[col][0] :
      L' ';
}

void DisplayChessboard (FILE* outputStream) {
   const wchar_t* topBorder = L"┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓",
      * rowSeparator = L"┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫",
      * bottomBorder = L"┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛";
   fwprintf (outputStream, L"%s\n", topBorder);
   for (int row = 0; row < 8; row++) {
      fwprintf (outputStream, L"┃");
      for (int col = 0; col < 8; col++) {
         wchar_t piece = PrintPieceAtPosition (row, col);
         fwprintf (outputStream, L" %lc ┃", piece);
      }
      fwprintf (outputStream, L"\n");
      if (row != 7) fwprintf (outputStream, L"%s\n", rowSeparator);
   }
   fwprintf (outputStream, L"%s\n", bottomBorder);
}

int CompareFilesContent (FILE* expectedFile, FILE* actualFile, int* row, int* col) {
   fseek (expectedFile, 0, SEEK_END);   // Get the size of both files
   long expectedFileSize = ftell (expectedFile);
   fseek (actualFile, 0, SEEK_END);
   long actualFileSize = ftell (actualFile);
   fseek (expectedFile, 0, SEEK_SET); fseek (actualFile, 0, SEEK_SET);
   if (expectedFileSize != actualFileSize) return -1;   // File size mismatch
   wchar_t expectedChar, actualChar;
   *row = 1;
   *col = 1;
   // Compare content of both files character by character
   while ((expectedChar = getwc (expectedFile)) != WEOF && (actualChar = getwc (actualFile)) != WEOF) {
      if (expectedChar == L'\n' && actualChar == L'\n') continue;   // Ignore extra newlines
      if (expectedChar != actualChar) return -2;   // Mismatch content
      (*col)++;
      if (expectedChar == L'\n') {
         (*row)++;
         *col = 1;
      }
   }
   return 0;   // Files match
}