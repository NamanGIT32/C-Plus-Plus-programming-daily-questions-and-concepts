#include<iostream>
using namespace std;
int main(){
    int n=5;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<" ";                                                                    *
        }                                                                                ***
        for(int j=1;j<=i;j++){                                                          * * *  
            if(i==n){                                                                  *  *  * 
                cout<<"*";                                                            ********* 
            }                                                                          *  *  *
            else{                                                                       * * *
                if(j==1 || j==i){                                                        ***
                    cout<<"*";                                                            *
                }
                else{
                    cout<<" ";
                }
            }
        }
        for(int k=i*2-2;k>=i;k--){
            if(i==n){
                cout<<"*";
            }
            else{
                if(k==i){
                    cout<<"*"<<" ";
                }
                else{
                    cout<<" ";
                }
            }
        }cout<<endl;
    }
    for(int i=1;i<=n-1;i++){
        for(int j=i;j>=1;j--){
            cout<<" ";
        }
        for(int j=n-i;j>=1;j--){
            if(j==n-i || j==1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        for(int k=n-i-1;k>=1;k--){
            if(k==1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }cout<<endl;
    }
    return 0;
}

 
