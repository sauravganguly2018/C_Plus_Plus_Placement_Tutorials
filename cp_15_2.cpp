//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
using namespace std;

int divisible(int n,int a,int b){
    int c1=n/a;
    int c2=n/b;
    int c3=n/(a*b);

    return c1+c2-c3;
}

//Finding GCD by Euclid's algorithm

int gcd(int a,int b){
    int temp;
    while(b!=0){
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int main(){
    int n,a,b;
    cout<<"Enter the no. respectively : ";
    cin>>n>>a>>b;
    cout<<"Output is : "<<divisible(n,a,b);

    int m,p;
    cout<<"\nEnter the two no. two find their GCD : ";
    cin>>m>>p;
    cout<<"GCD of "<<m<<" and "<<p<<" is : "<<gcd(m,p);
    return 0;
}