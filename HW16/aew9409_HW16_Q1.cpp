// aew9409_HW16_Q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

 #include <iostream>
 #include <list>
#include <stack>
 #include <fstream>
 #include <string>

#include <vector>
 //#include <iterator>

 using namespace std;


 template<class T>
 class Stack {
 
 private:

	list<T> data;
 public:
	void push(T newItem) { data.push_front(newItem); }
	
	T top() const { return *data.begin(); }
	T pop() { T temp = top(); data.pop_front(); return temp; }
	bool isEmpty()const { return data.size() == 0; }
	int size() const { return data.size(); }
	void clear() { data.clear(); }


};

 void openInputFile(ifstream& inFile) {
	 string filename;
	 cout << "What filename would you like to open: ";
	 cin >> filename;
	 inFile.open(filename);
	 while (!inFile) {
		 cout << "Bad filename!" << endl;
		 cout << "What filename would you like to open: ";
		 cin >> filename;
		 inFile.clear(); //release all flags!
		 inFile.open(filename);
	 }
 }


 bool isPascalBal(ifstream& inFile) 
 {


	Stack<char> balanceStack;

	string word;
	
	inFile >> word;
	if (word == "begin") {
		balanceStack.push('b');
	}
	else {
		cout << "This Code is NOT balanced." << endl;
		return false;

	}
	bool inString = false;
	while (inFile >> word) {
		if (!balanceStack.size()) {
			cout << "not balanced!" << endl;
			return false;
		}
		if (word == "end" && !inString) {
			if (balanceStack.pop() != 'b') {
				cout << "not balanced!" << endl;
				return false;
			}
		}
		else if (word == "begin" && !inString) {
			balanceStack.push('b');
		}
		else {
			for (int i = 0; i < word.size(); i++) {
				char c = word[i];
				if (inString) {
					if (c == '\'') {
						inString == false;
					}
				}
				else {
					switch (c) {
					case '\'':
						inString == true;
						break;

					case '(':
					case '{':
					case '[':
						balanceStack.push(c);
						break;
					case ')':
						if (balanceStack.pop() != '(') {
							return false;

						}
						break;
					case '}':
						if (balanceStack.pop() != '{') {
							return false;

						}
						break;
					case ']':
						if (balanceStack.pop() != '[') {
							return false;

						}
						break;
					default:
						break;


					}
				}
				
			}


		}
	}
	if (balanceStack.isEmpty()) {

		return true;
	}
	else {
		return false;
	}

 }

int main()
{
	/*Stack <int> test;
	for (int i = 0; i < 4; i++) {
		test.push(i);
	}
	while (test.size()) {
		cout << test.top() << endl;
		
		cout << test.pop() << endl;
	}
	*/


	ifstream inFile;
	openInputFile(inFile); //pascal_code.txt
	bool isBalanced = isPascalBal(inFile);
	if (isBalanced) {
		cout << "This is balanced code." << endl;
	}
	else {
		cout << "This is NOT balanced code." << endl;
	}

	return 0;




}