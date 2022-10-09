#include<bits/stdc++.h>
using namespace std; 
template <typename T>
class Node{
    public:
    T data;
    Node<T> *next;
    Node(T data){
        this->data=data;
        next=NULL;
    }
};
template <typename T>
class StackUsingLL{
    public:
    Node<T> *head;
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
    void push(T element){
        Node<T> *newnode=new Node<T>(element);
            newnode->next=head;
            head=newnode;
            sizeofstack++;
    }
    T pop(){
        if(isEmpty()){
            return 0;
        }
        T ans=head->data;
        Node<T> *temp=head;
        head=head->next;
        delete temp;
        sizeofstack--;
        return ans;
    }
    T top(){
        if(isEmpty()){
            return 0;
        }
        return head->data;
    }
};
int main(){
    StackUsingLL<char> s1;
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
