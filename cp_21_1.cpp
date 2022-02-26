//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<string>
// #include<bits/stdc++.h>
using namespace std;

class student{
    string name;
    public:
    int age;
    bool gender;

    student(){
        cout<<"Default Constructor"<<endl;
    }// default constructor

    student(string s,int a,bool g){
        cout<<"parameterised constructor"<<endl;
        name=s;
        age=a;
        gender=g;
    }// parameterised constructor

    student(student &a){
        cout<<"copy constructor"<<endl;
        name=a.name;
        age=a.age;
        gender=a.gender;
    }// copy constructor

    void setName(string s){
        name=s;
    }

    void getName(){
        cout<<name<<endl;
    }

    void printInfo(){
        cout<<"Name = ";
        cout<<name<<endl;
        cout<<"Age = ";
        cout<<age<<endl;
        cout<<"Gender = ";
        cout<<gender<<endl;      
    }

    bool operator == (student &a){
        if(name==a.name && age==a.age && gender==a.gender){
            return true;
        }
        return false;
    }

    ~student(){
        cout<<"Destructor Called"<<endl;
    }
    
};

int main(){
    // student arr[3];
    // for(int i=0;i<3;i++){
    //     string s;
    //     cout<<"Name = ";
    //     cin.ignore();
    //     getline(cin,s);
    //     arr[i].setName(s);
    //     cout<<"Age = ";
    //     cin>>arr[i].age;
    //     cout<<"Gender = ";
    //     cin>>arr[i].gender;
    // }
    // for(int i=0;i<3;i++){
    //     arr[i].printInfo();
    // }

    student a("saurav",18,0);
    // a.printInfo();
    student b("kundan",19,0);
    student c=a;

    if(b==a){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }
    
    return 0;
}