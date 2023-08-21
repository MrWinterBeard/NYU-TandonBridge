// aew9409_HW16_Q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;
/*
template <class T>
class QueueWithList {
private:
	list <T> data;
	int frontIndex = 0;

public:
	void enqueue(T newItem) { data.push_back(newItem); }
	T dequeue();
	T top() { return *data.begin(); }
	bool isEmpty() { return data.size() == 0; }
	int size() { return data.size(); }
	void clear() { data.clear(); }

};
template <class T>
T QueueWithList<T>:: dequeue() {
	//return data.pop_front();
	if (size() == 1) {
		T temp = top(); clear(); return temp;
	}
	else
		return data[frontIndex++];

};
*/

template <class T>
class Queue {
private:
	vector <T> data;
	int frontIndex = 0;

public:
	void enqueue(T newItem) { data.push_back(newItem); }
	T dequeue();
	T top() { return data[frontIndex]; }
	bool isEmpty() { return data.size() <= frontIndex; }
	int size() { return data.size() - frontIndex; }
	void clear() { data.clear(); frontIndex = 0; }

};

template <class T>
T Queue<T>:: dequeue() {
	if (size() == 1) {
		T temp = top(); clear(); return temp; 
	} 
	else 
		return data[frontIndex++]; 
};

int main()
{
	/*
	Queue<int> test;
	test.enqueue(1);
	test.enqueue(2);
	
	cout << "the size: " << test.size() << endl;
	cout << "the top: " << test.top() << endl;
	test.dequeue();
	cout << "the size: " << test.size() << endl;

	
	test.clear();
	cout << "the size: " << test.size() << endl;

	cout << endl;

	QueueWithList<int> listTest;

	test.enqueue(1);
	test.enqueue(2);

	cout << "the size: " << test.size() << endl;
	cout << "the top: " << test.top() << endl;
	test.dequeue();
	cout << "the size: " << test.size() << endl;


	test.clear();
	cout << "the size: " << test.size() << endl;

	cout << endl;
	*/
	
}

