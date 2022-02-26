//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
using namespace std;

void print_rectangle(){
    int rows,columns;
    cout<<"Enter the no. of rows : ";
    cin>>rows;
    cout<<"Enter the no. of column : ";
    cin>>columns;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void print_hollow_rectangle(){
    int rows,columns;
    cout<<"Enter the no. of rows : ";
    cin>>rows;
    cout<<"Enter the no. of column : ";
    cin>>columns;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(i==0 || i==rows-1){
                 cout<<"* ";
            }
             else{
                 if(j==0 || j==columns-1){
                     cout<<"* ";
                 }
                 else{
                     cout<<"  ";
                 }
             }
        }
        cout<<endl;
    }
}

void inverted_half_pyramid(){
    int rows;
    cout<<"Enter the no. of rows : ";
    cin>>rows;
    for(int i=0;i<rows;i++){
        for(int j=0;j<rows-i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void half_pyramid_after_180_degree_rotation(){
    int rows;
    cout<<"Enter the no. of rows : ";
    cin>>rows;
    for(int i=0;i<rows;i++){
        for(int j=0;j<rows;j++){
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

void half_pyramid_using_numbers(){
    int rows;
    cout<<"Enter the no. of rows : ";
    cin>>rows;
    for(int i=0;i<rows;i++){
        for(int j=0;j<=i;j++){
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
}

void floyds_triangle(){
    int rows;
    cout<<"Enter the no. of rows : ";
    cin>>rows;
    int count=0;
    for(int i=0;i<rows;i++){
          for(int j=0;j<=i;j++){
             count++;
             cout<<count<<" ";
          }
          cout<<endl;
      }
}

void butterfly_pattern(){
    int rows;
    cout<<"Enter the no. of rows : ";
    cin>>rows;
    for(int i=0;i<2*rows;i++){
        for(int j=0;j<2*rows;j++){
            if(i<rows){
                if(j>i && j<2*rows-i-1){
                    cout<<"  ";
                }
                else{
                    cout<<"* ";
                }
            }
            else{
                if(j>=2*rows-i && j<i){
                    cout<<"  ";
                }
                else{
                    cout<<"* ";
                }
            }
        }
        cout<<endl;
    }   
}

int main(){
    char ch;
    do{
        int choice;
        cout<<"Press 1 : To Print Rectangle\n";
        cout<<"Press 2 : To Print Hollow Rectangle\n";
        cout<<"Press 3 : To Print inverted half pyramid\n";
        cout<<"Press 4 : To Print half pyramid after 180 degree rotation\n";
        cout<<"Press 5 : To Print half pyramid using numbers\n";
        cout<<"Press 6 : To Print floyds triangle\n";
        cout<<"Press 7 : To Print butterfly pattern\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
              print_rectangle();
              break;
            case 2:
              print_hollow_rectangle();
              break;
            case 3:
              inverted_half_pyramid();
              break;
            case 4:
              half_pyramid_after_180_degree_rotation();
              break;
            case 5:
              half_pyramid_using_numbers();
              break;
            case 6:
              floyds_triangle();
              break;
            case 7:
              butterfly_pattern();
              break;
            default:
              return 1;
        }
        cout<<"\n\nPress y or Y to continue or any other key to exit : ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}