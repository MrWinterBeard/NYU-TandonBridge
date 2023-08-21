// aew9409_HW_15.cpp :
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

template <class T>
class LList; //Pre-Definition to make Friend work in LListNode
template <class T>
class Node;

class Employee {
public:
    Employee() { id = 0; hourlyRate = 0.0; hoursWorked = 0.0; pay = 0.0; }
    Employee(int new_id, double new_hourlyRate, string new_name, double new_hoursWorked, double new_pay);
    int getEmployeeId() const { return id; }
    string getEmployeeName() const { return name; }
    double  getEmployeeHourlyRate() const { return hourlyRate; }
    void addHoursWorked(double new_hoursWorked) { hoursWorked += new_hoursWorked; }
    double getHoursWorked() const { return hoursWorked; }
    double getPay() const { return pay; }
    void calcuatePay() { pay = hourlyRate * hoursWorked; }

    
private:
    string name;
    int id;
    double hourlyRate;
    double hoursWorked;
    double pay;

};

Employee::Employee(int new_id, double new_hourlyRate, string new_name, double new_hoursWorked, double new_pay) {
    name = new_name;
    id = new_id;
    hourlyRate = new_hourlyRate;
    hoursWorked = new_hoursWorked;
    pay = new_pay;
}


template <class T>
class Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
    
    
public:
    
    Node(const T& newdata = T(), Node<T>* newnext = nullptr, Node<T>* newprev = nullptr) :data(newdata), next(newnext), prev(newprev) {}
    T& getData();
    Node<T> *getNext() { return next; }
    Node<T> *getPrev() { return prev; }

   

    friend class LList<T>;
};


template<class T>
T& Node<T>::getData()
{
    return data;
}

template <class T>
class LList {
    
public:
    LList();
    ~LList();
    LList(const LList<T>& rhs);
    LList<T>& operator=(const LList<T>& rhs);

    void clear() { while (!isEmpty()) pop_front(); }
    void push_back(const T& data) { tail->prev = new Node<T>(data, tail, tail->prev); tail->prev->prev->next = tail->prev; }
    void push_front(const T& data) { head->next = new Node<T>(data, head->next, head);  head->next->next->prev = head->next; }
    T pop_back();
    T pop_front();
    int size();
    bool isEmpty() { return head->next == tail; }
    

  
  Node<T>* getHead() { return head; }
  Node<T>* getTail() { return tail; }

  /*Function to swap the nodes */
  Node<T>* swap(Node<T>* ptr1, Node<T>* ptr2);
  

  void bubbleSortLinkedLists(int count) {
      Node<T>** h;
      int swapped;
      for (int i = 0; i < count; i++) {
          h = &head;
          swapped = 0;

          for (int j = 0; j < count - i - 1; j++) {
              Node<T>* p1 = *h;
              Node<T>* p2 = p1->next;

              if (p1->getData().getPay() >= p2->getData().getPay()) {
                  //update the link!
                  //there is an issue in the line below -- see if you can debug it! Hint: it may require a custom function
                  *h = swap(p1, p2);
                  swapped = 1;
              }
              h = &(*h)->next;
              if (swapped == 0) {
                  break;
              }
          }
      }
  }
   
private:

    Node<T>* tail;
    Node<T>* head;

};

/*Function to swap the nodes */
template <class T>
LList<T>::Node<T>* swap(Node<T>* ptr1, Node<T>* ptr2)
{
    Node<T>* tmp2 = ptr2->next;
    Node<T>* tmp = ptr1->prev;
    ptr2->next = ptr1;
    ptr2->prev = tmp;
    ptr1->next = tmp2;
    ptr1->prev = ptr2;

    tmp2->prev = ptr1;
    tmp->next = ptr2;
    return ptr2;
}
template <class T>
LList<T>::void bubbleSortLinkedLists(int count) {
    Node<T>** h;
    int swapped;
    for (int i = 0; i < count; i++) {
        h = &head;
        swapped = 0;

        for (int j = 0; j < count - i - 1; j++) {
            Node<T>* p1 = *h;
            Node<T>* p2 = p1->next;

            if (p1->getData().getPay() >= p2->getData().getPay()) {
                //update the link!
                //there is an issue in the line below -- see if you can debug it! Hint: it may require a custom function
                *h = swap(p1, p2);
                swapped = 1;
            }
            h = &(*h)->next;
            if (swapped == 0) {
                break;
            }
        }
    }
}
template <class T>
T LList<T>::pop_back() {
    if (tail->prev == head) //empty list!
        return T(); //not sure what to do here?  User did something dumb.
    T retval = tail->prev->data;
    Node<T>* nodeToDelete = tail->prev;
    tail->prev = nodeToDelete->prev;
    nodeToDelete->prev->next = nodeToDelete->next;
    delete nodeToDelete;
    return retval;
}

template <class T>
LList<T>& LList<T>::operator=(const LList<T>& rhs) {
    if (this == &rhs)
        return *this;
    clear();
    Node<T>* ptr = rhs.head->next;
    while (ptr != rhs.tail) {
        push_back(ptr->data);
    }
    return *this;
}
template <class T>
T LList<T>::pop_front() {
    if (tail->prev == head) //empty list!
        return T(); //not sure what to do here?  User did something dumb.
    T retval = head->next->data;
    Node<T>* nodeToDelete = head->next;
    head->next = nodeToDelete->next;
    head->next->prev = head;
    delete nodeToDelete;
    return retval;
}
template <class T>
LList<T>::~LList() {
    clear();
    delete head;
    delete tail;
}
template <class T>
LList<T>::LList(const LList<T>& rhs) {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
    *this = rhs; //call to the assignment operator!!!
}
template <class T>
LList<T>::LList() { //build two nodes, as "Dummies" for teh sake of making things easier
    head = new Node<T>();
    tail = new Node<T>();
    head->next = tail;
    tail->prev = head;
}

