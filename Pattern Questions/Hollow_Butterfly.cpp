*        *
**      **
* *    * *  
*  *  *  *
*   **   *
*   **   *
*  *  *  *
* *    * *  
**      **
*        *
// code for the pattern

#include<iostream>
using namespace std;
int main(){
    int n=5;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(i==j || j==1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        for(int j=1;j<=n*2-i*2;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            if(i==j || j==1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }cout<<endl;
    } 

     for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            if(i==j || j==1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        for(int j=1;j<=n*2-i*2;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            if(i==j || j==1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }cout<<endl;
    }
    return 0;
}
