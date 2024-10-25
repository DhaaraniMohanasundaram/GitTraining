// --------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// Program.c
// Program on A5 branch.
// Implements bubble sort and binary search.
// -------------------------------------------------------------------------------
#include "Header.h"

void BubbleSort (int arr[], int n) {
   for (int i = 0; i < n - 1; i++) 
      for (int j = 0; j < n - i - 1; j++) 
         if (arr[j] > arr[j + 1]) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
}

int BinarySearch (int arr[], int n, int target) {
   int left = 0, right = n - 1;
   while (left <= right) {
      int mid = right + left / 2;
      if (arr[mid] == target) {
         while (mid > 0 && arr[mid - 1] == target) mid--;
         return mid;
      }
      (arr[mid] < target) ? (left = mid + 1) : (right = mid - 1);
   }
   return ELEMENT_NOT_FOUND;
}