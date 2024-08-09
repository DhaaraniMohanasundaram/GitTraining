// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// intlist.c
// Program on functions of Linked list.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <malloc.h>
#include "intlist.h"
// Allocate memory for a new list structure
// Initialize the list as empty
IntList* Create () {
   IntList* newList = (IntList*)malloc (sizeof (IntList));
   if (newList == NULL) {
      printf ("Memory allocation failed");
      return NULL;
   }
   newList->head = NULL;
   return newList;
}
// Delete the entire list and free memory
void Delete (IntList* list) {
   Node* current = list->head;
   Node* next;
   while (current != NULL) {
      next = current->next;
      free (current);
      current = next;
   }
   free (list);
}
// Add a new element to the end of the list
void Add (IntList* list, int data) {
   Node* newNode = (Node*)malloc (sizeof (Node));
   if (newNode == NULL) {
      printf ("Memory allocation failed");
      return;
   }
   newNode->data = data;
   newNode->next = NULL;
   if (list->head == NULL) {
      list->head = newNode;
   }
   else {
      Node* current = list->head;
      while (current->next != NULL) {
         current = current->next;
      }
      current->next = newNode;
   }
}
// Insert a new element at a specified index (zero-based)
void Insert (IntList* list, int index, int data) {
   if (index < 0 || index > Count (list)) {
      printf ("Invalid index\n");
      return;
   }
   Node* newNode = (Node*)malloc (sizeof (Node));
   if (newNode == NULL) {
      printf ("Memory allocation failed");
      return;
   }
   newNode->data = data;
   if (index == 0) {
      newNode->next = list->head;
      list->head = newNode;
   }
   else {
      Node* current = list->head;
      for (int i = 0; i < index - 1; i++) {
         current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
   }
}
// Remove the element at a specified index (zero-based)
void RemoveAt (IntList* list, int index) {
   if (index < 0 || index >= Count (list)) {
      printf ("Invalid index\n");
      return;
   }
   Node* current = list->head;
   Node* prev = NULL;
   if (index == 0) {
      list->head = current->next;
      free (current);
      printf ("Element at index 0 removed.\n");
   }
   else {
      for (int i = 0; i < index - 1; i++) {
         prev = current;
         current = current->next;
      }
      Node* temp = current->next;
      if (temp != NULL) {
         current->next = temp->next;
         free (temp);
         printf ("Element at index %d removed.\n", index);
      }
      else {
         printf ("Nothing was removed. Index %d is out of range.\n", index);
         return;
      }
   }
}
// Remove the first occurrence of a specific element
void Remove (IntList* list, int data) {
   Node* current = list->head;
   Node* prev = NULL;
   // Traverse the list to find the first occurrence of the element
   while (current != NULL) {
      if (current->data == data) {
         // If the element to remove is found
         if (prev == NULL) {
            // The element to remove is the head of the list
            list->head = current->next;
         }
         else {
            // The element is somewhere after the head
            prev->next = current->next;
         }
         free (current); // Free memory of the removed node
         printf ("First occurence of the element %d removed from list.\n", data);
         return; // Exit after removing the first occurrence
      }
      // Move to the next node
      prev = current;
      current = current->next;
   }
   // If the element was not found
   printf ("Element %d not found in list\n", data);
}
// Count the number of elements in the list
int Count (IntList* list) {
   int count = 0;
   Node* current = list->head;
   while (current != NULL) {
      count++;
      current = current->next;
   }
   return count;
}
// Get the element at a specified index (zero-based)
int Get (IntList* list, int index) {
   if (index < 0 || index >= Count (list)) {
      printf ("Invalid index\n");
      return -1;  // Return -1 indicating an error or empty list
   }
   Node* current = list->head;
   for (int i = 0; i < index; i++) {
      current = current->next;
   }
   return current->data;
}
