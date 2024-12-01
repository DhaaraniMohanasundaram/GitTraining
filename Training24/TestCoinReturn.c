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

void TestCoinReturn (int testNumber, int paidAmount, int actualAmount, int expectedCoins[]) {
   int coinsReturned[5] = { 0 };
   CalculateChange (paidAmount, actualAmount, coinsReturned);
   if (coinsReturned[0] == -1) {
      int isCoinsMatch = (expectedCoins[0] == -1);
      printf ("Test %d: %s\nPaid amount: %d, Actual amount: %d; Insufficient amount paid.\n" "\n",
         testNumber, isCoinsMatch ? GREEN "Passed" RESET : RED "Failed" RESET, paidAmount, actualAmount);
      return;
   }
   int isCoinsMatch = 1;
   for (int i = 0; i < 5; i++) {
      if (coinsReturned[i] != expectedCoins[i]) {
         isCoinsMatch = 0;
         break;
      }
   }
   int totalCoins = coinsReturned[1] + coinsReturned[2] + coinsReturned[3] + coinsReturned[4];
   printf ("Test %d: %s\nPaid amount: %d, Actual amount: %d\n"
      "Change: Rs.%d\nTotal Coins Returned: %d; Rs. 10: %d, Rs. 5: %d, Rs. 2: %d, Rs. 1: %d\n" "\n",
      testNumber, isCoinsMatch ? GREEN "Passed" RESET : RED "Failed" RESET, paidAmount, actualAmount,
      coinsReturned[0], totalCoins, coinsReturned[1], coinsReturned[2], coinsReturned[3], coinsReturned[4]);
}

void RunRandomTests (int numTests) {
   int coins[] = { 10, 5, 2, 1 };
   for (int i = 0; i < numTests; i++) {
      int paidAmount = rand () % 901 + 100,
         isSufficientAmount = rand () % 2,
         actualAmount;
      if (isSufficientAmount) actualAmount = rand () % (paidAmount + 1);
      else actualAmount = rand () % 250 + paidAmount + 1;
      int expectedCoins[5] = { 0 };
      if (paidAmount < actualAmount) expectedCoins[0] = -1;
      else {
         int change = paidAmount - actualAmount,
            coinCount[4] = { 0 };
         for (int j = 0; j < 4; j++) {
            coinCount[j] = change / coins[j];
            change = change % coins[j];
         }
         expectedCoins[0] = paidAmount - actualAmount;
         for (int j = 0; j < 4; j++) expectedCoins[j + 1] = coinCount[j];
      }
      TestCoinReturn (i + 4, paidAmount, actualAmount, expectedCoins);
   }
}

int main () {
   srand (time (0));
   TestCoinReturn (1, 50, 30, (int[]) { 20, 2, 0, 0, 0 });
   TestCoinReturn (2, 30, 50, (int[]) { -1, 0, 0, 0, 0 });
   TestCoinReturn (3, 100, 100, (int[]) { 0, 0, 0, 0, 0 });
   RunRandomTests (12);
   return 0;
}