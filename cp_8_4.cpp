//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<climits>
using namespace std;

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

void max_till_i_in_array(int arr[],int n){
    int maxNo=INT_MIN;
    for(int i=0;i<n;i++){
          maxNo=max(arr[i],maxNo);
          cout<<maxNo<<" ";
    }
}

void sum_of_all_subArrays(int arr[],int n){
         int total=0;
     for(int i=0;i<n;i++){
             int sum=0;
         for(int j=i;j<n;j++){
             sum+=arr[j];
             total+=sum;
             cout<<sum<<" ";
         }
     }
     cout<<"\n"<<total;
}

void length_of_longest_contiguous_subArray(int arr[],int n){
        int maxlen=1;
        int pd=arr[1]-arr[0];
        int cl=1;
        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i]==pd){
                cl+=1;
                maxlen=max(cl,maxlen);
            }
            else{
                pd=arr[i+1]-arr[i];
                cl=2;
            }
        }
        cout<<"The length of the longest subArray is "<<maxlen;
}

void recordBreakingDays(int arr[],int n){
    int maxVis=INT_MIN;
    int recBreakingDays=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]>maxVis && arr[i]>arr[i+1]){
             recBreakingDays+=1;
        }
        maxVis=max(maxVis,arr[i]);
    }
    if(arr[n-1]>maxVis){
        recBreakingDays+=1;
    }
    cout<<"Total no. of Record Breaking days is "<<recBreakingDays;
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
    char ch;
    do{
        int choice;
        cout<<"Press 1 : To get max till i in the array\n";
        cout<<"Press 2 : To get sum of all subArrays\n";
        cout<<"Press 3 : To get the length of longest contiguous subArrays\n";
        cout<<"Press 4 : To get the record breaking day\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
              max_till_i_in_array(arr,size);
              break;
            case 2:
              sum_of_all_subArrays(arr,size);
              break;
            case 3:
              length_of_longest_contiguous_subArray(arr,size);
              break;
            case 4:
              recordBreakingDays(arr,size);
              break;
            default:
              return 1;
        }
        cout<<"\n\nPress y or Y to continue or any other key to exit : ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');   
    return 0;
}