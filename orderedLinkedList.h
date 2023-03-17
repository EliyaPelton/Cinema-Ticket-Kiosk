//Author: Eliya Pelton
//Adapted from code in C++ Programming: Program Design Including Data Structures, D.S. Malik

#ifndef H_OrderedLinkedList
#define H_OrderedLinkedList

#include "linkedListType.h"

class orderedLinkedList: public linkedListType
{
public:
bool search(const showingType& searchItem) const;
void insert(const showingType& newItem);
void insertFirst(const showingType& newItem);
void insertLast(const showingType& newItem);
void deleteNode(const showingType& deleteItem);
};

#endif