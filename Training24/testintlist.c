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
   case NULL_LIST:
      printf ("Error: List is Null.\n");
      break;
   default:
      printf ("Error: Unknown error code %d.\n", errorCode);
      break;
   }
}

int main () {
   int errorcode;
   IntList* list = Create (&errorcode);
   if (list == NULL) {
      PrintError (errorcode);
      return 1;
   }
   printf ("List created successfully. \n");
   printf ("\n");

   int elementsToAdd[] = { -1, -2, -3, -4, 0, 1, 2, 3, 4 };
   int numElements = sizeof (elementsToAdd) / sizeof (elementsToAdd[0]);
   for (int i = 0; i < numElements; i++) Add (list, elementsToAdd[i]);
   printf ("List after adding elements: ");
   PrintList (list);
   printf ("\n");

   int indexToGet = 8;
   int value = Get (list, indexToGet, &errorcode);
   if (errorcode == SUCCESS) printf ("Element at index %d: %d\n", indexToGet, value);
   else {
      PrintError (errorcode);
      printf ("%d is an invalid index\n", indexToGet);
   }
   printf ("\n");

   int indexToInsert = 0;
   int valueToInsert = 15;
   Insert (list, indexToInsert, valueToInsert);
   PrintError (errorcode);
   printf ("List after attempting to insert %d at index %d: ", valueToInsert, indexToInsert);
   PrintList (list);
   printf ("\n");
  
   int indexToRemoveAt = 3;
   RemoveAt (list, indexToRemoveAt);
   PrintError (errorcode);
   printf ("List after attempting to remove element at index %d: ", indexToRemoveAt);
   PrintList (list);
   printf ("\n");

   int valueToRemove = 20;
   Remove (list, valueToRemove);
   PrintError (errorcode);
   printf ("List after attempting to remove element (First occurence) %d: ", valueToRemove);
   PrintList (list);
   printf ("\n");

   printf ("Total number of elements in the current list: %d \n", Count (list));
   printf ("\n");

   Delete (list);
   PrintError (errorcode);
   printf ("List deleted successfully.\n");

   return 0;
}
