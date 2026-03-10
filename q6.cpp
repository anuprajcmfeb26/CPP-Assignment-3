#include <iostream>
using namespace std;

class Vector{

    int *arr;
    int size;

public:

    Vector(int s){
        size=s;
        arr=new int[size];

        for(int i=0;i<size;i++)
            arr[i]=i+1;
    }

    int& operator[](int index){
        return arr[index];
    }

    int operator()(){

        int sum=0;

        for(int i=0;i<size;i++)
            sum+=arr[i];

        return sum;
    }

};

int main(){

    Vector v(5);

    v[2]=50;

    cout<<"Sum = "<<v()<<endl;

}