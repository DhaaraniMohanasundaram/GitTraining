// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// intlist.c
// Program on Linked list functions.
// ------------------------------------------------------------------------------------------------

#include <malloc.h>
#include "intlist.h"

// Global variable to store the last error code
 int mlastError = SUCCESS;

// Creating a new list
// Allocate memory for a new list structure and initialize the list as empty
IntList* Create () {
   IntList* newList = (IntList*)malloc (sizeof (IntList));
   if (newList == NULL) {
      mlastError = MEMORY_ALLOCATION_FAILED;
      return NULL;
   }
   newList->head = NULL; ; // Intialilze head pointer as null
   mlastError = SUCCESS;
   return newList;
}

// Delete the entire list and free memory
void Delete (IntList* list) {
   if (list == NULL) {
      mlastError = NULL_POINTER;
      return;
   }
   Node* current = list->head;
   Node* next;
   while (current != NULL) {  // Traverse the list and free each node
      next = current->next;
      free (current);
      current = next;
   }
   free (list);
   mlastError = SUCCESS;
}

// Add a new element to the end of the list
void Add (IntList* list, int data) {
   if (list == NULL) {
      mlastError = NULL_POINTER;
      return;
   }
   Node* newNode = (Node*)malloc (sizeof (Node));
   if (newNode == NULL) {
      mlastError = MEMORY_ALLOCATION_FAILED;
      return;
   }
   newNode->data = data;
   newNode->next = NULL;
   if (list->head == NULL) {  //If the list is empty, set the new node as the head
      list->head = newNode;
   }
   else {
      Node* current = list->head;
      while (current->next != NULL) {  // Traverse to the end of the list
         current = current->next;
      }
      current->next = newNode;
   }
   mlastError = SUCCESS;
}

// Insert a new element at a specified index (zero-based)
void Insert (IntList* list, int index, int data) {
   if (list == NULL) {
      mlastError = NULL_POINTER;
      return;
   }
   if (index < 0 || index > Count (list)) {
      mlastError = INVALID_INDEX;
      return;
   }
   Node* newNode = (Node*)malloc (sizeof (Node));
   if (newNode == NULL) {
      mlastError = MEMORY_ALLOCATION_FAILED;
      return;
   }
   newNode->data = data;
   if (index == 0) { // If inserting at the head
      newNode->next = list->head;
      list->head = newNode;
   }
   else {
      Node* current = list->head;
      for (int i = 0; i < index - 1; i++) {  // Traverse to the node before the insertion point
         current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
   }
   mlastError = SUCCESS;
}

// Remove the element at a specified index (zero-based)
void RemoveAt (IntList* list, int index) {
   if (list == NULL) {
      mlastError = NULL_POINTER;
      return;
   }
   if (index < 0 || index >= Count (list)) {
      mlastError = INVALID_INDEX;
      return;
   }
   Node* current = list->head;
   Node* prev = NULL;
   if (index == 0) { //If removing the head node
      list->head = current->next;
      free (current);
   }
   else {   // Traverse to the node before the one to be removed
      for (int i = 0; i < index - 1; i++) {
         prev = current;
         current = current->next;
      }
      Node* temp = current->next;
      if (temp != NULL) {
         current->next = temp->next;   // Node to be removed
         free (temp);
      }
      else {
         mlastError = INVALID_INDEX;
         return;
      }
   }
   mlastError = SUCCESS;
}

// Remove the first occurrence of a specific element
void Remove (IntList* list, int data) {
   if (list == NULL) {
      mlastError = NULL_POINTER;
      return;
   }
   Node* current = list->head;
   Node* prev = NULL;
   while (current != NULL) {  // Traverse the list to find the first occurrence of the element
      if (current->data == data) {
         if (prev == NULL) {  // If the element to remove is found at head of the list
            list->head = current->next;
         }
         else {
            prev->next = current->next;   // The element is somewhere after the head
         }
         free (current);
         mlastError = SUCCESS;
         return;
      }
      prev = current;
      current = current->next;   // Move to the next node
   }
   mlastError = ELEMENT_NOT_FOUND;
}

// Count the number of elements in the list
int Count (IntList* list) {
   if (list == NULL) {
      mlastError = NULL_POINTER;
      return 0;
   }
   int count = 0;
   Node* current = list->head;
   while (current != NULL) {  // Traverse the list and count nodes
      count++;
      current = current->next;
   }
   mlastError = SUCCESS;
   return count;
}

// Get the element at a specified index
int Get (IntList* list, int index, int* element) {
   if (list == NULL) {
      mlastError = NULL_POINTER;
      return INVALID_INDEX;
   }
   if (index < 0 || index >= Count (list)) {
      mlastError = INVALID_INDEX;
      return INVALID_INDEX;
   }
   Node* current = list->head;
   for (int i = 0; i < index; i++) {   // Traverse to the node at the specified index
      current = current->next;
   }
   *element = current->data;
   mlastError = SUCCESS;
   return SUCCESS;
}

// Function to get the last error code
int GetIntListLastError () {
   return mlastError;
}
