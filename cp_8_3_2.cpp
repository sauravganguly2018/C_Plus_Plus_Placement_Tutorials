//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    int temp;
     for(int i=n-1;i>0;i--){
         for(int j=0;j<i;j++){
             if(arr[j]>arr[j+1]){
                 temp=arr[j];
                 arr[j]=arr[j+1];
                 arr[j+1]=temp;
             }
         }
     }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }   
}

void insertionSort(int arr[],int n){
    int temp;
    for(int i=1;i<n;i++){
         int temp=arr[i];
         int j=i-1;
         while(arr[j]>temp && j>=0){
             arr[j+1]=arr[j];
             j--;
         }
         arr[j+1]=temp;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }    
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
    cout<<"\n\n\t\t\t----------------------------------Bubble Sort-------------------------------------\n\n";
    bubbleSort(arr,size);
    cout<<"\n\n\t\t\t----------------------------------Insertion Sort----------------------------------\n\n";
    insertionSort(arr,size);
    return 0;
}