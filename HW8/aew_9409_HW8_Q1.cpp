// aew_9409_HW8_Q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
const int MAX_NUMBER_ENTRYS = 20;
int minInArray(int arr[], int arrSize);
void indFind(int arr[], int arrSize, int min);

int main()
{
    int twentyNums;
    int twentyList[MAX_NUMBER_ENTRYS];
    int currentNum;
    const int NumOfEntry = 20;
    int minNum;

    cout << "Please enter 20 integers seperated by a space:" << endl;
    int ind;
    for (ind = 0; ind < NumOfEntry; ind++) {
        cin >> currentNum;
        twentyList[ind] = currentNum;

    }
   minNum = minInArray(twentyList, MAX_NUMBER_ENTRYS);

   cout << "The minimum value is " << minNum << " and is located in the following indices: ";
   indFind(twentyList, MAX_NUMBER_ENTRYS, minNum);
}
int minInArray(int arr[], int arrSize) {
    int ind;
    int min = arr[0];

    for (ind = 1; ind < MAX_NUMBER_ENTRYS; ind++) {
        if (arr[ind] < min) {
            min = arr[ind];
        }

    }
    return min;
}
void indFind(int arr[], int arrSize, int min)
{
    int ind;
    

    for (ind = 0; ind < MAX_NUMBER_ENTRYS; ind++) {
        if (arr[ind] == min) {
            cout << ind << " ";
        }
    }
    
}