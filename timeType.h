//Author: Eliya Pelton

#ifndef H_TimeType
#define H_TimeType

#include <iostream>

using namespace std;

class timeType
{
friend ostream& operator<<(ostream&, const timeType&);
friend istream& operator>>(istream&, timeType&);

public:
void setTime(int hours, int minutes);
void getTime(int& hours, int& minutes) const;
timeType operator++();
timeType operator--();
timeType operator-(const timeType& otherTime);
const timeType& operator=(const timeType& otherTime);
bool operator==(const timeType& otherTime) const;
bool operator!=(const timeType& otherTime) const;
bool operator<=(const timeType& otherTime) const;
bool operator<(const timeType& otherTime) const;
bool operator>=(const timeType& otherTime) const;
bool operator>(const timeType& otherTime) const;
timeType(int hours = 0, int minutes = 0);

private:
int hr;
int min;
};

#endif