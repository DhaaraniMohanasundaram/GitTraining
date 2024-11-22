// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -------------------------------------
//  Dhaarani Mohanasundaram
// -------------------------------------
// Standard Program file in Main
// -------------------------------------
// Program.c
// Program on main branch.
// ------------------------------------------------------------------------------------

#include <stdio.h>

void calculateChange (int cashPaid, int actualAmount) {
   int change = cashPaid - actualAmount;

   if (change < 0) {
      printf ("not enough cash.\n");
      return;
   }
   int coins[4] = { 10, 5, 2, 1 }; 
   int count[4] = { 0 };
   for (int i = 0; i < 4; i++) {
      count[i] = change / coins[i];
      change %= coins[i]; 
   }
   printf ("Change to be retn: Rs.%d\n", cashPaid - actualAmount);
   printf ("10: %d\n" "5: %d\n" "2: %d\n" "1: %d\n", count[0], count[1], count[2], count[3]);
}
