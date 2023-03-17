//Author: Eliya Pelton

#ifndef H_MovieType
#define H_MovieType

#include <string>
#include "orderedLinkedList.h"

using namespace std;

class movieType: public orderedLinkedList
{
public:
void addShowingTime(int hours, int minutes);
void deleteShowingTime(showingType showing);
void updateAvailableSeats(int hours, int minutes, int num, bool& successful);
void findShowingTime(int hours, int minutes = 0);
bool isShowingFull(int hours, int minutes = 0);
int getAvailableSeats(int hours, int minutes = 0);
void findAvailableShowingTimes() const;
bool areAllShowingsFull() const;
string getTitle() const;
const movieType& operator=(string movieName);
bool operator==(const movieType& otherMovie) const;
bool operator==(string movieName) const;
movieType(string = "");

protected:
string title;

private:
void searchShowingTime(int hours, int minutes, bool& found, nodeType* &current);
};

#endif