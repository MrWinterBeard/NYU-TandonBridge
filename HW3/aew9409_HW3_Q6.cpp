// aew9409_HW3_Q6.cpp : This program takes the time day, the day of the week and the l
//

#include <iostream>
using namespace std;

int main()


{
	string dayInput;
	int hours, minutes, callLengthInMins;
	char colon;

	cout << "Please enter the time in 24 hour format (hours and minutes seperated by a colon):" << endl;
	cin >> hours >> colon >> minutes;
	cout << "Please enter the day of the week the call was made (In Sa, Su or Ma format etc):" << endl;
	cin >> dayInput;
	cout << "Please enter the length of the call in minutes:";
	cin >> callLengthInMins;

	const double call_between_eight_six_week = .40;
	const double call_after_six_before_eight_week = .25;
	const double call_sat_sun = .15;

	const string monday = "Ma";
	const string tuesday = "Tu";
	const string wednesday = "We";
	const string thursday = "Th";
	const string friday = "Fr";
	const string saturday = "Sa";
	const string sunday = "Su";

	double cost_of_call = 0;

	if (dayInput == saturday || dayInput == sunday) {
		cost_of_call = call_sat_sun * callLengthInMins;
		cout << "The cost of the call is: $" << cost_of_call;
	}
	else {
		if (hours >= 8 && hours < 18 || hours == 18 && minutes == 0) {
			cost_of_call = call_between_eight_six_week * callLengthInMins;
			cout << "the cost of the call is: $" << cost_of_call;
		}
		else {
			cost_of_call = call_after_six_before_eight_week * callLengthInMins;
			cout << "the cost of the call is: $" << cost_of_call;
		}

	}

	return 0;
	

  
}

