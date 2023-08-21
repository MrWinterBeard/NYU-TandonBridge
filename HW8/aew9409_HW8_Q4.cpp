// aew9409_HW8_Q4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void fillInMappedValue(char *mapping, int digits);
bool passwordCheck(const char *mapping, string password, string passwordEntry);

const string password = "12345";

int main()
{
	cout << "Please enter your pin according to the folling mapping:" << endl;
	cout << "PIN:";
	for (int i = 0; i < 10; ++i)
		cout << ' ' << i;
	cout << endl;
	cout << "NUM: ";
	srand(time(0));
	const int digits = 10;
	char mapping[digits];
	fillInMappedValue(mapping, digits);

	string passwordEntry;
	cin >> passwordEntry;

	bool passwordIsMatch = passwordCheck(mapping, password, passwordEntry);

	if (passwordIsMatch == true) {
		cout << "Your PIN is correct." << endl;
	}
	else {
		cout << "Your PIN is not correct." << endl;
	}
}

void fillInMappedValue(char *mapping, int digits)
{
	for (int i = 0; i < digits; i++) {

		char currentDigit = '1' + (rand() % 3);
		cout << currentDigit << " ";

		mapping[i] = currentDigit;
		
	}
	cout << endl;
}
bool passwordCheck(const char *mapping, string password, string passwordEntry)
{
	string mappedPassword;
	for (int i = 0; i < password.length(); i++) {
		const int index = password[i] - '0';
		mappedPassword += mapping[index];
	}

	return passwordEntry == mappedPassword;

}