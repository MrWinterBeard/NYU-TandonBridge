// aew9409_HW9_Q1.cpp :
//

#include <iostream>
#include <string>

using namespace std;

void wordsFromLine(string line, int& i, int& numOfWords);
void charCount(string, int* letterCount);
string removePunctuation(string line);



const int lettersInAlphabet = 26;

int main()
{
	string line;
	cout << "Please enter a line of text:" << endl;
	getline(cin, line);

	string lineOfLetters = removePunctuation(line);
	cout << " punctuation removed: " << lineOfLetters << endl;
	
	int i = 0;
	int numOfWords = 0;

	while (i < line.length()) {
		wordsFromLine(line, i, numOfWords);

	}
	cout << numOfWords << "\t" << "words" << endl;

	int letterCount[lettersInAlphabet];
	for (int i = 0; i < lettersInAlphabet; i++) {
		letterCount[i] = 0;
	}

	
	charCount(lineOfLetters, letterCount);


	for (int i = 0; i < lettersInAlphabet; i++) {
		if (letterCount[i] > 0) {
			cout << letterCount[i] << "\t" << char('a' + i) << endl;
		}
	}
}

void wordsFromLine(string line, int& i, int& numOfWords)
{
	string word;
	while (i < line.length() && line[i] != ' ' && line[i] != '.' && line[i] != ',') {
		word += line[i];
		i++;

	}
	while (i < line.length() && (line[i] == ' ' || line[i] == '.' || line[i] == ',')) {
		i++;
	}
	if (word.length() > 0) {
		numOfWords++;
	}
}

string removePunctuation(string line)
{
	string lineOfLetters;
	for (int i = 0; i <= line.length(); i++) {
		if (line[i] != ' ' && line[i] != '.' && line[i] != ',') {
			lineOfLetters += line[i];
		}
	}
	return lineOfLetters;
}




void charCount(string lineOfLetters, int *letterCount)
{
	
	
	for (int j = 0; j < lineOfLetters.length(); j++) {
		char ch = lineOfLetters[j];
		if (ch >= 'a' && ch <= 'z') {
			int index = ch - 'a';

			letterCount[index]++;
		}
		else if (ch >= 'A' && ch <= 'Z') {
			int index = ch - 'A';

			letterCount[index]++;
		}
	}
	
}

