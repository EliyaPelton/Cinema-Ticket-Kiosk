#include <iostream>
#include <fstream>
#include <string>
#include "customerType.h"
#include "theaterType.h"
using namespace std;

// Function to populate a theater with movies and showing times
void createTheater(ifstream& infile, string fileName, theaterType& newTheater, bool& successful);

// Function to greet user when they begin interaction with kiosk
void greeting();

void buyTickets(theaterType& theater);
// Function to prompt user to select desired movie, showing time, and ticket quantity then process payment

customerType addCustomer(string);
// Gets a users first and last name and creates a customer object

bool isValidName(string);
// Tests if user input consists of valid characters

bool isValidNumber(string);
// Tests if user input string consists of valid numerals


int main()
{
  ifstream infile;
  theaterType theater;
  bool fileOpen;

  // Creates new theater object and populates with current available movies and showing times
  createTheater(infile, "CreateTheater.txt", theater, fileOpen);
  if (fileOpen)
  {
    buyTickets(theater);
  }
}


// Definitions of functions to create a theater
void createTheater(ifstream &infile, string fileName, theaterType &newTheater, bool &successful)
{
  string movieName;
  int hour, min, numOfShowings;
  char ch;
  successful = false;
  
  infile.open(fileName);
  
  if (!infile)
    cout << "ERROR. Could not open file." << endl;

  else
  {
    successful = true;
    getline(infile, movieName);
    while (infile && !newTheater.isTheaterFull())
    {
      newTheater.addNewMovie(movieName);
      infile >> numOfShowings;
      for (int i = 0; i < numOfShowings; i++)
      {
        infile >> hour;
        infile >> min;
        newTheater.addNewShowingTime(movieName, hour, min);
      }
      infile.get(ch);
      getline(infile, movieName);
    }
  }
  infile.close();
}

// Definitions of functions to be used in kiosk
bool isValidName(string name) 
{
  for (int i = 0; i < name.length(); i++) {
    if (isalpha(name[i]) == false) {
      if (name[i] != '-') {
        return false;
      }
    }
  }
  return true;
}

customerType addCustomer(string movie) 
{
  string first = " ", last = " ", title = " ";
  customerType *customer;
  cout << "Enter the your first and last name" << endl;
  cin >> first >> last;
  if (isValidName(first) == true && isValidName(last) == true) 
  {
    customer = new customerType(first, last, movie);
    return *customer;
  } 
  else 
  {
    cout << "invailid name" << endl;
    return addCustomer(movie);
  }
}

void buyTickets(theaterType& theater)
{
  string movie;
  char answer, ch;
  char strHour[3], strMin[3];
  int hour, min, totalTickets;
  bool isOpen = true;
  bool successful = false;
  while (isOpen == true) 
  {
    greeting();
    theater.displayMovies();
    cout << endl;
    
    do
    {
      cout << "What movie would you like to purchase tickets for? ";
      getline(cin, movie);
      cout << endl;
      theater.findMovie(movie, successful);
    } while (!successful);
    

    do
    {
      cout << "What showing would you like to purchase tickets for? (enter ##:##)" << endl << "Showing: ";
      cin.get(strHour, 3, ':');
      cin.get(ch);
      cin.get(strMin, 3);
      if (isValidNumber(strHour) && isValidNumber(strHour))
      {
        hour = atoi(strHour);
        min = atoi(strMin);
        successful = (theater.isShowingFound(movie, hour, min));
      }
      else
      {
        cout << "Error. Invalid input." << endl;
        successful = false;
      }
      cin.clear();
      cin.ignore(1000, '\n');
      cout << endl;
    } while (!successful);
    
    customerType person = addCustomer(movie);
    person.getPrice();
    totalTickets = person.getTickets();
    
    theater.sellSeats(movie, hour, min, totalTickets, successful);
    while (!successful)
    {
      cout << endl << "Please re-enter ticket information." << endl;
      person.getPrice();
      totalTickets = person.getTickets();
      theater.sellSeats(movie, hour, min, totalTickets, successful);
    }
    person.printAccepted();
    person.getPayment();
    
    if(!person.isPaid())
    {
      theater.cancel(movie, hour, min, totalTickets);
      cout << "Purchase cancelled." << endl;
    }
    
    cout << "Would you like to start a purchase?" << endl
         << "Enter Y for yes or any other key for no: "; 
    cin >> answer;
    cin.get(ch);
    answer = toupper(answer);
    if (answer != 'Y') 
    {
      isOpen = false;
    }
    cout << endl;
  }
}

void greeting()
{
  customerType person;
  cout << "**************************************************" << endl;
  cout << "Welcome to AMC" << endl;
  person.printRates();
}


bool isValidNumber(string strNum)
{
  for (int i = 0; i < strNum.length(); i++)
	{
		if (!isdigit(strNum[i]))
			return false;
	}
	return true;
}