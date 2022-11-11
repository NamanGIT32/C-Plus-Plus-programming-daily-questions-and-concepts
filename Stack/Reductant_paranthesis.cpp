#include<iostream>
#include<stack>
using namespace std;
bool redp(string s){
    int count=0;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                st.pop();
                count++;
            }
            if(!st.empty()){
                st.pop();
            }
            if(!st.empty()){
                count=0;
            }
        }
        else{
            st.push(s[i]);
        }
        
    }
    if(count==0){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    if(redp("((a*b)+(c+d))")){
        cout<<"valid!";
    }
    else{
        cout<<"not valid!";
    }
    return 0;
}
