// aew9409_HW_12.cpp : 

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cctype>

using namespace std;




class Money
{
public:
    friend Money operator +(const Money & amount1, const Money & amount2);
    //Returns the sum of the values of amount1 and amount2.
        friend Money operator -(const Money & amount1, const Money & amount2);
    //Returns amount1 minus amount2.
        friend Money operator -(const Money & amount);
    //Returns the negative of the value of amount.
        friend bool operator ==(const Money & amount1, const Money & amount2);
    //Returns true if amount1 and amount2 have the same value; false otherwise.
        friend bool operator <(const Money & amount1, const Money & amount2);
    //Returns true if amount1 is less than amount2; false otherwise.
        Money(long dollars, int cents);
    //Initializes the object so its value represents an amount with
        //the dollars and cents given by the arguments. If the amount
        //is negative, then both dollars and cents should be negative.
        Money(long dollars);
    //Initializes the object so its value represents $dollars.00.
        Money();
    //Initializes the object so its value represents $0.00.
        double get_value() const;
    //Returns the amount of money recorded in the data portion of the calling
        //object.
        friend istream & operator >>(istream & ins, Money & amount);
    //Overloads the >> operator so it can be used to input values of type
        //Money. Notation for inputting negative amounts is as in − $100.00.
        //Precondition: If ins is a file input stream, then ins has already been
        //connected to a file.
    
        friend ostream & operator <<(ostream & outs, const Money & amount);
    //Overloads the << operator so it can be used to output values of type
        //Money. Precedes each output value of type Money with a dollar sign.
        //Precondition: If outs is a file output stream, then outs has already been
        //connected to a file.
private:
    long all_cents;
};
Money::Money(long dollars, int cents) {
    if (dollars * cents < 0) {
        cout << "illegal values for dollars and cent." << endl;
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}
Money::Money(long dollars) : all_cents(dollars * 100) {

}
Money::Money() : all_cents(0) {

}
double Money::get_value() const{
    return (all_cents * 0.01);
}

Money operator +(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}
bool operator <(const Money& amount1, const Money& amount2) {
    if (amount1.all_cents < amount2.all_cents) {
        return true;
    }
    else {
        return false;
    }
}

bool operator ==(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents == amount2.all_cents);
}
Money operator -(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}
Money operator -(const Money& amount)
{
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}
ostream& operator <<(ostream& outs, const Money& amount)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    cents = positive_cents % 100;
    dollars = positive_cents / 100;

    if (amount.all_cents < 0) {
        outs << "-$" << dollars << '.';
    }
    else {
        outs << "$" << dollars << '.';
    }
    if (cents < 10) {
        outs << '0' << cents;
    }
    else{
        outs << cents;
    }

    return outs;
}
int digit_to_int(char digit) {
   return digit - '0';
    
}
bool isdigit(char digit) {
    return digit >= '0' && digit <= '9';
}
istream& operator >>(istream& ins, Money& amount)
{
    char one_char, decimal_point, digit1, digit2;
    long dollars;
    int cents;
    bool negative;

    ins >> one_char;
    if (one_char == '-') {
        negative = true;
        ins >> one_char;
    }
    else {
        negative = false;
    }
        ins >> dollars >> decimal_point >> digit1 >> digit2;
        if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)) {
            cout << "Error illegal form for money input" << endl;
            exit(1);
        }
        cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);

        amount.all_cents = dollars * 100 + cents;
        if (negative) {
            amount.all_cents = -amount.all_cents;
        }
    
    return ins;
}

//typedef double Money; // change this!!



class Check {

    int checkNum;
    Money amount;
    bool isCashed;
public:
    Check() {
        checkNum = 0;
        isCashed = false;
    };

    Check(int CheckNum, Money Amount, bool IsCashed) {
        checkNum = CheckNum;
        amount = Amount;
        isCashed = IsCashed;

    }

    friend istream& operator >>(istream& ins, Check& check);
    friend ostream& operator <<(ostream& outs, const Check& check);
    int getCheckNum()const { return checkNum; }
    Money getCheckAmount()const { return amount; }
    double getIsCashed()const { return isCashed; }
    friend bool operator <(const Check& amount1, const Check& amount2);
};

