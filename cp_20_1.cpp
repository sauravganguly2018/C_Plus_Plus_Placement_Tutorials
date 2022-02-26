//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void countSort(int *arr,int n){
    int maxNum=INT_MIN;
    for(int i=0;i<n;i++){
      if(arr[i]>maxNum){
          maxNum=arr[i];
      }
    }
    int count[maxNum+1]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]+=1;
    }
    for(int i=0;i<=maxNum;i++){
        cout<<count[i]<<" ";
    }
    cout<<endl;
    int prevSum=0;
    for(int i=0;i<=maxNum;i++){
        prevSum+=count[i];
        count[i]=prevSum;
    }
    for(int i=0;i<=maxNum;i++){
        cout<<count[i]<<" ";
    }
    cout<<endl;
    int sortedArr[n];
    for(int i=n-1;i>=0;i--){
      sortedArr[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=sortedArr[i];
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    countSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}