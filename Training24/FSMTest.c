// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
//  Dhaarani Mohanasundaram
// -------------------------------------
// FSMTest.c
// Program on A6b branch.
// ------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS 1
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

/// <summary>Function to run the program with the given input and compare output with expected.</summary>
int RunTestProgram (const char* exeFilePathAndName, const char* inputFilePathAndName, const char* outputFilePathAndName);

/// <summary>Function to compare two files.</summary>
int CompareFiles (const char* file1, const char* file2);

int RunTestProgram (const char* exeFilePathAndName, const char* inputFilePathAndName, const char* outputFilePathAndName) {
   char* cmdline = malloc (strlen (exeFilePathAndName) + strlen (inputFilePathAndName) + strlen (outputFilePathAndName) + 3);
   if (cmdline == NULL) {
      printf ("Unable to allocate memory\n");
      return 1;
   }
   sprintf (cmdline, "%s %s %s", exeFilePathAndName, inputFilePathAndName, outputFilePathAndName);
   STARTUPINFOA si;
   PROCESS_INFORMATION pi;
   ZeroMemory (&si, sizeof (si));
   si.cb = sizeof (si);
   ZeroMemory (&pi, sizeof (pi));
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
   FILE* f1 = fopen (file1, "r"), * f2 = fopen (file2, "r");
   if (!f1 || !f2) {
      printf ("Error opening files.\n");
      return 1;
   }
   int pos = 0, ch1, ch2;
   while ((ch1 = fgetc (f1)) != EOF && (ch2 = fgetc (f2)) != EOF) {
      if (ch1 != ch2) {
         printf ("Error at bit no. %d, Expected %c, Actual %c\n", pos, ch1, ch2);
         fclose (f1);
         fclose (f2);
         return 1;
      }
      pos++;
   }
   fclose (f1);
   fclose (f2);
   return 0;
}

int main (int argc, char** argv) {
#define NTESTS 8
   if (argc != 2) {
      printf ("Usage: %s <FSM executable name>\n", argv[0]);
      return -1;
   }
   const char* inputFiles[] = { "Test1in.txt", "Test2in.txt", "Test3in.txt", "Test4in.txt", "Test5in.txt",
      "Test6in.txt", "Test7in.txt", "Test8in.txt" },
      * outputFiles[] = { "Test1out.txt", "Test2out.txt", "Test3out.txt", "Test4out.txt", "Test5out.txt",
      "Test6out.txt", "Test7out.txt", "Test8out.txt"},
      * expectedFiles[] = { "Test1ref.txt", "Test2ref.txt", "Test3ref.txt", "Test4ref.txt", "Test5ref.txt",
      "Test6ref.txt", "Test7ref.txt", "Test8ref.txt" };
   for (int i = 0; i < NTESTS; i++) {
      const char* inputFile = inputFiles[i], * outputFile = outputFiles[i], * expectedFile = expectedFiles[i];
      printf ("Running test %d with input file: %s\n", i + 1, inputFile);
      if (RunTestProgram (argv[1], inputFile, outputFile) != 0) {
         printf ("Test %d failed to execute.\n", i + 1);
         continue;
      }
      // Compare the output with the expected reference file
      if (CompareFiles (outputFile, expectedFile) == 0) printf ("Test %d passed. Output matches expected result.\n\n", i + 1);
      else printf ("Test %d failed. Output does not match expected result.\n\n", i + 1);
   }
   return 0;
}