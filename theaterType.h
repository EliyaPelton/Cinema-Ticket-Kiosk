//Author: Eliya Pelton

#ifndef H_TheaterType
#define H_TheaterType

#include "movieType.h"
using namespace std;

const int NUM_OF_AUDITORIUMS = 8;

class theaterType
{
public:
void searchEmptyAuditoriums() const;
bool isTheaterFull() const;
void addNewMovie(string movieName);
void addNewShowingTime(string movieName, int hours, int minutes = 0);
void findMovie(string movieName, bool& successful);
movieType getMovie(string movieName);
void isMovieFull(string movieName);
void sellSeats(string movieName, int hours, int minutes, int numOfSeatsSold, bool& successful);
void displayMovies() const;
void cancel(string movieName, int hours, int minutes, int numOfSeatsReturned);
bool isShowingFound(string movieName, int hours, int minutes);
theaterType();

private:
movieType movies[NUM_OF_AUDITORIUMS];
int occupiedAuditoriums;
int searchMovie(string movieName);
};

#endif