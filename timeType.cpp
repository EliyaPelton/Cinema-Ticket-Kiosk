//Eliya Pelton

#include "timeType.h"
using namespace std;

timeType timeType::operator++()
{
    min = min + 30;

    if (min == 60)
    {
      min = 0;
      hr++;

      if (hr > 23)
        hr = 0;
    }
  return *this;
}

timeType timeType::operator--()
{
    min = min - 30;

    if (min == -30)
    {
      min = 30;
      hr--;

      if (hr == -1)
        hr = 23;
    }
  return *this;
}

timeType timeType::operator-(const timeType& otherTime)
{
  timeType difference;
  difference.hr = hr - otherTime.hr;
  difference.min = min - otherTime.min;
  
  return difference;
}

const timeType& timeType::operator=(const timeType& otherTime)
{
  if (*this != otherTime)
  {
    hr = otherTime.hr;
    min = otherTime.min;
  }
  return *this;
}

bool timeType::operator==(const timeType& otherTime) const
{
  return (hr == otherTime.hr && min == otherTime.min);
}

bool timeType::operator<=(const timeType& otherTime) const
{
  return ((hr < otherTime.hr) || (hr == otherTime.hr && min <= otherTime.min));
}

bool timeType::operator!=(const timeType& otherTime) const
{
  return (hr != otherTime.hr || min != otherTime.min);
}

bool timeType::operator<(const timeType& otherTime) const
{
  return ((hr < otherTime.hr) || (hr == otherTime.hr && min < otherTime.min));
}

bool timeType::operator>=(const timeType& otherTime) const
{
  return ((hr > otherTime.hr) || (hr == otherTime.hr && min >= otherTime.min));
}

bool timeType::operator>(const timeType& otherTime) const
{
  return ((hr > otherTime.hr) || (hr == otherTime.hr && min > otherTime.min));
}

void timeType::setTime(int hours, int minutes)
{
  if (-24 < hours && hours < 24)
    hr = hours;
  else
    hr = 0;
  if (-60  < minutes && minutes < 60)
    min = minutes;
  else
    min = 0;
}

void timeType::getTime(int& hours, int&minutes) const
{
  hours = hr;
  minutes = min;
}

timeType::timeType(int hours, int minutes)
{
  setTime(hours, minutes);
}

ostream& operator<<(ostream& osObject, const timeType& timeOut)
{
  osObject << timeOut.hr << ':';

  if (timeOut.min < 10)
    osObject << '0';
  osObject << timeOut.min;

  return osObject;
}

istream& operator>> (istream& is, timeType& timeIn)
{
  char ch;

  is >> timeIn.hr;
  if(timeIn.hr < 0 || timeIn.hr >= 24)
    timeIn.hr = 0;

  is.get(ch);

  is >> timeIn.min;

  if(timeIn.min < 0 || timeIn.min >= 60)
    timeIn.min = 0;

  return is;
}