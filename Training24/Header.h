// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// Header.h
// Program on A6 branch.
// A6: Display the chess board with all pieces black and white so it resembles
//     an actual chess board in the console window using Unicode.
// ------------------------------------------------------------------------------------
#pragma once
#pragma warning (disable:4996)
#define CHESS_BOARD_HANDLER_H

#include <cstdio>

///<summary>Determines the type of chess piece to be displayed at a given position on the board.</summary>
wchar_t PrintPieceAtPosition (int row, int col);

///<summary>Prints the complete chessboard to a specified output(file or console).</summary>
void DisplayChessboard (FILE* outputStream);

///<summary>Compares two files character by character and checks for differences.</summary>
int CompareFilesContent (FILE* expectedFile, FILE* actualFile, int* row, int* col);