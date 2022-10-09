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
class StackUsingLL{
    public:
    Node *head;
    int sizeofstack;
    StackUsingLL(){
        sizeofstack=0;
        head=NULL;
    }
    int size(){
        return sizeofstack;
    }
    bool isEmpty(){
        if(sizeofstack==0){
            cout<<"Stack is empty"<<endl;
            return 1;
        }
        else{
            return 0;
        }
    }
    void push(int element){
        Node *newnode=new Node(element);
            newnode->next=head;
            head=newnode;
            sizeofstack++;
    }
    int pop(){
        if(isEmpty()){
            return 0;
        }
        int ans=head->data;
        Node *temp=head;
        head=head->next;
        delete temp;
        sizeofstack--;
        return ans;
    }
    int top(){
        if(isEmpty()){
            return 0;
        }
        return head->data;
    }
};
int main(){
    StackUsingLL s1;
    s1.push(100);
    s1.push(101);
    s1.push(102);
    cout<<s1.size()<<endl;
    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    
    return 0;
}
