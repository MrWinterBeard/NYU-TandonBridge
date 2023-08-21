// aew9409_HW11_Q2.cpp : 
//

#include <iostream>
#include <cmath>

using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main()
{
    const int arrSize = 4;
    int arr[arrSize];
    cout << "Please enter 4 numbers to add to the array: " << endl;

    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }
    
    
    int answer = sumOfSquares(arr, arrSize);

    cout << " The sum of squares is : " << answer << endl;

    bool inOrder = isSorted(arr, arrSize);
    if (inOrder == true) {
        cout << "arr is in ascending order." << endl;
    }
    else {
        cout << "arr is not in ascending order." << endl;
    }
}

int sumOfSquares(int arr[], int arrSize)
{
    int answer = 0;
    if (arrSize > 0) {
        answer = sumOfSquares(arr, arrSize - 1);
        answer += arr[arrSize - 1] * arr[arrSize - 1];
        cout << answer << endl;
    }  
    return answer;
}
bool isSorted(int arr[], int arrSize)
{
    bool isInOrder = true;
    if (arrSize <= 1) {
        return isInOrder;

    }
    if (arr[arrSize - 2] <= arr[arrSize - 1]) {

        isInOrder = isSorted(arr, arrSize - 1);
    }
    else {
        isInOrder = false;
        return isInOrder;
    }
       
        
    

    
}