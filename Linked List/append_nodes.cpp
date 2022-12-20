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
void print(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int length(Node *head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
Node *append_nodes(Node *head,int n,int len){
    if(n==0 || n>=len){
        return head;
    }
    Node *temp=head;
    Node *head2;
    Node *tail;
    for(int i=0;i<len-n;i++){
        if(i<len-n-1){
            temp=temp->next;
        }
    }
    head2=temp->next;
    temp->next=NULL;
    tail=head2;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=head;
    return head2;
}
int main(){
    cout<<"enter the linked list to be shown : "<<endl;
    Node *head=takeinput();
    cout<<"The entered linked list is :"<<endl;
    print(head);
    int n=3;
    head=append_nodes(head,n,len);
    cout<<"The appended linked list is : "<<endl;
    print(head);
    cout<<endl;
    return 0;
}
