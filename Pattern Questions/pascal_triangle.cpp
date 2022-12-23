1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
//code for the above pattern  
  
#include<iostream>
using namespace std;
int main(){
    int n=5;
    for(int i=1;i<=n;i++){
        int var=1;
        for(int j=1;j<=i;j++){
            cout<<var<<" ";
            var=var*(i-j)/j;
        }cout<<endl;
    }
    return 0;
}
