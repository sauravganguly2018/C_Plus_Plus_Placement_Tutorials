//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<cmath>
using namespace std;


void primeSieve(int n){
    int prime[n+1];
    for(int i=0;i<=n;i++){
        prime[i]=0;
    }

    for(int i=2;i<=sqrt(n);i++){
        if(prime[i]==0){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=1;
            }
        }
    }

    for(int j=2;j<=n;j++){
        if(prime[j]==0){
            cout<<j<<" ";
        }
    }
}

void primeFactor(int n){
    int spf[n+1];
    for(int i=0;i<=n;i++){
        spf[i]=i;
    }

    for(int i=2;i<=sqrt(n);i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(spf[j]==j){
                  spf[j]=i;
                }
            }
        }
    }

    while(n!=1){
        cout<<spf[n]<<" ";
        n/=spf[n];
    }
}

int main(){
    int no;
    cout<<"Enter the no. upto which you want all prime numbers and also its prime factor : ";
    cin>>no;
    cout<<"All prime no. till "<<no<<" are : ";
    primeSieve(no);
    cout<<"\nPrime factor of "<<no<<" is : ";
    primeFactor(no);
    return 0;
}