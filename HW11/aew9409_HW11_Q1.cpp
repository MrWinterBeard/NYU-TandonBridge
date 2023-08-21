// aew9409_HW11_Q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void printTriangle(int n);
void printOpositeTriangles(int n);
void printRuler(int n);

int main()
{

    int n;
    cout << " Please enter a number for your triangle:" << endl;
    cin >> n;

    

    printTriangle(n);

    cout << "Please enter a second number for your second triangle shape:" << endl;
    cin >> n;

    printOpositeTriangles(n);

    cout << "Please enter a third number for the size of your ruler:" << endl;
    cin >> n;

    printRuler(n);


    
}

void printRuler(int n)
{

    if (n == 1) {
        cout << "-" << endl;
    }
    else {
        printRuler(n - 1);
        for (int i = 0; i < n; i++) {
            cout << "-";
        }
        cout << endl;
        printRuler(n - 1);
    }
    

   

}
void printTriangle(int n)
{
    if (n == 0) {
       
    }
    else {
        printTriangle(n - 1);
        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << endl;

    }
        
}

void printOpositeTriangles(int n)
{
    
 
    for (int i = 0; i < n; ++i) {
        cout << '*';
        
    }
    cout << endl;

    if (n > 1) {
        printOpositeTriangles(n - 1);
    }
   
    for (int i = 0; i < n; ++i){
        cout << '*';
        
    }
    cout  << endl;

}

