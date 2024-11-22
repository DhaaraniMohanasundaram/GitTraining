// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// -------------------------------------
//  Dhaarani Mohanasundaram
// -------------------------------------
// Standard Test file in Main
// -------------------------------------
// Test.c
// Program on main branch.
// ------------------------------------------------------------------------------------


int main () {
   int cashPaid, actualAmount;

   // Take input for the amount paid and the actual cost
   printf ("Enter the cash paid by the customer: Rs.");
   scanf_s ("%d", &cashPaid);
   printf ("Enter the actual amount: Rs.");
   scanf_s ("%d", &actualAmount);

   // Call the function to calculate and display the change
   calculateChange (cashPaid, actualAmount);

   return 0;
}

