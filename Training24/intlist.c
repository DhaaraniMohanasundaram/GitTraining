// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// intlist.c
// Program on Linked list functions.
// ------------------------------------------------------------------------------------------------


#include <malloc.h>
#include "intlist.h"

// Allocate memory for a new list structure and Initialize the list as empty
IntList* Create () {
   IntList* newList = (IntList*)malloc (sizeof (IntList));
   if (newList == NULL) { // Check if memory allocation failed
      return NULL;
   }
   newList->head = NULL; // Intialilze head pointer as null
   return newList;
}

// Delete the entire list and free memory
void Delete (IntList* list) {
   Node* current = list->head;
   Node* next;
   // Traverse the list and free each node
   while (current != NULL) {
      next = current->next;
      free (current);
      current = next;
   }
   free (list);
   return SUCCESS;
}

// Add a new element to the end of the list
int Add (IntList* list, int data) {
   Node* newNode = (Node*)malloc (sizeof (Node));
   if (newNode == NULL) {
      return ALLOCATION_FAILURE;
   }
   newNode->data = data;
   newNode->next = NULL;
   //If the list is empty, set the new node as the head
   if (list->head == NULL) {
      list->head = newNode;
   }
   else {
      Node* current = list->head;
      // Traverse to the end of the list
      while (current->next != NULL) {
         current = current->next;
      }
      current->next = newNode;
   }
   return SUCCESS;
}

// Insert a new element at a specified index (zero-based)
int Insert (IntList* list, int index, int data) {
   if (index < 0 || index > Count (list)) {
      return INVALID_INDEX;
   }
   Node* newNode = (Node*)malloc (sizeof (Node));
   if (newNode == NULL) {
      return ALLOCATION_FAILURE;
   }
   newNode->data = data;
   // If inserting at the head
   if (index == 0) {
      newNode->next = list->head;
      list->head = newNode;
   }
   else {
      Node* current = list->head;
      // Traverse to the node before the insertion point
      for (int i = 0; i < index - 1; i++) {
         current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
   }
   return SUCCESS;
}

// Remove the element at a specified index
int RemoveAt (IntList* list, int index) {
   if (index < 0 || index >= Count (list)) {
      return INVALID_INDEX;
   }
   Node* current = list->head;
   Node* prev = NULL;
   //If removing the head node
   if (index == 0) {
      list->head = current->next;
      free (current);
   }
   else {
      // Traverse to the node before the one to be removed
      for (int i = 0; i < index - 1; i++) {
         prev = current;
         current = current->next;
      }
      Node* temp = current->next;
      if (temp != NULL) {
         current->next = temp->next; // Node to be removed
         free (temp);
      }
      else {
         return INVALID_INDEX;
      }
   }
   return SUCCESS;
}

// Remove the first occurrence of a specific element
int Remove (IntList* list, int data) {
   Node* current = list->head;
   Node* prev = NULL;
   // Traverse the list to find the first occurrence of the element
   while (current != NULL) {
      if (current->data == data) {
         // If the element to remove is found
         if (prev == NULL) {
            list->head = current->next;
         }
         else {
            prev->next = current->next;
         }
         free (current);
         return SUCCESS;
      }
      // Move to the next node
      prev = current;
      current = current->next;
   }
   return ELEMENT_NOT_FOUND;
}

// Count the number of elements in the list
int Count (IntList* list) {
   int count = 0;
   Node* current = list->head;
   // Traverse the list and count nodes
   while (current != NULL) {
      count++;
      current = current->next;
   }
   return count;
}

// Get the element at a specified index
int Get (IntList* list, int index, int* element) {
   if (index < 0 || index >= Count (list)) {
      return INVALID_INDEX; // Return error code for invalid index
   }
   Node* current = list->head;
   // Traverse to the node at the specified index
   for (int i = 0; i < index; i++) {
      current = current->next;
   }
   *element = current->data; // Store the result in the output parameter
   return SUCCESS; 
}

