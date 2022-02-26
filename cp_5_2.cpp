//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<cmath>
using namespace std;

void reverse_a_number(){
    int num;
    cout<<"Enter a number : ";
    cin>>num;
    int rev_num=0;
    while(num>0){
      int lastdigit;
      lastdigit=num%10;
      rev_num=10*rev_num+lastdigit;
      num=num/10;
    }
    cout<<"The reversed number is : "<<rev_num;
}

void check_armstrong_number(){
    int num;
    cout<<"Enter a number : ";
    cin>>num;
    double org_num=num;
    double total=0;
    while(num>0){
        int lastdigit;
        lastdigit=num%10;
        total+=pow(lastdigit,3);
        num=num/10;
    }
    if(total==org_num){
        cout<<"It is an armstrong number";
    }
    else{
        cout<<"It is not an armstrong number";
    }
}

int main(){
    char ch;
    do{
        int choice;
        cout<<"Press 1 : To get the reverse of a number\n";
        cout<<"Press 2 : To check for an armstrong number\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
              reverse_a_number();
              break;
            case 2:
              check_armstrong_number();
              break;
            default:
              return 1;
        }
        cout<<"\n\nPress y or Y to continue or any other key to exit : ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}