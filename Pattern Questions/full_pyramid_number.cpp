#include<iostream>
using namespace std;
int main(){
    int n=20;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<"  ";
        }
        for(int j=i;j<=i*2-1;j++){
            cout<<j<<" ";
        }
        for(int k=i*2-2;k>=i;k--){
            cout<<k<<" ";
        }cout<<endl;
    }
    return 0;
}
