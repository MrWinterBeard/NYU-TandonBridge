// aew9409_HW5_Q1.cpp : 
//

#include <iostream>
using namespace std;

int main()

{
    int num;
    
    cout << "Please enter a positive integer:\n";
    cin >> num;
    int printOut;
    for (int countOne = 1; countOne <= num; countOne++) {

        for (int countTwo = 1; countTwo <= num; countTwo++) {
            printOut = countOne * countTwo;

             cout << printOut << '\t';
           
            if (countTwo == num) {
                cout << endl;
            }
        }
    }

    return 0;
}

