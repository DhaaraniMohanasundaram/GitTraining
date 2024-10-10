// ------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// Header.h
// Program on A5 branch.
// A5: Program that sorts the integer array and search for an element in the array.
// ------------------------------------------------------------------------------------
#pragma once
#pragma warning (disable:4996)

#define _CRT_SECURE_NO_WARNINGS
#define HEADER_H

/// <summary>Function to sort the array using bubble sort.</summary>
void BubbleSort (int arr[], int n);

/// <summary>Function to perform binary search on a sorted array.</summary>
int BinarySearch (int arr[], int n, int target);

/// <summary>Function to run the testcases.</summary>
void ExecuteTestCases ();

/// <summary>Function to run user input for sort and search.</summary>
void ExecuteUserInput ();