#include<bits/stdc++.h>
#include<unordered_map>
#include<vector>
using namespace std;
int max_num(vector<int>& vec,int size){
    unordered_map<int,int> mp;
    for(int i=0;i<vec.size();i++){
        mp[vec[i]]++;
    }
    int mx=-1,ele=-1;
    for(auto i: mp){
        if(mx<i.second){
            mx=i.second;
            ele=i.first;
        }
    }
    return ele;
}
int main(){
    vector<int> vec={1,3,5,2,5,4,6,5,7};
    int num=max_num(vec,vec.size());
    cout<<num;

    return 0;
}
