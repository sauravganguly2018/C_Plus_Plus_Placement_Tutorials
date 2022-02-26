//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
using namespace std;

void inverted_pattern(){
    int rows;
    cout<<"Enter the no. of rows : ";
    cin>>rows;
    for(int i=rows;i>0;i--){
        for(int j=0;j<i;j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}

void zero_one_pattern(){
    int rows;
    cout<<"Enter the no. of rows : ";
    cin>>rows;
    for(int i=0;i<rows;i++){
        for(int j=0;j<=i;j++){
            if((i+j)%2==0){
                cout<<1<<" ";
            }
            else{
            cout<<0<<" ";
            }
        }
        cout<<endl;
    }    
}

void rhombus(){
    int rows;
    cout<<"Enter the no. of rows : ";
    cin>>rows;
    for(int i=0;i<rows;i++){
        for(int j=0;j<2*rows-i-1;j++){
             if(j<rows-i-1){
                 cout<<"  ";
             }
             else{
                cout<<"* ";
             }
        }
        cout<<endl;
    }
}

void number_pattern(){
    int rows;
    cout<<"Enter the no. of rows : ";
    cin>>rows;
    for(int i=0;i<rows;i++){
        int count=0;
       for(int j=0;j<rows;j++){
           if(j<rows-i-1){
               cout<<" ";
           }
           else{
               count++;
               cout<<count<<" ";
           }
       }
       cout<<endl;
    }
}

void palindromic_pattern(){
    int rows;
    cout<<"Enter the no. of rows : ";
    cin>>rows;
    for(int i=0;i<rows;i++){
        int c=i+2;
        for(int j=0;j<2*rows;j++){
            if(j<rows){
                if(j<rows-i-1){
                    cout<<"  ";
                }
                else{
                    c--;
                    cout<<c<<" ";                   
                }
            }
            else{
                if(j<rows+i){
                    c++;
                    cout<<c<<" ";
                }
                else{
                    cout<<"  ";
                }
            }
        }
        cout<<endl;
    } 
}

void star_pattern(){
    int rows;
    cout<<"Enter the no. of rows : ";
    cin>>rows;
    for(int i=0;i<2*rows;i++){
        for(int j=0;j<2*rows-1;j++){
            if(i<rows){
                if(j<rows-i-1 || j>rows+i-1){
                    cout<<" ";
                }
                else{
                    cout<<"*";
                }
            }
            else{
                if(j<i-rows || j>3*rows-i-2){
                    cout<<" ";
                }
                else{
                    cout<<"*";
                }
            }
        }
        cout<<endl;
    }
}

void zig_zag_pattern(){
    int rows;
    cout<<"Enter the no. of rows : ";
    cin>>rows;
    for(int i=0;i<rows;i++){
        if(i%4==2){
            cout<<"*";
        }
        else{
            cout<<" ";
        }
    }
    cout<<endl;
    for(int i=0;i<rows;i++){
        if(i%2==1){
            cout<<"*";
        }
        else{
            cout<<" ";
        }
    }
    cout<<endl;
    for(int i=0;i<rows;i++){
        if(i%4==0){
            cout<<"*";
        }
        else{
            cout<<" ";
        }
    }
}

int main(){
    char ch;
    do{
        int choice;
        cout<<"Press 1 : To Print Inverted Pattern\n";
        cout<<"Press 2 : To Print zero-one pattern\n";
        cout<<"Press 3 : To Print the Rhombus\n";
        cout<<"Press 4 : To Print the number pattern\n";
        cout<<"Press 5 : To Print the palindromic pattern\n";
        cout<<"Press 6 : To Print the star pattern\n";
        cout<<"Press 7 : To Print the zig-zag pattern\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
              inverted_pattern();
              break;
            case 2:
              zero_one_pattern();
              break;
            case 3:
              rhombus();
              break;
            case 4:
              number_pattern();
              break;
            case 5:
              palindromic_pattern();
              break;
            case 6:
              star_pattern();
              break;
            case 7:
              zig_zag_pattern();
              break;
            default:
              return 1;
        }
        cout<<"\n\nPress y or Y to continue or any other key to exit : ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}