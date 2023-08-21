// aew9409_HW11_Q3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
int minInArray1(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);

int main() {
	int arr[10] = { 9, -2, 14, 12, 3, 6, 2, 1, -9, 15 };
	int res1, res2, res3, res4;
	

	res1 = minInArray1(arr, 10);

	res2 = minInArray2(arr, 0, 9);

	cout << " res 1: " << res1 << " " << "res 2:" << res2 << endl; //should both be -9
	res3 = minInArray2(arr, 2, 5);

	res4 = minInArray1(arr + 2, 4); //arr+2 is equivalent to &(arr[2])

	cout << "res 3: " << res3 << " " << "res 4: " << res4 << endl; //should both be 3

	return 0;
}
int minInArray1(int arr[], int arrSize)
{
	

	if (arrSize == 1) {
		return arr[arrSize - 1];
		

	}
	else {
		int minVal;
		minVal = minInArray1(arr, arrSize - 1);
		
		if (minVal < arr[arrSize - 1]) {
			
			
		}
		else {
			minVal = arr[arrSize - 1];
			
			
		}
		return minVal;
	}
	
	
}
int minInArray2(int arr[], int low, int high)
{
	
	if (low == high) {
		
		
		return arr[low];
	}
	else {
		int minVal;
		minVal = minInArray2(arr, low, high - 1);
		
		
		if (minVal < arr[high]) {
			return minVal;
		}
		else {
			minVal = arr[high];
			return minVal;
		}
	}

	

}
