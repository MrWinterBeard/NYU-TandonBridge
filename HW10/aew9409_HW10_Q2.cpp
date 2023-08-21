// aew9409_HW10_Q2.cpp : 
//

#include <iostream>
#include <string>

using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main()
{
    const int n = 8;
    int arr[n] = { 1, 1, 5, 6, 6, 6, 7, 7 };
    int resArrSize = 0;


   

    int* missingPtr = findMissing(arr, n, resArrSize);
    delete[] missingPtr;
    missingPtr = NULL;
    
}


int* findMissing(int arr[], int n, int& resArrSize)
{
    int* missingNums = new int[n];

    int i = 0;
    int j = 0;
    int index = 0;

    while (i < n ) {
        if (i == arr[j]) {
            i++;
            j++;
        }
        if (i > arr[j]) {
            n++;
        }
        if (i < arr[j]) {
            missingNums[index] = i;
            i++;
        }
        else {
            cout << "something wrong" << endl;
            cout << "j= " << j << endl;
            cout << "i= " << i << endl;
            break;
        }
            
        
    }
    resArrSize = index;


    return missingNums;

}
