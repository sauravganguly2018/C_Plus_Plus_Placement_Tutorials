//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void per(string s,string ans){
    if(s.size()==1){
        cout<<ans+s<<endl;
        return;
    }
    for(int i=0;i<s.size();i++){
        string ts=s;
        per(ts.erase(i,1),ans+s[i]);
    }
}

int countPath(int s, int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count=0;
    for(int i=1;i<=6;i++){
        count+=countPath(s+i,e);
    }
    return count;
}

int countPathMaze(int n,int i,int j){
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }
    return countPathMaze(n,i+1,j)+countPathMaze(n,i,j+1);
}

int tilingways(int n){
    if(n<=2){
        return n;
    }
    return tilingways(n-1)+tilingways(n-2);
}

int friendsPairing(int n){
    if(n<=2){
        return n;
    }
    return friendsPairing(n-1)+friendsPairing(n-2)*(n-1);
}

int knapsack(int wt[],int value[],int n,int W){
    if(n==0 || W==0){
        return 0;
    }
    if(wt[n-1]>W){
        return knapsack(wt,value,n-1,W);
    }
    return max(knapsack(wt,value,n-1,W-wt[n-1])+value[n-1],knapsack(wt,value,n-1,W));
}

int main(){
    char ch;
    do{
        int choice;
        cout<<"Press 1 : To print all possible permutations of a string\n";
        cout<<"Press 2 : To count the no. of paths possible from start point to end point in gameboard\n";
        cout<<"Press 3 : To count the number of paths possible in a maze\n";
        cout<<"Press 4 : To count the no. of ways to tile the given board using these tiles\n";
        cout<<"Press 5 : To find the no. of ways in which friends can remain single or can be paired up\n";
        cout<<"Press 6 : To find the value of a knapsack problem\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
            per("abc","");
              break;
            case 2:
            cout<<countPath(0,3);
              break;
            case 3:
            cout<<countPathMaze(3,0,0);;
              break;
            case 4:
            cout<<tilingways(4);;
              break;
            case 5:
            cout<<friendsPairing(4);
              break;
            case 6:{
            int n=3;
            int wt[n]={10,20,30};
            int value[]={100,50,150};
            int W=50;
            cout<<knapsack(wt,value,n,W);
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