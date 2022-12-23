#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the nth row no. : "<<endl;
    cin>>n;
    int m;
    cout<<"enter the mth column no. : "<<endl;
    cin>>m;
    int var=1;
    for(int i=1;i<=n;i++){
        if(i==m){
            cout<<var;
            break;
        }
        var=var*(n-i)/i;
    }
    return 0;
}
