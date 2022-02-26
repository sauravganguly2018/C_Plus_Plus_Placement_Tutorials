//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<climits>
using namespace std;

int min(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}

void first_repeating_element(int arr[],int n){
    const int N=100002;
    int idx[N];
    for(int i=0;i<N;i++){
        idx[i]=-1;
    }
    int minindex=INT_MAX;
    for(int i=0;i<n;i++){
        if(idx[arr[i]]==-1){
            idx[arr[i]]=i;
        }
        else{
            minindex=min(minindex,idx[arr[i]]);
        }
    }
    if(minindex==INT_MAX){
        minindex=-1;
    }
    cout<<"We got the first repetative element at index "<<minindex;
}

void subarray_with_given_sum(int arr[],int n){
    int sum;
    cout<<"Enter the sum which you want to find in a subArray : ";
    cin>>sum;
    int flag=1;
    int i=0;
    int j=0;
    int currsum=arr[0];
    while(i<n && j<n){
        if(currsum==sum){
            cout<<i<<" "<<j;
            flag=0;
            break;
        }
        else if(currsum>sum){
            if(i==j){
                i++;
                j++;
                currsum=arr[j];
            }
            else{
             currsum-=arr[i];
             i++;
            }
        }
        else{
            j++;
            currsum+=arr[j];
        }
    }
    if(flag){
       cout<<"No any subArray found whose sum matches with "<<sum;
    }
}

void smallest_positive_missing_number(int arr[],int n){
     int N=100002;
     bool idx[N];
     for(int i=0;i<N;i++){
         idx[i]=false;
     }
     for(int i=0;i<n;i++){
         if(arr[i]>=0){
             idx[arr[i]]=true;
         }
     }
     for(int i=1;i<N;i++){
         if(idx[i]==false){
             cout<<i<<" is the smallest positive missing number in the array";
             break;
         }
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
    char ch;
    do{
        int choice;
        cout<<"Press 1 : To get the first repeating element in the array\n";
        cout<<"Press 2 : To get subArray with given sum\n";
        cout<<"Press 3 : To get the smallest positive missing number in the array\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
              first_repeating_element(arr,size);
              break;
            case 2:
              subarray_with_given_sum(arr,size);
              break;
            case 3:
              smallest_positive_missing_number(arr,size);
              break;
            default:
              return 1;
        }
        cout<<"\n\nPress y or Y to continue or any other key to exit : ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}