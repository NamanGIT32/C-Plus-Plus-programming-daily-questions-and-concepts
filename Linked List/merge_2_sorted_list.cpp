#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
Node *takeInput(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1){
        Node *newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node *merge_list(Node *h1,Node *h2){
    if(h1==NULL && h2==NULL){
        return NULL;
    }
    if(h1==NULL){
        return h2;
    }
    if(h2==NULL){
        return h1;
    }
    Node *fh=NULL;
    Node *ft=NULL;
    if(h1->data < h2->data){
        fh=h1;
        ft=h1;
        h1=h1->next;
    }
    else{
        fh=h2;
        ft=h2;
        h2=h2->next;
    }
    while(h1!=NULL && h2!=NULL){
        if(h1->data < h2->data){
            ft->next=h1;
            ft=h1;
            h1=h1->next;
        }
        else{
            ft->next=h2;
            ft=h2;
            h2=h2->next;
        }
    }
    while(h1!=NULL){
        ft->next=h1;
        ft=h1;
        h1=h1->next;
    }
    while(h2!=NULL){
        ft->next=h2;
        ft=h2;
        h2=h2->next;
    }
    return fh;
}
int main(){
    cout<<"Input the 1st Linked list : "<<endl;
    Node *head1=takeInput();
    cout<<"Input the 2nd Linked list : "<<endl;
    Node *head2=takeInput();
    cout<<"the 1st linked list is : "<<endl;
    print(head1);
    cout<<endl;
    cout<<"the 2nd linked list is : "<<endl;
    print(head2);
    cout<<endl;
    Node *head=merge_list(head1,head2);
    cout<<"the merged linked list is : "<<endl;
    print(head);
    return 0;
}
