//Author Grace Conti

#include "customerType.h"


//confirms that a purchase was made.
bool customerType:: isPaid()
{
	return isPurchased;
}//End isPaid

//confirms that the user entered a valid payment method.
bool customerType:: isAccepted()
{
	for (int i = 0; i < payment.length(); i++)//This is for case insensitivity
	{
		payment[i] = tolower(payment[i]);
	}//End for
	for (int i = 0; i<ARRAY_SIZE; i++)
	{
		if (payment.compare(paymentTypes[i]) == 0)
		{
			return true;
		}
	}//End for
	return false;
}//End isAccepted

int customerType::getTickets()
{
  return tickets;
}//getTotal

//confirms that the input is only numbers.
bool customerType::isNumeric(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			return false;
		}//End if

	}//End for
	return true;
}//End isNumeric

//Allows the user to enter a payment method
void customerType::getPayment()
{
	bool isValid = false;
	while (isValid == false) 
	{//iterates until the user enters a valid method 
		cout << "Enter a payment method" << endl;
		cin >> payment;
		if (isAccepted() == true)
		{
			isValid = true;
			processReceipt();
		}//End if
	}
}//End getPayment

//Allows the user to enter his/her card information.
string customerType::getCard()
{
	isCard = true;
	string card = " ";
	cout << "Please enter your card number ";
	cin >> card;
	if (card.length() == 16) //makes sure the card is the proper length
	{
			if (isNumeric(card) == true)
			{
				for (int i = 0; i < 12; i++)
				{
					card[i] = 'X';
				}//End for
			}
			else
			{
				cout << "Invalid Card!  Please only enter numbers" << endl;
				return getCard();
			}//End else
	}
	else
	{
		cout << "Invalid Card!  Please enter a new number" << endl;
		return getCard();
	}//End else
	return card;
}//End getCard

/*Allows the user to enter the quantities of each ticket type
and calculates the total */
void customerType::getPrice()
{
	string child;
	string adult;
	string senior;
	cout << endl;
  cout << "How many adult (non-senior) tickets? ";
	cin >> adult;
	cout << "How many seniors? ";
	cin >> senior;
	cout << "How many children? ";
	cin >> child;
	if (isNumeric(adult) ==true && isNumeric(senior) == true 
		&& isNumeric(child) == true)
	{
		adultNum = stoi(adult);
		childNum = stoi(child);
		seniorNum = stoi(senior);
		total = adultNum * PRICE;//Adds up the total price for tickets
		total += childNum * CHILD_PRICE;
		total += seniorNum * SENIOR_PRICE;
    tickets = adultNum + childNum + seniorNum;
	}//End else
	else
	{
		cout << "Please only enter numbers." << endl;
		getPrice();
	}//End else

  cout << endl;

}//End getPrice

//formats the payment type for the receipt
string customerType::processPayment()
{
	if (payment.compare(paymentTypes[0]) == 0)
	{
		payment = "Visa " + getCard(); /*Because there is no real card info
		we assume Visa for credit and MasterCard for debit.*/
	}//End if
	else if (payment.compare(paymentTypes[1]) == 0)
	{
		payment = "MasterCard " + getCard();
	}//End else if
	else if (payment.compare(paymentTypes[2]) == 0)
	{
		payment = "Gift Card " + getCard();
	}//End else if
	else if (payment.compare(paymentTypes[3]) == 0)
	{
		cout << "Please pay at the counter"<<endl<<endl;
		payment = "Cash";
	}//End else if

	else//mobile payments
	{
		if (payment.compare(paymentTypes[5]) == 0)
		{
			payment[3] = toupper(payment[3]);
		}
		payment[0] = toupper(payment[0]);
		cout << "Processing in the "<<payment<<" app..." << endl<<endl;
		/*Since there is no actual money exchange, it just says processing
		in the Venmo or PayPal app
		*/
	}//End else
	return payment;
}//End processPayment

//Displays the receipt
void customerType::processReceipt()
{
	payment = processPayment();
	if (confirmPayment() == true)
	{
		cout << "		AMC" << endl << endl;
		cout << "	Virginia Beach, VA" << endl;
		cout << movie << endl;
		if (adultNum > 0)
		{
			cout << "	" << adultNum << " Adult tickets $" << PRICE << endl;
		}//End if
		if (childNum > 0)
		{
			cout << "	" << childNum << " Children's tickets $" << CHILD_PRICE << endl;
		}//End if
		if (seniorNum > 0)
		{
			cout << "	" << seniorNum << " Senior's tickets $" << SENIOR_PRICE << endl;
		}//End if
		cout << payment<<endl;
		cout << "***************************************"<<endl;
		cout << "Total: $" << total<<endl;
		cout << "***************************************" << endl;
		cout << "		Thank You." << endl<<endl;
	}//End if
}//End processReceipt

//Prints the different ticket prices.
void customerType::printRates()
{
	cout << "Our prices are:"<< endl << PRICE << " for adults, "
		<< SENIOR_PRICE << " for seniors, and " << CHILD_PRICE << " for children"
		<< endl << endl;
}//End printRates

//prints the accepted ticket methods.
void customerType:: printAccepted()
{
	cout << "We accept:" << std::endl;
	cout << "Credit, Debit, Venmo, PayPal, Cash, and "
		"Gift"<<std::endl;
}//End printAccepted

/*
If the user is paying with a card, it allows them to confirm purchase or cancel.
If the user is paying with mobile or cash, he/she confirms details in the app
or at the counter.
*/
bool customerType::confirmPayment()
{
	if (isCard == false)
	{//Non card payments see confirmation at the counter or on a mobile payment app.

		total += .25;//Add tax
		isPurchased = true;
		return true;
	}//End if
	cout << "Name: " << firstName << " " << lastName<<endl;

	if (adultNum > 0)
	{
		cout << adultNum << " Adult tickets " <<PRICE<< endl;
	}//End if
	if (childNum > 0)
	{
		cout << childNum << " Children's tickets " <<CHILD_PRICE<< endl;
	}//End if
	if (seniorNum > 0)
	{
		cout << childNum << " Senior's tickets " <<SENIOR_PRICE<< endl;
	}//End if
	cout << "Subtotal $" << total<<endl;
	total += .25;//Add tax.
	cout << "Total $" << total<< endl;
	char answer;
	cout << "Enter Y to confirm, any other character to cancel "<<endl;
	cin >> answer;
	answer = toupper(answer);//input is case insensitive.
	if (answer == 'Y')
	{
		isPurchased = true;
		return true;
	}//End if
	return false;
}//End confirmPayment

//initializes the paymentTypes array.
void customerType::setTypes()
{
	paymentTypes[0] = "credit";
	paymentTypes[1] = "debit";
	paymentTypes[2] = "gift";
	paymentTypes[3] = "cash";
	paymentTypes[4] = "venmo";
	paymentTypes[5] = "paypal";
}//End setType

//Takes in a users first and last name, and the movie 
customerType::customerType(std::string first, std::string last, string title) 
{
	setTypes();
	firstName = first;
	lastName = last;
	movie = title;
}//End constructor

customerType::customerType()
{
  
}//End default constructor