// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// CoinReturn.c
// Program on Test2.2 branch.
// ------------------------------------------------------------------------------------
#include <stdio.h>
#include "CoinReturn.h"

void calculateChange (int paidAmount, int actualAmount) {
   if (paidAmount < actualAmount) {
      printf ("Insufficient amount paid.\n");
      return;
   }
   int change = paidAmount - actualAmount;
   int coins[] = { 10, 5, 2, 1 };
   int coinCount[4] = { 0 };
   for (int i = 0; i < 4; i++) {
      coinCount[i] = change / coins[i];
      change = change % coins[i];
   }
   if (paidAmount == actualAmount) {
      printf ("Change to be returned: 0\n");
      return;
   }
   printf ("Change to be returned: %d\n", paidAmount - actualAmount);
   int totalCoins = 0;
   for (int i = 0; i < 4; i++) {
      if (coinCount[i] > 0) {
         printf ("%d x Rs.%d\n", coinCount[i], coins[i]);
         totalCoins += coinCount[i];
      }
   }
   printf ("Total coins returned: %d\n", totalCoins);
}
