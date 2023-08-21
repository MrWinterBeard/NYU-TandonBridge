// aew9409_HW8_Q5.cpp :
//

#include <iostream>
#include <string>

using namespace std;

string middleNameInitial(string wordTwo);

int main()
{
	cout << "Please enter your first, second and last name. Each followed by a space:" << endl;
	string wordOne, wordTwo, wordThree;
	cin >> wordOne;

	cin >> wordTwo;

	cin >> wordThree;

	cout << wordThree << ", ";
	cout << wordOne << " ";

   cout << middleNameInitial(wordTwo);
   cout << endl;


}

string middleNameInitial(string wordTwo)
{
	string wordTwoFirstletter;
	
		const char period = '.';
		wordTwoFirstletter = wordTwo[0];
		wordTwoFirstletter += period;

		return wordTwoFirstletter;
	

}