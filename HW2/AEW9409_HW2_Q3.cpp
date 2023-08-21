// AEW9409_HW2_Q3.cpp : This program takes the days, hours and minutes of two 
// workers and adds them together, producing a combined total.

#include <iostream>
using namespace std;

int main()

{
	const int mins_in_hr = 60, hrs_in_day = 24;

	int johnDays, johnHrs, johnMins, billDays, billHrs, billMins;
	johnDays = johnHrs = johnMins = billDays = billHrs = billMins = 0;

	cout << "Please enter the number of days John has worked:";
	cin >> johnDays;
	cout << "please enter the number of hours John has worked:";
	cin >> johnHrs;
	cout << "please enter the number of minutes John has worked:";
	cin >> johnMins;
	cout << "\n\n";
	cout << "Please enter the number of days Bill has worked:";
	cin >> billDays;
	cout << "please enter the number of hours Bill has worked:";
	cin >> billHrs;
	cout << "please enter the number of minutes Bill has worked:";
	cin >> billMins;

	int minsOut = johnMins + billMins;

	int hoursOut = minsOut / mins_in_hr;

	minsOut = minsOut % mins_in_hr;

	hoursOut = johnHrs + billHrs + hoursOut;

	int daysOut = hoursOut / hrs_in_day;

	hoursOut = hoursOut % hrs_in_day;

	daysOut = johnDays + billDays + daysOut;
	cout << "\n\n";

	cout << "The total time both of them worked together is:" << daysOut << " days, "
	<< hoursOut << " hours and " << minsOut << " minutes." << endl;
	
	return 0;
}