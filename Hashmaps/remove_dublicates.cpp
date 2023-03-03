#include<bits/stdc++.h>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> remove_dublicates(int arr[],int size){
    vector<int> output;
    unordered_map<int,bool> seen;
    for(int i=0;i<size;i++){
        if(seen.count(arr[i])>0){
            continue;
        }
        seen[arr[i]]=true;
        output.push_back(arr[i]);
    }
    return output;
}
int main(){
    vector<int> vec={1,3,5,2,5,4,6,5,7};
    vector<int> output=remove_dublicates(vec,vec.size());
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }cout<<endl;
    
    return 0;
    }
