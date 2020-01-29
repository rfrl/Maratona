// Paths with size K on a tree using DSU

vi g[ms];
int sum;
int sz[ms];
int h[ms];

int getSize(int v, int p){
  for(auto x: g[v]){
    if(x==p) continue;
    h[x] = 1 + h[v];
    sz[v]+=getSize(x, v);
  }
  return ++sz[v];
}

void dfs(int v, int p,  map<int, int> &freq){
  freq[h[v]]++;
  for(auto u: g[v]){
    if(u==p) continue;
    map<int, int> nxt;
    dfs(u, v, nxt); 
    if(nxt.size()>freq.size()) freq.swap(nxt);
    for(auto x: nxt){
      int obj = k - x.x + 2*h[v];
      if(freq.count(obj))
        sum+=freq[obj] * x.y;
    }
    for(auto y: nxt) freq[y.x] += y.y;
  }
}

int getPathsWithSizeK(int k){
  sum = 0;
  map<int, int> t;
  dfs(0, 0, t);
  return sum;
}

void init(){
  memset(h, 0, sizeof(h));
  getSize(0, 0);
}
