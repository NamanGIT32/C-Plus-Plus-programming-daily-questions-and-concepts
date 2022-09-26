#include<iostream>
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

// ------------Take input of LL------------
Node *takeinput(){
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
int main(){
    cout<<"enter the linked list to be shown : "<<endl;
    Node *head=takeinput();
    cout<<"The entered linked list is :"<<endl;
    print(head);
    return 0;
}
