// aew9409_HW6_Q1.cpp :
//

#include <iostream>
using namespace std;

int fibOut(int num);
// This Function takes the entry of an int "num" and computes its corosponding fibancci number
// for example if "num" is 7 the function returns 13. The seventh fibanacci number.

int main()

{
    int num;

    cout << "Please enter a positive integer: ";
    cin >> num;

    int usersFibNum = fibOut(num);

    cout << usersFibNum;

}

int fibOut(int num) {
    int currentFib = 1;
    int temp = 0;
    int a = 0;
    int b = 0;
    for (int numCount = 2; numCount <= num; numCount++) {


        temp = a;
        a = currentFib;
        b = temp;

        currentFib = a + b;

        int fibOut = a + b;
        if (numCount == num) {
            return fibOut;
        }

    }
}