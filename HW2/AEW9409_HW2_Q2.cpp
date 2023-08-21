// AEW9409_HW2_Q2.cpp : This program takes entry from the user of amount of dollars and cents and 
// calculates how many of each USA curency coin someone would need to equal the entered value.

#include <iostream>
using namespace std; 

int main()
{
	const int dollar_value = 100, cents = 1, quarter = 25, nickel = 5, dime = 10, pennies = 1;
	int dollarEntry, centsEntry;
	dollarEntry = centsEntry = 0;

	cout << "Please enter your amount in the format of dollars and cents separated by a space:\n";
	cin >> dollarEntry;
	cin >> centsEntry;
	

	int totalCents = dollarEntry * dollar_value + centsEntry;
	
	int quartersOut = totalCents / quarter;
	totalCents = totalCents % quarter;
	int dimesOut = totalCents / dime;
	totalCents = totalCents % dime;
	int nickelsOut = totalCents / nickel;
	totalCents = totalCents % nickel;
	int penniesOut = totalCents / pennies;

	cout << dollarEntry << " dollars and " << centsEntry << " cents are:\n";
	
	cout << quartersOut << " quarters, " << dimesOut << " dimes, ";
	cout << nickelsOut << " nickels and " << penniesOut << " pennies.";

		return 0;

	
}
