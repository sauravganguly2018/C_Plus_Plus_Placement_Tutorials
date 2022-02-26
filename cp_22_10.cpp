//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    n->next=head;
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    head=n;
}

void insertAtTail(node* &head,int val){
    node* n=new node(val);
    node* temp=head;
    if(temp==NULL){
        temp=n;
        temp->next=temp;
        head=temp;
        return;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    temp->next->next=head;
}

int findLen(node* head){
    int count=0;
    node* temp=head;
    if(temp!=NULL){
        count++;
    }
    while(temp!=NULL && temp->next!=head){
        count++;
        temp=temp->next;
    }
    return count;
}

void deleteAtHead(node* &head){
    if(head==NULL){
        cout<<"Circular LL is empty so head cannot be deleted"<<endl;
        return;
    }
    node* temp=head;
    int l=findLen(head);
    node* todelete=head;
    if(l==1){
        delete todelete;
        head=NULL;
        return;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=head->next;
    head=head->next;
    delete todelete;
}

void deletion(node* &head,int pos){
    if(head==NULL){
        cout<<"Circular LL is empty so node cannot be deleted at given position"<<endl;
        return;
    }
    node* temp=head;
    int l=findLen(head);
    if(pos<=0){
        cout<<"node cannot be deleted at given position because the given position is less than or equal to zero"<<endl;
    }
    else{
        int realpos=pos%l;
        if(l==1 || realpos==1){
            deleteAtHead(head);
            return;
        }
        if(realpos==0){
            realpos=l;
        }
        node* prevtemp;
        while(realpos>1){
            prevtemp=temp;
            temp=temp->next;
            realpos--;
        }
        node* todelete=temp;
        prevtemp->next=temp->next;
        delete todelete;
    }
}

void display(node* head){
    node* temp=head;
    if(temp==NULL){
        cout<<"NULL"<<endl;
        return;
    }
    else{
        cout<<temp->data<<" ";
    }
    while(temp->next!=head){
        cout<<temp->next->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);    
    display(head);
    insertAtHead(head,5);
    display(head);
    cout<<findLen(head)<<endl;
    deletion(head,6);
    display(head);
    return 0;
}