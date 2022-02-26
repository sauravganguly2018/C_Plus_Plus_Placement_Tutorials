//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int sum_of_first_n_natural_no(int num){
    int sum=0;
      for(int i=1;i<=num;i++){
         sum+=i;
      }
      return sum;
}

bool check_pythagorian_triplet(int x,int y,int z){
        if(x>y){
            if(x>z){
                if(pow(x,2)==pow(y,2)+pow(z,2)){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                if(pow(z,2)==pow(y,2)+pow(x,2)){
                    return true;
                }
                else{
                    return false;
                } 
            }
        }
        else{
            if(y>z){
                if(pow(y,2)==pow(x,2)+pow(z,2)){
                    return true;
                }
                else{
                    return false;
                }               
            }
            else{
                if(pow(z,2)==pow(y,2)+pow(x,2)){
                    return true;
                }
                else{
                    return false;
                }               
            }
        }
}

int binary_to_decimal(int num){
    int i=0;
    int res=0;
    int lastdigit;
    while(num>0){
      lastdigit=num%10;
      if(lastdigit==0 || lastdigit==1){
          res+=lastdigit*pow(2,i);
      }
      else{
          return -1;
      }
      num/=10;
      i++;
    }
    return res;
}

int octal_to_decimal(int num){
    int i=0;
    int res=0;
    int lastdigit;
    while(num>0){
      lastdigit=num%10;
      if(lastdigit>=0 && lastdigit<8){
          res+=lastdigit*pow(8,i);
      }
      else{
          return -1;
      }
      num/=10;
      i++;
    }
    return res;
}

int hexadecimal_to_decimal(string s){
    int res=0;
    int size=s.size();
    int j=0;
    for(int i=size-1;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            res+=(s[i]-'0')*pow(16,j);
            j++;
        }
        else if(s[i]>='A' && s[i]<='F'){
            res+=(s[i]-'A'+10)*pow(16,j);
            j++;
        }
        else{
            return -1;
        }   
    }
    return res;
       
}

int decimal_to_binary(int num){
       int total=0;
       int res=1;
       int lastdigit;
       while(num>0){
            lastdigit=num%2;
            total+=res*lastdigit;
            res*=10;
            num/=2;
       }
       return total;
}

int decimal_to_octal(int num){
       int total=0;
       int res=1;
       int lastdigit;
       while(num>0){
            lastdigit=num%8;
            total+=res*lastdigit;
            res*=10;
            num/=8;
       }
       return total;
}

string decimal_to_hexadecimal(int num){
    int x=1;
    while(x<num){
        x*=16;
    }
    x/=16;
    int lastdigit;
    string total="";
      while(x>0){     //We can also put num instead of x
         lastdigit=num/x;
         num-=lastdigit*x;
         if(lastdigit<10){
            total=total+to_string(lastdigit);
         }
         else{
            char c='A'+(lastdigit-10);
            total+=c;
         }
         x/=16;
    }

    // method 2

    // string total="";
    // int x=16;
    // int rem;
    // while(num>0){
    //     rem=num%16;
    //    if(rem<10){
    //        total=to_string(rem)+total;
    //    }
    //    else{
    //        char c='A'+(rem-10);
    //        total=c+total;
    //    }
    //    num/=16;
    // }

    return total;
}

int add_binary(int a,int b){
    int total=0;
    int x=1;
    int previouscarry=0;
    while(a>0 && b>0){
           if(a%2==0 && b%2==0){
               total+=previouscarry*x;
               previouscarry=0;
               x*=10;
           }
           else if((a%2==0 && b%2==1) || (a%2==1 && b%2==0)){
               if(previouscarry==0){
                   total+=1*x;
                   previouscarry=0;
                   x*=10;
               }
               else{
                   total+=0*x;
                   previouscarry=1;
                   x*=10;
               }
           }
           else{
               total+=previouscarry*x;
               previouscarry=1;
               x*=10;
           }
           a/=10;
           b/=10;
    }
    while(a>0){
        if(a%2==0){
            total+=previouscarry*x;
            previouscarry=0;
            x*=10;
        }
        else{
            if(previouscarry==1){
               total+=0*x;
               previouscarry=1;
               x*=10;
            }
            else{
                total+=1*x;
                previouscarry=0;
                x*=10;
            }
        }
        a/=10;
    }
    while(b>0){
        if(b%2==0){
            total+=previouscarry*x;
            previouscarry=0;
            x*=10;
        }
        else{
            if(previouscarry==1){
               total+=0*x;
               previouscarry=1;
               x*=10;
            }
            else{
                total+=1*x;
                previouscarry=0;
                x*=10;
            }
        }
        b/=10;
    }
    if(previouscarry==1){
        total+=1*x;
    }
    return total;
}

