// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// CoinReturn.c
// Program on Test2.2 branch.
// ------------------------------------------------------------------------------------
#include "CoinReturn.h"
#include <stdbool.h>

bool CalculateChange (int paidAmount, int actualAmount, int* coinsReturned, int* coins, int numCoins) {
   if (paidAmount == actualAmount) {
      for (int i = 0; i < numCoins; i++) coinsReturned[i] = 0;   // No change needed
      return true;
   }
   if (paidAmount < actualAmount) return false;   // Insufficient amount paid
   int change = paidAmount - actualAmount;
   coinsReturned[0] = change;
   for (int i = 0; i < numCoins; i++) {
      coinsReturned[i + 1] = change / coins[i];
      change %= coins[i];
   }
   return true;   // Change calculated
}