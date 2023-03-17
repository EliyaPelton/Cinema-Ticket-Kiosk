//Author: Eliya Pelton

#include "showingType.h"
using namespace std;

bool showingType::isShowingFull() const
{
  return (vacancy == 0);
}

void showingType::updateVacancy(int num, bool &successful)
{
  successful = false;
  if (isShowingFull())
    cout << "Error. Auditorium is full." << endl;
  else if (num > vacancy)
    cout << "Error. Not enough seats to sell." << endl;
  else
  {
    vacancy -= num;
    successful = true;
  }
}

int showingType::getVacancy() const
{
  return vacancy;
}

void showingType::setShowingTime(int hours, int minutes)
{
  showTime.setTime(hours, minutes);
}

bool showingType::isWithinRange(int hours, int minutes)
{
  timeType otherTime(hours, minutes);
  timeType upperRange(2, 30);
  timeType lowerRange(-2, -30);

  return ((showTime - otherTime) > lowerRange && (showTime - otherTime) < upperRange);
}

bool showingType::operator==(const showingType& otherShowing) const
{
  return (showTime == otherShowing.showTime);
}

bool showingType::operator!=(const showingType& otherShowing) const
{
  return (showTime != otherShowing.showTime);
}

bool showingType::operator<=(const showingType& otherShowing) const
{
  return (showTime <= otherShowing.showTime);
}

bool showingType::operator<(const showingType& otherShowing) const
{
  return (showTime < otherShowing.showTime);
}

bool showingType::operator>=(const showingType& otherShowing) const
{
  return (showTime >= otherShowing.showTime);
}

bool showingType::operator>(const showingType& otherShowing) const
{
  return (showTime > otherShowing.showTime);
}

showingType::showingType(int hours, int minutes, int emptySeats)
{
  setShowingTime(hours, minutes);
  if (emptySeats > MAX_OCCUPANCY)
  {
    cout << "Error. Vacancy cannot excede max occupancy. Setting vacancy to " << MAX_OCCUPANCY << endl;
    vacancy = MAX_OCCUPANCY;
  }
  else if (emptySeats < 0)
  {
    cout << "Error. Vacancy cannot be a negative number. Setting vacancy to 0." << endl;
    vacancy = 0;
  }
  else
    vacancy = emptySeats;
}

ostream& operator<<(ostream& osObject, const showingType& showingOut)
{
  osObject << "Showing: " << showingOut.showTime << "; Seats available: " << showingOut.vacancy;

  return osObject;
}