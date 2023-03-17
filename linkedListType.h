//Author: Eliya Pelton
//Adapted from code in C++ Programming: Program Design Including Data Structures, D.S. Malik

#ifndef H_LinkedListType
#define H_LinkedListType

#include <cassert>
#include "linkedListIterator.h"

class linkedListType
{
public:
const linkedListType& operator=(const linkedListType&);
void initializeList();
bool isEmptyList() const;
void print() const;
int length() const;
void destroyList();
showingType front() const;
showingType back() const;
virtual bool search(const showingType& searchItem) const = 0;
virtual void insertFirst(const showingType& newItem) = 0;
virtual void insertLast(const showingType& newItem) = 0;
virtual void deleteNode(const showingType& deleteItem) = 0;
linkedListIterator begin();
linkedListIterator end();
linkedListType();
linkedListType(const linkedListType& otherList);
~linkedListType();

protected:
int count;
nodeType *first;
nodeType *last;

private:
void copyList(const linkedListType& otherList);
};

#endif