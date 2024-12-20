// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
//  Dhaarani Mohanasundaram
// -------------------------------------
// FSM6A.c
// Program on A6b branch.
// ------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/// See File: // FSMDiagram.png

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
   case S1:   // S1: 0/0->S2, 1/0->S7
      if (input == 0) {
         *output = 0;
         return S2;
      }
      else {
         *output = 0;
         return S7;
      }
   case S2:   // S2: 0/0->S2, 1/0->S3
      if (input == 0) {
         *output = 0;
         return S2;
      }
      else {
         *output = 0;
         return S3;
      }
   case S3:   // S3: 0/0->S2, 1/0->S4
      if (input == 0) {
         *output = 0;
         return S2;
      }
      else {
         *output = 0;
         return S4;
      }
   case S4:   // S4: 0/1->S5, 1/0->S6
      if (input == 0) {
         *output = 1;
         return S5;
      }
      else {
         *output = 0;
         return S6;
      }
   case S5:   // S5: 0/0->S2, 1/1->S3
      if (input == 0) {
         *output = 0;
         return S2;
      }
      else {
         *output = 1;
         return S3;
      }
   case S6:   // S6: 0/0->S5, 1/0->S6
      if (input == 0) {
         *output = 0;
         return S5;
      }
      else {
         *output = 0;
         return S6;
      }
   case S7:   // S7: 0/0->S2, 1/0->S6
      if (input == 0) {
         *output = 0;
         return S2;
      }
      else {
         *output = 0;
         return S6;
      }
   default:
      return S1;  // Default return to initial state
   }
}
/// <summary>Function to process the FSM from input file and output to output file.</summary>
int ProcessFSM (FILE* inputFile, FILE* outputFile) {
   State currentState = S1;  // Start in the initial state
   int input, output = 0;
   // Read input from the file and process it until the end of file (EOF)
   while ((input = getc (inputFile)) != EOF) {
      currentState = GetNextMealyState (currentState, input - '0', &output);   // Transition to the next state and calculate the output
      // Write the output value to the output file
      fprintf (outputFile, "%d", output);
   }
   return 0;
}

int main (int argc, char** argv) {
   if (argc != 3) {
      printf ("Usage: %s <input file> <output file>\n", argv[0]);
      return 1;
   }
   FILE* inputFile = fopen (argv[1], "r");
   FILE* outputFile = fopen (argv[2], "w");
   if (inputFile == NULL || outputFile == NULL) {
      printf ("Error opening file.\n");
      return 1;
   }
   State currentState = S1;   // Start in the initial state
   int input, output = 0;
   while (fscanf (inputFile, "%1d", &input) == 1) {
      currentState = GetNextMealyState (currentState, input, &output);
      fprintf (outputFile, "%d", output);
   }
   fclose (inputFile);
   fclose (outputFile);
   return 0;
}