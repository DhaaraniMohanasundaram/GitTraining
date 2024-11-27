// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
//  Dhaarani Mohanasundaram
// --------------------------------------
// Program.c
// Program on A6 branch.
// ------------------------------------------------------------------------------------
#include <stdio.h>

wchar_t GetPieceAtPosition (int row, int col) {
   const wchar_t* chessBoard[8][8] = {
       {L"♜", L"♞", L"♝", L"♛", L"♚", L"♝", L"♞", L"♜"},
       {L"♟", L"♟", L"♟", L"♟", L"♟", L"♟", L"♟", L"♟"},
       {L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "},
       {L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "},
       {L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "},
       {L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "},
       {L"♙", L"♙", L"♙", L"♙", L"♙", L"♙", L"♙", L"♙"},
       {L"♖", L"♘", L"♗", L"♕", L"♔", L"♗", L"♘", L"♖"}
   };
   return chessBoard[row][col][0];
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
         wchar_t piece = GetPieceAtPosition (row, column);
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