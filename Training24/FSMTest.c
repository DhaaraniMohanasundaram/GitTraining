// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// FSMTest.c
// Program on A6b branch.
// ------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS 1

#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"

/// <summary>To run the program with the given input and compare output with expected.</summary>
int RunTestProgram (const char* exeFilePathAndName, const char* inputFilePathAndName, const char* outputFilePathAndName);

/// <summary>To compare two files.</summary>
int CompareFiles (const char* file1, const char* file2);

int RunTestProgram (const char* exeFilePathAndName, const char* inputFilePathAndName, const char* outputFilePathAndName) {
   char* cmdline = malloc (strlen (exeFilePathAndName) + strlen (inputFilePathAndName) + strlen (outputFilePathAndName) + 3);
   if (cmdline == NULL) {
      printf ("Unable to allocate memory\n");
      return 1;
   }
   sprintf (cmdline, "%s %s %s", exeFilePathAndName, inputFilePathAndName, outputFilePathAndName);
   STARTUPINFOA si = { 0 };
   si.cb = sizeof (si);
   PROCESS_INFORMATION pi = { 0 };
   if (!CreateProcessA (NULL, cmdline, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
      printf ("Failed to start process. Error: %lu\n", GetLastError ());
      free (cmdline);
      return 1;
   }
   WaitForSingleObject (pi.hProcess, INFINITE);
   CloseHandle (pi.hProcess);
   CloseHandle (pi.hThread);
   free (cmdline);
   return 0;
}

int CompareFiles (const char* file1, const char* file2) {
   FILE* f1 = fopen (file1, "rb"), * f2 = fopen (file2, "rb");
   if (!f1 || !f2) {
      printf (RED "Error opening files.\n" RESET);
      return 1;
   }
   // Move to the end of the files to check their sizes
   fseek (f1, 0, SEEK_END); fseek (f2, 0, SEEK_END);
   int size1 = ftell (f1), size2 = ftell (f2);
   if (size1 != size2) {
      printf (RED "Error: Files have different sizes. Expected size: %ld, Actual size: %ld.\n" RESET, size2, size1);
      fclose (f1); fclose (f2);
      return 1;
   }
   fseek (f1, 0, SEEK_SET); fseek (f2, 0, SEEK_SET);
   char buffer1, buffer2;
   while ((buffer1 = fgetc (f1)) != EOF && (buffer2 = fgetc (f2)) != EOF) {
      if (buffer1 != buffer2) {
         printf (RED "Error at bit %ld: Expected %c, Actual %c\n" RESET, ftell (f2), buffer2, buffer1);
         fclose (f1); fclose (f2);
         return 1;
      }
   }
   fclose (f1); fclose (f2);
   return 0;  // Files are identical
}

int main (int argc, char** argv) {
   if (argc != 2) {
      printf ("Usage: %s <FSM executable name>\n", argv[0]);
      return -1;
   }
   const char* inputFiles[] = { "TData/Test1in.txt", "TData/Test2in.txt", "TData/Test3in.txt", "TData/Test4in.txt",
                                "TData/Test5in.txt", "TData/Test6in.txt", "TData/Test7in.txt", "TData/Test8in.txt" },
      * expectedFiles[] = { "TData/Test1ref.txt", "TData/Test2ref.txt", "TData/Test3ref.txt", "TData/Test4ref.txt",
                            "TData/Test5ref.txt", "TData/Test6ref.txt", "TData/Test7ref.txt", "TData/Test8ref.txt" },
      * outputFile = "tempOutput.txt";
   int numTests = sizeof (inputFiles) / sizeof (inputFiles[0]);
   for (int i = 0; i < numTests; i++) {
      printf ("\nRunning test %d with input file: %s\n", i + 1, inputFiles[i]);
      if (RunTestProgram (argv[1], inputFiles[i], outputFile) != 0) {
         printf (RED "Test %d failed to execute.\n" RESET, i + 1);
         break;  // Exit immediately if the test fails to execute
      }
      if (CompareFiles (outputFile, expectedFiles[i]) != 0) {
         printf (RED "\nTest %d has failed!\n" RESET "Expected Output: ", i + 1);
         FILE* expectedFilePtr = fopen (expectedFiles[i], "r");
         if (expectedFilePtr) {
            char ch;
            while ((ch = fgetc (expectedFilePtr)) != EOF) putchar (ch);
            fclose (expectedFilePtr);
         }
         printf ("\nActual   Output: ");
         FILE* actualFilePtr = fopen (outputFile, "r");
         if (actualFilePtr) {
            char ch;
            while ((ch = fgetc (actualFilePtr)) != EOF) putchar (ch);
            fclose (actualFilePtr);
         }
         printf ("\n");
         remove (outputFile);
         return 1;  // Exit immediately after the first failure
      }
   }
   remove (outputFile);
   printf (GREEN "\nAll TestCases are passed!!\n" RESET);
   return 0;
}