// aew9409_HW8_Q3.cpp :
//

#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize);
void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);



int main()
{
	int arr1[10] = { 9, 2, 14, 12, -3 };
	int arr1Size = 5;

	int arr2[10] = { 21,12, 6, 7, 14 };
	int arr2Size = 5;

	int arr3 [10] = { 3, 6, 4, 1, 12 };
	int arr3Size = 5;

	reverseArray(arr1, arr1Size);
	printArray(arr1, arr1Size);

	removeOdd(arr2, arr2Size);
	printArray(arr2, arr2Size);

	splitParity(arr3, arr3Size);
	printArray(arr3, arr3Size);

	return 0;

}

void printArray(int arr[], int arrSize) 
{
	int i;

	for (i = 0; i < arrSize; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}
void reverseArray(int arr[], int arrSize)
{
	int lhs = 0;
	int rhs = arrSize - 1;

	while (lhs < rhs) {
		//swap using temp
		int temp = arr[lhs];
		arr[lhs] = arr[rhs];
		arr[rhs] = temp;
		//Update ind and arraysize
		lhs++;
		rhs--;

	}


}
void removeOdd(int arr[], int& arrSize)
{
	int rhs = arrSize - 1;
	int lhs = 0;

	while (lhs <= rhs) {
		if (arr[lhs] % 2 == 1) {
			int temp = arr[rhs];
			arr[rhs] = arr[lhs];
			arr[lhs] = temp;

			arrSize--;
			rhs--;
		}
		else {
			lhs++;
		}
	}


}

void splitParity(int arr[], int arrSize)
{
	int lhs = 0, rhs = (arrSize - 1);

	while (rhs >= lhs) {

		if (arr[rhs] % 2 != 0)
		{
			if (arr[lhs] % 2 == 0)
			{

				int temp = arr[rhs];
				arr[rhs] = arr[lhs];
				arr[lhs] = temp;

				lhs++;
				rhs--;
			}
			else
				lhs++;
		}
		else
			rhs--;
	}
}