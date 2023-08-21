 /*aew9409_HW3_Q4.cpp : This program takes entry of any Real number from a user. 
 The user then decides if they want their number rounded up to the next whole number, 
 down to the next whole number or to be rounded to the next whole number it is closest to. */
// negative numbers rounding ceiling number goes closer to zero oposite for floor.

#include <iostream>
using namespace std;

int main()

{
	const int FLOOR_ROUND = 1;
	const int CEILING_ROUND = 2;
	const int ROUND = 3;

	int roundingChoice;
	double real_num_entry;

	cout << "Please enter a Real number:" << endl;
	cin >> real_num_entry;
	int firstDigit = real_num_entry;

	cout << "Choose your rounding method:" << endl;
	cout << "1. Floor round" << endl;
	cout << "2. Ceiling round" << endl;
	cout << "3. Round" << endl;
	cin >> roundingChoice;

	int roundUp = firstDigit + 1;
	int choiceThree;

	switch (roundingChoice) {

		case FLOOR_ROUND:
			if (firstDigit >= 0)
				cout << firstDigit << endl;
			else cout << firstDigit - 1;

			break;
		case CEILING_ROUND:
			if (firstDigit >= 0)
				cout << roundUp << endl;
			else cout << firstDigit;

			break;
		case ROUND:
			if (real_num_entry - firstDigit >= .50) {
				choiceThree = firstDigit + 1;
				cout << choiceThree;
				}
			else if (real_num_entry - firstDigit >= .0) 
				cout << firstDigit;
				
			else if (real_num_entry - firstDigit <= -.50) 
				cout << firstDigit - 1;
				
			else if (real_num_entry - firstDigit >= -.49) 
				cout << firstDigit;
				
			break;

		default:
		cout << "That is not a possible entry!" << endl;
			break;

	}
	
	return 0;
}