// --------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// Header.h
// Program on A5 branch.
// A5: Sorts integer array and search for an element in array using binary search.
// --------------------------------------------------------------------------------
#pragma once
#pragma warning (disable:4996)

#define _CRT_SECURE_NO_WARNINGS
#define HEADER_H

/// <summary>Sorts the array using bubble sort.</summary>
void BubbleSort (int arr[], int n);

/// <summary>Function to swap two elements in an array for bubble sort.</summary>
void Swap (int* a, int* b);

/// <summary>Performs binary search on a sorted array.</summary>
int BinarySearch (int arr[], int n, int target);