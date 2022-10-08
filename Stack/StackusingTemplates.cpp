#include<bits/stdc++.h>
#include<iostream>
using namespace std;
template<typename T>
class StackUsingArray{
    T *data;
    int nextIndex;
    int capacity;
    public:
    StackUsingArray(){
        //Now we gives a ranndom value to totalsize of array, here this random value is 4
        data=new T[4];
        nextIndex=0;
        capacity=4;
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
    void push(T element){
        if(nextIndex==capacity){
            //creating a new array of double size of previous array
            T *newdata=new T[capacity*2];
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
    T pop(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    //Show top element
    T top(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
        return data[nextIndex-1];
    }
};
int main(){
    StackUsingArray<int> s1;

    cout<<"Size before push"<<endl;
    cout<<s1.size()<<endl;
    s1.push(100);
    s1.push(101);
    s1.push(102);
    s1.push(103);
    s1.push(104);
    s1.push(105);
    s1.push(106);
    cout<<"Size after push"<<endl;
    cout<<s1.size()<<endl;
    cout<<"Top element is : "<<endl;
    cout<<s1.top()<<endl;
    cout<<"Poped elements are :"<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<"Top element is : "<<endl;
    cout<<s1.top();
    return 0;
}
