//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<cmath>
using namespace std;

int single_unique_in_twice(int arr[],int n){
    int xorsum=0;
    for(int i=0;i<n;i++){
        xorsum=xorsum ^ arr[i];
    }
    return xorsum;
}

int getbit(int n,int pos){
    return ((n & 1<<pos)!=0);
}

int binary_to_decimal(int n){
    int sum=0;
    int k,i=0;
    while(n){
        k=n%10;
        sum+=k*pow(2,i);
        i++;
        n/=10;
    }
    return sum;
}

int double_unique_in_twice(int arr[],int n){
    int xorsum=0;
    for(int i=0;i<n;i++){
        xorsum=xorsum ^ arr[i];
    }
    int tempxor=xorsum;
    int getbit1=0;
    int pos=0;
    while(getbit1==0){
        getbit1 = 1 & xorsum;
        pos++;
        xorsum=xorsum>>1;
    }
    int newxor=0;
    for(int i=0;i<n;i++){
         if(getbit(arr[i],pos-1)){
            newxor=newxor ^ arr[i];
         }
    }
    cout<<"First unique no. in duplet array is : "<<newxor<<endl;
    cout<<"Second unique no. in duplet array is : "<<(newxor^tempxor)<<endl;
}

int single_unique_in_thrice(int arr[],int n){
    int arr2[6];
    for(int i=0;i<6;i++){
          arr2[i]=0;
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<n;j++){
            if(getbit(arr[j],i)){
                 arr2[i]++;
            }
        }
    }
    for(int i=0;i<6;i++){
         if(arr2[i]%3==0){
             arr2[i]=0;
         }
         else{
             arr2[i]=1;
         }
    }
    int x=1;
    int res=0;
    for(int i=0;i<6;i++){
         res=arr2[i]*x+res;
         x*=10;
    }
    cout<<"The single unique no. in the triplet array is : "<<binary_to_decimal(res);
}

int main(){
    int arr[]={1,2,3,4,9,4,3,2,1};
    int res=single_unique_in_twice(arr,9);
    cout<<"The single unique no. in the duplet array is : "<<res<<endl;

    int arr2[]={1,2,3,4,3,2,5,1};  
    double_unique_in_twice(arr2,8);

    int arr3[]={1,2,3,3,17,2,1,2,3,1,4,4,4};
    single_unique_in_thrice(arr3,13);
    
    return 0;
}