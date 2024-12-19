// --------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Dhaarani Mohanasundaram
// -------------------------------------
// Program.c
// Program on A5 branch.
// Implements bubble sort and binary search.
// -------------------------------------------------------------------------------
void Swap (int* a, int* b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

void BubbleSort (int arr[], int n) {
   for (int i = 0; i < n - 1; i++)
      for (int j = 0; j < n - i - 1; j++)
         if (arr[j] > arr[j + 1])
            Swap (&arr[j], &arr[j + 1]);
}

int BinarySearch (int arr[], int n, int target) {
   int left = 0, right = n - 1;
   int result = -1;   // Not found
   while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
         result = mid;
         right = mid - 1;   // Search left for the first occurrence
      }
      else if (arr[mid] < target) left = mid + 1;
      else right = mid - 1;
   }
   return result;   // Returns Target index or -1
}