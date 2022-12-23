1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
  
 //code to print particular row of pascal triangle 
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the row of pascal triangle to be printed : "<<endl;
    cin>>n;
    int var=1;
    for(int j=1;j<=n;j++){
        cout<<var<<" ";
        var=var*(n-j)/j;
    }
    return 0;
}
