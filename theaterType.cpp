//Author: Eliya Pelton

#include "theaterType.h"

void theaterType::searchEmptyAuditoriums() const
{
  if (isTheaterFull())
    cout << "Theater is full, no empty auditoriums." << endl;
  else
  {
    cout << "(" << NUM_OF_AUDITORIUMS - occupiedAuditoriums << ") empty auditorium(s) found. Auditoriums ";
    for (int i = occupiedAuditoriums; i < NUM_OF_AUDITORIUMS; i++)
    {
      cout << i + 1;
      if (i + 1 < NUM_OF_AUDITORIUMS)
        cout << ", ";
    }
    cout << " are empty." << endl;
  }
}

bool theaterType::isTheaterFull() const
{
  return (occupiedAuditoriums == NUM_OF_AUDITORIUMS);
}

void theaterType::addNewMovie(string movieName)
{
  int num = searchMovie(movieName);
  
  if (num != -1)
    cout << "ERROR. Movie already being played in auditorium " << num + 1 << endl;
  else if (isTheaterFull())
    cout << "ERROR. All auditoriums are already in use. Cannot add new movie." << endl;
  else
  {
    movies[occupiedAuditoriums] = movieName;
    occupiedAuditoriums++;
  }
}

void theaterType::addNewShowingTime(string movieName, int hours, int minutes)
{
  int num = searchMovie(movieName);
  if (num == -1)
    cout << "ERROR. Movie is not being played at theater." << endl;
  else
    movies[num].addShowingTime(hours, minutes);
}

void theaterType::findMovie(string movieName, bool &successful)
{
  successful = false;
  int num = searchMovie(movieName);
  if (searchMovie(movieName) == -1)
    cout << "Movie is not being played at this theater." << endl;
  else
  {
    cout << "Current available showings for " << movieName << ":" << endl;
    movies[num].findAvailableShowingTimes();
    cout << endl;
    successful = true;
  }
}

movieType theaterType::getMovie(string movieName)
{
  return movies[searchMovie(movieName)];
}

void theaterType::isMovieFull(string movieName)
{
  int num = searchMovie(movieName);
  
  if (num == -1)
    cout << "ERROR. Movie not being played at this theater.";
  else
    movies[num].findAvailableShowingTimes();
  cout << endl;
}

void theaterType::sellSeats(string movieName, int hours, int minutes, int numOfSeatsSold, bool &successful)
{
  successful = false;
  int num = searchMovie(movieName);

  if (num == -1)
    cout << "ERROR. Movie not being played at this theater." << endl;
  else
    movies[num].updateAvailableSeats(hours, minutes, numOfSeatsSold, successful);
}

int theaterType::searchMovie(string movieName)
{
  for (int i = 0; i < NUM_OF_AUDITORIUMS; i++)
  {
    if (movies[i] == movieName)
      return i;
  }
  return -1;
}

void theaterType::displayMovies() const
{
  if (occupiedAuditoriums == 0)
    cout << "No movies currently being played at this theater." << endl;
  else
  {
    cout << "Movies currently being played at theater:" << endl;
    for (int i = 0; i < occupiedAuditoriums; i++)
      cout << "Auditorium " << i + 1 << ": " << movies[i].getTitle() << endl;
  }
}

void theaterType::cancel(string movieName, int hours, int minutes, int numOfSeatsReturned)
{
  bool successful;
  int num = searchMovie(movieName);

  if (num == -1)
    cout << "ERROR. Movie not being played at this theater." << endl;
  else
    movies[num].updateAvailableSeats(hours, minutes, (-1*numOfSeatsReturned), successful);
}

bool theaterType::isShowingFound(string movieName, int hours, int minutes)
{  
  int num = searchMovie(movieName);
  if (!movies[num].isShowingFull(hours, minutes))
    return true;
  return false;
}

theaterType::theaterType()
{
  occupiedAuditoriums = 0;
}