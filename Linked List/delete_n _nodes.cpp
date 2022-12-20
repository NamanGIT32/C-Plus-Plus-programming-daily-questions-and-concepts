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
Node *n_delete(Node *head,int n,int m){
    if(head==NULL || head->next==NULL){ 
        return head;
    }
    // Node *temp=head;
    int c1=1,c2=1;
    Node *t1=head;
    while(t1!=NULL){
        while(c1<n && t1!=NULL){
            c1++;
            t1=t1->next;
        }
        Node *t2=t1->next;
        while(c2<m && t2!=NULL){
            Node *del=t2;
            t2=t2->next;
            delete del;
            c2++;
        }
        if(t2==NULL || t2->next==NULL){
            t1->next=NULL;
            return head;
        }
        t2=t2->next;
        t1->next=t2;
        t1=t2;
        c1=1,c2=1;
    }
}
int main(){
    cout<<"enter the linked list to be shown : "<<endl;
    Node *head=takeinput();
    cout<<"The entered linked list is :"<<endl;
    print(head);
    cout<<"delete after n nodes of linked list is : "<<endl;
    int n=2,m=3;
    head=n_delete(head,n,m);
    print(head);
    return 0;
}
