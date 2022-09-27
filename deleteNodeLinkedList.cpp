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
// -----------Delete Node------------
Node *deletenode(int i,Node *head){
    Node *temp=head;
    int count=0;
    if(i==0){
        temp=head->next;
        delete head;
        return temp;
    }
    while(temp!=NULL && count<i-1){
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){
    Node *a=temp->next;
    Node *b=a->next;
    temp->next=b;
    delete a;
    return head;
    }
    else{
        return head;
    }
}

int main(){
    cout<<"enter the linked list to be shown : "<<endl;
    Node *head=takeinput();
    cout<<"The entered linked list is :"<<endl;
    print(head);
    int i;
    cout<<"enter the position to be deleted"<<endl;
    cin>>i;
    head=deletenode(i,head);
    print(head);

    return 0;
}
