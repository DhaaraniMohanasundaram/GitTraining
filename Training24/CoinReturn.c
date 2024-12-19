// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// CoinReturn.c
// Program on Test2.2 branch.
// ------------------------------------------------------------------------------------
#include "CoinReturn.h"

void CalculateChange (int paidAmount, int actualAmount, int* coinsReturned, int* coins, int numCoins) {
   if (paidAmount == actualAmount) {
      coinsReturned[0] = 0;   // No change needed
      return;
   }
   if (paidAmount < actualAmount) {
      coinsReturned[0] = -1;   // Insufficient amount paid
      return;
   }
   int change = paidAmount - actualAmount;
   for (int i = 0; i < numCoins; i++) {
      coinsReturned[i + 1] = change / coins[i];
      change = change % coins[i];
   }
   coinsReturned[0] = paidAmount - actualAmount;
}
