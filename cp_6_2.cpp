//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<cmath>
using namespace std;

void print_all_prime_no(int num1,int num2){
    for(int i=num1;i<=num2;i++){
        int flag=1;
        for(int j=2;j<=sqrt(i);j++){
             if(i%j==0){
                 flag=0;
                 break;
             }
        }
        if(flag){
          cout<<i<<" ";
        }
    }
}

void fibonacci(int num){
    int next,previous=0,current=1;
    cout<<0<<" "<<1<<" ";
    for(int i=0;i<num-2;i++){
         next=current+previous;
         cout<<next<<" ";
         previous=current;
         current=next;
    }
}

int factorial(int num){
    if(num<0){
        return -1;
    }
    else{
    int factorial=1;
    for(int i=2;i<=num;i++){
         factorial*=i;
    }
    return factorial;
    }
}

int combination(int n,int r){
    int comb;
    if(n>=r && n>=0 && r>=0){
        comb=factorial(n)/(factorial(n-r)*factorial(r));
        return comb;
    }
    else{
        return -1;
    }
}

void pascal_triangle(int rows){
      for(int i=0;i<rows;i++){
          for(int j=0;j<=i;j++){
              cout<<combination(i,j)<<" ";
          }
          cout<<endl;
      }
}

int main(){
    char ch;
    do{
        int choice;
        cout<<"Press 1 : To print all prime numbers\n";
        cout<<"Press 2 : To print the fibonacci sequence\n";
        cout<<"Press 3 : To get the factorial of a number\n";
        cout<<"Press 4 : To get the value of nCr\n";
        cout<<"Press 5 : To print the pascal triangle pattern\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:{
               int a,b;
               cout<<"Enter the two no. respectively : ";
               cin>>a>>b;
               print_all_prime_no(a,b);
            }
              break;
            case 2:{
                int n;
                cout<<"Enter the term number : ";
                cin>>n;
                fibonacci(n);
            }
             break;
            case 3:{
                int fact,n;
                cout<<"Enter the number : ";
                cin>>n;
                fact=factorial(n);
                if(fact==-1){
                    cout<<"Invalid input given !";
                }
                else{
                cout<<"The factorial of "<<n<<" is : "<<fact;
                }
            }
             break;
            case 4:{
                int comb,n,r;
                cout<<"Enter the value of n and r respectively : ";
                cin>>n>>r;
                comb=combination(n,r);
                if(comb==-1){
                      cout<<"Invalid Input given !";
                }
                else{
                    cout<<"The combination of "<<n<<"C"<<r<<" is : "<<comb;
                }
            }
             break;
            case 5:{
                int rows;
                cout<<"Enter the number of rows : ";
                cin>>rows;
                pascal_triangle(rows);

            }
             break;
            default:
              return 1;
        }
        cout<<"\n\nPress y or Y to continue or any other key to exit : ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}