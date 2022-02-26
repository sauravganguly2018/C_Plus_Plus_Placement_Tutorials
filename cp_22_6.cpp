//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;
    node(int val){
       data=val;
       prev=NULL;
       next=NULL;
    }
};

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    if(head!=NULL){
       n->next=head;
       head->prev=n; 
    }
    head=n;
}

void insertAtTail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void deleteAtHead(node* &head){
    if(head!=NULL){
        node* todelete=head;
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        delete todelete;
    }
    else{
        cout<<"Since there is no element at head so we can't delete at head"<<endl;        
    }
}

void deletion(node* &head,int val){
    node *temp=head;
    if(temp!=NULL && temp->data==val){
        node *todelete=temp;
        if(temp->next!=NULL){
            head->next->prev=NULL;
        }
        head=temp->next;
        delete todelete;
        return;
    }
    while(temp!=NULL && temp->next!=NULL){
        if(temp->next->data==val){
            node *todelete=temp->next;
            temp->next=temp->next->next;
            if(temp->next!=NULL){
                temp->next->prev=temp;
            }
            delete todelete;
            return;
        }
        temp=temp->next;
    }
    cout<<val<<" is not present in the linked list so can't be deleted"<<endl;
}

int findLen(node* head){
    node* temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}

void appendLast_K_NodesAtBeg(node* &head,int k){
    int l=findLen(head);
    if(l>k && k>0){
        int newTailPos=l-k;
        node* temp=head;
        node* newTail;
        node* newHead;
        node* tail;
        int count=1;
        while(temp!=NULL){
            if(count==newTailPos){
                newTail=temp;
            }
            if(count==newTailPos+1){
                newHead=temp;
            }
            if(count==l){
                tail=temp;
            }
            temp=temp->next;
            count++;
        }
        tail->next=head;
        head->prev=tail;
        newTail->next=NULL;
        newHead->prev=NULL;
        head=newHead;       
    }
    else{
        if(k>0){
            cout<<"No append happened because Length of DLL is not greater than the Length of the last K Nodes to be appended"<<endl;
        }
        else{
            cout<<"No append happened because the value of Length of the last K Nodes is less than or equal to zero"<<endl;
        }
    }
}

void display(node* head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);
    insertAtHead(head,4);
    display(head);
    deletion(head,2);
    display(head);
    deleteAtHead(head);
    display(head);
    cout<<findLen(head)<<endl;
    appendLast_K_NodesAtBeg(head,1);
    display(head);
    return 0;
}