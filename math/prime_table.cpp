vector<bool> prime_table(int n){
    vector<bool> res(n+1,true);
    if(n>=0) res[0]=false;
    if(n>=1) res[1]=false;
    for(int i=2;i*i<=n;++i){
        if(!res[i]) continue;
        for(int j=i*i;j<=n;j+=i) res[j]=false;
    }
    return res;
}

