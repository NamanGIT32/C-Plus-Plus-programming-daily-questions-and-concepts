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
Node *evenafterodd(Node *head){
    Node *oddh=NULL;
    Node *oddt=NULL;
    Node *evenh=NULL;
    Node *event=NULL;
    while(head!=NULL){
        if((head->data)%2!=0){
            if(oddh==NULL){
                oddh=head;
                oddt=head;
            }
            else{
                oddt->next=head;
                oddt=head;
            }
        }
        else{
            if(evenh==NULL){
                evenh=head;
                event=head;
            }
            else{
                event->next=head;
                event=head;
            }
        }
        head=head->next;
    }
    event->next=NULL;
    oddt->next=NULL;
    oddt->next=evenh;
    return oddh;
} 
void print(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}
int main(){
    cout<<"enter the linked list to be shown : "<<endl;
    Node *head=takeinput();
    print(head);
    head=evenafterodd(head);
    cout<<"Linked list even after odd is : "<<endl;
    print(head);
}
