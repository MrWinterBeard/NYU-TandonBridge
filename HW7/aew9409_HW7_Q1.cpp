// aew9409_HW7_Q1.cpp : 
//

#include <iostream>
using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
void printCalenderYear(int year, int startingDay);
bool leapYearCheck(int year);

int main()
{   
    int usersStartingDay;
    int yearEntered;
    cout << "Please enter a year for your calender:";
    cin >> yearEntered;
    cout << endl;
    cout << "Please enter a number for the starting day. Where 1 = Mon, 2 = Tue etc: ";
    cin >> usersStartingDay;
    cout << endl;

    
   printCalenderYear(yearEntered, usersStartingDay);
   
   
}

int printMonthCalender(int numOfDays, int startingDay)
{
    int lastDay = 0;
    const int week = 7;

    int firstTabs = startingDay - 1;
    int numOfDaysCounter = 1;
    int weekDayCounter = startingDay;
    
    cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun" << endl;
    while (firstTabs >= 1) {
        cout << "\t";
        firstTabs--;
    }

    for (weekDayCounter; weekDayCounter <= week; weekDayCounter++) {
        cout << numOfDaysCounter << "\t";

        numOfDaysCounter++;
        if (numOfDaysCounter > numOfDays) {
            lastDay = weekDayCounter;
            cout << endl << endl;
            break;
        }
        if (weekDayCounter == week) {
            cout << endl;
            weekDayCounter = 0;
        }
    }
    
    return lastDay;
}
void printCalenderYear(int year, int startingDay)
{
    // divisible by 4 but not by 100 unless it is also divisible by 400 it is a leap year.
   const bool isLeapYear = leapYearCheck(year);
    int feb = 28;
    
      if (isLeapYear == true) {
        feb = 29;
      }
      
    for (int monthCount = 1; monthCount <= 12; monthCount++) {
        int numOfDays = 0;
        switch (monthCount) {
        case 1: cout << "January " << year << endl;
            break;
        case 2: cout << "February " << year << endl;
            break;
        case 3: cout << "March " << year << endl;
            break;
        case 4: cout << "April " << year << endl;
            break;
        case 5: cout << "May " << year << endl;
            break;
        case 6: cout << "June " << year << endl;
            break;
        case 7: cout << "July " << year << endl;
            break;
        case 8: cout << "August " << year << endl;
            break;
        case 9: cout << "September " << year << endl;
            break;
        case 10: cout << "October " << year << endl;
            break;
        case 11: cout << "November " << year << endl;
            break;
        case 12: cout << "December " << year << endl;
            break;
        }
        

        if (monthCount == 1 || monthCount == 3 || monthCount == 5 || monthCount == 7 || monthCount == 8 || monthCount == 10 || monthCount == 12) {
           numOfDays = 31;
        }
        else if (monthCount == 4 || monthCount == 6 || monthCount == 9 || monthCount == 11) {
          numOfDays = 30;
        }
        else if (monthCount == 2) {
          numOfDays = feb;
        }
        else {
            break;
        }
       

        startingDay = printMonthCalender(numOfDays, startingDay) % 7 + 1;
    }

    
}


bool leapYearCheck(int year)
{
    // divisible by 4 but not by 100 unless it is also divisible by 400 it is a leap year.
    bool isLeapYear;
    if (year % 4 == 0 && (year % 100 > 0 || year % 400 == 0)) {
        isLeapYear = true;
    }
    else {
        isLeapYear = false;
    }
    return isLeapYear;
}