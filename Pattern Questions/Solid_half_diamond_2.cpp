3
4 4
5 5 5
6 6 6 6
5 5 5
4 4
3

//code for above pattern
#include<iostream>
using namespace std;
int main(){
    int n=4;
    int m=2;
    int sum=m;
    for(int i=1;i<=n;i++){
        sum++;
        for(int j=1;j<=i;j++){
            cout<<sum<<" ";
        }cout<<endl;
    }
    for(int i=n-1;i>=1;i--){
        sum--;
        for(int j=1;j<=i;j++){
            cout<<sum<<" ";
        }cout<<endl;
    }
    return 0;
}
