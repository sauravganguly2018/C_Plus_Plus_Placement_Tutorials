//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
using namespace std;

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
            int temp=arr[i];
            int minNo=arr[i];
            int index=i;
            int flag=0;
        for(int j=i+1;j<n;j++){
            if(arr[j]<minNo){
                minNo=arr[j];
                index=j;
                flag=1;
            }
        }
           if(flag){
              arr[i]=minNo;
              arr[index]=temp;
           }
    }
        for(int i=0;i<n;i++){
          cout<<arr[i]<<" ";
    }  
}

int main(){
    cout<<"\n\n\t\t\t----------------------------------Selection Sort----------------------------------\n\n";
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;
    int arr[size];
    cout<<"Enter all the "<<size<<" no. respectively : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }  
    selectionSort(arr,size);

    return 0;
}