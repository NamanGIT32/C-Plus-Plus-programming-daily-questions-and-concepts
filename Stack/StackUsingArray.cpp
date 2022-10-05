#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;
    public:
    StackUsingArray(int totalsize){
        data=new int[totalsize];
        nextIndex=0;
        capacity=totalsize;
    }
    //returns size of Stack
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        if(nextIndex==0){
            return 1;
        }
        else{
            return 0;
        }
    }

    //Insert Element
    void push(int element){
        if(nextIndex==capacity){
            cout<<"stack is full"<<endl;
            return;
        }
        data[nextIndex]=element;
        nextIndex++;
    }

    //pop element
    int pop(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    //Show top element
    int top(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
};
int main(){
    StackUsingArray s1(5);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    
    cout<<s1.size()<<endl;
    cout<<s1.isEmpty()<<endl;
    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.size()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.size()<<endl;
    
    return 0;
}
