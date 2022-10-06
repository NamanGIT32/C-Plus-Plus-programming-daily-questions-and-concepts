#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;
    public:
    StackUsingArray(){
        //Now we gives a random value to totalsize of array, here this random value is 4
        data=new int[4];
        nextIndex=0;
        capacity=4;
    }
    //returns size of Stack
    int size(){
        return nextIndex;
    }
  //Shows if stack is empty or not
    bool isEmpty(){
        if(nextIndex==0){
            return 1;
        }
        else{
            return 0;
        }
    }

    //Push element or Insert Element
    void push(int element){
        if(nextIndex==capacity){
            //creating a new array of double size of previous array
            int *newdata=new int[capacity*2];
            //copying the elements of previous array
            for(int i=0;i<capacity;i++){
                newdata[i]=data[i];
            }
        
        //double the capacity
        capacity*=2;
        //delete the previous array
        delete [] data;
        //point previous array to the newely created array
        data=newdata;
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
  
    StackUsingArray s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    s1.push(70);

    cout<<s1.size()<<endl;
    cout<<s1.isEmpty()<<endl;
    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.size()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.size()<<endl;
    
    return 0;
}
