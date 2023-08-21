// aew9409_HW10_Q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);

int main()
{
    string sentence;
    int outWordsArrSize = 0;

    cout << "Please enter any sentance: " << endl;
    getline(cin, sentence);

    

    string* ptr = createWordsArray(sentence, outWordsArrSize);

    for (int i = 0; i < outWordsArrSize; i++) {
        cout << "'" << ptr[i] << "' ";
    }
    delete[] ptr;
    ptr = NULL;
    cout << endl;

    cout << "Number of words in returned array: " << outWordsArrSize << endl;
   

}


string* createWordsArray(string sentence, int& outWordsArrSize)
{
    string* arrOfWords = new string[sentence.length()];
    

    int start = 0;
    int wordCount = 0;
    int lettersInWord = 0;
    for (int i = 0; i < sentence.length() + 1; i++) {
        
        if (sentence[i] >= 'a' && sentence[i] <= 'z' || sentence[i] >= 'A' && sentence[i] <= 'Z') {
            lettersInWord++;
        }
        else {
            string newWord = sentence.substr(start, lettersInWord);
            arrOfWords[sentence.length()] = newWord;
            wordCount++;
            start = i + 1;
           
            lettersInWord = 0;
        }
       
    }
    outWordsArrSize = wordCount;
     return arrOfWords;
}