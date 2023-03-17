//Author: Eliya Pelton
//Adapted from code in C++ Programming: Program Design Including Data Structures, D.S. Malik

#include "linkedListIterator.h"

linkedListIterator::linkedListIterator(nodeType *ptr)
{
  current = ptr;
}

showingType linkedListIterator::operator*()
{
  return current->info;
}

linkedListIterator linkedListIterator::operator++()
{
  current = current->link;
  return *this;
}

bool linkedListIterator::operator==(const linkedListIterator& right) const
{
  return (current == right.current);
}

bool linkedListIterator::operator!=(const linkedListIterator& right) const
{
  return (current != right.current);
}