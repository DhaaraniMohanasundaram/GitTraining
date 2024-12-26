// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// TicTacToe.c
// Program on Test3.2 branch.
// TicTacToe.c: Implements a two-player Tic-Tac-Toe game.
// ------------------------------------------------------------------------------------
#pragma warning (disable:4996)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define WIN 1
#define CONTINUE 0
#define DRAW -1

/// <summary>To clear the console screen.</summary>
void ClearScreen () {
#ifdef _WIN32
   system ("cls");
#endif
}

/// <summary>To print the TicTacToe game board.</summary>
void PrintBoard (char board[BOARD_SIZE][BOARD_SIZE], int isReferenceBoard) {
   int num = 1;
   for (int i = 0; i < BOARD_SIZE; i++) {
      for (int j = 0; j < BOARD_SIZE; j++) {
         if (isReferenceBoard && board[i][j] == ' ') printf (" %d ", num++);   // Prints reference board with moves
         else printf (" %c ", board[i][j]);
         if (j < BOARD_SIZE - 1) printf ("|");
      }
      printf ("\n");
      if (i < BOARD_SIZE - 1) printf ("---+---+---\n");
   }
   printf ("\n");
}

/// <summary>Checks for win, draw, or continue the game.</summary>
int CheckGameStatus (char board[BOARD_SIZE][BOARD_SIZE], char player) {
   for (int i = 0; i < BOARD_SIZE; i++) {
      if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
         (board[0][i] == player && board[1][i] == player && board[2][i] == player))
         return WIN;   // Check rows and columns for a win
   }
   if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
      (board[0][2] == player && board[1][1] == player && board[2][0] == player))
      return WIN;   // Check diagonals for a win
   for (int i = 0; i < BOARD_SIZE; i++)
      for (int j = 0; j < BOARD_SIZE; j++)
         if (board[i][j] == ' ') return CONTINUE;   // Check if there are any empty spaces left to continue
   return DRAW;
}

/// <summary>Gets a valid move from the player.</summary> 
int GetValidMove (char board[BOARD_SIZE][BOARD_SIZE], char player) {
   char input[10];
   int move;
   while (true) {
      printf ("\nPlayer %c, enter a move (1-9): ", player);
      fgets (input, sizeof (input), stdin);
      int i = 0;
      while (input[i] == '0' || input[i] == '+') i++;   // Skip leading zeros or plus signs
      char* endptr;
      move = strtol (&input[i], &endptr, 10);
      if (*endptr == '\n' && move >= 1 && move <= 9) {
         if (board[(move - 1) / BOARD_SIZE][(move - 1) % BOARD_SIZE] == ' ') return move;
         else printf ("That spot is already taken! Please choose another spot.\n");
      }
      else printf ("Invalid input! Please enter a number between 1 and 9.\n");
   }
}

/// <summary>Starts two player TicTacToe game.</summary>
void StartGame () {
   char board[BOARD_SIZE][BOARD_SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} }, gameMessage[50], currentPlayer = 'X';
   int move, gameStatus;
   printf ("Reference board with available moves (1-9):\n");
   PrintBoard (board, true);
   while (true) {
      move = GetValidMove (board, currentPlayer);
      board[(move - 1) / BOARD_SIZE][(move - 1) % BOARD_SIZE] = currentPlayer;
      ClearScreen ();
      PrintBoard (board, false);
      gameStatus = CheckGameStatus (board, currentPlayer);
      if (gameStatus != CONTINUE) {
         snprintf (gameMessage, sizeof (gameMessage), gameStatus == WIN ? "Player %c wins..!!" : "It's a draw!", currentPlayer);
         printf ("%s\n", gameMessage);
         break;
      }
      currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
   }
}

int main () {
   StartGame ();
   return 0;
}