// aew9409_HW4_Q5.cpp : This file contains a program that asks the user for an entry of an intiger and 

#include <iostream>
using namespace std;


int main()

{
	int row, space, star, rowEntry;
	row = 0;

	cout << "Please enter a positive intiger:\n";
	cin >> rowEntry;
 
	for (row = rowEntry; row >= 1; row--) {

		for (space = rowEntry - row; space > 0; space--) {
			cout << " ";
		}
		for (star = (row * 2) - 1; star > 0; star--) {
			cout << "*";
		}
		cout << endl;
	}
	for (row = 1; row <= rowEntry; row++) {

		for (space = 1; space <= rowEntry - row; space++) {
			cout << " ";
		}
		for (star = 1; star <= (row * 2) - 1; star++) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}
