#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Queue_using_arrays{
    public:
    T *data;
    int nextindex;
    int firstindex;
    int size;
    int capacity;
    Queue_using_arrays(int s){
        data=new T[s];
        nextindex=0;
        firstindex=-1;
        size=0;
        capacity=s;
    }
    
    //---------returns the size of queue-----------
    int getSize(){
        return size;
    }
    
    //--------shows if queue is empty or not ---------
    bool isEmpty(){
        return size==0;
    }
    
    //--------insert element in queue----------
    void enqueue(T element){
    if(size==capacity){
        cout<<"Queue full!"<<endl;
        return;
    }
    data[nextindex]=element;
    size++;
    nextindex=(nextindex+1) % capacity;
    if(firstindex==-1){
        firstindex=0;
    }
    }
    
    //--------returns the first element of queue---------
    T front(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        return data[firstindex];
    }
    
    //---------delete & returns the element of queue----------
    T dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        T ans=data[firstindex];
        firstindex=(firstindex+1) % capacity;
        size--;
        return ans;
    }
};

int main(){

    Queue_using_arrays<int> q1(5);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    cout<<q1.front()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    q1.enqueue(50);
    q1.enqueue(60);
    cout<<q1.front()<<endl;
    cout<<q1.getSize()<<endl;
    cout<<q1.isEmpty()<<endl;;
    return 0;
}
