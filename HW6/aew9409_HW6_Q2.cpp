// aew9409_HW6_Q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);//prints triangle with input with spaces from the marign.

void printPineTree(int n, char symbol);// controls input of charactor symbol and number of shifted triangles to be printed.

int main()

{
	char symbol;
	int num;
	cout << "Please enter a number for the amount of triangles in your tree:";
	cin >> num; 
	cout << endl;
	cout << "Please enter the character the tree should be made from:";
	cin >> symbol;
	cout << endl;

	
	printPineTree(num, symbol);
	
	
 
}


void printPineTree(int n, char symbol)
{
	int shift = n;
	
	for (int rows = 2; rows <= n + 1; rows++) {
		
		shift--;
		printShiftedTriangle(rows, shift, symbol);
		

	}
}

void printShiftedTriangle(int num, int shift, char symbol)
{
	int spaces = num + shift;
	int spaceReset = spaces;
	
	
	for (int row = 1; row <= num; row++) {

		
		while (spaces > row) {
			cout << " ";
			spaces--;
		}


		for (int starCount = 0; starCount < row * 2 - 1; starCount++) {
			cout << symbol;

		}

		cout << endl;
		spaces = spaceReset;
	}
}
