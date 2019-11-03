// Both centroids

vector<int> get_centroids(vector<vector<int> > const & g, int root, set<int> const & forbidden) {
    map<int, int> available; {
        function<void (int, int)> go = [&](int i, int parent) {
            available.emplace(i, available.size());
            for (auto j : g[i]) if (j != parent and not forbidden.count(j)) {
                go(j, i);
            }
        };
        go(root, -1);
    }
    int n = available.size();
    vector<int> result;
    vector<int> size(n, -1);
    function<void (int, int)> go = [&](int x, int parent) {
        bool is_centroid = true;
        int i = available[x];
        size[i] = 1;
        for (auto y : g[x]) if (y != parent and available.count(y)) {
            int j = available[y];
            go(y, x);
            size[i] += size[j];
            if (size[j] > n / 2) is_centroid = false;
        }
        if (n - size[i] > n / 2) is_centroid = false;
        if (is_centroid) result.push_back(x);
    };
    go(root, -1);
    return result;
}

// Any Centroid

void dfsSize(int v, int pa) {
  sz[v] = 1;
  for(int u : adj[v]) {
    if (u == pa || rem[u]) continue;
    dfsSize(u, v);
    sz[v] += sz[u];
  }
}

int getCentroid(int v, int pa, int tam) {
  for(int u : adj[v]) {
    if (u == pa || rem[u]) continue;
    if (2 * sz[u] > tam) return getCentroid(u, v, tam);
  }
  return v;
}


// Decomposition

void decompose(int v, int pa = -1) {
  //cout << v << ' ' << pa << '\n';
  dfsSize(v, pa);
  int c = getCentroid(v, pa, sz[v]);
  //cout << c << '\n';
  par[c] = pa;
  rem[c] = 1;
  for(int u : adj[c]) {
    if (!rem[u] && u != pa) decompose(u, c);
  }
  adj[c].clear();
}
