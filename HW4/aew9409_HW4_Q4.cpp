// aew9409_HW4_Q4.cpp : This file contains two programs that
// take user entered positive inigers and calculate the gometric mean of the entered values.
// Program one uses a pre determined length by the user to know when the sequence has been 
// completed while "section b" uses a technique which asks the user to enter -1 to indicate 
// the sequnce has been completed and a bool flag operator nested inside an if statement inside a loop.

#include <iostream>
#include <cmath>
using namespace std;

int main()

{
	cout << "Section a\n";

	int length;
	int sum = 1;
	int count, current;
	

	cout << "Please enter the length of the sequence: ";
	cin >> length;
	cout << endl;
	cout << "Please enter your sequence: \n";
	current = 0;
	count = 0;

	for (count = 1; count <= length; count++) {
		cin >> current;
		sum *= current;
	}
	double numerator = 1;
	double geo_mean = pow((double)sum, numerator / (double)length);

	cout << "The geometric mean is: " << geo_mean << endl;

	cout << "Section b\n";

	bool seenEndOfInput;
	int sumTwo = 1;
	int countTwo, currentTwo;

	cout << "Please enter a non-empty sequence of positive intigers, each one in a seperate line. End your sequence by typing -1:\n";
	seenEndOfInput = false;
	countTwo = 0;
	currentTwo = 0;

	while (seenEndOfInput == false) {
		cin >> currentTwo;
		if (currentTwo == -1)
			seenEndOfInput = true;

		else {
			sumTwo *= currentTwo;
			countTwo++;
		}
	}
	double numeratorTwo = 1;
	double geo_meanTwo = pow((double)sumTwo, numeratorTwo / (double)countTwo);

	cout << "The geometric mean is: " << geo_meanTwo << endl;

	return 0;

}

