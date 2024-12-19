// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// TestCoinReturn.c
// Program on Test2.2 branch.
// ------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CoinReturn.h"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"

void TestCoinReturn (int testNumber, int paidAmount, int actualAmount, int expectedCoins[], int* coins, int numCoins) {
   int coinsReturned[5] = { 0 };
   CalculateChange (paidAmount, actualAmount, coinsReturned, coins, numCoins);
   if (coinsReturned[0] == -1) {
      int isCoinsMatch = (expectedCoins[0] == -1);
      printf ("Test %d: %s\nPaid amount: %d, Actual amount: %d; Insufficient amount paid.\n\n",
         testNumber, isCoinsMatch ? GREEN "Passed" RESET : RED "Failed" RESET, paidAmount, actualAmount);
      return;
   }
   int isCoinsMatch = 1;
   for (int i = 0; i < numCoins + 1; i++) {
      if (coinsReturned[i] != expectedCoins[i]) {
         isCoinsMatch = 0;
         break;
      }
   }
   int totalCoins = 0;
   for (int i = 1; i <= numCoins; i++) totalCoins += coinsReturned[i];
   printf ("Test %d: %s\nPaid amount: %d, Actual amount: %d\n" "Change: Rs.%d\nTotal Coins Returned: %d; ", testNumber,
      isCoinsMatch ? GREEN "Passed" RESET : RED "Failed" RESET, paidAmount, actualAmount, coinsReturned[0], totalCoins);
   for (int i = 1; i <= numCoins; i++) printf ("Rs. %d: %d, ", coins[i - 1], coinsReturned[i]);
   printf ("\n\n");
}

void RunRandomTests (int numTests) {
   int coins[] = { 10, 5, 2, 1 }, numCoins = sizeof (coins) / sizeof (coins[0]);
   for (int i = 0; i < numTests; i++) {
      int paidAmount = rand () % 900, isSufficientAmount = rand () % 2, actualAmount;
      if (isSufficientAmount) actualAmount = rand () % (paidAmount + 1);
      else actualAmount = rand () % 250 + paidAmount + 1;
      int expectedCoins[5] = { 0 };
      if (paidAmount < actualAmount) expectedCoins[0] = -1;  // Not enough money
      else {
         int change = paidAmount - actualAmount, coinCount[4] = { 0 };
         for (int j = 0; j < numCoins; j++) {
            coinCount[j] = change / coins[j];
            change = change % coins[j];
         }
         expectedCoins[0] = paidAmount - actualAmount;
         for (int j = 0; j < numCoins; j++) expectedCoins[j + 1] = coinCount[j];
      }
      TestCoinReturn (i + 4, paidAmount, actualAmount, expectedCoins, coins, numCoins);
   }
}

int main () {
   srand ((unsigned int)time (NULL));
   int coins[] = { 10, 5, 2, 1 };
   int numCoins = sizeof (coins) / sizeof (coins[0]);
   // Test Cases as (TestNum, Paid, actual, { change, Rs.10, 5, 2, 1 })
   TestCoinReturn (1, 50, 30, (int[]) { 20, 2, 0, 0, 0 }, coins, numCoins);
   TestCoinReturn (2, 30, 50, (int[]) { -1, 0, 0, 0, 0 }, coins, numCoins);
   TestCoinReturn (3, 100, 100, (int[]) { 0, 0, 0, 0, 0 }, coins, numCoins);
   RunRandomTests (12);
   return 0;
}