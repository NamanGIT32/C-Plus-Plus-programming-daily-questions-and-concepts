A
A B A
A B C B A
A B C D C B A
A B C D E D C B A

// code for above pattern is : 

#include<iostream>
using namespace std;
int main(){
    int n=5;
    char ch=65;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            cout<<char(ch+j)<<" ";
        }
        for(int j=i-2;j>=0;j--){
            cout<<char(ch+j)<<" ";
        }cout<<endl;
    }
    return 0;
}
