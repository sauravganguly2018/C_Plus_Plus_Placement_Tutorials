//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool myCompare(pair<int,int> p1,pair<int,int> p2){
    return p1.first<p2.first;
}

int main(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);  

    for(int i=0; i<v1.size();i++){
        cout<<v1[i]<<endl;
    }// 1 2 3

    vector<int>::iterator it;
    for(it=v1.begin();it!=v1.end();it++){
        cout<<*it<<endl;
    }// 1 2 3

    for(auto element:v1){
        cout<<element<<endl;
    }// 1 2 3

    v1.pop_back(); // 1 2

    vector<int> v2 (3,50);
    // 50 50 50

    swap(v1,v2);
    for(auto element:v1){
        cout<<element<<endl;
    }

    for(auto element:v2){
        cout<<element<<endl;
    }

    sort(v1.begin(),v1.end());

    pair<int,char> p;
    p.first=2;
    p.second='s';
    
    int arr[]={10,16,7,14,5,3,12,9};
    vector<pair<int,int>> v;

    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
        v.push_back(make_pair(arr[i],i));
    }

    sort(v.begin(),v.end(),myCompare);
    for(int i=0;i<v.size();i++){
        arr[v[i].second]=i;
    }
    for(int i=0;i<v.size();i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}