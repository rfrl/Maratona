#include <iostream>

using namespace std;

#define lim 5010

typedef long long ll;

ll x, y, d;
void gcde(ll a, ll b){
    if(b==0){
        x=1;
        y=0;
        d=a;
        return;
    }
    gcde(b, a%b);
    ll x1=y;
    ll y1=x-(a/b)*y;
    x=x1;
    y=y1;
}

int main(){
    ll a, b, c;
    cin>>a>>b>>c;
    gcde(a,b);
    if(c%d){
        cout<<"-1"<<endl;
    }else{
        cout<<x*(-c/d)<<" "<<y*(-c/d)<<endl;
    }
    return 0;
}
