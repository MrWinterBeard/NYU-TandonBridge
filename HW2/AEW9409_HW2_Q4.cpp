/* AEW9409_HW2_Q4.cpp : This program takes two integers from the user and performs + , -, / , *, div and mod operations
 to produce the answer for each.*/

#include <iostream>
using namespace std;

int main()

{
    int numOne = 0;
    int numTwo = 0;
   
    cout << "Please enter two positive integers, separated by a space:" << endl;
    cout << endl;
    cin >> numOne;
    cin >> numTwo;
    cout << endl;
    double divideOne = numOne; // Here the users two integers are being assigned to doubles so that a division with decimal point can be calculated.
    double divideTwo = numTwo;

    int addition = numOne + numTwo;
    int subtract = numOne - numTwo;
    int multiply = numOne * numTwo;
    double divideOut = divideOne / divideTwo;
    int div = numOne / numTwo;
    int mod = numOne % numTwo;

    cout << numOne << " + " << numTwo << " = " << addition << endl 
        << endl;
    cout << numOne << " - " << numTwo << " = " << subtract << endl
        << endl;
    cout << numOne << " * " << numTwo << " = " << multiply << endl
        << endl;
    cout << numOne << " / " << numTwo << " = " << divideOut << endl
        << endl;
    cout << numOne << " div " << numTwo << " = " << div << endl
        << endl;
    cout << numOne << " mod " << numTwo << " = " << mod << endl;

    return 0;
}
