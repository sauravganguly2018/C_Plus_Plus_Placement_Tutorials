//*******************************************----Coded by Saurav Ganguly----*******************************************
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
    
    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head,int val){
    node *n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}

bool search(node *head,int key){
    node *temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void display(node* head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleteAtHead(node* &head){
    if(head!=NULL){
        node* todelete=head;
        head=head->next;
        delete todelete;
    }
    else
    {
        cout<<"Since there is no element at head so we can't delete at head"<<endl;
    }
}

void deletion(node* &head,int val){
    node *temp=head;
    if(temp!=NULL && temp->data==val){
        node *todelete=temp;
        head=temp->next;
        delete todelete;
        return;
    }
    while(temp!=NULL && temp->next!=NULL){
        if(temp->next->data==val){
            node *todelete=temp->next;
            temp->next=temp->next->next;
            delete todelete;
            return;
        }
        temp=temp->next;
    }
    cout<<val<<" is not present in the linked list so can't be deleted"<<endl;
}

void reverse(node* &head){
    node* prev=NULL;
    node* current=head;
    node* nxt;
    while(current!=NULL){
        nxt=current->next;
        current->next=prev;
        prev=current;
        current=nxt;
    }
    head=prev;
}

node* reverseRecursive(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newhead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

node* reversek(node* &head,int k){
    node* prev=NULL;
    node* curr=head;
    node* nxt;
    if(curr==NULL || curr->next==NULL){
        return curr;
    }
    while(k>0){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
        k--;
    }
    head->next=reversek(curr,2);
    return prev;
}

void reverse_first_k_nodes(node* &head,int k){
    node* prev=NULL;
    node* current=head;
    node* nxt;
    node* revlast=current;
    if(k==0){
        return;
    }
    else{
     while(k>0 && current!=NULL){
        nxt=current->next;
        current->next=prev;
        prev=current;
        current=nxt;
        k--;
     }
     head=prev;
     if(current!=NULL){
        revlast->next=current;
     }
    }
}

void makeCycle(node* &head,int pos){
    node* temp=head;
    node* startNode;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}

bool detectCycle(node* &head){
    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

void removeCycle(node* &head){
    if(detectCycle(head)){
        node* slow=head;
        node* fast=head;

        do{
            slow=slow->next;
            fast=fast->next->next;
        }while(slow!=fast);
        fast=head;
        while(fast->next!=slow->next){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=NULL;
    }
    else{
        cout<<"It is not a cycled linked list so cannot be uncycled"<<endl;
    }
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
        newTail->next=NULL;
        head=newHead;       
    }
    else{
        if(k>0){
            cout<<"No append happened because Length of LL is not greater than the Length of the last K Nodes to be appended"<<endl;
        }
        else{
            cout<<"No append happened because the value of Length of the last K Nodes is less than or equal to zero"<<endl;
        }
    }
}

void intersect(node* head1,node* head2,int pos){
    node* temp1=head1;
    node* temp2=head2;
    int len1=findLen(head1);
    int len2=findLen(head2);
    if(len1>=len2 && len1>0 && len2>0 && len1>=pos){
        while(pos>1){
            temp1=temp1->next;
            pos--;
        }
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp2->next=temp1;
    }
    else if(len2>len1 && len2>0 && len1>0 && len2>=pos){
        while(pos>1){
            temp2=temp2->next;
            pos--;
        }
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp2;
    }
    else{
        cout<<"Intersection of given LL is not possible"<<endl;
    }
}

int intersectionTwoLL(node* head1,node* head2){
    int len1=findLen(head1);
    int len2=findLen(head2);
    int pos;
    node* temp1=head1;
    node* temp2=head2;
    if(len1>=len2){
        pos=len1-len2;
        while(pos>0){
            temp1=temp1->next;
            pos--;
        }
    }
    else{
        pos=len2-len1;
        while(pos>0){
            temp2=temp2->next;
            pos--;
        }
    }
    while(temp1!=NULL){
        if(temp1==temp2){
            return temp1->data;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return -1;
}

node* mergeTwoSortedLL(node* head1,node* head2){
    node* ptr3=new node(-1);
    node* dummyNode=ptr3;
    node* ptr1=head1;
    node* ptr2=head2;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data<=ptr2->data){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    while(ptr1!=NULL){
        ptr3->next=ptr1;
        break;
    }
    while(ptr2!=NULL){
        ptr3->next=ptr2;
        break;
    }
    return dummyNode->next;
}

node* mergeRecursive(node* head1,node* head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    node* result;
    if(head1->data<=head2->data){
        result=head1;
        result->next=mergeRecursive(head1->next,head2);
    }
    else{
        result=head2;
        result->next=mergeRecursive(head1,head2->next);
    }
    return result;
}

void putEvenPosNodAftOddPosNod(node* head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        return;
    }
    node* oddend=head;
    node* odd=head;
    node* starteven=head->next;
    node* even=head->next;
    do{
        oddend=odd;
        odd->next=even->next;
        odd=odd->next;
        if(even->next!=NULL){
            even->next=odd->next;
            even=even->next;
        }
    }while(odd!=NULL && even!=NULL);
    if(odd==NULL){
        oddend->next=starteven;
    }
    else{
        odd->next=starteven;
    }
}

int main(){
    node *head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    // display(head);
    // insertAtHead(head,4);
    // display(head);
    // cout<<search(head,2)<<endl;
    // deletion(head,2);
    // display(head);
    // deleteAtHead(head);
    // display(head);
    // reverse(head);
    // display(head);
    // node* newhead=reverseRecursive(head);
    // display(newhead);
    // display(head);
    // reverse_first_k_nodes(head,3);
    // display(head);
    // node* newhead1=reversek(head,2);
    // display(newhead1);
    display(head);
    // makeCycle(head,2);
    // cout<<detectCycle(head)<<endl;
    // removeCycle(head);
    // display(head);
    // cout<<detectCycle(head);
    appendLast_K_NodesAtBeg(head,3);
    display(head);

    node* head1=NULL;
    node* head2=NULL;
    int arr1[6]={1,2,3,4,5,6};
    int arr2[2]={9,10};
    for(int i=0;i<6;i++){
        insertAtTail(head1,arr1[i]);
    }
    for(int i=0;i<2;i++){
        insertAtTail(head2,arr2[i]);
    } 
    display(head1);
    display(head2);
    intersect(head1,head2,5);   
    display(head1);
    display(head2);  
    cout<<intersectionTwoLL(head1,head2)<<endl;

    node* head3=NULL;
    node* head4=NULL;
    int arr3[5]={1,4,5,7};
    int arr4[3]={2,3,6};
    for(int i=0;i<4;i++){
        insertAtTail(head3,arr3[i]);
    }
    for(int i=0;i<3;i++){
        insertAtTail(head4,arr4[i]);
    } 
    display(head3);
    display(head4);
    // node* head5=mergeTwoSortedLL(head3,head4);
    node* head5=mergeRecursive(head3,head4);
    display(head5);

    node* head6=NULL;
    int arr6[6]={1,2,3,4,5,6};
    for(int i=0;i<6;i++){
        insertAtTail(head6,arr6[i]);
    }
    display(head6);
    putEvenPosNodAftOddPosNod(head6);
    display(head6);

    return 0;
}