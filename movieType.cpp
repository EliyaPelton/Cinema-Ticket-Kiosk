//Author: Eliya Pelton

#include "movieType.h"
using namespace std;

void movieType::addShowingTime(int hours, int minutes)
{
  bool found;
  bool conflict = false;
  nodeType* location;
  searchShowingTime(hours, minutes, found, location);
  
  //Case: Given time is not between 0:00-23:30 or given time is not an increment of half an hour
  if (hours < 0 || hours > 23 || minutes < 0 || minutes > 30 || minutes%30 != 0)
  {
    cout << "ERROR. Time must be between 0:00 and 23:30 and must be an increment of half an hour." << endl;
    conflict = true;
  }

  //Case: Given show time already exists
  else if (found)
    cout << "ERROR. Showing time already exists." << endl;

  else
  {
    nodeType* current = first;
    
    while (current != nullptr && !conflict)
    {
      //Case: Given time is within 2h30min of an already existing show time
      if (current->info.isWithinRange(hours, minutes))
      {
        cout << "ERROR. Unable to create new showing time.\nShowing time is within 2h30min of already existing showing time: " << current->info << endl;
        conflict = true;
      }
      current = current->link;
    }

    //Case: No errors
    if (!conflict)
    {
      showingType showing(hours, minutes);
      insert(showing);
    }
  }
}

void movieType::deleteShowingTime(showingType showing)
{
  deleteNode(showing);
}

void movieType::updateAvailableSeats(int hours, int minutes, int num, bool &successful)
{
  bool found;
  nodeType *current;

  searchShowingTime(hours, minutes, found, current);

  if (!found)
    cout << "Error. Showing time not found." << endl;
  else
    current->info.updateVacancy(num, successful);
}

void movieType::findShowingTime(int hours, int minutes)
{
  bool found;
  nodeType *current;

  searchShowingTime(hours, minutes, found, current);

  if (!found)
    cout << "Error. Showing time not found." << endl;
  else
    cout << current->info << endl;
}

bool movieType::isShowingFull(int hours, int minutes)
{
  bool found;
  nodeType *current;

  searchShowingTime(hours, minutes, found, current);

  if (found)
    return current->info.showingType::isShowingFull();
  else
  {
    cout << "Error. Showing time not found." << endl;
    return true;
  }
}

int movieType::getAvailableSeats(int hours, int minutes)
{
  bool found;
  nodeType *current;

  searchShowingTime(hours, minutes, found, current);

  if (!found)
  {
    cout << "Error. Showing time not found." << endl;
    return 0;
  }
  else
    return current->info.getVacancy();
}

void movieType::findAvailableShowingTimes() const
{
  nodeType *current;
  current = first;
  bool found = false;
  
  if (current == nullptr)
    cout << "No showings for this movie." << endl;
  
  while (current !=nullptr)
  {
    if (!current->info.isShowingFull())
    {
      cout << current->info << endl;
      found = true;
    }
    current = current->link;
  }

  if (!found && first != nullptr)
    cout << "All showings are full." << endl;
}

bool movieType::areAllShowingsFull() const
{
  nodeType *current;
  current = first;
  
  if (current == nullptr)
    return true;
  
  while (current !=nullptr)
  {
    if (!current->info.isShowingFull())
      return false;
    current = current->link;
  }

  return true;
}

string movieType::getTitle() const
{
  return title;
}

const movieType& movieType::operator=(string movieName)
{
  if (title != movieName)
  {
    title = movieName;
  }
  return *this;
}

bool movieType::operator==(const movieType& otherMovie) const
{
  return (title == otherMovie.title);
}

bool movieType::operator==(string movieName) const
{
  return (title == movieName);
}

movieType::movieType(string name)
{
  title = name;
}

void movieType::searchShowingTime(int hours, int minutes, bool &found, nodeType* &current)
{
  found = false;
  current = first;

  showingType targetShowing(hours, minutes);

  while (current != nullptr && !found)
  {
    if (current -> info >= targetShowing)
      found = true;
    else
      current = current -> link;
  }

  if (found)
    found = (current -> info == targetShowing);
}