/*template <class T>
void LList<T>::addEmployeeHead(int id, double hourlyRate, string name) {
    Employee* anotherEmployee = new Employee(id, hourlyRate, name);
    Node<T>* anotherNode = new Node;
    anotherNode->data = anotherEmployee;
    anotherNode->next = nullptr;
    anotherNode->prev = nullptr;
    if (head == nullptr) {
        head = anotherNode;
        return;
    }
    else {
        Node<T>* addNode = head;
        while (addNode->next != nullptr) {
            addNode = addNode->next;
        }
        addNode->next = anotherNode;
        anotherNode->prev = addNode;
    }

}
*/

template <class T>
int LList<T>::size() {
    Node<T>* ptr = head->next;
    int count = 0;
    while (ptr != tail) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

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



int main()
{
    ifstream inFile;
    openInputFile(inFile); // employee_info.txt
    double hoursWorked = 0.0;
    int id;
    double hourlyRate;
    string name;
    double pay = 0.0;
    
    LList<Employee> employeeList;

    
    LList<int> testList;

    for(int i = 0; i < 4; ++i)
        testList.push_back(i);

    while(!testList.isEmpty())
        cout << testList.pop_front() << endl;

    for(int i = 0; i < 4; ++i)
        testList.push_back(i);

    while(!testList.isEmpty())
        cout << testList.pop_back() << endl;

    for (int i = 0; i < 4; ++i)
        testList.push_back(i);

    for(Node<int> *node = testList.getHead()->getNext(); node != testList.getTail(); node = node->getNext())
        cout << node->getData() << endl;

    cout << testList.size() << endl;

    cout << endl;
    cout << endl;
    

    for (Node<int>* node = testList.getHead()->getNext(); node != testList.getTail(); node = node->getNext())
        cout << node->getData() << endl;
    for (Node<int>* node = testList.getTail()->getPrev(); node != testList.getHead(); node = node->getPrev())
        cout << node->getData() << endl;

    cout << endl;
    cout << endl;


    Node<int>* p1 = testList.getHead()->getNext();
    Node<int>* p2 = p1->getNext();
    testList.swap(p1, p2);

    for (Node<int>* node = testList.getHead()->getNext(); node != testList.getTail(); node = node->getNext())
        cout << node->getData() << endl;
    for (Node<int>* node = testList.getTail()->getPrev(); node != testList.getHead(); node = node->getPrev())
        cout << node->getData() << endl;


    int empListSize = 0;
    while (inFile >> id) {
        inFile >> hourlyRate;
        inFile.ignore(9999, ' ');
        getline(inFile, name);
        employeeList.push_back(Employee(id, hourlyRate, name, hoursWorked, pay));
        empListSize++;
    }

   /* for (Node<Employee>* node = employeeList.getHead()->getNext(); node != employeeList.getTail(); node = node->getNext())
        cout << node->getData().getEmployeeId() << endl;

    cout << endl;

    for (Node<Employee>* node = employeeList.getHead()->getNext(); node != employeeList.getTail(); node = node->getNext())
        cout << node->getData().getEmployeeHourlyRate() << endl;

    cout << endl;

    for (Node<Employee>* node = employeeList.getHead()->getNext(); node != employeeList.getTail(); node = node->getNext())
        cout << node->getData().getEmployeeId() << " " << node->getData().getEmployeeName() << endl;

    cout << endl;

    */
    ifstream inFile2;
    openInputFile(inFile2); // hours_worked.txt

    LList<Employee> employeeHours;

    while (inFile2 >> id) {
        
        inFile2.ignore(9999, ' ');
        inFile2 >> hoursWorked;
        employeeHours.push_back(Employee(id, hourlyRate, name, hoursWorked, pay));
    }

    //for (Node<Employee>* node = employeeHours.getHead()->getNext(); node != employeeHours.getTail(); node = node->getNext())
       // cout << node->getData().getEmployeeId() << " " << node->getData().getHoursWorked() << endl;

   // cout << endl;
   // cout << endl;
   // cout << endl;

    for (Node<Employee>* node = employeeHours.getHead()->getNext(); node != employeeHours.getTail(); node = node->getNext()) {
        for (Node<Employee>* node2 = employeeList.getHead()->getNext(); node2 != employeeList.getTail(); node2 = node2->getNext()) {

            if (node->getData().getEmployeeId() == node2->getData().getEmployeeId()) {
                node2->getData().addHoursWorked(node->getData().getHoursWorked());
                node2->getData().calcuatePay();
            }
            
        }

    }

   // cout << endl;

    //for (Node<Employee>* node = employeeList.getHead()->getNext(); node != employeeList.getTail(); node = node->getNext())
       // cout << node->getData().getEmployeeId() << " " << node->getData().getHoursWorked() << endl;

   // cout << endl;

    //for (Node<Employee>* node = employeeList.getHead()->getNext(); node != employeeList.getTail(); node = node->getNext())
      //  cout << node->getData().getEmployeeName() << " " << node->getData().getHoursWorked() << " " << node->getData().getPay() << endl;

    //cout << endl;

    employeeList.bubbleSortLinkedLists(employeeList.size());




    cout << "*********Payroll Information********" << endl;

    for (Node<Employee>* node = employeeList.getHead()->getNext(); node != employeeList.getTail(); node = node->getNext())
        cout << node->getData().getEmployeeName() << ", $"<< node->getData().getPay() << endl;

    cout << endl;
    cout << "*********End payroll**************" << endl;

  //  ofstream outFile;
   // outFile.open("writtenOut.txt");

   // outFile << "this is a test" << endl;


    
}
