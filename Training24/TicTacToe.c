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

#define BOARD_SIZE 3
#define WIN 1
#define CONTINUE 0
#define DRAW -1

/// <summary>To print the TicTacToe game board.</summary>
void PrintBoard (char board[BOARD_SIZE][BOARD_SIZE]) {
   for (int i = 0; i < BOARD_SIZE; i++) {
      for (int j = 0; j < BOARD_SIZE; j++) {
         printf (" %c ", board[i][j]);
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
   // Check rows and columns for a win
      if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
         (board[0][i] == player && board[1][i] == player && board[2][i] == player))
         return WIN;
   }
   // Check diagonals for a win
   if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
      (board[0][2] == player && board[1][1] == player && board[2][0] == player))
      return WIN;
   for (int i = 0; i < BOARD_SIZE; i++)   // Check if there are any empty spaces left if so game continues
      for (int j = 0; j < BOARD_SIZE; j++) if (board[i][j] == ' ') return CONTINUE;
   return DRAW;   // No space left
}

/// <summary>Gets a valid move from the player.</summary> 
int GetValidMove (char board[BOARD_SIZE][BOARD_SIZE], char player) {
   char input[10];
   int move;
   while (true) {
      printf ("\nPlayer %c, enter a move (1-9): ", player);
      fgets (input, sizeof (input), stdin);
      if (input[0] < '1' || input[0] > '9' || input[1] != '\0' && input[1] != '\n') {
         printf ("Invalid input! Please enter a number between 1 and 9.\n");
         continue;
      }
      move = input[0] - '0';
      int row = (move - 1) / BOARD_SIZE, col = (move - 1) % BOARD_SIZE;
      if (board[row][col] == ' ') return move;   // Check if the selected spot is available then move
      printf ("That spot is already taken! Please choose another spot.\n");
   }
}

/// <summary>Starts two player TicTacToe game.</summary>
void StartGame () {
   char board[BOARD_SIZE][BOARD_SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} }, gameMessage[50], currentPlayer = 'X';
   int move, gameStatus;
   while (true) {
      PrintBoard (board);
      move = GetValidMove (board, currentPlayer);
      int row = (move - 1) / BOARD_SIZE, col = (move - 1) % BOARD_SIZE; 
      board[row][col] = currentPlayer;
      gameStatus = CheckGameStatus (board, currentPlayer);
      if (gameStatus == WIN) {
         snprintf (gameMessage, sizeof (gameMessage), "Player %c wins!", currentPlayer);
         break;  //  End the game
      }
      if (gameStatus == DRAW) {
         snprintf (gameMessage, sizeof (gameMessage), "It's a draw!");
         break;
      }
      currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';   // Switch to the other player
   }
   PrintBoard (board);
   printf ("%s\n", gameMessage);
}

int main () {
   StartGame ();
   return 0;
}