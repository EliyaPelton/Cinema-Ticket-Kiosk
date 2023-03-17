//Author: Grace Conti

#pragma once
#include<iostream>
#include<string>
using namespace std;
class customerType
{
private:
	const double PRICE = 12.55;
	const double SENIOR_PRICE = 10.92;
	const double CHILD_PRICE = 9.35;
	const int ARRAY_SIZE = 6;
	bool isPurchased = false;
	bool isCard;
	string payment;
	string paymentTypes[6];
	string firstName;
	string lastName;
	string movie;
	int childNum; //These three integers are the quantity of the three ticket types
	int seniorNum;
	int adultNum;
	int tickets;
	double total;
	string getCard();
	void setTypes();
	bool isNumeric(string);
public:
	customerType(string, string, string);
  customerType();
	void getPrice();
	bool isPaid();
	bool isAccepted();
	void getPayment();
	string processPayment();
	void printRates();
	void printAccepted();
	void processReceipt();
	bool confirmPayment();
  int getTickets();
  
};//End class
