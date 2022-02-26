//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
using namespace std;

int sum(int n){
    if(n==0){
        return 0;
    }
    return (n+sum(n-1));
}

int power(int n,int p){
    if(p==0){
        return 1;
    }
    return n*power(n,p-1);
}

int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}

int fibonacci(int index){
    if(index==0 || index==1){
        return index;
    }
    return fibonacci(index-1)+fibonacci(index-2);
}

int main(){
    int n1;
    cout<<"Enter the no. to get sum upto that no. : ";
    cin>>n1;
    cout<<"Sum of all the no. till "<<n1<<" is : "<<sum(n1);
    int n2,p;
    cout<<"\n\nEnter the no. and it's power respectively : ";
    cin>>n2>>p;
    cout<<"The value of "<<n2<<" raised to the power "<<p<<" is : "<<power(n2,p);
    int n3;
    cout<<"\n\nEnter the no. to find the factorial : ";
    cin>>n3;
    cout<<"The factorial of "<<n3<<" is : "<<factorial(n3);
    int n4;
    cout<<"\n\nEnter the index of fibonacci series : ";
    cin>>n4;
    cout<<"The no. at index "<<n4<<" in the fibonacci series is : "<<fibonacci(n4);
    return 0;
}