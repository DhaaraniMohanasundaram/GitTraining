// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// FSM6A.c
// Program on A6b branch.
// ------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/// See File: // FSMDiagram.png for State Transition diagram

typedef enum {
   S1,  // Initial state
   S2,  // After '0' or sequence transition
   S3,  // After specific transitions
   S4,  // Pattern recognition state
   S5,  // Transition state after '0'
   S6,  // Pattern continuation state
   S7   // Alternative path state
} State;

/// <summary>Function to get the next state and output based on the current state and input.</summary>
State GetNextMealyState (State currentState, int input, int* output) {
   switch (currentState) {
   case S1: *output = 0; return (input == 0) ? S2 : S7;
   case S2: *output = 0; return (input == 0) ? S2 : S3;
   case S3: *output = 0; return (input == 0) ? S2 : S4;
   case S4: *output = !input; return (input == 0) ? S5 : S6;
   case S5: *output = (input == 0) ? 0 : 1; return (input == 0) ? S2 : S3;
   case S6: *output = 0; return (input == 0) ? S5 : S6;
   case S7: *output = 0; return (input == 0) ? S2 : S6;
   default:  printf ("Error: Invalid input encountered. Exiting.\n"); exit (1);
   }
}

/// <summary>Function to process the FSM from input file and output to output file.</summary>
int ProcessFSM (FILE* inputFile, FILE* outputFile) {
   State currentState = S1;
   int input, output = 0;
   for (input = getc (inputFile); input != EOF; input = getc (inputFile)) {
      if (input == '0' || input == '1')  currentState = GetNextMealyState (currentState, input - '0', &output);
      else output = 0; // Non-binary characters output '0'
      fprintf (outputFile, "%d", output);
   }
   return 0;
}

int main (int argc, char** argv) {
   if (argc != 3) {
      printf ("Usage: %s <input file> <output file>\n", argv[0]);
      return 1;
   }
   // Open input and output files
   FILE* inputFile = fopen (argv[1], "r"), * outputFile = fopen (argv[2], "w");
   if (inputFile == NULL || outputFile == NULL) {
      printf ("Error opening file.\n");
      return 1;
   }
   ProcessFSM (inputFile, outputFile);
   fclose (inputFile);
   fclose (outputFile);
   return 0;
}