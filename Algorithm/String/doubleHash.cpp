ll base1[ms];
ll base2[ms];

ll mod1 = 1e9+7;
ll mod2 = 1073676287;
ll prime1 = 49;
ll prime2 = 71;
 
struct stringh {
  vector<ii> a;
  stringh () {};
  
  stringh (string &s) {
    a.resize(s.size()+1);
    a[0] = {0, 0};
    for (int i = 0; i < s.size(); i++){
      a[i+1].x = (a[i].x * prime1 + s[i]) % mod1;
      a[i+1].y = (a[i].y * prime2 + s[i]) % mod2;
    }
  }
  // 0 based
  ii get (int l, int r) {
    return {(a[r+1].x - a[l].x * base1[r-l+1] % mod1 + mod1) % mod1, (a[r+1].y - a[l].y * base2[r-l+1] % mod2 + mod2) % mod2};
  }
};
 
void init () {
  base1[0] = 1;
  base2[0] = 1;
  for (int i = 1; i < ms; i++) {
    base1[i] = (base1[i-1] * prime1) % mod1;
    base2[i] = (base2[i-1] * prime2) % mod2;
  }
}
