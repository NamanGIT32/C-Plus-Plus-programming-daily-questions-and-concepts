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
    Queue_using_arrays(){
        data=new T[4];
        nextindex=0;
        firstindex=-1;
        size=0;
        capacity=4;
    }
  
    int getSize(){
        return size;
    }
  
    bool isEmpty(){
        return size==0;
    }
  
    void enqueue(T element){
        if(size==capacity){
            T *newdata=new T[capacity*2];
            int j=0;
            for(int i=firstindex;i<capacity;i++){
                newdata[j]=data[i];
                j++;
            }
            for(int i=0;i<firstindex;i++){
                newdata[j]=data[i];
                j++; 
            }

            delete [] data;
            data=newdata;
            capacity*=2;
            nextindex=capacity;
            firstindex=0;
        }
        data[nextindex]=element;
        if(firstindex==-1){
            firstindex=0;
        }
        size++;
        nextindex=(nextindex+1)%10;
    }
    
    T front(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        return data[firstindex];
    }
  
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
    Queue_using_arrays<int> q1;
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
