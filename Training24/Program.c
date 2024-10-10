// --------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// Program.c
// Program on A5 branch.
// Program has functions for sorting an array and searching an element in array.
// -------------------------------------------------------------------------------
void BubbleSort (int arr[], int n) {
   for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - i - 1; j++) {
         // Swap if the element found is greater than the next element
         if (arr[j] > arr[j + 1]) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }
}

int BinarySearch (int arr[], int n, int target) {
   int left = 0, right = n - 1;
   while (left <= right) {
      int mid = left + (right - left) / 2;
      // Check if target is present at mid
      if (arr[mid] == target) {
         while (mid > 0 && arr[mid - 1] == target) mid--;   // Return the index of target's first occurrence
         return mid;
      }
      if (arr[mid] < target) left = mid + 1;
      else right = mid - 1;
   }
   return -1;   // Target element not found
}