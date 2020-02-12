// Number of coprimes with x smaller than n
// O(sqrt(n))

int sol(int x, int n){
  int ans = n;
  for(int i=2; i*i<=n; i++) if(x%i==0){
    ans-=(ans/i);
    while(x%i==0) x/=i;
  }
  if(x!=1) ans-= ans/x;
  return ans;
}
