// --------------------------------------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// --------------------------------------------------------------------------
/// <summary>
/// Implementation of  a linked list data structure to handle integer elements. The implementation will consist of three files:
///   intlist.h -  Header file
///   intlist.c -  Code for functions.
///   testintlist.c - Program that tests the implementation.
/// The following functions have been implemented :
///     a)	Create – Creates a new linked list.
///     b)	Delete – Deletes the list and all the linked elements.
///     c)	Add – Adds an element to the end of the list.
///     d)	Insert – Inserts an element at a particular index (zero based).
///     e)	RemoveAt – Removes the element at a particular index (zero based).
///     f)	Remove – Removes the first occurrence of a specific element.
///     g)	Count – Counts number of elements in the list.
///     h)	Get – Gets the element at a particular index
/// -------------------------------------------------------------------------
/// intlist.h
/// Program on Linked list header file.
/// </summary>
// --------------------------------------------------------------------------------------------------------------------------------
#pragma once
#define INTLIST_H

#include <stdbool.h>
// Define a structure for a node in the linked list
typedef struct Node {
   int data;
   struct Node* next;
} Node;

// Define the structure for the linked list itself
typedef struct {
   Node* head;
} IntList;

// Error codes for various error conditions
#define SUCCESS 0
#define INVALID_INDEX -1
#define ELEMENT_NOT_FOUND -2
#define MEMORY_ALLOCATION_FAILED -3
#define NULL_LIST -4

/// <summary>Creates a new list and initialize the list as empty.</summary>
IntList* Create (int* errorCode);

/// <summary>Creates a new node.</summary>
Node* CreateNode (int data);

/// <summary>Checks if the list pointer is null.</summary>
bool CheckListNull (IntList* list);

/// <summary>Checks if the index is valid.</summary>
bool CheckValidIndex (IntList* list, int index);

/// <summary>Deletes the entire list and frees memory.</summary>
int Delete (IntList* list);

/// <summary>Adds a new element to the end of the list.</summary>
int Add (IntList* list, int data);

/// <summary>Insert a new element at a specified index(zero-based).</summary>
int Insert (IntList* list, int index, int data);

/// <summary>Remove the element at a specified index(zero-based).</summary>
int RemoveAt (IntList* list, int index);

/// <summary>Remove the first occurrence of a specific element.</summary>
int Remove (IntList* list, int data);

/// <summary>Count the number of elements in the list.</summary>
int Count (IntList* list);

/// <summary>Get the element at a specified index.</summary>
int Get (IntList* list, int index, int* errorCode);

/// <summary>Function to print all elements in the list.</summary>
void PrintList (IntList* list);

/// <summary>Function to print the error message based on error code.</summary>
void PrintError (int errorCode);