int main(){
    char ch;
    do{
        int choice;
        cout<<"Press 1 : To get sum of n natural number\n";
        cout<<"Press 2 : To check for a pythagorian triplet\n";
        cout<<"Press 3 : To convert binary to decimal no.\n";
        cout<<"Press 4 : To convert octal to decimal no.\n";
        cout<<"Press 5 : To convert hexadecimal to decimal no.\n";
        cout<<"Press 6 : To convert decimal to binary no.\n";
        cout<<"Press 7 : To convert decimal to octal no.\n";
        cout<<"Press 8 : To convert decimal to hexadecimal no.\n";
        cout<<"Press 9 : To add two binary no.\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:{
               int num,sum;
               cout<<"Enter the no. : ";
               cin>>num;
               sum=sum_of_first_n_natural_no(num);
               cout<<"The sum of natural no. upto "<<num<<" is "<<sum;
            }
              break;
            case 2:{
               int x,y,z;
               bool check;
               cout<<"Enter all the three no. respectively : ";
               cin>>x>>y>>z;
               check=check_pythagorian_triplet(x,y,z);
               if(check){
                   cout<<"This is a pythagorian Triplet";
               }
               else{
                   cout<<"This is not a pythagorian Triplet";
               }
            }
              break;
            case 3:{
               int res,num;
               cout<<"Enter your binary no. : ";
               cin>>num;
               res=binary_to_decimal(num);
               if(res==-1){
                   cout<<"Invalid Binary Number given !";
               }
               else{
                   cout<<"The decimal no. of "<<num<<" is "<<res;
               }
            }
              break;
            case 4:{
               int res,num;
               cout<<"Enter your octal no. : ";
               cin>>num;
               res=octal_to_decimal(num);
               if(res==-1){
                   cout<<"Invalid Octal Number given !";
               }
               else{
                   cout<<"The decimal no. of "<<num<<" is "<<res;
               }
            }
              break;
            case 5:{
               string s;
               int res;
               cout<<"Enter your hexadecimal no. : ";
               cin>>s;
               res=hexadecimal_to_decimal(s);
               if(res==-1){
                   cout<<"Invalid Hexadecimal Number given !";
               }
               else{
                   cout<<"The decimal no. of "<<s<<" is "<<res;
               }
            }
              break;
            case 6:{
               int num;
               int res;
               cout<<"Enter your decimal no. : ";
               cin>>num;
               res=decimal_to_binary(num);
               cout<<"The binary no. of "<<num<<" is "<<res;
            }
              break;
            case 7:{
               int num;
               int res;
               cout<<"Enter your decimal no. : ";
               cin>>num;
               res=decimal_to_octal(num);
               cout<<"The octal no. of "<<num<<" is "<<res;
            }
              break;
            case 8:{
               int num;
               string res;
               cout<<"Enter your decimal no. : ";
               cin>>num;
               res=decimal_to_hexadecimal(num);
               cout<<"The hexadecimal no. of "<<num<<" is "<<res;
            }
              break;
            case 9:{
               int num1,num2;
               int res;
               cout<<"Enter your first binary no. : ";
               cin>>num1;
               cout<<"Enter your second binary no. : ";
               cin>>num2;
               res=add_binary(num1,num2);
               cout<<"The resultant binary no. is "<<res;
            }
              break;
            default:
              return 1;
        }
        cout<<"\n\nPress y or Y to continue or any other key to exit : ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}