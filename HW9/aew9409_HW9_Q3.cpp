// aew9409_HW9_Q3.cpp :
//

#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);


void printOutput(int* output1, int outPosArrSize);
void printOutput2(int* output1, int* outPosArrSizePtr);
void printOutput3(int* output1, int outPosArrSize);
void printOutput4(int* output1, int* outPosArrSizePtr);

int main()
{
	int arr[] = { 3, -1, -3, 0, 6, 4 };
	const int arrSize = 6;
	int outPosArrSize = 0;

	int* output1 = getPosNums1( arr, arrSize, outPosArrSize);
	printOutput(output1, outPosArrSize);
	delete[] output1;

	outPosArrSize = 0;
	int* outPosArrSizePtr = &outPosArrSize;

	int* output2 = getPosNums2(arr, arrSize, outPosArrSizePtr);

	printOutput2(output2, outPosArrSizePtr);
	delete[] output2;

	int* outPosArr = 0;

	getPosNums3(arr, arrSize, outPosArr, outPosArrSize);

	printOutput3(outPosArr, outPosArrSize);
	delete[] outPosArr;

	int* outPosArrPtr = 0;
	getPosNums4(arr, arrSize, &outPosArrPtr, outPosArrSizePtr);

	printOutput4(outPosArrPtr, outPosArrSizePtr);
	delete[] outPosArrPtr;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize)
{
	int newArrSize = 0;
	
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			newArrSize++;
		}
	}

	outPosArrSize = newArrSize;
	int* outArray = new int[newArrSize];
	int j = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			outArray[j] = arr[i];
			j++;
		}
	}
	
	return outArray;


}
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr)
{
	int newArrSize = 0;

	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			newArrSize++;
		}
	}

	*outPosArrSizePtr = newArrSize;
	int* outArray = new int[newArrSize];
	int j = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			outArray[j] = arr[i];
			j++;
		}
	}

	return outArray;


}
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize)
{
	int newArrSize = 0;

	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			newArrSize++;
		}
	}
	outPosArr = new int[newArrSize];
	outPosArrSize = newArrSize;
	int j = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			outPosArr[j] = arr[i];
			j++;
		}
	}

}
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr)
{
	int newArrSize = 0;

	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			newArrSize++;
		}
	}
	*outPosArrPtr = new int[newArrSize];
	int* outPosArr = *outPosArrPtr;

	*outPosArrSizePtr = newArrSize;
	int j = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			outPosArr[j] = arr[i];
			j++;
		}
	}

}

void printOutput(int* output1, int outPosArrSize)
{
	cout << "Function Version One:" << endl;
	cout << "Returned Address which points to Array of positive integers is : " << output1 << endl;
	cout << "The size of the postive array is: " << outPosArrSize << endl;
	cout << "The positive numbers from the aray are: ";
	for (int i = 0; i < outPosArrSize; i++) {
		cout << output1[i] << ", ";
	} 
	cout << endl << endl;
}
void printOutput2(int* output1, int* outPosArrSizePtr)
{
	cout << "Function Version Two:" << endl;
	cout << "Returned Address which points to Array of positive integers is : " << output1 << endl;
	cout << "The size of the postive array is: " << *outPosArrSizePtr << endl;
	cout << "The positive numbers from the aray are: ";
	for (int i = 0; i < *outPosArrSizePtr; i++) {
		cout << output1[i] << ", ";
		
	}
	cout << endl << endl;
}
void printOutput3(int* outPosArr, int outPosArrSize)
{
	cout << "Function Version Three:" << endl;
	cout << "Returned Address which points to Array of positive integers is : " << outPosArr << endl;
	cout << "The size of the postive array is: " << outPosArrSize << endl;
	cout << "The positive numbers from the aray are: ";
	for (int i = 0; i < outPosArrSize; i++) {
		cout << outPosArr[i] << ", ";

	}
	cout << endl << endl;
}
void printOutput4(int* outPosArrPtr, int* outPosArrSizePtr)
{
	cout << "Function Version Four:" << endl;
	cout << "Returned Address which points to Array of positive integers is : " << outPosArrPtr << endl;
	cout << "The size of the postive array is: " << *outPosArrSizePtr << endl;
	cout << "The positive numbers from the aray are: ";
	for (int i = 0; i < *outPosArrSizePtr; i++) {
		cout << outPosArrPtr[i] << ", ";

	}
	cout << endl << endl;
}