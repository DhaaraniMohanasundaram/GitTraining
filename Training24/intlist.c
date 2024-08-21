// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// intlist.c
// Program on Linked list functions.
// ------------------------------------------------------------------------------------------------
#include <malloc.h>
#include "intlist.h"

int mlastError = SUCCESS;  // Global variable to store the last error code

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
   if (list->head == NULL) list->head = newNode;    //If the list is empty, set the new node as the head
   else {
      Node* current = list->head;
      while (current->next != NULL) {  // Traverse to the end of the list
         current = current->next;
      }
      current->next = newNode;
   }
   mlastError = SUCCESS;
}

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
      for (int i = 0; i < index - 1; i++) current = current->next;   // Traverse to the node before the insertion point
      newNode->next = current->next;
      current->next = newNode;
   }
   mlastError = SUCCESS;
}

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

void Remove (IntList* list, int data) {
   if (list == NULL) {
      mlastError = NULL_POINTER;
      return;
   }
   Node* current = list->head;
   Node* prev = NULL;
   while (current != NULL) {  // Traverse the list to find the first occurrence of the element
      if (current->data == data) {
         if (prev == NULL)  list->head = current->next;   // If the element to remove is found at head of the list
         else prev->next = current->next;   // The element is somewhere after the head
         free (current);
         mlastError = SUCCESS;
         return;
      }
      prev = current;
      current = current->next;   // Move to the next node
   }
   mlastError = ELEMENT_NOT_FOUND;
}

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
   for (int i = 0; i < index; i++)  // Traverse to the node at the specified index
      current = current->next;
   *element = current->data;
   mlastError = SUCCESS;
   return SUCCESS;
}

int GetIntListLastError () {
   return mlastError;
}
