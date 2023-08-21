// aew9409_HW3_Q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()

{
	string userName;
	int graduationYear, currentYear;
	cout << "Please enter your name: ";
	cin >> userName;
	cout << "Please enter your graduation year: ";
	cin >> graduationYear;
	cout << "Please enter current year: ";
	cin >> currentYear;


	if (graduationYear - currentYear == 4)
		cout << userName << " you are a Freshman.";

	else if (graduationYear - currentYear == 3)
		cout << userName << " you are a Sophomore.";

	else if (graduationYear - currentYear == 2)
		cout << userName << " you are a Junior.";

	else if (graduationYear - currentYear == 1)
		cout << userName << " you are a Senior.";

	else if (currentYear >= graduationYear)
		cout << userName << " you have Graduated.";
	else if (graduationYear - currentYear >= 5)
		cout << userName << " you are not in college yet.";
	

	return 0;

}

