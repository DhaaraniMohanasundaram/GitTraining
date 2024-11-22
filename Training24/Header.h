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

#ifndef CHESS_BOARD_HANDLER_H
#define CHESS_BOARD_HANDLER_H

#include <cstdio>

///<summary>Determines the type of piece to be displayed at a given position on the board.</summary>
wchar_t GetPieceAtPosition (int row, int col);

///<summary>Prints the complete chessboard to a specified output stream (file or console).</summary>
void DisplayChessboard (FILE* outputStream);

#endif // CHESS_BOARD_HANDLER_H