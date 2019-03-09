#include <bits/stdc++.h>

using namespace std;

#define lim 200010

int elea[lim];
int eleb[lim];
map<pair<int, int>, int> mapa;

int gcd(int a, int b){
   if(b==0) return a;
   else return gcd(b, a%b);
}

int main(){
   int n, resp=0;
   cin>>n;
   mapa.clear();
   for(int i=0; i<n; i++){
      cin>>elea[i];
   }
   for(int i=0; i<n; i++){
      cin>>eleb[i];
   }
   int zero=0;
   for(int i=0; i<n; i++){
      if(elea[i]==0&&eleb[i]==0){
         zero++;
         continue;
      }
      if(elea[i]!=0){
         int div=gcd(abs(elea[i]), abs(eleb[i]));
         if(elea[i]<0){
            elea[i]=-elea[i];
            eleb[i]=-eleb[i];
         }
         int atu= ++mapa[{elea[i]/div,eleb[i]/div}];
         resp=max(resp, atu);
      }
   }
   cout<<resp+zero<<endl;
}
