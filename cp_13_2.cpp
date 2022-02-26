//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    string str="saurav ganguly";
//Convert into uppercase
    for(int i=0;i<str.size();i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i]-=32;
        }
    }
    cout<<str<<endl;

//Convert into lowercase
    for(int i=0;i<str.size();i++){
        if(str[i]>='A' && str[i]<='Z'){
            str[i]+=32;
        }
    }
    cout<<str<<endl;

    string str2="saurav ganguly";
    transform(str2.begin(),str2.end(),str2.begin(),::toupper);
    cout<<str2<<endl;
    transform(str2.begin(),str2.end(),str2.begin(),::tolower);
    cout<<str2<<endl;

//sort the numeric string in decreasing order
    string str3="476587664239";
    sort(str3.begin(),str3.end(),greater<int>());
    cout<<str3<<endl;

//Maximum frequency in a string
    int arr[26];
    for(int i=0;i<26;i++){
        arr[i]=0;
    }
    string str4="gdsjhfguyegfbsshgfjdkjfhsgdywubjdjhsgdg";
    for(int i=0;i<str4.size();i++){
         arr[str4[i]-'a']++;
    }
    char ch2='a';
    int maxf=0;
    for(int i=0;i<26;i++){
        if(arr[i]>maxf){
            maxf=arr[i];
            ch2=i+'a';
        }
    }
    cout<<ch2<<" is the most occuring character which occured "<<maxf<<" times in the string ";
    

    return 0;
}