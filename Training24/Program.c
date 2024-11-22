// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
//  Dhaarani Mohanasundaram
// --------------------------------------
// Program.c
// Program on A6 branch.
// ------------------------------------------------------------------------------------



#include <stdio.h>

//wchar_t GetPieceAtPosition (int row, int col) {
//   // Create a 2D array of wide characters representing the chessboard pieces for black and white
//   // Using chess piece symbols instead of letters
//   const wchar_t* chessBoard[8][8] = {
//       {L"♜", L"♞", L"♝", L"♛", L"♚", L"♝", L"♞", L"♜"}, // Black pieces row (row 0)
//       {L"♟", L"♟", L"♟", L"♟", L"♟", L"♟", L"♟", L"♟"}, // Black pawns row (row 1)
//       {L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "},    // Empty row (row 2)
//       {L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "},    // Empty row (row 3)
//       {L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "},    // Empty row (row 4)
//       {L" ", L" ", L" ", L" ", L" ", L" ", L" ", L" "},    // Empty row (row 5)
//       {L"♙", L"♙", L"♙", L"♙", L"♙", L"♙", L"♙", L"♙"}, // White pawns row (row 6)
//       {L"♖", L"♘", L"♗", L"♕", L"♔", L"♗", L"♘", L"♖"}  // White pieces row (row 7)
//   };
//
//   // Return the appropriate piece based on the row and column
//   return chessBoard[row][col][0];  // Return as wchar_t (single wide character)
//}    //works well but pawn grid differs


//char GetPieceAtPosition (int row, int col) {
//   // Create a 2D array to represent the chessboard pieces for black and white
//   // For black pieces, use uppercase letters for clarity.
//   char chessBoard[8][8] = {
//       {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}, // Black pieces row (row 0)
//       {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, // Black pawns row (row 1)
//       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // Empty row (row 2)
//       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // Empty row (row 3)
//       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // Empty row (row 4)
//       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // Empty row (row 5)
//       {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'}, // White pawns row (row 6)
//       {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}  // White pieces row (row 7)
//   };
//
//   // Check if the row is between 0 and 7
//   if (row >= 0 && row <= 7) {
//      if (row == 1 || row == 6) {
//         // Handle pawn pieces (use 'P' and 'p' for Black and White pawns respectively)
//         return chessBoard[row][col];
//      }
//      else if (row == 0 || row == 7) {
//         // Handle pieces on the back rows (Black pieces are uppercase and White pieces are lowercase)
//         return chessBoard[row][col];
//      }
//   }
//   return ' '; // Return empty space for other rows
//}   //printed perfectly but letters 



//wchar_t GetPieceAtPosition (int row, int col) {
//   // Handle black pieces on the first two rows
//   if (row == 0) {  // Black pieces at row 0
//      switch (col) {
//      case 0: case 7: return L'\u265C';  // Black Rook
//      case 1: case 6: return L'\u265E';  // Black Knight
//      case 2: case 5: return L'\u265D';  // Black Bishop
//      case 3: return L'\u265B';          // Black Queen
//      case 4: return L'\u265A';          // Black King
//      default: return L' ';              // Empty space (shouldn't occur)
//      }
//   }
//   else if (row == 1) return L'\u265F';  // Black Pawn
//   else if (row == 6) return L'\u2659';  // White Pawn
//   else if (row == 7) {                  // White pieces at row 7
//      switch (col) {
//      case 0: case 7: return L'\u2656';  // White Rook
//      case 1: case 6: return L'\u2658';  // White Knight
//      case 2: case 5: return L'\u2657';  // White Bishop
//      case 3: return L'\u2655';          // White Queen
//      case 4: return L'\u2654';          // White King
//      default: return L' ';              // Empty space (shouldn't occur)
//      }
//   }
//   return L' '; // Return empty space for other rows
//}

void DisplayChessboard (FILE* outputStream) {
   // Print top border
   wprintf (L"┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n");
   fwprintf (outputStream, L"┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n");

   // Loop through the chessboard to print each piece
   for (int row = 0; row < 8; row++) {
      for (int column = 0; column < 8; column++) {
         wchar_t piece = GetPieceAtPosition (row, column);
         wprintf (L"┃ %lc ", piece);          // Print piece to console
         fwprintf (outputStream, L"┃ %lc ", piece);  // Print piece to file
      }
      wprintf (L"┃ \n");
      fwprintf (outputStream, L"┃ \n");
      // Add separator lines between rows, except for the last row
      if (row != 7) {
         wprintf (L"┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n");
         fwprintf (outputStream, L"┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n");
      }
   }
   // Print bottom border
   wprintf (L"┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛\n");
   fwprintf (outputStream, L"┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛\n");
}