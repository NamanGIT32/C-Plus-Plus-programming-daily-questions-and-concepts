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
void print(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

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
Node *remove_dublicates(Node *head){
    if(head->next==NULL){
        return head;
    }
    Node *temp;
    Node *t1=head;
    Node *t2=t1->next;
    while(t2!=NULL){
        if(t2->data!=t1->data){
            t2=t2->next;
            t1=t1->next;
        }
        else{
            temp=t2;
            t2=t2->next;
            t1->next=t2;
            delete temp;
        }
    }
    return head;
}
int main(){
    cout<<"enter the linked list to be shown : "<<endl;
    Node *head=takeinput();
    cout<<"The entered linked list is :"<<endl;
    print(head);
    cout<<"the linked list after removing dublicates is : "<<endl;
    head=remove_dublicates(head);
    print(head);
    cout<<endl;
    return 0;
}
