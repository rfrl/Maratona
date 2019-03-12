//Define the limit and the modulo

long long cata[lim];

void cat(int l, int mod){
    cata[0]=cata[1]=1;
    for(int i=2; i<l; i++){
        cata[i]=0;
        for(int j=0; j<i; j++){
            cata[i]=( cata[i]+ (cata[j]*cata[i-j-1]))%mod;
        }
    }
}

/*

1 -> 1
2 -> 2
3 -> 5
4 -> 14
5 -> 42
6 -> 132

*/
