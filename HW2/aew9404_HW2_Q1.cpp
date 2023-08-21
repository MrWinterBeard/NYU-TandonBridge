// aew9404_HW2_Q1.cpp : This program takes USA currency coin counts and adds them together
// giving the user a total in dollars and cents value.

#include <iostream>
using namespace std;
int main()
{
	const int quarter_value = 25, dime_value = 10, nickel_value = 5, penny_value = 1, cents = 100;

	int quartersEntered, dimesEntered, nickelsEntered, penniesEntered;
		quartersEntered = dimesEntered = nickelsEntered = penniesEntered = 0;

	cout << "Please enter number of coins:\n";
	cout << "# of quarters:";
	cin >> quartersEntered;
	cout << "# of dimes:";
	cin >> dimesEntered;
	cout << "# of nickels:";
	cin >> nickelsEntered;
	cout << "# of pennies:";
	cin >> penniesEntered;

	int total = (quartersEntered * quarter_value) + (dimesEntered * dime_value)
		+ (nickelsEntered * nickel_value) + (penniesEntered * penny_value);
	int dollarsOut = total / cents;
	int centsOut = total % cents;
	cout << "The total is " << dollarsOut << " dollars and " << centsOut << " cents";
	
	

	return 0;
}


