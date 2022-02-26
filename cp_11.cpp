//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
using namespace std;

    void swap(int *a,int *b){
        int temp=*a;
        *a=*b;
        *b=temp;
    }

    void increment(int *a){
        cout<<a<<"\n";
        cout<<*a<<endl;
        a++;
        cout<<a<<endl;
        cout<<*a<<endl;
    }

int main(){
    int a=15;
    int *aptr=&a;
    cout<<*aptr<<endl;
    *aptr=20;
    cout<<a<<endl;
    cout<<aptr<<endl;
    aptr++;
    cout<<aptr<<endl;

//Pointers and Arrays

    int arr[]={1,2,3,4};
    cout<<*arr<<endl;

    int *ptr=arr;
    for(int i=0;i<4;i++){
        cout<<*ptr<<" ";
        ptr++;
    }
    cout<<endl;
    for(int i=0;i<4;i++){
        cout<<*(arr+i)<<" ";
        //arr++;   //not allowed because arr is a constant pointer
    }
    cout<<endl;

//Pointer to Pointer

    int b=10;
    int *bptr=&b;
    int **cptr=&bptr;
    cout<<bptr<<endl;
    cout<<*bptr<<endl;
    cout<<cptr<<endl;
    cout<<*cptr<<endl;
    cout<<**cptr<<endl;

//Passing Pointers to function

    int c=20;
    int d=30;
    //Call by reference
    swap(&c,&d);
    cout<<c<<" "<<d<<endl;

    increment(&c);
    cout<<c<<endl;
    cout<<&c;

    return 0;
}