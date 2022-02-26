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

void printing_the_subArray(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
}

void maximum_subArray_sum2(int arr[],int n){
    int maxsum=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
           sum+=arr[j];
           maxsum=max(maxsum,sum);
        }
    }
    cout<<maxsum<<" is the maximum sum of a subArray using double loop";
}

//kadane's Algorithm
int maximum_subArray_sum1(int arr[],int n){
        int i=0;
        int maxsum=INT_MIN;
        int currsum=arr[0];
        while(i<n){
                maxsum=max(maxsum,currsum);
                i++;
                if(currsum>0){
                currsum+=arr[i];
                }
                else{
                currsum=arr[i];
                }
        }
        return maxsum;

        // Method 2

        // int i=0;
        // int maxsum=INT_MIN;
        // int currsum=0;
        // while(i<n){
        //         currsum+=arr[i];
        //         maxsum=max(maxsum,currsum);
        //         if(currsum<0){
        //         currsum=0;
        //         }
        //         i++;
        // }
        // return maxsum;
}

void maximum_circular_subArray_sum(int arr[],int n){
        int sumOrgArray=0;
        int arr1[n];
        for(int i=0;i<n;i++){
            sumOrgArray+=arr[i];
            arr1[i]=-arr[i];
        }
        int maxSumNegsubArray=maximum_subArray_sum1(arr1,n);
        int totalsum=sumOrgArray+maxSumNegsubArray;
        cout<<totalsum<<" is the maximum subArray sum";

    //  Method 2

    // int maxs=INT_MIN;
    // for(int i=0;i<n;i++){
    //     int temp=i;
    //     int c=0;
    //     int sum=0;
    //     while(c!=n){
    //         if(temp==n){
    //             temp=0;
    //         }
    //         sum+=arr[temp];
    //         maxs=max(maxs,sum);
    //         if(sum<0){
    //             sum=0;
    //         }
    //         temp++;
    //         c++;
    //     }
    // }
    // cout<<maxs<<" is the maximum subArray sum";
}

bool pairSum2(int arr[],int n){
    int sum;
    cout<<"Enter the desired sum which you want to find : ";
    cin>>sum;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==sum){
                cout<<"pair sum is found at an index of "<<i<<" "<<j<<endl;
                return true;
            }
        }
    }
    return false;
}

bool pairSum1(int arr[],int n){
    int sum;
    cout<<"Enter the desired sum which you want to find : ";
    cin>>sum;

//insertionSort
    int arr1[n];
    for(int i=0;i<n;i++){
        arr1[i]=arr[i];
    }
    int temp;
    for(int i=1;i<n;i++){
         int temp=arr1[i];
         int j=i-1;
         while(arr1[j]>temp && j>=0){
             arr1[j+1]=arr1[j];
             j--;
         }
         arr1[j+1]=temp;
    }
    cout<<"The sorted array is : ";
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }

    int low=0;
    int high=n-1;
    while(low<high){
        if(arr1[low]+arr1[high]==sum){
            cout<<"\nWe got the sum at an index of "<<low<<" "<<high<<" according to sorted array\n";
            return true;
        }
        else if(arr1[low]+arr1[high]<sum){
            low++;
        }
        else{
            high--;
        }
    }
    return false;
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
        cout<<"Press 1 : To print all the subArrays of an array\n";
        cout<<"Press 2 : To get the maximum subArray sum using double loop\n";
        cout<<"Press 3 : To get the maximum subArray sum using single loop\n";
        cout<<"Press 4 : To get the maximum circular subArray sum\n";
        cout<<"Press 5 : To get the desired pair sum is present in array or not using double loop\n";
        cout<<"Press 6 : To get the desired pair sum is present in array or not using single loop\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
              printing_the_subArray(arr,size);
              break;
            case 2:
              maximum_subArray_sum2(arr,size);
              break;
            case 3:
              {
              int maxsum=maximum_subArray_sum1(arr,size);
              cout<<maxsum<<" is the maximum sum of a subArray using single loop";
              }
              break;
            case 4:
              maximum_circular_subArray_sum(arr,size);
              break;
            case 5:
            {
              bool ispresent=pairSum2(arr,size);
              if(ispresent){
                  cout<<"so pair sum is present in the array using double loop";
              }
              else{
                  cout<<"pair sum is not present in the array using double loop";
              }
            }
              break;
            case 6:
            {
              bool ispresent=pairSum1(arr,size);
              if(ispresent){
                  cout<<"so pair sum is present in the array using single loop";
              }
              else{
                  cout<<"pair sum is not present in the array using single loop";
              }
            }
              break;
            default:
              return 1;
        }
        cout<<"\n\nPress y or Y to continue or any other key to exit : ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}