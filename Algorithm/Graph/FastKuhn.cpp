int n, m;

int matchA[ms], matchB[ms];
int visB[ms];

vi g[ms];

bool dfsKuhn(int v){
  for(auto u: g[v]){
    if(visB[u]==1) continue;
    visB[u] = 1;
    if(matchB[u]==-1 || dfsKuhn(matchB[u])){
      matchB[u] = v;
      matchA[v] = u;
      return 1;
    }
  }
  return 0;
}

int fastKuhn(){
  for(int i=0; i<n; i++) matchA[i] = -1;
  for(int i=0; i<m; i++) matchB[i] = -1;
  bool aux = 1;
  int ans = 0;
  while(aux){
    for(int i=0; i<m; i++) visB[i] = 0;
    aux = 0;
    for(int i=0; i<n; i++){
      if(matchA[i] != -1) continue;
      if(dfsKuhn(i)){
        ans++;
        aux = 1;
      }
    }
  }
  return ans;
}
