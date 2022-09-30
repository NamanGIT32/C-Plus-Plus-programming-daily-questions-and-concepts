#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int data){
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};
Node *takeinput(){
    Node *head=NULL;
    Node *tail=NULL;
    Node *temp=head;
    int data;
    cin>>data;
    
    while(data!=-1){
        Node *newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
            temp=head;
        }
        else{
            tail->next=newnode;
            tail=newnode;
            tail->prev=temp;
            temp=tail;
        }
        cin>>data;
    }
    return head;
}
Node *insertnode(Node *head,int pos,int data){
    Node *temp=head;
    int count=0;
    Node *newnode=new Node(data);
    if(pos==0){
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
        return head;
    }
    while(temp!=NULL && count<pos-1){
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){
    Node *a=temp->next;
    temp->next=newnode;
    newnode->next=a;
    newnode->prev=temp;
    a->prev=newnode;
    }
    return head;
}
void print(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}
int main(){
    cout<<"enter the doubly linked list : "<<endl;
    Node *head=takeinput();
    cout<<"Entered doubly linked list is : "<<endl;
    print(head);
    int pos,data;
    cout<<"enter the position and data : "<<endl;
    cin>>pos>>data;
    head=insertnode(head,pos,data);
    print(head);

    return 0;

}
