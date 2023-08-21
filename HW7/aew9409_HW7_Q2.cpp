// aew9409_HW7_Q2.cpp :
//

#include <iostream>
using namespace std;
void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main()
{
    int outCountDivs = 0;
    int outSumDivs = 0;
    int num = 1;
    int userEntry;
    bool perfectNumCheck;
    cout << "Please enter a positive integer >= 2: ";
    cin >> userEntry;

    for (num; num <= userEntry; num++) {

        perfectNumCheck = isPerfect(num);

        if (perfectNumCheck == true) {
            cout << num << " is a perfect number." << endl;
        }
        else {

            analyzeDividors(num, outCountDivs, outSumDivs);
            if (outSumDivs <= userEntry) {

                int sumOfDivsHolder = outSumDivs;

                analyzeDividors(sumOfDivsHolder, outCountDivs, outSumDivs);
                if (outSumDivs == num && outSumDivs > 1 && sumOfDivsHolder < outSumDivs) {

                    cout << sumOfDivsHolder << " and " << outSumDivs << " are amicable numbers." << endl;
                }
            }


        }


    }


}
void analyzeDividors(int num, int& outCountDivs, int& outSumDivs)
{
    int divCount = 0;
    int sumOfDiv = 0;
    int i = 1;
    int midDiv = 0;
    for (i; i <= sqrt(num); i++) {
        if (num % i == 0) {
            divCount++;
            sumOfDiv += i;
            midDiv = i;
        }
    }

    for (i = sqrt(num); i > 0; --i) {
        if (num % i == 0) {

            int divisor = num / i;
            if (divisor != midDiv && divisor < num) {
                sumOfDiv += divisor;
                divCount++;
            }

        }
    }

    outSumDivs = sumOfDiv;
    outCountDivs = divCount;

}
bool isPerfect(int num)
{
    int outCountDivs = 0;
    int outSumDivs = 0;
    analyzeDividors(num, outCountDivs, outSumDivs);
    bool perfectNumCheck;
    if (num == outSumDivs && num >= 2) {
        perfectNumCheck = true;
    }
    else {
        perfectNumCheck = false;
    }
    return perfectNumCheck;
}