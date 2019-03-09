#include <bits/stdc++.h>

using namespace std;

int main(){
   string a,b;
   cin>>a>>b;
   int mina=0, minb=0;
   mina=(a[0]-'0')*600+(a[1]-'0')*60 + (a[3]-'0')*10+(a[4]-'0');
   minb=(b[0]-'0')*600+(b[1]-'0')*60 + (b[3]-'0')*10+(b[4]-'0');
   printf("%02d:%02d", ((mina+minb)/2)/60, ((mina+minb)/2)%60);
   return 0;
}
