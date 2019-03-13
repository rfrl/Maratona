vector<int> fastPrime(int lim) {
    vector<bool> sieve( lim , 1);
    vector<int> resp;
    resp.push_back(2);
    for(int i=3; i<lim; i+=2){
        if(sieve[i]){
            resp.push_back(i);
            if(i*1ll*i>lim) continue;
            for(int j=i*i; j<lim; j+=i+i){
               sieve[j]=0;
            }
         }
      }
      return resp;
}