bool operator <(const Check& amount1, const Check& amount2) {
    if (amount1.checkNum < amount2.checkNum) {
        return true;
    }
    else {
        return false;
    }
}

istream& operator >>(istream& ins, Check& check) {
    ins >> check.checkNum >> check.amount >> check.isCashed;
    return ins;
}
ostream& operator <<(ostream& outs, const Check& check) {
    outs << "Check Number: " << check.checkNum << " Value: " << check.amount << " Cashed status: ";
    if (check.isCashed == 1) {
        outs << "CASHED." << endl;
    }
    else {
        outs << "NOT-Cashed." << endl;
    }
      
    return outs;
}
void SortDeposits(vector <Check>& checks);


int main()
{
    vector <int> depositList;
    Money deposits = 0.00;
    int n;
    Money totalDeposits = 0.00;
    cout << "Please enter how many deposits you want to make:" << endl;
    cin >> n;

    cout << "Please enter the deposits: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> deposits;
        totalDeposits = totalDeposits + deposits;
    }
   
    
   int arrSize;
    
   // vector <Check> arr[10];
    cout << "How many checks do you have to enter: " << endl;
    cin >> arrSize;
    Check *arr = new Check[arrSize]; // remember to delete [] arr;

    for (int i = 0; i < arrSize; i++) {
        cout << "Check: " << i + 1 << endl;
        cout << "Enter the Check number, the amount and whether it has been cashed with a '1' for YES and '0' for NO:" << endl;
        cin >> arr[i]; 
    }
   // for (int i = 0; i < arrSize; i++) {
     //   cout << "Check: " << i + 1 << endl;
    //    cout << arr[i] << endl;
   //  }
    
    Money oldBalance;
    cout << "Please enter the old balance of your account: " << endl;
    cin >> oldBalance;
    Money newBalForcast;
    cout << "Please enter the new balance of your account: " << endl;
    cin >> newBalForcast;

    Money cashedAmountTotal = 0.0;
    Money notCashedAmountTotal = 0.0;
    vector <Check> cashedArr;
    vector <Check> unCashedArr;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i].getIsCashed() == 1) {
            cashedAmountTotal = cashedAmountTotal + arr[i].getCheckAmount();
            cashedArr.push_back(arr[i]);
        }
        else {
            notCashedAmountTotal = notCashedAmountTotal + arr[i].getCheckAmount();
            unCashedArr.push_back(arr[i]);
        }
    }
    cout << endl;
    cout << endl;

    cout << "The total deposits are: " << totalDeposits << endl;

    cout << "Total of cashed checks: " << cashedAmountTotal << endl;

    cout << "Total of un-cashed checks: " << notCashedAmountTotal << endl;

    Money newBalCalculated = oldBalance - cashedAmountTotal + totalDeposits;
    cout << "The new bank balance should be: " << newBalCalculated << endl;
    Money difference = newBalCalculated - newBalForcast;
    SortDeposits(unCashedArr);
    SortDeposits(cashedArr);
    

    cout << "The difference between the users calculated balance and the actual new balance is: " << difference << endl;
    cout << "The un-cashed checks are:" << endl;
    for (int i = 0; i < unCashedArr.size(); i++) {
        
        cout << unCashedArr[i] << endl;
    }
    cout << "The cashed checks are:" << endl;
    for (int i = 0; i < cashedArr.size(); i++) {
        
        cout << cashedArr[i] << endl;
    }

    delete[] arr;
}
void SortDeposits(vector <Check> &chks) {
    Check temp;
    int k;
    bool isSorted = false;
    for (k = 1; k < chks.size(); k++) {
        isSorted = false;

        for (int i = 0; i < chks.size() - k; i++) {

            if (chks[i].getCheckNum() > chks[i + 1].getCheckNum()) {
                temp = chks[i];
                chks[i] = chks[i + 1];
                chks[i + 1] = temp;
                isSorted = true;

            }
        }
        if (isSorted == true) {
            break;
        }
    }
}
