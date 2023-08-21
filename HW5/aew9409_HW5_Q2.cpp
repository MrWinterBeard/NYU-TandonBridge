// aew9409_HW5_Q2.cpp : This file contains a program which plays a guessing game with the user. the program calculates a
//  number from one to 100 and updates a range of possible numbers the user could choose in order to find the number after 
// each guess. the max guesses is five.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
	int secretNumber;

	srand(time(0));

	secretNumber = 1 + (rand() % 100) + 1;

	cout << "I thought of a number between 1 and 100! Try to guess it." << endl;
	
	int guess;
	int guessesLeft = 5;
	int guessCount = 0;
	const int maxGuess = 5;
	int rangeLow = 1;
	int rangeHigh = 100;

	while (guessCount < maxGuess) {
		guessesLeft = maxGuess - guessCount;
		cout << "Range: [" << rangeLow << ", " << rangeHigh << "], Number of guesses left : " << guessesLeft << endl;
		cout << "Your guess: ";
		cin >> guess;
		guessCount++;

		if (guess == secretNumber) {
			cout << "Congrats! you guessed my number in " << guessCount << " guesses.";
			break;
		}
		else if (guessCount == maxGuess) {
			cout << "Out of guesses! My number is " << secretNumber << endl;
			break;
		}

		else if (guess < secretNumber) {
			rangeLow = guess +1;
			cout << "Wrong! My number is bigger.";
			cout << endl << endl;
		}

		else if (guess > secretNumber) {
			rangeHigh = guess - 1;
			cout << "Wrong! My number is smaller.";
			cout << endl << endl;
		}
		
	}
	
	return 0;
	
}


