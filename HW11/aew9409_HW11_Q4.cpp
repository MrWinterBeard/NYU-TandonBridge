// aew9409_HW11_Q4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void jumpit(int arr[], int arrSize, int count, int& sum, int& postion);

int main()
{
    int arrSize = 10;
    int arr[10] = { 0, 3, 80, 6, 57, 10, 13, 7, 8, 1 };
    int position = 0;
    int count = arrSize - 1;





    int sum = 0;


    jumpit(arr, arrSize, count, sum, position);
    cout << "the lowest cost option costs: " << sum << endl;

}
void jumpit(int arr[], int arrSize, int count, int& sum, int& position)
{
    if (arrSize == 1) {
        sum = arr[0];

    }
    else if (arrSize == 2) {
        sum = arr[0] + arr[1];


    }
    else if (arrSize == 3) {
        sum = arr[0] + arr[2];


    }
    else if (count == 0) {
        sum = arr[arrSize - 1] + arr[0];



    }
    else {

        jumpit(arr, arrSize, count - 1, sum, position);


        if (position == arrSize - 2) {

            
            sum = sum;
        }


        else if (arr[position + 1] < arr[position + 2]) {
            sum = sum + arr[count];
            position++;



        }
        else if (arr[position + 1] > arr[position + 2]) {

            sum = sum + arr[position + 2];
            position++;
            position++;

           

        }
       
    }



}


