//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    // string str="Saurav Ganguly";
    // string str1(5,'a');
    // cout<<str<<endl;
    // cout<<str1<<endl;

    // string str2;
    // cout<<"Enter the string : ";
    // cin>>str2;
    // cout<<"Without use of getline string is printed as : ";
    // cout<<str2<<endl;

    string str3;
    cout<<"Enter the string : ";
    getline(cin,str3);
    cout<<"using getline string is printed as : ";
    cout<<str3<<endl;

    string s1="fam";
    string s2="ily";
    s1=s1+s2;
    cout<<s1<<endl;
    cout<<s1[4]<<endl;

    string s3="saurav is a good boy";
    cout<<s3<<endl;
    s3.clear();
    cout<<s3<<endl;

    string s4="sau";
    string s5="sau";
    cout<<s4.compare(s5)<<endl;
    if(!s4.compare(s5)){
        cout<<"strings are equal"<<endl;
    }

    string s6="abc";
    cout<<s6<<endl;
    s6.clear();
    if(s6.empty()){
       cout<<"string is empty"<<endl;
    }
    if(!s6.empty()){
       cout<<"string is not empty"<<endl;
    }

    string s7="hippopotomonstro";
    cout<<s7.find("opo")<<endl;
    s7.insert(4,"opo");
    cout<<s7<<endl;
    s7.erase(5,4);
    cout<<s7<<endl;
    cout<<s7.size()<<endl;
    cout<<s7.length()<<endl;

    string s8="rhinoceros";
    string s9=s8.substr(5,4);
    cout<<s9<<endl;

    string s10="567";
    int x=stoi(s10);
    cout<<x*2<<endl;

    int y=342;
    string s11=to_string(y);
    cout<<s11+"45"<<endl;

    string s12="dhcueurfjhsbcjhjzertyw";
    sort(s12.begin(),s12.end());
    cout<<s12<<endl;

    return 0;
}