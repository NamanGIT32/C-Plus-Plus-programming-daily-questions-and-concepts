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
Node *inputcircularlist(){
    Node *head=NULL;
    Node *tail=NULL;
    int data;
    cin>>data;
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
    tail->next=head;
    return head;
}
void print(Node *head){
    Node *temp=head;
    while(temp->next!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<endl;
}
int main(){
    cout<<"enter the circular LL : "<<endl;
    Node *head=inputcircularlist();  
    cout<<"entered circular LL is : "<<endl;
    print(head);
    return 0;
}
