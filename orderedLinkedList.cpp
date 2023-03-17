//Author: Eliya Pelton
//Adapted from code in C++ Programming: Program Design Including Data Structures, D.S. Malik

#include "orderedLinkedList.h"

bool orderedLinkedList::search(const showingType& searchItem) const
{
  bool found = false;
  nodeType *current;
  current = first;

  while (current != nullptr && !found)
  {
    if (current -> info >= searchItem)
      found = true;
    else
      current = current -> link;
  }

  if (found)
    found = (current -> info == searchItem);

  return found;
}

void orderedLinkedList::insert(const showingType& newItem)
{
  nodeType *current;
  nodeType *trailCurrent = nullptr;
  nodeType *newNode;

  bool found;

  newNode = new nodeType;
  newNode -> info = newItem;
  newNode -> link = nullptr;

  if (first == nullptr)
  {
    first = newNode;
    last = newNode;
    count++;
  }
  else
  {
    current = first;
    found = false;

    while (current != nullptr && !found)
    {
      if (current -> info >= newItem)
        found = true;
      else
      {
        trailCurrent = current;
        current = current -> link;
      }
    }
    if (current == first)
    {
      newNode -> link = first;
      first = newNode;
      count++;
    }
    else
    {
      trailCurrent -> link = newNode;
      newNode -> link = current;
      if (current == nullptr)
        last = newNode;
      count++;
    }
  }
}

void orderedLinkedList::insertFirst(const showingType& newItem)
{
  insert(newItem);
}

void orderedLinkedList::insertLast(const showingType& newItem)
{
  insert(newItem);
}

void orderedLinkedList::deleteNode(const showingType& deleteItem)
{
  nodeType *current;
  nodeType *trailCurrent;
  bool found;

  if (first == nullptr)
    cout << "Cannot delete from an empty list." << endl;
  else
  {
    current = first;
    found = false;

    while (current != nullptr && !found)
    {
      if (current -> info >= deleteItem)
        found = true;
      else
      {
        trailCurrent = current;
        current = current -> link;
      }
    }

    if (current == nullptr)
      cout << "The item to be deleted is not in the list." << endl;
    else
      if (current -> info == deleteItem)
      {
        if (first == current)
        {
          first = first -> link;
          if (first == nullptr)
            last = nullptr;
          delete current;
        }
        else
        {
          trailCurrent -> link = current -> link;
          if (current == last)
            last = trailCurrent;
          delete current;
        }
        count--;
      }
    else
        cout << "The item to be deleted is ont in the list." << endl;
  }
}