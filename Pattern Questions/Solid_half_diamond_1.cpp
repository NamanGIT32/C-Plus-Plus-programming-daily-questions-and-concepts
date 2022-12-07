  1
  2*3
  4*5*6
  7*8*9*10
  7*8*9*10
  4*5*6
  2*3
  1
          
//Code for the above pattern
#include<iostream>
using namespace std;
int main(){
    int n=4;
    int sum=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j==i){
                cout<<sum;
            }
            else{
                cout<<sum<<"*";
            }
            sum++;
        }cout<<endl;
    }
    // sum=sum-n;
    for(int i=n;i>=1;i--){
        if(i==n){
            sum=sum-n;
        }
        else{
           sum=sum-1-i*2; 
        }
        for(int j=1;j<=i;j++){
            if(j==i){
                cout<<sum;
            }
            else{
                cout<<sum<<"*";
            }
            sum++;
        }cout<<endl;
        
    }
    return 0;

}
