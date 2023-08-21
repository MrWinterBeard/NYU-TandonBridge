// aew_HW4_Q2.cpp : This file contains a program which lets a user input a positive intiger
// and then converts it to a roman numeral system.

#include <iostream>
using namespace std;

int main()

{
int decimalNumber;
string d, m, c, l, x, v, i;
	

	cout << "Enter a decimal number:\n";
	cin >> decimalNumber;
	cout << decimalNumber << " is ";

	const int thousand = 1000;
	while (decimalNumber >= thousand) {
		m += "M";
		decimalNumber -= thousand;
	}
	cout << m;

	const int fiveHundred = 500;
	while (decimalNumber >= fiveHundred) {
		d += "D";
		decimalNumber -= fiveHundred;
	}
	cout << d;

	const int hundred = 100;
	while (decimalNumber >= hundred) {
		c += "C";
		decimalNumber -= hundred;
	}
	cout << c;

	const int fifty = 50;
	while (decimalNumber >= fifty) {
		l += "L";
		decimalNumber -= fifty;
	}
	cout << l;

	const int ten = 10;
	while (decimalNumber >= ten) {
		x += "X";
		decimalNumber -= ten;
	}
	cout << x;

	const int five = 5;
	while (decimalNumber >= five) {
		v += "V";
		decimalNumber -= five;
	}
	cout << v;


	const int one = 1;
	while (decimalNumber >= one) {
		i += "I";
		decimalNumber -= one;
	}
	cout << i;

	return 0;
}
