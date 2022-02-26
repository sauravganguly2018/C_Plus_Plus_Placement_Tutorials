//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
using namespace std;

int main(){
    char arr1[20]="saurav";
    int i=0;
    while(arr1[i]!='\0'){
        cout<<arr1[i];
        cout<<endl;
        i++;
    }

    char arr2[30];
    cout<<"Enter your character array : ";
    cin>>arr2;
    cout<<arr2<<endl;
    cout<<arr2[1];

//Check Palindrome
    int n;
    cout<<"\nEnter the size of character array to check palindrome : ";
    cin>>n;
    char arr3[n+1];
    cout<<"Enter the character array : ";
    cin>>arr3;
    bool check=true;
    for(int i=0;i<n;i++){
        if(arr3[i]!=arr3[n-i-1]){
            check=false;
            break;
        }
    }
    if(check){
        cout<<"It is a palindrome";
    }
    else{
        cout<<"It is not a palindrome";
    }

//Largest word in a sentence
    int w;
    cout<<"\nEnter the maximum character limit in a sentence : ";
    cin>>w;
    cin.ignore();
    char arr4[w+1];
    cout<<"Enter the sentence : ";
    cin.getline(arr4,w);
    cin.ignore();

    int k=0,currlen=0,maxlen=0,sl,el;
    while(true){
        bool flag=1;
        if(arr4[k]==' ' || arr4[k]=='\0'){
         if(currlen>maxlen){
            maxlen=currlen;
            sl=k-maxlen;
            el=k;
         }
            flag=0;
            currlen=0;
        }
        if(arr4[k]=='\0'){
            break;
        }
        if(flag){
         currlen++;
        }
        k++;
    }
    for(int i=sl;i<el;i++){
        cout<<arr4[i];
    }
    cout<<" is the largest word in the sentence of length : "<<maxlen<<" character";
    return 0;
}