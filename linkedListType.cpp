//Author: Eliya Pelton
//Adapted from code in C++ Programming: Program Design Including Data Structures, D.S. Malik

#include "linkedListType.h"

const linkedListType& linkedListType::operator=(const linkedListType& otherList)
{
  if (this != &otherList)
  {
    copyList(otherList);
  }
  return *this;
}

void linkedListType::initializeList()
{
  destroyList();
}

bool linkedListType::isEmptyList() const
{
  return (first == nullptr);
}

void linkedListType::print() const
{
  nodeType *current;
  current = first;
  while (current != nullptr)
  {
    cout << current->info << " ";
    current = current ->link;
  }
}

int linkedListType::length() const
{
  return count;
}

void linkedListType::destroyList()
{
  nodeType *temp;
  while (first != nullptr)
  {
    temp = first;
    first = first->link;
    delete temp;
  }
  last = nullptr;
  count = 0;
}

showingType linkedListType::front() const
{
  assert(first != nullptr);
  return first->info;
}

showingType linkedListType::back() const
{
  assert(last != nullptr);
  return last->info;
}

linkedListIterator linkedListType::begin()
{
  linkedListIterator temp(first);
  return temp;
}

linkedListIterator linkedListType::end()
{
  linkedListIterator temp(nullptr);
  return temp;
}

linkedListType::linkedListType()
{
  first = nullptr;
  last = nullptr;
  count = 0;
}

linkedListType::linkedListType(const linkedListType& otherList)
{
  first = nullptr;
  copyList(otherList);
}
  
linkedListType::~linkedListType()
{
  destroyList();
}

//private member function
void linkedListType::copyList(const linkedListType& otherList)
{
  nodeType *newNode;
  nodeType *current;

  if (first != nullptr)
    destroyList();

  if (otherList.first == nullptr)
  {
    first = nullptr;
    last = nullptr;
    count = 0;
  }

  else
  {
    current = otherList.first;
    count = otherList.count;
    first = new nodeType;
    first->info = current->info;
    first->link = nullptr;
    last = first;
    current = current->link;

    while (current != nullptr)
    {
      newNode = new nodeType;
      newNode->info = current->info;
      newNode->link = nullptr;
      last->link = newNode;
      last = newNode;
      current = current->link;
    }
  }
}