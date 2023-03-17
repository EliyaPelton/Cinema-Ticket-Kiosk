//Author: Eliya Pelton

#ifndef H_ShowingType
#define H_ShowingType

#include <iostream>
#include "timeType.h"

using namespace std;

const int MAX_OCCUPANCY = 50;    //number of seats in the auditorium

class showingType
{
friend ostream& operator<<(ostream&, const showingType&);

public:
bool isShowingFull() const;
void updateVacancy(int, bool&);
int getVacancy() const;
void setShowingTime(int hours, int minutes);
bool isWithinRange(int hours, int minutes = 0);
bool operator==(const showingType& otherShowing) const;
bool operator!=(const showingType& otherShowing) const;
bool operator<=(const showingType& otherShowing) const;
bool operator<(const showingType& otherShowing) const;
bool operator>=(const showingType& otherShowing) const;
bool operator>(const showingType& otherShowing) const;
showingType(int hours = 0, int minutes = 0, int emptySeats = MAX_OCCUPANCY);

protected:
int vacancy;          //number of empty seats in the auditorium
timeType showTime;    //time of showing
};

#endif