// aew9409_HW6_Q3.cpp : 
//

#include <iostream>
using namespace std;

double eApprox(int n);
// This function returns the nth iteration of the logarythm e.
// the higher the users entry the closer the closer the appoximation returned is to log e.

int main()
{
    cout.precision(30);

    int num;
    double e;
    cout << "Please enter a positive integer:";
    cin >> num;
    e = eApprox(num);
    cout << e;
}

double eApprox(int n) 
{
    double factorial = 1;
    double e = 1;
    for (int count = 1; count <= n; count++) {
        factorial *= count;
        e += 1 / factorial;
    }
    return e;
}