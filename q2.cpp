#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int roll;
    string name;
    int marks;

    Student() {}

    Student(int r, string n, int m) {
        roll = r;
        name = n;
        marks = m;
    }

    ~Student() {
        cout << "Destroying student " << name << endl;
    }
};

int main() {

    Student s[3] = {
        Student(1,"Aman",85),
        Student(2,"Riya",90),
        Student(3,"Karan",78)
    };

    ofstream fout("students.txt");

    for(int i=0;i<3;i++){
        fout<<s[i].roll<<" "<<s[i].name<<" "<<s[i].marks<<endl;
    }

    fout.close();

    ifstream fin("students.txt");

    int r,m;
    string n;

    cout<<"\nReading from file:\n";

    while(fin>>r>>n>>m){
        cout<<r<<" "<<n<<" "<<m<<endl;
    }

    fin.close();

    return 0;
}