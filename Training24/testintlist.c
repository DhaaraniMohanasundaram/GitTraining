// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// testintlist.c
// Program on Testing and implementing the Linked list functions.
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include "intlist.h"

// Function to print all elements in the list
void PrintList (IntList* list) {
   Node* current = list->head; // Start at the head of the list
   if (current == NULL) {
      printf ("List is empty\n");
   }
   else {
      // Traverse the list
      while (current != NULL) {
         printf ("%d", current->data);
         current = current->next;
         // Move to next node
         if (current != NULL) {
            printf (" -> ");
         }
      }
      printf (" -> NULL\n");
   }
}

// Function to test creation and deletion of the list
void TestCreateAndDelete () {
   printf ("Testing the create and delete functions of a list ::\n");
   IntList* list = Create ();
   if (list == NULL) {
      printf ("Failed to create the list.\n");
      return;
   }
   printf ("List created successfully.\n");
   // Adding elements to the newly created list
   if (Add (list, 0) || Add (list, 2) || Add (list, 4) || Add (list, 6)) {
      printf ("Failed to add elements to the list.\n");
   }
   else {
      printf ("List after adding new elements: ");
      PrintList (list);
   }
   // Test cleaning up memory in list
   Delete (list);
   list = NULL; // Set pointer to NULL to avoid accessing freed memory
   if (list == NULL) {
      printf ("List deleted successfully.\n");
   }
   else {
      printf ("List was not deleted properly.\n");
   }
   printf ("\n");
}

// Function to test add, insert, removeAt, removeElement, count and get functions
void TestListFunctions () {
   printf ("Testing additional list functionalities ::\n");
   IntList* list = Create ();
   if (list == NULL) {
      printf ("Failed to create the list.\n");
      return;
   }

   // Test Add function
   if (Add (list, 1) != SUCCESS || Add (list, 2) != SUCCESS || Add (list, 3) != SUCCESS || Add (list, 2) != SUCCESS || Add (list, 1) != SUCCESS) {
      printf ("Failed to add elements to the list.\n");
   }
   else {
      printf ("List after adding new elements: ");
      PrintList (list);
   }
   printf ("\n");

   // Test Insert function
   int indexToInsert = -1;
   if (Insert (list, -1, 2) != SUCCESS) {
      printf ("Failed to insert element at index %d.\n", indexToInsert);
   }
   else {
      printf ("List after attempting to insert the element at %d:  ", indexToInsert);
      PrintList (list);
   }
   printf ("\n");

   // Test RemoveAt function
   int indexToRemove = 3;
   if (RemoveAt (list, indexToRemove) != SUCCESS) {
      printf ("Failed to remove element at index %d.\n", indexToRemove);
   }
   else {
      printf ("List after attempting to remove element at index %d:  ", indexToRemove);
      PrintList (list);
   }
   printf ("\n");

   // Test Remove function
   int elementToRemove = 1;
   if (Remove (list, elementToRemove) != SUCCESS) {
      printf ("Failed to remove element %d.\n", elementToRemove);
   }
   else {
      printf ("List after attempting to remove first occurence of element %d:  ", elementToRemove);
      PrintList (list);
   }
   printf ("\n");

   // Test CountElements function
   int count = Count (list);
   printf ("Number of elements in the list: %d\n", count);
   printf ("\n");

   // Test Get function
   int indexToGet = -3;  // Example index
   int element;
   int result = Get (list, indexToGet, &element);
   if (result == INVALID_INDEX) {
      printf ("No element found at index %d or list is empty.\n", indexToGet);
   }
   else {
      printf ("Element at index %d: %d\n", indexToGet, element);
   }
}

int main () {
   TestCreateAndDelete ();
   TestListFunctions ();
   return 0;
}
