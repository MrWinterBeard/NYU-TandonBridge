// aew9409_HW6_Q4.cpp : 
//

#include <iostream>
using namespace std;

void printDivisors(int num);

int main()
{
    int num;

    cout << "Please enter an integer >= 2:";
    cin >> num;
    printDivisors(num);


    
}
void printDivisors(int num)
{
    int sumOFDiv = 0;
    int i = 1;
    for (i ; i <= sqrt(num); i++) {
        if (num % i == 0) {
            cout << i << " ";
            sumOFDiv += i;
        }
    }

    for (i = sqrt(num); i > 0; i--) {
        if (num % i == 0) {
            int divisor = num / i;
            cout << divisor << " ";
            sumOFDiv += divisor;
        }
    }
    cout << sumOFDiv - num;
}