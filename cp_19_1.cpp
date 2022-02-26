//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(int *arr,int l,int mid,int r){
    int i=l;
    int j=mid+1;
    int k=0;
    int temp[r-l+1];
    while(i<=mid && j<=r){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i++;
            k++;
        }
        else{
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=r){
        temp[k]=arr[j];
        j++;
        k++;
    }
    int c=0;
    for(int i=l;i<=r;i++){
        arr[i]=temp[c];
        c++;
    }
}

void mergeSort(int *arr,int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
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
    mergeSort(arr,0,n-1);
    cout<<"The array after applying merge sort is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}