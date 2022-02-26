//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long merge(int *arr,int l,int mid,int r){
    long long inv=0;
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
            inv+=mid-i+1;
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
    return inv;
}

long long mergeSort(int *arr,int l,int r){
    long long inv=0;
    if(l<r){
        int mid=(l+r)/2;
        inv+=mergeSort(arr,l,mid);
        inv+=mergeSort(arr,mid+1,r);
        inv+=merge(arr,l,mid,r);
    }
    return inv;
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
    cout<<"Total no. of count inversions in this array is : ";
    cout<<mergeSort(arr,0,n-1)<<endl;
    
    return 0;
}