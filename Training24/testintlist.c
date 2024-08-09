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
      printf ("List is null\n");
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
   printf ("Testing the create and delete functions of a list :: \n");
   IntList* list = Create ();
   if (list == NULL) {
      printf ("Failed to create the list.\n");
      return;
   }
   printf ("List created successfully.\n");
   // Test adding elements to the newly created list
   Add (list, 0);
   Add (list, 2);
   Add (list, 4);
   Add (list, 6);
   printf ("Current elements in list : ");
   PrintList (list);
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
   printf ("Testing additional list functionalities :: \n");
   IntList* list = Create ();
   if (list == NULL) {
      printf ("Failed to create the list.\n");
      return;
   }
   // Test Add function
   Add (list, 1);
   Add (list, 2);
   Add (list, 3);
   Add (list, 4);
   printf ("List after adding new elements : ");
   PrintList (list);
   printf ("\n");
   // Test Insert function
   Insert (list, 0, 2);
   printf ("List after inserting the elements : ");
   PrintList (list);
   printf ("\n");
   // Test RemoveAt function
   int indexToRemove = 1;
   RemoveAt (list, indexToRemove);
   if (Count (list) > indexToRemove) {
      printf ("List after attempting to remove element at index %d : ", indexToRemove);
      PrintList (list);
      printf ("\n");
   }
   // Test Remove function
   int elementToRemove = 2;
   Remove (list, elementToRemove); // Removes the first occurence of given index
   printf ("List after attempting to remove element %d : ", elementToRemove);
   PrintList (list);
   printf ("\n");
   // Test Count function
   printf ("Total number of elements in the current list : %d \n", Count (list));
   printf ("\n");
   // Test Get function
   int indexToGet = 3;
   int element = Get (list, indexToGet);
   if (element == -1) {
      printf ("No element found at index %d or list is empty.\n", indexToGet);
   }
   else {
      printf ("Element at index %d : %d \n", indexToGet, element);
   }
   // Cleans up memory
   Delete (list);
}
int main () {
   TestCreateAndDelete (); // Test create and delete functions
   TestListFunctions ();   // Test other list functions
   return 0;
}

