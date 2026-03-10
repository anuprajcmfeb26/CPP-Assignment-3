#include <iostream>
using namespace std;

class Inspector;

class Number{

    int value;

public:

    Number(int v){ value=v; }

    friend bool operator>(Number a,Number b);

    friend class Inspector;

    Number operator++(){
        ++value;
        return *this;
    }

    Number operator++(int){
        Number temp=*this;
        value++;
        return temp;
    }

    Number& operator=(const Number &n){
        value=n.value;
        return *this;
    }

};

bool operator>(Number a,Number b){
    return a.value > b.value;
}

class Inspector{
public:
    void show(Number n){
        cout<<"Value = "<<n.value<<endl;
    }
};

int main(){

    Number n1(5),n2(10);

    ++n1;
    n2++;

    Inspector i;

    i.show(n1);
    i.show(n2);

    if(n2>n1)
        cout<<"n2 is greater\n";
}