//Fiding the result for ax+by+c=0

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


