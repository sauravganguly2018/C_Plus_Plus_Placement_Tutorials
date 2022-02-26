//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void swap(int *arr,int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void waveSort(int *arr,int n){
    for(int i=1;i<n-1;i+=2){
        if(arr[i]>arr[i-1]){
            swap(arr,i-1,i);
        }
        if(arr[i]>arr[i+1] && i+1<n){
            swap(arr,i,i+1);
        }
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
    waveSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }  
    return 0;
}