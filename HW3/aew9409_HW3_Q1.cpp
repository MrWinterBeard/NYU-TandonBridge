// aew9409_HW3_Q1.cpp : This program calculates the total price for a customer buying two items 
// in a buy one get one half price promotion where the lower prced item is discounted. 
// If the customer is a club card member a further 10% is discounted from the two items being purchased.
// Tax is then added to bring up the total price of the transaction.

#include <iostream>
using namespace std;

int main()
{
	double tax, first_item, second_item;
	char clubCardEntry, yesClubCardCap, noClubCardCap, yesClubCardLow, noClubCardLow;
	yesClubCardCap = 'Y', noClubCardCap = 'N', yesClubCardLow = 'y', noClubCardLow = 'n';

	cout << "Enter price of first item:";
	cin >> first_item;
	cout << "Enter price of second item:";
	cin >> second_item;
	cout << "Does customer have a club card? (Y/N):";
	cin >> clubCardEntry;
	cout << "Enter tax rate e.g 5.5 for 5.5% tax:";
	cin >> tax;

	double base_price = second_item + first_item;
	cout << "Base price: " << base_price << endl;

	double promo_price = 0.; /* "promo_price" updates throughout the rest of the program
	depending on wether the customer is a club card member. */ 
	double promotionDiscount = 2.0;

	if (first_item <= second_item) {
		first_item /= promotionDiscount;
	}
	else {
		second_item /= promotionDiscount;
		
	}
	promo_price = second_item + first_item;
	double club_card_discount = .90;

	if (clubCardEntry == yesClubCardCap || clubCardEntry == yesClubCardLow) {
		promo_price *= club_card_discount;
	}
	cout << "Price after discounts: " << promo_price << endl;
	double price_with_tax = ((100 + tax) / 100) * promo_price;

	cout << "Total price: " << price_with_tax << endl;

	return 0;
}
