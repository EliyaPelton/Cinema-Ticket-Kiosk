//Author: Eliya Pelton
//Adapted from code in C++ Programming: Program Design Including Data Structures, D.S. Malik

#ifndef H_LinkedListIterator
#define H_LinkedListIterator

#include <iostream>
#include "nodeType.h"

class linkedListIterator
{
public:
linkedListIterator(nodeType *ptr = nullptr);
showingType operator*();
linkedListIterator operator++();
bool operator==(const linkedListIterator& right) const;
bool operator!=(const linkedListIterator& right) const;

private:
nodeType *current;
};

#endif