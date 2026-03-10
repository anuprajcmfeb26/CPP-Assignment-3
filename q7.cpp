#include <iostream>
#include <cstring>
using namespace std;

class MyString{

    char *str;

public:

    MyString(){
        str=new char[1];
        str[0]='\0';
    }

    MyString(const char *s){
        str=new char[strlen(s)+1];
        strcpy(str,s);
    }

    MyString(const MyString &s){
        str=new char[strlen(s.str)+1];
        strcpy(str,s.str);
    }

    ~MyString(){
        delete[] str;
    }

    MyString& operator=(const MyString &s){

        if(this!=&s){
            delete[] str;
            str=new char[strlen(s.str)+1];
            strcpy(str,s.str);
        }

        return *this;
    }

    MyString operator+(MyString &s){

        MyString temp;

        delete[] temp.str;

        temp.str=new char[strlen(str)+strlen(s.str)+1];

        strcpy(temp.str,str);
        strcat(temp.str,s.str);

        return temp;
    }

    friend ostream& operator<<(ostream &out,MyString &s){
        out<<s.str;
        return out;
    }

    friend istream& operator>>(istream &in,MyString &s){
        char temp[100];
        in>>temp;

        delete[] s.str;

        s.str=new char[strlen(temp)+1];
        strcpy(s.str,temp);

        return in;
    }

};

int main(){

    MyString s1,s2;

    cout<<"Enter first string: ";
    cin>>s1;

    cout<<"Enter second string: ";
    cin>>s2;

    MyString s3 = s1 + s2;

    cout<<"s1 = "<<s1<<endl;
    cout<<"s2 = "<<s2<<endl;
    cout<<"s3 = "<<s3<<endl;
}