//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
using namespace std;

void max_of_three_numbers(){
    int no1,no2,no3;
    cout<<"Enter your all three no. respectively : ";
    cin>>no1>>no2>>no3;
    if(no1>no2){
        if(no1>no3){
            cout<<no1<<" is maximum";
        }
        else{
            cout<<no3<<" is maximum";
        }
    }
    else{
        if(no2>no3){
            cout<<no2<<" is maximum";
        }
        else{
            cout<<no3<<" is maximum";
        }
    }
}

void check_prime(){
  int num,c=0;
  cout<<"Enter the number : ";
  cin>>num;
  for(int i=1;i<=num;i++){
      if(num%i==0){
        c++;
      }
  }
  if(c==2){
      cout<<num<<" is prime";
  }
  else{
      cout<<num<<" is not prime";
  }
}

void print_all_prime(){
    int num,total=0;
    cout<<"Enter the number : ";
    cin>>num;
    for(int i=2;i<=num;i++){
        int c=0;
        for(int j=2;j<i;j++){
            if(i%j==0){
                c++;
                break;
            }
        }
        if(c==0){
            total++;
            cout<<i<<" ";
        }
    }
    cout<<"\nNumber of prime till "<<num<<" is "<<total;
}

int main(){
    char ch;
    do{
        int choice;
        cout<<"Press 1 : To get max of three numbers\n";
        cout<<"Press 2 : To get the given no. is prime or not\n";
        cout<<"Press 3 : To print all prime no. till the given no.\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
              max_of_three_numbers();
              break;
            case 2:
              check_prime();
              break;
            case 3:
              print_all_prime();
              break;
            default:
              return 1;
        }
        cout<<"\n\nPress y or Y to continue or any other key to exit : ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}