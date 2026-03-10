#include <iostream>
using namespace std;

class Employee {
public:
    int id;
    string name;
    mutable int accessCount;

    Employee(int i, string n) {
        id = i;
        name = n;
        accessCount = 0;
    }

    // User defined copy constructor
    Employee(const Employee &e) {
        id = e.id;
        name = e.name;
        accessCount = e.accessCount;
        cout << "User-defined copy constructor called\n";
    }

    // const function
    void display() const {
        accessCount++; 
        cout << "ID: " << id << " Name: " << name 
             << " Access Count: " << accessCount << endl;
    }
};

int main() {

    Employee e1(1,"Rahul");

    e1.display();
    e1.display();
    e1.display();

    Employee e2 = e1;   // copy

    cout << "\nAfter copying to e2:\n";

    e2.display();

    return 0;
}