// aew9409_HW3_Q5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()

{
	double weight, height, height_in_meters_squared, weight_in_kg;

	cout << "Please enter weight (in pounds):\n";
	cin >> weight;
	cout << "Please enter height (in inches):\n";
	cin >> height;

	weight_in_kg = weight * 0.453592;
	height_in_meters_squared = height * 0.0254;
	height_in_meters_squared *= height_in_meters_squared;

	double bmi = weight_in_kg / height_in_meters_squared;

	if (bmi < 18.5)
		cout << "The weight status is: Underweight \n";
	else if (bmi >= 18.5 || bmi < 25)
		cout << "The weight status is: Normal \n";
	else if (bmi >= 25 && bmi < 30)
		cout << "The weight status is: Overweight \n";
	else if (bmi >= 30)
		cout << "The weight status is: Obese \n";

	else 
		cout << "Invalid entry. \n";

	return 0;

}
