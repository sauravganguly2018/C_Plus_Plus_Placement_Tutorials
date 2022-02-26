//*******************************************----Coded by Saurav Ganguly----*******************************************s
#include<iostream>
#include<string>
using namespace std;

void reverse(string s){
    if(s.length()==0){
        return;
    }
    reverse(s.substr(1));
    cout<<s[0];
}

void replacepi(string s){
    if(s.length()==0){
        return;
    }
    if(s[0]=='p' && s[1]=='i'){
        cout<<"3.14";
        replacepi(s.substr(2));
    }
    else{
        cout<<s[0];
        replacepi(s.substr(1));
    }
}

void toh(int n,char source,char helping,char destination){
    if(n==0){
        return;
    }
    toh(n-1,source,destination,helping);
    cout<<"\nMove a disc from "<<source<<" to "<<destination;
    toh(n-1,helping,source,destination);
}

string removeDup(string s){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];
    string ans=removeDup(s.substr(1));
    if(ch==ans[0]){
        return ans;
    }
    return ch+ans;
}


string movexToLast(string s){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];
    string ans=movexToLast(s.substr(1));
    if(ch=='x'){
        return ans+ch;       
    }
    return ch+ans;
}

void subseq1(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string res=s.substr(1);
    subseq1(res,ans);
    subseq1(res,ans+ch);
}

void subseq2(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    int ascii=ch;
    string res=s.substr(1);
    subseq2(res,ans);
    subseq2(res,ans+ch);
    subseq2(res,ans+to_string(ascii));
}

string keypadArr[]={"","./","abc","def","ghi","jkl","mno"};

void keypad(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch=s[0];
    string res=s.substr(1);
    string code=keypadArr[ch-'0'];
    for(int i=0;i<code.length();i++){
        keypad(res,ans+code[i]);
    }
}

int main(){
    reverse("saurav ganguly");
    cout<<endl;
    replacepi("pepifjdpppipqpi");
    cout<<"\n\n\t\t\t Tower of Hanoi\n\n";
    int n;
    cout<<"Enter the no. of discs : ";
    cin>>n;
    char start,help,dest;
    cout<<"Enter the starting, helping and destination point respectively : ";
    cin>>start>>help>>dest;
    cout<<"Transfer of discs occurs as follows :\n";
    toh(n,start,help,dest);
    cout<<"\nTransfer completed\n\n";
    cout<<removeDup("aaaabbcdddeeggfff")<<endl;
    cout<<movexToLast("azxhxxjhsgxhxxhxjxjjpx")<<endl;
    cout<<"\nsubseq1 start !\n";   
    subseq1("ABC","");
    cout<<"subseq1 finished !";
    cout<<"\n\nsubseq2 start !\n";
    subseq2("AB","");
    cout<<"subseq2 finished !";
    cout<<"\n\n\t\t\tKeypad problem !\n\n";
    keypad("23","");
    return 0;
}