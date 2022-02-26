//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
using namespace std;

int main(){
    int rows,columns;
    cout<<"Enter the no. of rows and columns respectively : ";
    cin>>rows>>columns;
    int arr[rows][columns];
    cout<<"Enter all the elements : \n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"\nyour given matrix is :\n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }   

//Searching an element in the matrix

    int elem;
    cout<<"\nEnter the element which you want to find in the matrix : ";
    cin>>elem;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(arr[i][j]==elem){
                cout<<"Element is found at an index of "<<i<<" "<<j<<endl;
                // break;
            }
        }
    }

//Spiral Order Matrix Traversal

    int row_start=0,row_end=rows-1,column_start=0,column_end=columns-1;
    while(row_start<=row_end && column_start<=column_end){
        //row start
        if(row_start<=row_end && column_start<=column_end){
        for(int col=column_start;col<=column_end;col++){
              cout<<arr[row_start][col]<<" ";
           }
        row_start++;
        }
        else{
            break;
        }

        //column end
        if(row_start<=row_end && column_start<=column_end){
        for(int row=row_start;row<=row_end;row++){
            cout<<arr[row][column_end]<<" ";
        }
        column_end--;          
        }
        else{
            break;
        }

        //row end
        if(row_start<=row_end && column_start<=column_end){
        for(int col=column_end;col>=column_start;col--){
            cout<<arr[row_end][col]<<" ";
        }
        row_end--;
        }
        else{
            break;
        }

        //column start
        if(row_start<=row_end && column_start<=column_end){
        for(int row=row_end;row>=row_start;row--){
            cout<<arr[row][column_start]<<" ";
        }
        column_start++;
        }
        else{
            break;
        }
    }
    return 0;
}