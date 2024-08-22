// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// testintlist.c
// Program on Testing and implementing the Linked list functions.
// -----------------------------------------------------------------------------------------------
#include <stdio.h>
#include "intlist.h"

void PrintList (IntList* list) {
   Node* current = list->head;
   if (current == NULL) printf ("List is empty.\n");
   else {
      while (current != NULL) {
         printf ("%d", current->data);
         current = current->next;
         if (current != NULL) printf (" -> ");
      }
      printf (" -> NULL\n");
   }
}

void PrintError (int errorCode) {
   switch (errorCode) {
   case SUCCESS:
      printf ("Operation succeeded.\n");
      break;
   case INVALID_INDEX:
      printf ("Error: Invalid index.\n");
      break;
   case ELEMENT_NOT_FOUND:
      printf ("Error: Element not found.\n");
      break;
   case MEMORY_ALLOCATION_FAILED:
      printf ("Error: Memory allocation failed.\n");
      break;
   case NULL_POINTER:
      printf ("Error: Null pointer.\n");
      break;
   default:
      printf ("Error: Unknown error code %d.\n", errorCode);
      break;
   }
}

int main () {
   IntList* list = Create ();
   if (list == NULL) {
      PrintError (GetIntListLastError ());
      return 1;
   }
   PrintError (GetIntListLastError ());
   printf ("List created successfully. \n");
   printf ("\n");

   Add (list, -1);
   Add (list, 20);
   Add (list, 30);
   Add (list, 20);
   Add (list, -10);
   PrintError (GetIntListLastError ());
   printf ("List after adding elements:\n");
   PrintList (list);
   printf ("\n");

   int value;
   int indexToGet = -1;
   int result = Get (list, indexToGet, &value);
   if (result == SUCCESS) printf ("Element at index %d : %d\n", indexToGet, value);
   else {
      PrintError (GetIntListLastError ());
      printf ("%d is an invalid index.\n", indexToGet);
   }
   printf ("\n");

   int indexToInsert = 1;
   int valueToInsert = 15;
   Insert (list, indexToInsert, valueToInsert);
   PrintError (GetIntListLastError ());
   printf ("List after attempting to insert %d at index %d:\n", valueToInsert, indexToInsert);
   PrintList (list);
   printf ("\n");

   int indexToRemoveAt = 2;
   RemoveAt (list, indexToRemoveAt);
   PrintError (GetIntListLastError ());
   printf ("List after attempting to remove element at index %d:\n", indexToRemoveAt);
   PrintList (list);
   printf ("\n");
 
   int valueToRemove = 40;
   Remove (list, valueToRemove);
   PrintError (GetIntListLastError ());
   printf ("List after attempting to remove element (First occurence) %d:\n", valueToRemove);
   PrintList (list);
   printf ("\n");

   printf ("Total number of elements in the current list : %d \n", Count (list));
   printf ("\n");

   Delete (list);
   PrintError (GetIntListLastError ());
   printf ("List deleted successfully.\n");

   return 0;
}
