// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// intlist.c
// Program on Linked list functions.
// ------------------------------------------------------------------------------------------------
#include <malloc.h>
#include "intlist.h"
Node* CreateNode (int data) {
   Node* newNode = (Node*)malloc (sizeof (Node));
   if (newNode == NULL) return NULL; 
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}

bool CheckListNull (IntList* list) {   // If the list pointer is null
   return list == NULL;
}

bool CheckValidIndex (IntList* list, int index) {   // Validate if the list pointer is NULL or the index is out of bounds
   return !(CheckListNull (list) || index < 0 || index >= Count (list));
}

IntList* Create (int* errorCode) {
   IntList* newList = (IntList*)malloc (sizeof (IntList));   // Allocates memory for list
   if (newList == NULL) {
      if (errorCode) *errorCode = MEMORY_ALLOCATION_FAILED;
      return NULL;
   }
   newList->head = NULL; ; // Intialilze head pointer as null
   if (errorCode) *errorCode = SUCCESS;
   return newList;
}

int Delete (IntList* list) {
   if (CheckListNull (list)) return NULL_LIST;   // If list is already null
   Node* current = list->head;
   Node* next =  NULL;
   while (current != NULL) {  // Traverse the list and free each node
      next = current->next;
      free (current);
      current = next;   //Move to next node
   }
   free (list);
   return SUCCESS;
}

int Add (IntList* list, int data) {
   if (CheckListNull (list)) return NULL_LIST;
   Node* newNode = CreateNode (data);
   if (newNode == NULL) return MEMORY_ALLOCATION_FAILED;
   if (list->head == NULL) list->head = newNode;    //If the list is empty, set the new node as the head
   else {
      Node* current = list->head;
      while (current->next != NULL) {  // Traverse to the end of the list
         current = current->next;
      }
      current->next = newNode;
   }
   return SUCCESS;
}

int Insert (IntList* list, int index, int data) {
   if (CheckListNull (list)) return NULL_LIST;
   if (!CheckValidIndex (list, index)) return INVALID_INDEX;
   Node* newNode = CreateNode (data);
   if (newNode == NULL) return MEMORY_ALLOCATION_FAILED;
   if (index == 0) {   // Insert at the head
      newNode->next = list->head;
      list->head = newNode;
   }
   else {
      Node* current = list->head;
      for (int i = 0; i < index - 1; ++i) current = current->next;   // Traverse to the node before the insertion point
      newNode->next = current->next;
      current->next = newNode;
   }
   return SUCCESS;
}


int RemoveAt (IntList* list, int index) {
   if (CheckListNull (list)) return NULL_LIST;
   if (!CheckValidIndex (list, index)) return INVALID_INDEX;
   if (index == 0) {   // If removing the head node
      Node* temp = list->head;
      list->head = list->head->next;
      free (temp);
      return SUCCESS;
   }
   Node* current = list->head;
   int count = 0;
   while (current != NULL && count < index - 1) {   // Traverse to the node before the one to be removed
      current = current->next;
      count++;
   }
   if (current == NULL || current->next == NULL) {
      return INVALID_INDEX;   // Index is out of bounds
   }
   Node* temp = current->next;
   current->next = current->next->next;
   free (temp);
   return SUCCESS;
}

int Remove (IntList* list, int data) {
   if (CheckListNull (list)) return NULL_LIST;
   Node* current = list->head;
   Node* prev = NULL;
   while (current != NULL) {  // Traverse the list to find the first occurrence of the element
      if (current->data == data) {
         if (prev == NULL)  list->head = current->next;   // If the element to remove is found at head of the list
         else prev->next = current->next;   // The element is somewhere after the head
         free (current);
         return SUCCESS;
      }
      prev = current;
      current = current->next;   // Move to the next node
   }
   return ELEMENT_NOT_FOUND;
}

int Count (IntList* list) {
   if (CheckListNull (list)) return -1;
   int count = 0;
   Node* current = list->head;
   while (current != NULL) {  // Traverse the list and count nodes
      count++;
      current = current->next;
   }
   return count;
}

int Get (IntList* list, int index, int* errorCode) {
   if (CheckListNull (list) || !CheckValidIndex (list, index)) {
      if (errorCode) *errorCode = INVALID_INDEX;
      return 0; 
   }
   Node* current = list->head;
   int count = 0;
   while (current != NULL) {   // Traverse the list to find the node at the specified index
      if (count == index) {
         if (errorCode) *errorCode = SUCCESS;
         return current->data;
      }
      current = current->next;
      count++;
   }
   if (errorCode) *errorCode = INVALID_INDEX;   // If the index was not found
   return 0; // Return a default value; 
}

