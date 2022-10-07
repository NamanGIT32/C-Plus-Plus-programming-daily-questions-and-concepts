#include<bits/stdc++.h>
using namespace std;
template<typename T>
class value{
    T a;
    T b;
    public:
    void seta(T a){
        this->a=a;
    }
    T geta(){
        return a;
    }

    void setb(T b){
        this->b=b;
    }
    T getb(){
        return b;
    }
};
int main(){
    value<int> v1;
    v1.seta(20);
    v1.setb(67);
    cout<<v1.geta()<<" "<<v1.getb()<<endl;

    value<char> v2;
    v2.seta('a');
    v2.setb('b');
    cout<<v2.geta()<<" "<<v2.getb()<<endl;
    return 0;

}
