// aew9409_HW10_Q3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
void main1();
void main2();
int* searchList(int* numbers, int search, int n, int j, int& indexCount, bool& searchFound);
void printSearchRes(bool searchFound, int indexCount, int search, int* searchResPtr);
int searchList2(vector<int> numbers, int search, vector<int>& searchRes);
void printSearchRes2(const vector<int>& searchRes, int search);
void makemebigger(int*& array, int size); //remember to delete the arr;


int main()
{
	
	main1();
	cout << endl;
	
	main2();
	cout << endl;
	
	
}

void main1() 
{
	cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
	cout << "End your input by typing -1." << endl;
	int size = 5;
	int* numbers = new int[size];

	bool entrynotneg = true;
	int n = 0;
	for (n; entrynotneg; n++) {
		if (n == size) {
			makemebigger(numbers, size);
		}
		cin >> numbers[n];
		
		if (numbers[n] == -1) {
			entrynotneg = false;
		}
	}
	int search;

	cout << "Please enter a number you want to search." << endl;
	cin >> search;

	int indexCount = 0;
	bool searchFound = false;
	int* searchResPtr = searchList(numbers, search, n, size, indexCount, searchFound);
	printSearchRes(searchFound, indexCount, search, searchResPtr);
	delete[] numbers;
	numbers = NULL;
	delete[] searchResPtr;
	searchResPtr = NULL;




	
}

void makemebigger(int*& oldArr, int size)
{

int* newArr = new int[size * 2];
for (int i = 0; i < size; i++) {
	
	newArr[i] = oldArr[i];
}
delete[] oldArr;

oldArr = newArr;

}//remember to delete the arr;

int* searchList(int* numbers, int search, int n, int size, int& indexCount, bool& searchFound) {
	
	int* indexOfNum = new int[size];
	for (int i = 0; i < n; i++) {
		if (numbers[i] == search) {

			indexOfNum[indexCount] = i;
			indexCount++;
			searchFound = true;
		}
	}
	
	return indexOfNum;
}
void printSearchRes(bool searchFound, int indexCount, int search, int* searchResPtr) {

	if (searchFound == true) {
		cout << search << " shows in lines ";

		for (int i = 0; i < indexCount; i++) {

			if (i != indexCount - 1) {

				cout << *searchResPtr << ", ";
				searchResPtr++;
			}
			else {
				cout << *searchResPtr << ".";
			}

		}

	}
	else if (searchFound == false) {
		cout << search << " does not show at all in the sequence.";
	}

}

void main2() {
	cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
	cout << "End your input by typing -1." << endl;
	vector<int> numbers;
	int input;

	while ((cin >> input) && input != -1) {
		numbers.push_back(input);

	}

	int search;
	cout << "Please enter a number you want to search." << endl;
	cin >> search;


	vector<int> searchRes;
	
	



	int n = searchList2(numbers, search, searchRes);
	

	printSearchRes2(searchRes, search);


}
int searchList2(vector<int> numbers, int search, vector<int>& searchRes) {
	
	int n = 0;
	for (int i = 0; i < numbers.size(); i++) {
		if (n == 0) {
			if (numbers[i] == search) {
				searchRes[n] = i;
				n++;
			}

		}
		else if(numbers[i] == search) {
			searchRes.push_back(i);
			n++;
		}
		
	}

	for (int i : searchRes)
		cout << "searchRes: " << i << endl;
	return n;
}
void printSearchRes2(const vector<int>& searchRes, int search)
{
	int n = searchRes.size();
	if (n != 0) {
		cout << search << " shows in lines ";

		for (int i = 0; i < n; i++) {
			if (i != n - 1) {
				cout << searchRes[i] << ", ";
			}
			else {
				cout << searchRes[i] << ".";
			}
		}
	}
	else {
		cout << search << " does not show at all in the sequence." << endl;
	}
	
	

}
