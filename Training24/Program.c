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
   const wchar_t blackPieces[] = { L'\u265C', L'\u265E', L'\u265D', L'\u265B', L'\u265A' }, // Rook, Knight, Bishop, Queen, King
      whitePieces[] = { L'\u2656', L'\u2658', L'\u2657', L'\u2655', L'\u2654' },
      blackPawn = L'\u265F', whitePawn = L'\u2659';
   if (row == 0) return blackPieces[col == 0 || col == 7 ? 0 : col == 1 || col == 6 ? 1 : col == 2 || col == 5 ? 2 : col == 3 ? 3 : 4];
   return (row == 1) ? blackPawn : (row == 6) ? whitePawn : (row == 7) ? whitePieces[col == 0 || col == 7 ? 0 : col == 1 ||
      col == 6 ? 1 : col == 2 || col == 5 ? 2 : col == 3 ? 3 : 4] : L' ';
}

void DisplayChessboard (FILE* outputStream) {
   const wchar_t* topBorder = L"┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓",
      * rowSeparator = L"┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫",
      * bottomBorder = L"┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛";
   fwprintf (outputStream, L"%s\n", topBorder);
   wprintf (L"%s\n", topBorder);
   for (int row = 0; row < 8; row++) {
      wprintf (L"┃");
      fwprintf (outputStream, L"┃");
      for (int column = 0; column < 8; column++) {
         wchar_t piece = PrintPieceAtPosition (row, column);
         wprintf (L" %lc ┃", piece);
         fwprintf (outputStream, L" %lc ┃", piece);
      }
      wprintf (L"\n");
      fwprintf (outputStream, L"\n");
      if (row != 7) {
         fwprintf (outputStream, L"%s\n", rowSeparator);
         wprintf (L"%s\n", rowSeparator);
      }
   }
   fwprintf (outputStream, L"%s\n", bottomBorder);
   wprintf (L"%s\n", bottomBorder);
}

int CompareFilesContent (FILE* expectedFile, FILE* actualFile, int* row, int* col) {
   wchar_t expectedChar, actualChar;
   *row = 1;
   *col = 1;
   while ((expectedChar = getwc (expectedFile)) != WEOF && (actualChar = getwc (actualFile)) != WEOF) {
      if (expectedChar != actualChar) return -3;  // Mismatch detected
      (*col)++;
      if (expectedChar == L'\n') {
         (*row)++;
         *col = 1;
      }
   }
   return (getwc (expectedFile) != WEOF) ? -1 : (getwc (actualFile) != WEOF) ? -2 : 0;  // Early termination or Files match
}