// aew9409_HW4_Q6.cpp : 
#include <iostream>
using namespace std;

int main()

{
    int userEntry;

    cout << "Please enter a positive integer" << endl;
    cin >> userEntry; 
    int count = 1;
    while (count <= userEntry) {

        int workingNum = count;
        int sumOfEvens = 0;
        int sumOfOdds = 0;
        while (workingNum > 0) {
            int currentDigit = workingNum % 10;
            if (currentDigit % 2 == 0) {
                sumOfEvens += 1;
            }
            else {
                sumOfOdds += 1;
            }
            workingNum = workingNum / 10;
            

        }
        if (sumOfEvens > sumOfOdds) {
            cout << count << endl;

        }
        count++; 
    }
}