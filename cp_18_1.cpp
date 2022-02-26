//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int** arr,int x,int y,int n){
    if(x<n && y<n && arr[y][x]==1){
        return true;
    }
    return false;
}

bool ratinMaze(int** arr,int x,int y,int n,int** solArr){
    if(x==n-1 && y==n-1){
        solArr[y][x]=1;
        return true;
    }
    if(isSafe(arr,x,y,n)){
        solArr[y][x]=1;
        if(ratinMaze(arr,x+1,y,n,solArr)){
            return true;
        }
        if(ratinMaze(arr,x,y+1,n,solArr)){
            return true;
        }
        solArr[y][x]=0;    // backtracking
        return false;
    }
    return false;
}

void cha(int** arr,int n,int m){
    arr[3][1]=0;
}

int main(){
    int n;
    cout<<"Enter the size of the matrix : ";
    cin>>n;
    int** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
    }
    cout<<"Enter all the elements of the matrix :\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    int** solArr=new int*[n];
    for(int i=0;i<n;i++){
        solArr[i]=new int[n];
        for(int j=0;j<n;j++){
            solArr[i][j]=0;
        }
    }

    ratinMaze(arr,0,0,n,solArr);

    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<solArr[i][j]<<" ";
        }
        cout<<endl;
    }
 
    return 0;
}

// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0  
// 1 0 0 1 1
// 1 1 1 0 1