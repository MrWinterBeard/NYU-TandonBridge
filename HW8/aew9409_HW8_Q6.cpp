// aew9409_HW8_Q6.cpp : 
//

#include <iostream>
#include <string>

using namespace std;

string readWord(string text, int& i);
bool isANumber(string word);


int main()
{
    cout << "Please enter a line of text:" << endl;
    string text;
    getline(cin, text);

    int i = 0;
    string word;
    while (i < text.length()) {
        word = readWord(text, i);
       
        if (isANumber(word)) {
            for (int i = 0; i < word.length(); i++) {
                cout << "x";

                
            }

        }
        else {
            cout << word;
        }
        cout << " ";
    }
    
    cout << endl;
}
string readWord(string text, int& i)
{
    string word;
    while (i < text.length() && text[i] != ' ') {
        word += text[i];
        i++;
        
    }
    while (i < text.length() && text[i] == ' ') {
        i++;
    }
    return word;

}
bool isANumber(string word) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] < '0' || word[i] > '9') {

            return false;
        }
    }
    return true;
}
