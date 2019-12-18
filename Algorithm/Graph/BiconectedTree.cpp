const int V=1e6+5;
int timer, dfsroot, rootchildren;
vector<int>num, low, par, cutvertex, g[V];

int ds[ms], sz[ms], n;
set<ii> bridge;

vector<int> biG[V];
set<int> used;
set<int> hasEdge[V];

void dsBuild() {
  for(int i = 0; i < n; i++) {
    ds[i] = i;
    sz[i] = 1;
  }
}

int dsFind(int i) {
  if(ds[i] != i) ds[i] = dsFind(ds[i]);
  return ds[i];
}

void dsUnion(int a, int b) {
  a = dsFind(a); b = dsFind(b);
  if(sz[a] < sz[b]) swap(a, b);
  if(a != b) sz[a] += sz[b];
  ds[b] = a;
}

inline void iscutvertex(int v){
	cutvertex[v]=true;
}

inline void isbridge(int u, int v){
  bridge.insert({u, v});
  bridge.insert({v, u});
}

void dfspointbridge(int u){
	low[u]=num[u]=timer++;
	for(int v : g[u]){
		if(num[v]==0){
			par[v]=u;
			if(u == dfsroot) rootchildren++;

			dfspointbridge(v);

			if(low[v]>=num[u]){
				iscutvertex(v);
			}
			if(low[v]>num[u]){
				isbridge(u,v);
			}
			low[u]=min(low[u], low[v]);
		}else if(v != par[u]) low[u]=min(low[u],num[v]);
	}
}

void findpointbridge(int n=V){
	timer=0;
	num.assign(n+1,0);
	low.assign(n+1,0);
	par.assign(n+1,0);
	cutvertex.assign(n+1,0);
	for(int i=0;i<n;i++){
		if(num[i]==0){
			dfsroot=i; rootchildren=0; dfspointbridge(i);
			if(rootchildren > 1) iscutvertex(i);
		}
	}
}

void dfsJoinComponentes(int v, int prev_bridge){
  dsUnion(v, prev_bridge);
  used.insert(v);
  for(auto u: g[v]){
    if(used.count(u)) continue;
    if(bridge.count({v, u})){
      dfsJoinComponentes(u, u);
    }else{
      dfsJoinComponentes(u, v);
    }
  }
}

void createBiconectedTree(int root = 0){
  findpointbridge(n);
  for(int i=0; i<n; i++){
    if(used.count(i)==0){
      dfsJoinComponentes(i, i);
    }
  }
  for(int i=0; i<n; i++){
    for(auto v: g[i]){
      if(bridge.count({i, v}) && hasEdge[dsFind(i)].count(dsFind(v))==0){
        biG[dsFind(i)].pb(dsFind(v));
        hasEdge[dsFind(i)].insert(dsFind(v));
      }
    }
  }
}
