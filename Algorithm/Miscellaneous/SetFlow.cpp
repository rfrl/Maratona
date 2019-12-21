// Set/Map Flow
// Variable limit, minimizes scores
// Doce de banana as exemple
// Process: Buy, Extend, limit

void solve(){
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>a[i]>>b[i]>>c[i];
  }

  a[n] = 0;
  int qtB = 0;
  map<int, int> preco;
  int ans = 0;

  for(int i=0; i<n; i++){

    preco[c[i]]+=b[i];
    qtB+=b[i];
    int obj = a[i];
    while(preco.size() && obj>0){

      ii cur = *preco.begin();
      preco.erase(cur.x);
      int aux = min(obj, cur.y);
      cur.y-=aux;
      qtB-=aux;
      obj-=aux;
      ans+=(aux*cur.x);
      
      if(cur.y){
        preco[cur.x]=cur.y;
      }

    }

    if(obj){
      cout<<-1<<endl;
      return;
    }

    while(qtB>a[i+1]){
    
      ii cur = *preco.rbegin();
      preco.erase(cur.x);
      int aux = min(qtB-a[i+1], cur.y);
      cur.y-=aux;
      qtB-=aux;
      
      if(cur.y){
        preco[cur.x]=cur.y;
      }
      
    }

  }
  cout<<ans<<endl;
}
