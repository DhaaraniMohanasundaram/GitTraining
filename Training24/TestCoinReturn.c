// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// TestCoinReturn.c
// Program on Test2.2 branch.
// ------------------------------------------------------------------------------------
#include <stdio.h>
#include "CoinReturn.h"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"

void RunTestCases (int* coins, int numCoins) {
   int failedTests = 0;
   struct TestCase {
      int paidAmount;
      int actualAmount;
      int expectedCoins[5]; // {Totalchange + 4coins}
   };
   struct TestCase testCases[] = {
       {50, 30, {20, 2, 0, 0, 0}},
       {130, 112, {18, 1, 1, 1, 1}},
       {30, 27, {3, 0, 0, 1, 1}},
       {245, 210, {35, 3, 1, 0, 0}},
       {100, 100, {0, 0, 0, 0, 0}}
   };
   for (int i = 0; i < sizeof (testCases) / sizeof (testCases[0]); i++) {
      int coinsReturned[5] = { 0 };
      CalculateChange (testCases[i].paidAmount, testCases[i].actualAmount, coinsReturned, coins, numCoins);
      printf ("\nTest %d:\n" "Paid amount: %d, Actual amount: %d\n", i + 1, testCases[i].paidAmount, testCases[i].actualAmount);
      int changeStatus = coinsReturned[0];
      printf ("Return Change: Rs.%d\n" "Coin Denominations: ", changeStatus);
      for (int j = 0; j < numCoins; j++) printf ("Rs.%d: %d, ", coins[j], coinsReturned[j + 1]);
      printf ("\n");
      for (int j = 0; j < numCoins + 1; j++) {
         if (coinsReturned[j] != testCases[i].expectedCoins[j]) {
            failedTests++;
            printf (RED "\nTest %d has Failed.\n" RESET "Expected Change Rs.%d; \nCoin Denominations: ", i + 1, testCases[i].expectedCoins[0]);
            for (int j = 1; j <= numCoins; j++) printf ("Rs.%d: %d, ", coins[j - 1], testCases[i].expectedCoins[j]);
            printf ("\n");
            break; 
         }
      }
   }
   if (failedTests == 0) printf (GREEN "\nAll tests are passed.\n" RESET);
   else printf ("\nTotal Test(s) failed = %d\n", failedTests);
}


int main () {
   int coins[] = { 10, 5, 2, 1 },
      numCoins = sizeof (coins) / sizeof (coins[0]);
   RunTestCases (coins, numCoins);
   return 0;
}