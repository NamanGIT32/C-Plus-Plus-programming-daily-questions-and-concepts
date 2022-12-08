********1********
*******2*2*******
******3*3*3******
*****4*4*4*4*****
****5*5*5*5*5****

//Code for the above pattern


#include<iostream>
using namespace std;
int main(){
    int n=5;
    int sum=0;
    for(int i=1;i<=n;i++){
        sum++;
        for(int j=1;j<=4;j++){
            cout<<"*";
        }
        for(int j=1;j<=n-i;j++){
            cout<<"*";
        }
        for(int j=1;j<=i;j++){
            if(j==i){
                cout<<sum;
            }
            else{
                cout<<sum<<"*";
            } 
        }
        for(int j=1;j<=n-i;j++){
            cout<<"*";
        }
        for(int j=1;j<=4;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
