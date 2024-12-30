// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// CoinReturn.h
// Program on Test2.2 branch.
// Test2.2: To calculate the fewest coins (Rs.1, Rs.2, Rs.5, Rs.10) needed as 
// change when a customer pays in cash, given the cash paid and the actual amount.
// ------------------------------------------------------------------------------------
#pragma once
#define COINRETURN_H

#include <stdbool.h> 

/// <summary>Calculates the change and stores the coin counts in the coinsReturned.</summary>
bool CalculateChange (int paidAmount, int actualAmount, int* coinsReturned, int* coins, int numCoins);