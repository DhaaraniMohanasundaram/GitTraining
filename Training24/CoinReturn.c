// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// CoinReturn.c
// Program on Test2.2 branch.
// ------------------------------------------------------------------------------------
#include "CoinReturn.h"

void CalculateChange (int paidAmount, int actualAmount, int* coinsReturned) {
   if (paidAmount < actualAmount) {
      coinsReturned[0] = -1;   // Insufficient amount paid
      return;
   }
   int change = paidAmount - actualAmount,
      coins[] = { 10, 5, 2, 1 },
      coinCount[4] = { 0 };
   for (int i = 0; i < 4; i++) {
      coinCount[i] = change / coins[i];
      change = change % coins[i];
   }
   if (paidAmount == actualAmount) {
      coinsReturned[0] = 0;   // No change needed
      return;
   }
   coinsReturned[0] = paidAmount - actualAmount;
   for (int i = 0; i < 4; i++) coinsReturned[i + 1] = coinCount[i];
}