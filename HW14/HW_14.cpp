// HW_14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

vector <int> getMinAndMax(vector <int> array, int start, int end);

int main()
{
	vector <int> array;
	array.push_back(1);
	array.push_back(2);
	array.push_back(0);
	array.push_back(7);
	array.push_back(20);
	array.push_back(6);
	
	
	int start = 0;
	int end = array.size();
	
	vector <int> result = getMinAndMax(array, start, end);

	cout << "The Min and Max values are: ";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}

vector <int> getMinAndMax(vector <int> array, int start, int end) {

	int min;
	int max;
	//cout << "flag ";
	if (start + 1 == end ) { // in case of size 1
		max = (array[start]);
		min = (array[start]);
	}
	else if (start + 2 == end) { // in case of size 2
		if (array[start] > array [end - 1]) {
			max = (array[start]);
			min = (array[end - 1]);
		}
		else  {
			max = (array[end - 1]);
			min = (array[start]);
		}
		

		
	}
	else {
		
		int mid = start + (end - start) / 2;
		//cout << "mid: "<< mid << endl;
		vector <int> halfOne = getMinAndMax(array, start, mid);
		vector <int> halfTwo = getMinAndMax(array, mid, end);

		if (halfOne[1] > halfTwo[1]) {
			max = (halfOne[1]);
		}
		else {
			max = (halfTwo[1]);
		}
			
		
		if (halfOne[0] < halfTwo[0]) {
			min = (halfOne[0]);
			
		}
		else {
			min = (halfTwo[0]); 
		}
		/**cout << "half one ";
		for (int i = 0; i < halfOne.size(); i++) {
			cout << halfOne[i] << " ";
		}
		cout << "half Two ";
		for (int i = 0; i < halfTwo.size(); i++) {
			cout << halfTwo[i] << " ";
		}*/
	}
	

	
	vector <int> results;
	results.push_back(min);
	results.push_back(max);

	return results;


}
/*
vector <int> array = {10, 2, 6, 8, 13};
int min, max;

int start = 0;
int end = array.length() - 1;
int mid;

int getMinAndMax( vector <int> array, start, mid)

1: if the vector array is of length 1{
max and min are the same.
}
if the vector array is of length 2{
then if( ar[0] > ar[1]) then{
ar[0] is the max.
ar[1] is the min.
}
else ar[1] is larger{
ar[1] is the max.
ar[0] is the min.
}

2: if not the above{
divide vect array by 2
mid = array.length() / 2 - 1;
}
3: now the recursion

int placeholder1 getMinAndMax( vector <int> array, start, mid) (they kind of showed us this in a video for a sorting algorithm) so i can go back and re watch).
int placeholder2 getMinAndMax( vector <int> array, mid + 1, end)

4:  Comparison of place holders.

if (placeHolder1 > placeHolder2) {
max = placeHolder1;
min = placeHolder 2;
}
else if (placeHolder1 > placeHolder2){
max = placeHolder 1;
min = placeHolder 2;
}
else {
max = placeHolder 2
min = placeHolder 1
}

vector <int> minAndMax;
push_back(min);
push_back(max);

*/