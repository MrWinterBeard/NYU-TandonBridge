// aew9409_HW9_Q4.cpp :
//

#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);

int main()
{
	int arr[6] = { 5, 2, 11, 7, 6, 4 };
	const int arrSize = 6;

	//after calling oddsKeepEvensFlip(arr, 6), arr will be: 5, 11, 7, 4, 6, 2

	oddsKeepEvensFlip(arr, arrSize);
}

void oddsKeepEvensFlip(int arr[], int arrSize)
{
	int* oddArr = new int[arrSize];
	int oddCount = 0;
	int* evenArr = new int[arrSize];
	int evenCount = 0;

	for (int i = 0; i < arrSize; i++) {
		if (arr[i] % 2 > 0) {
			oddArr[oddCount] = arr[i];
			oddCount++;
		}
		else {
			evenArr[evenCount] = arr[i];
			evenCount++;
		}
	}

	
	int rhs = evenCount - 1;
	
	for (int i = 0 ; i < evenCount / 2; i++)
	{
		int temp = evenArr[i];
		evenArr[i] = evenArr[rhs];
		evenArr[rhs] = temp;
		rhs--;
	}
	

	
	int j = 0;
	for (int i = 0; i < arrSize; i++) {
		if (i < oddCount)
		arr[i] = oddArr[i];
		else {
			arr[i] = evenArr[j];
			j++;
		}
	}
	delete[] oddArr;
	delete[] evenArr;
	cout << "arr elements after function: ";
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}


}
