//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
// #include<bits/stdc++.h>
#include<stack>
using namespace std;

bool isValid(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='[' || s[i]=='{' || s[i]=='('){
            st.push(s[i]);
        }
        else if(!st.empty()){
            if(s[i]==')'){
                if(st.top()=='('){
                    st.pop();
                }else{
                    return false;
                }
            }
            if(s[i]=='}'){
                if(st.top()=='{'){
                    st.pop();
                }else{
                    return false;
                }
            }
            if(s[i]==']'){
                if(st.top()=='['){
                    st.pop();
                }else{
                    return false;
                }
            }
        }else{
            return false;
        }
    }
    if(!st.empty()){
        return false;
    }
    return true;
}

int main(){
    string s="{([]})";
    if(isValid(s)){
        cout<<"Valid String"<<endl;
    }else{
        cout<<"Invalid String"<<endl;
    }
    return 0;
}