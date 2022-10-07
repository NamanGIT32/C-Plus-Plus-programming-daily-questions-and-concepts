#include<bits/stdc++.h>
using namespace std;
template<typename T,typename V>
class value{
    T a;
    V b;
    public:
    void seta(T a){
        this->a=a;
    }
    T geta(){
        return a;
    }

    void setb(V b){
        this->b=b;
    }
    V getb(){
        return b;
    }
};
int main(){
    value<int,double> v1;
    v1.seta(20);
    v1.setb(67.87);
    cout<<v1.geta()<<" "<<v1.getb()<<endl;

    // value<char> v2;
    // v2.seta('a');
    // v2.setb('b');
    // cout<<v2.geta()<<" "<<v2.getb()<<endl;
    return 0;

}
