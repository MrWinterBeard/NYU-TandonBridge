// aew9409_HW4_Q1.cpp : This file contains two programs
// which take an input of a positive intiger from a user
//and prints the corrosponding even numbers up until the intiger entered.
// both the programs achieve the same end. One with a while, and the other with a for loop.

#include <iostream>
using namespace std;

int main()

{
	cout << "section a" << endl;
	int numEntryOne;

	cout << "Please enter a positive integer: ";
	cin >> numEntryOne;
	int evens  = 0;
	int count = 0;
	while (count < numEntryOne) {
		cout << evens + 2 << endl;
		evens += 2;
		count++;
		 }


	cout << "section b" << endl;

	int numEntryTwo;
	int evensTwo = 0;

	cout << "Please enter a positive integer: ";
	cin >> numEntryTwo;

	for (count = 0; count < numEntryTwo; count++) {
		cout << evensTwo + 2 << endl;
		evensTwo += 2;
	}


	return 0;
}
