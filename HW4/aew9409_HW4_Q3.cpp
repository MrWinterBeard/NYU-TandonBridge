// aew9409_HW4_Q3.cpp : This file contains a program that takes a users decimal entry and converts it to binery.
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    unsigned number;

    cout << "Please enter a number: \n";
    cin >> number;
    unsigned binary = 1;
    const int one = 1;
    const int zero = 0;
    bool keepLooping = true;

    for (int count = 0; count < 31 && keepLooping; count++) {
        if (number < binary) {
            keepLooping = false;

        }
        else {
            binary *= 2;
        }
    }
    if (binary > number)
        binary /= 2;

    while (binary > 0) {
        if (number >= binary) {
            number -= binary;
            cout << one;
        }
        else {
            cout << zero;
        }
        binary /= 2;
    }
}