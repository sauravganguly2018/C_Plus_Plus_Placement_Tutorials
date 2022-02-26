//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
// #include<bits/stdc++.h>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st,int elem){
    if(st.empty()){
        st.push(elem);
        return;
    }
    int topelem=st.top();
    st.pop();
    insertAtBottom(st,elem);
    st.push(topelem);
}

void reverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    int topelem=st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,topelem);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverse(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();  
    }
    return 0;
}