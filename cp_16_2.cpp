//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
using namespace std;

bool issorted(int arr[],int n){
    if(n==1){
        return true;
    }
    return (arr[0]<=arr[1]) && (issorted(arr+1,n-1));
}

void dec(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    dec(n-1);
}

void inc(int n){
    if(n==0){
        return;
    }
    inc(n-1);
    cout<<n<<" ";
}

int firstoccur(int arr[],int n,int i,int key){
    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return firstoccur(arr,n,i+1,key);
}

int lastoccur(int arr[],int n,int i,int key){
    if(i==n){
        return -1;
    }
    if(arr[n-i-1]==key){
        return n-i-1;
    }
    return lastoccur(arr,n,i+1,key);
}

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter all the elements of the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(issorted(arr,n)){
         cout<<"The given array is sorted ";
    }
    else{
         cout<<"The given array is not sorted";
    }
    cout<<"\nThe decreasing order is : ";
    dec(7);
    cout<<"\nThe increasing order is : ";
    inc(7);
    int arr2[7]={4,2,1,2,5,2,7};
    cout<<"\nThe first occurrence of 2 in the array is at index : "<<firstoccur(arr2,7,0,2);
    cout<<"\nThe last occurrence of 2 in the array is at index : "<<lastoccur(arr2,7,0,2);
    return 0;
}