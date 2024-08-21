// --------------------------------------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Implementation of  a linked list data structure to handle integer elements. The implementation will consist of three files:
// intlist.h -  Header file
// intlist.c -  Code for functions.
// testintlist.c - Program that tests the implementation.
// The following functions have been implemented :
// a)	Create – Creates a new linked list.
// b)	Delete – Deletes the list and all the linked elements.
// c)	Add – Adds an element to the end of the list.
// d)	Insert – Inserts an element at a particular index (zero based).
// e)	RemoveAt – Removes the element at a particular index (zero based).
// f)	Remove – Removes the first occurrence of a specific element.
// g)	Count – Counts number of elements in the list.
// h)	Get – Gets the element at a particular index
// ------------------------------------------------------------------
// intlist.h
// Program on Linked list header file.
// --------------------------------------------------------------------------------------------------------------------------------

#pragma once
#define INTLIST_H

// Define a structure for a node in the linked list
typedef struct Node {
   int data;
   struct Node* next;
} Node;

// Define the structure for the linked list itself
typedef struct {
   Node* head;
} IntList;

// Define error codes for various error conditions
#define SUCCESS 0
#define INVALID_INDEX -1
#define ELEMENT_NOT_FOUND -2
#define MEMORY_ALLOCATION_FAILED -3
#define NULL_POINTER -4

// Function prototypes
IntList* Create ();
void Delete (IntList* list);
void Add (IntList* list, int data);
void Insert (IntList* list, int index, int data);
void RemoveAt (IntList* list, int index);
void Remove (IntList* list, int data);
int Count (IntList* list);
int Get (IntList* list, int index, int* element);

// Function to get the last error code
int GetIntListLastError ();
