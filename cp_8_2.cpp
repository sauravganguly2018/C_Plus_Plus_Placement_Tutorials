//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
using namespace std;

int linearSearch(int arr[],int size,int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[],int size,int key){
    int s=0;
    int e=size-1;
    int mid;
    while(s<=e){
        mid=(s+e)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return -1;
}

int main(){
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;
    int arr[size];
    cout<<"Enter all the "<<size<<" no. respectively : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the no. which you want to find : ";
    cin>>key;
    cout<<"\n\n\t\t\t-----------------------------Through Linear Search---------------------------";
    cout<<"\n\nThe element is found at index "<<linearSearch(arr,size,key);
    cout<<"\n\n\t\t\t-----------------------------Through Binary Search---------------------------";
    cout<<"\n\nThe element is found at index "<<binarySearch(arr,size,key);

    return 0;
}