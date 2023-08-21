// aew9409_HW9_Q2.cpp :
//

#include <iostream>
#include <string>

using namespace std;

void removePunctuation(string& line);
void charCount(string lineOfLetters, int* letterCount);
bool isAnogramCheck(int* letterCountOne, int* letterCountTwo, const int alphabet);

const int alphabet = 26;

int main()
{
    cout << "Please enter two lines of text that will be checked to find if they are anograms:" << endl;
    cout << "Enter line one:" << endl;
    string lineOne;
    getline(cin, lineOne);
    cout << "Enter line two:" << endl;
    string lineTwo;
    getline(cin, lineTwo);

    removePunctuation(lineOne);
    removePunctuation(lineTwo);


    int letterCountOne[alphabet];
    for (int i = 0; i < alphabet; i++) {
        letterCountOne[i] = 0;
    }

    charCount(lineOne, letterCountOne);

    int letterCountTwo[alphabet];
    for (int i = 0; i < alphabet; i++) {
        letterCountTwo[i] = 0;
    }
    charCount(lineTwo, letterCountTwo);

    bool isAnogram = isAnogramCheck(letterCountOne, letterCountTwo, alphabet);

    if (isAnogram == true) {
        cout << "Line one and line two ARE an anogram!" << endl;
    }
    else {
        cout << "Line one and line Two are NOT an anogram!" << endl;
    }
}

void removePunctuation(string& line)
{
    string lineOfLetters;
    for (int i = 0; i <= line.length(); i++) {
        if (line[i] >= 'a' && line[i] <= 'z' || line[i] >= 'A' && line[i] <= 'Z') {
            lineOfLetters += line[i];
        }
    }
    line = lineOfLetters;
}

void charCount(string lineOfLetters, int* letterCount)
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
bool isAnogramCheck(int* letterCountOne, int* letterCountTwo, const int alphabet)
{
    bool isAnogram = true;
    for (int i = 0; isAnogram == true && i < alphabet ; i++) {
        if (letterCountOne[i] == letterCountTwo[i]) {
            isAnogram = true;
        }
        else {
            isAnogram = false;

        }
    }
    return isAnogram;



}