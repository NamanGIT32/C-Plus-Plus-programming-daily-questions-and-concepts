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
    value<int,value<char,double>> v1;
    v1.seta(56);
    value<char,double> v2;
    v2.seta('N');
    v2.setb(75.97);
    v1.setb(v2);

    cout<<v1.geta()<<endl;
    cout<<v1.getb().geta()<<endl;
    cout<<v1.getb().getb();
    return 0;

}
