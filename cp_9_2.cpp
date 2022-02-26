//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
using namespace std;

//Transpose of a matrix

void transpose_of_a_matrix(){
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

    if(rows==columns){
    cout<<"\nTranspose of this matrix is : \n";
    for(int i=0;i<rows;i++){
        for(int j=i;j<columns;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }  

    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    } 
    }
    else{
        cout<<"\nCannot find transpose because given matrix is not a Square Matrix\n";
    }  
}

//Multiplication of two matrices

void multiplication_of_matrices(){
    int m1,n1;
    cout<<"\nEnter the no. of rows and columns respectively for 1st matrix : ";
    cin>>m1>>n1;
    int arr1[m1][n1];
    cout<<"Enter all the elements : \n";
    for(int i=0;i<m1;i++){
        for(int j=0;j<n1;j++){
            cin>>arr1[i][j];
        }
    }
    cout<<"\nyour given 1st matrix is :\n";
    for(int i=0;i<m1;i++){
        for(int j=0;j<n1;j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }

    int m2,n2;
    cout<<"\nEnter the no. of rows and columns respectively for 2nd matrix : ";
    cin>>m2>>n2;
    int arr2[m2][n2];
    cout<<"\nEnter all the elements : \n";
    for(int i=0;i<m2;i++){
        for(int j=0;j<n2;j++){
            cin>>arr2[i][j];
        }
    }
    cout<<"\nyour given 2nd matrix is :\n";
    for(int i=0;i<m2;i++){
        for(int j=0;j<n2;j++){
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }

    if(n1==m2){
        cout<<"\nNew Matrix after multiplication is : \n";
        int arr3[m1][n2];
        for(int i=0;i<m1;i++){
            for(int j=0;j<n2;j++){
                   arr3[i][j]=0;
                for(int k=0;k<n1;k++){
                    arr3[i][j]+=arr1[i][k]*arr2[k][j];
                }
            }
        }
    for(int i=0;i<m1;i++){
        for(int j=0;j<n2;j++){
            cout<<arr3[i][j]<<" ";
        }
        cout<<endl;
    } 
    cout<<endl; 
    }
    else{
        cout<<"\nGiven two matrices cannot be multiplied as no. of columns of first matrix is not equal to no. of rows of second matrix\n";
    } 
}

//Matrix Search

void matrix_search(){
    int m4,n4;
    cout<<"\nEnter the no. of rows and columns respectively for the matrix : ";
    cin>>m4>>n4;
    int arr4[m4][n4];
    cout<<"Enter all the elements : \n";
    for(int i=0;i<m4;i++){
        for(int j=0;j<n4;j++){
            cin>>arr4[i][j];
        }
    }
    cout<<"\nyour given matrix is :\n";
    for(int i=0;i<m4;i++){
        for(int j=0;j<n4;j++){
            cout<<arr4[i][j]<<" ";
        }
        cout<<endl;
    }
    int elem;
    cout<<"\nEnter the element you desire to search in the matrix : ";
    cin>>elem;
    int i=0;
    int j=n4-1;
    int flag=1;
    while(i<m4 && j>=0){
        if(arr4[i][j]==elem){
            cout<<elem<<" is found at an index of "<<i<<" "<<j;
            flag=0;
            break;
        }
        else if(arr4[i][j]>elem){
            j--;
        }
        else{
            i++;
        }
    }
    if(flag){
    cout<<"\n"<<elem<<" is not found in the matrix"; 
    } 
}

int main(){
    char ch;
    do{
        int choice;
        cout<<"Press 1 : To get a transpose of the matrix\n";
        cout<<"Press 2 : To get multiplication of two matrices\n";
        cout<<"Press 3 : To get search an element in the matrix\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
              transpose_of_a_matrix();
              break;
            case 2:
              multiplication_of_matrices();
              break;
            case 3:
              matrix_search();
              break;
            default:
              return 1;
        }
        cout<<"\n\nPress y or Y to continue or any other key to exit : ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}