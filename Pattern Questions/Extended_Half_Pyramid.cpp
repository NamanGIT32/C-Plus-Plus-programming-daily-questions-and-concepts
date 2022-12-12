*
* *
* * * *
* * * * * * *
* * * * * * * * * * *
* * * * * * * * * * * * * * * *

// code for the above pattern

#include<iostream>
using namespace std;
int main(){
    int n=6;
    int count=1;
    int value=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=count;j++){
            cout<<"*"<<" ";
            value++;
        }
        for(int j=i-1;j>=1;j--){
            cout<<"*"<<" ";
            value++;
        }
        count=value;
        value=0;
        cout<<endl;
    }
    return 0;
}
