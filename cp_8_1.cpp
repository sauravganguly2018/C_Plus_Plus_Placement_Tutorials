//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<climits>
using namespace std;

int main(){
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    int arr[size];
    int maxNo=INT_MIN;
    int minNo=INT_MAX;
    cout<<"Enter all "<<size<<" no. respectively : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
        if(arr[i]>maxNo){
            maxNo=arr[i];
        }
        if(arr[i]<minNo){
            minNo=arr[i];
        }
    }
    cout<<"The max no. is "<<maxNo<<endl;
    cout<<"The min no. is "<<minNo<<endl;
    return 0;
}