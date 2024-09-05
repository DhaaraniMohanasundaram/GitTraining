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
      printf ("Error: Null pointer encountered.\n");
      break;
   default:
      printf ("Error: Unknown error code %d.\n", errorCode);
      break;
   }
}

int main () {
   int errorCode;
   IntList* list = Create (&errorCode);
   if (list == NULL) {
      PrintError (errorCode);
      return 1;
   }
   printf ("List created successfully. \n\n");

   int elementsToAdd[] = { -1, -2, -3, -4, 0, 4, 1, 2, 3, 4 };
   int numElements = sizeof (elementsToAdd) / sizeof (elementsToAdd[0]);
   for (int i = 0; i < numElements; i++) {
      if (Add (list, elementsToAdd[i]) != SUCCESS) {
         PrintError (errorCode);
         return 1;
      }
   }
   printf ("List after adding elements: ");
   PrintList (list);
   printf ("\n");

   int indexToGet[] = {0, 2, -4, 50};
   int numIndex = sizeof (indexToGet) / sizeof (indexToGet[0]);
   for (int i = 0; i < numIndex; i++) {
      int value = Get (list, indexToGet[i], &errorCode);
      if (errorCode == SUCCESS) printf ("Element at index %d: %d\n", indexToGet[i], value);
      else {
         PrintError (errorCode);
         printf ("Index %d is invalid to get the element.\n", indexToGet[i]);
      }
      printf ("\n");
   }


   int indexToInsert[] = { 0, -2, 100 };
   int valuesToInsert[] = { 15, 25, 45 };
   int numInsert = sizeof (indexToInsert) / sizeof (indexToInsert[0]);
   for (int i = 0; i < numInsert; i++) {
      int index = indexToInsert[i];
      int value = valuesToInsert[i % (sizeof (valuesToInsert) / sizeof (valuesToInsert[0]))];
      int result = Insert (list, index, value);
      if (result == SUCCESS) {
         printf ("List after inserting %d at index %d: ", value, index);
         PrintList (list);
         printf ("\n");
      }
      else {
         PrintError (result);
         if (result == INVALID_INDEX) printf ("Index %d is invalid for insertion.\n", index);
         else if (result == MEMORY_ALLOCATION_FAILED) printf ("Memory allocation failed while trying to insert %d at index %d.\n", value, index);
         printf ("\n");
      }
   }
  
   int indexToRemove[] = { 2, -4, 100 };
   int numRemove = sizeof (indexToRemove) / sizeof (indexToRemove[0]);
   for (int i = 0; i < numRemove; i++) {
      int index = indexToRemove[i];
      int result = RemoveAt (list, index);
      if (result == SUCCESS) {
         printf ("List after removing element at index %d: ", index);
         PrintList (list);
         printf ("\n");
      }
      else {
         PrintError (result);
         if (result == INVALID_INDEX) printf ("Index %d is invalid for removal.\n", index);
         else if (result == NULL_LIST) printf("List is NULL, cannot remove element.\n");
         printf ("\n");
      }
   }

   int valueToRemove[] = { -1, 4, 100 };
   int numRemoveValue = sizeof (valueToRemove) / sizeof (valueToRemove[0]);
   for (int i = 0; i < numRemoveValue; i++) {
      int value = valueToRemove[i];
      int result = Remove (list, value);
      if (result == SUCCESS) {
         printf ("List after removing element %d First occurrence: ", value);
         PrintList (list);
         printf ("\n");
      }
      else {
         PrintError (result);
         if (result == ELEMENT_NOT_FOUND) printf ("Element %d not found in the list.\n", value);
         else if (result == NULL_LIST) printf ("List is NULL, cannot remove element.\n");
         printf ("\n");
      }
   }

   printf ("Total number of elements in the current list: %d \n", Count (list));
   printf ("\n");

   if (Delete (list) != SUCCESS) {
      PrintError (errorCode);
      return 1;
   }
   printf ("List deleted successfully.\n");

   return 0;
}
