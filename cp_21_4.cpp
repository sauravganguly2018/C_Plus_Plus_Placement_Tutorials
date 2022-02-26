//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class saurav{
    public:
    void fun(){
        cout<<"I am a function with no arguments"<<endl;
    }
    void fun(int x){
        cout<<"I am function with int argument"<<endl;
    }
    void fun(double x){
        cout<<"I am a function with double argument"<<endl;
    }
};

class Complex{
    int real,imag;
    public:
    Complex(){

    }
    Complex(int r,int i){
        real=r;
        imag=i;
    }
    Complex operator + (Complex const &obj){
        Complex res;
        res.real=real+obj.real;
        res.imag=imag+obj.imag;
        return res;
    }

    void display(){
        cout<<real<<" + "<<imag<<"i"<<endl;
    }
};

class base{
    public:
    virtual void print(){
        cout<<"This is a base class's print function"<<endl;
    }
    void display(){
        cout<<"This is a base class's display function"<<endl;
    }
};

class derived:public base{
    public:
    void print(){
        cout<<"This is a derived class's print function"<<endl;
    }
    void display(){
        cout<<"This is a derived class's display function"<<endl;
    }
};
int main(){
    // function overloading
    saurav obj;
    obj.fun();
    obj.fun(4);
    obj.fun(8.9);

    // operator overloading
    Complex c1(3,4);
    Complex c2(5,6);
    Complex c3=c1+c2;
    c3.display();

    // virtual function
    base *baseptr;
    derived d;
    baseptr = &d;
    baseptr -> print();
    baseptr -> display();
    return 0;
}